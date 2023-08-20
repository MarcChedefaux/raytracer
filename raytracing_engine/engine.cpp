#include "engine.hpp"

engine::engine(camera c, scene s)
{
    cam = c;
    sce = s;
}

point3 engine::pixel_sample_square() const
{
    double px = -0.5 + random_double();
    double py = -0.5 + random_double();
    return (px * pixel_delta_u) + (py * pixel_delta_v);
}

ray engine::get_ray(int i, int j) const
{
    point3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
    point3 pixel_sample = pixel_center + pixel_sample_square();

    vector3 ray_direction = pixel_center - sce.cameraPosition;
    return ray(sce.cameraPosition, ray_direction);
}

color3 engine::ray_color(const ray &r) const
{
    hit_record rec;
    if (sce.hit(r, interval(0, infinity), rec))
    {
        return color3(0.5 * (rec.normal + vector3(1, 1, 1)));
    }
    vector3 unit_direction = unit_vector(r.direction());
    double a = 0.5 * (unit_direction.y() + 1.0);
    return color3((1.0 - a) * color3(1.0, 1.0, 1.0) + a * color3(0.5, 0.7, 1.0));
}

void engine::init()
{
    vector3 viewport_u = vector3(cam.viewport_width, 0, 0);
    vector3 viewport_v = vector3(0, -cam.viewport_height, 0);

    pixel_delta_u = viewport_u / cam.image_width;
    pixel_delta_v = viewport_v / cam.image_height;

    point3 viewport_upper_left = sce.cameraPosition - vector3(0, 0, cam.focal_length) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

void engine::render()
{
    cv::Mat img(cam.image_height, cam.image_width, CV_8UC3);

    for (int i : tq::trange(cam.image_width))
    {
        for (int j = 0; j < cam.image_height; j++)
        {
            color3 pixcol(0, 0, 0);
            for (int sample = 0; sample < cam.samples_per_pixel; sample++)
            {
                ray r = get_ray(i, j);
                pixcol += ray_color(r);
            }

            img.at<cv::Vec3b>(cv::Point(i, j)) = pixcol.to_cvColor(cam.samples_per_pixel);
        }
    }

    cv::imshow("test", img);
    cv::waitKey();
}