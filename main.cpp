#include <iostream>
#include "raytracing_engine/engine.hpp"
#include "scenes/camera.hpp"
#include "scenes/scene.hpp"
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>
#include <unistd.h>
#include <memory>

std::vector<cv::Mat> images;

camera cam;
scene sce(cam);
unsigned long current = 0;

void oneThreadFunction()
{
    engine eng(sce);
    eng.init();
    images.emplace_back(eng.render(current));
}

int main()
{

    sce.cam.readJson("../scenes/configurations/camera_high.json");

    sce.readJson("../scenes/configurations/scene6.json");

    int nbThread = sce.cam.nbThread;
    std::vector<std::thread> threads;
    for (int i = 0; i < nbThread; i++)
    {
        threads.emplace_back(oneThreadFunction);
        usleep(10000);
    }
    while (current <= nbThread * (sce.cam.image_height - 1) * (sce.cam.image_width - 1))
    {
        std::cout << "\r" << current << "/" << nbThread * (sce.cam.image_height - 1) * (sce.cam.image_width - 1) << ":" << static_cast<double>(current * 100) / (nbThread * (sce.cam.image_height - 1) * (sce.cam.image_width - 1)) << "%" << std::flush;
        sleep(1);
    }
    for (int i = 0; i < nbThread; i++)
    {
        threads.at(i).join();
    }

    cv::Mat img(sce.cam.image_height, sce.cam.image_width, CV_8UC3);

    for (int i : tq::trange(sce.cam.image_width))
    {
        for (int j = 0; j < sce.cam.image_height; j++)
        {
            cv::Vec3i colors(0, 0, 0);
            for (int t = 0; t < nbThread; t++)
            {
                colors += images.at(t).at<cv::Vec3b>(cv::Point(i, j));
            }

            img.at<cv::Vec3b>(cv::Point(i, j)) = colors / nbThread;
        }
    }
    cv::imshow("image finale", img);
    cv::imwrite("../results/scene6.png", img);
    cv::waitKey(0);
}