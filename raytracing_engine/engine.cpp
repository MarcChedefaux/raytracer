#include "engine.hpp"

engine::engine(camera c, scene s)
{
    cam = c;
    sce = s;
}

double hit_sphere(const point3 &center, double radius, const ray &r)
{
    vector3 oc = r.origin() - center;
    double a = r.direction().lengthSquarred();
    double half_b = dot(oc, r.direction());
    double c = oc.lengthSquarred() - radius * radius;
    double discriminant = half_b * half_b - a * c;

    if (discriminant < 0)
    {
        return -1.0;
    }
    else
    {
        return (-half_b - sqrt(discriminant)) / a;
    }
}

color3 engine::ray_color(const ray &r)
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
            point3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            vector3 ray_direction = pixel_center - sce.cameraPosition;
            ray r(sce.cameraPosition, ray_direction);

            color3 col = ray_color(r);

            img.at<cv::Vec3b>(cv::Point(i, j)) = col.to_cvColor();
        }
    }

    cv::imshow("test", img);
    cv::waitKey();
}