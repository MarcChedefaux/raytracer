#include "engine.hpp"

engine::engine(camera c)
{
    cam = c;
}

void engine::render()
{

    cv::Mat img(cam.image_height, cam.image_width, CV_8UC3);

    for (int i : tq::trange(cam.image_width))
    {
        for (int j = 0; j < cam.image_height; j++)
        {

            color3 col(double(i) / (cam.image_width - 1), double(j) / (cam.image_height - 1), 0);

            img.at<cv::Vec3b>(cv::Point(i, j)) = col.to_cvColor();
        }
    }

    cv::imshow("test", img);
    cv::waitKey();
    std::cout << "END" << std::endl;
}