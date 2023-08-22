#include "engine.hpp"

engine::engine(scene s)
{
    cam = s.cam;
    sce = s;
}

point3 engine::pixel_sample_square() const
{
    double px = -0.5 + random_double();
    double py = -0.5 + random_double();
    return (px * pixel_delta_u) + (py * pixel_delta_v);
}

point3 engine::defocus_disk_sample() const
{
    vector3 p = vector3::random_in_unit_disk();
    return cam.lookFrom + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
}

ray engine::get_ray(int i, int j) const
{
    point3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
    point3 pixel_sample = pixel_center + pixel_sample_square();

    vector3 ray_origin = (cam.defocus_angle <= 0 ? cam.lookFrom : defocus_disk_sample());
    vector3 ray_direction = pixel_sample - ray_origin;
    return ray(ray_origin, ray_direction);
}

color3 engine::ray_color(const ray &r, int depth) const
{
    if (depth <= 0)
        return color3(0, 0, 0);
    hit_record rec;
    if (sce.hit(r, interval(0.001, infinity), rec))
    {
        ray scattered;
        color3 attenuation;
        if (rec.mat->scatter(r, rec, attenuation, scattered))
        {
            return attenuation * ray_color(scattered, depth - 1);
        }
        if (rec.isLighting)
        {
            return attenuation;
        }
        else
        {
            return color3(0, 0, 0);
        }
    }
    return color3(0, 0, 0);
}

void engine::init()
{
    vector3 w = unit_vector(cam.lookFrom - cam.lookAt);
    vector3 vup(0, 1, 0);
    vector3 u = unit_vector(cross(vup, w));
    vector3 v = cross(w, u);

    vector3 viewport_u = cam.viewport_width * u;
    vector3 viewport_v = cam.viewport_height * -v;

    pixel_delta_u = viewport_u / cam.image_width;
    pixel_delta_v = viewport_v / cam.image_height;

    point3 viewport_upper_left = cam.lookFrom - (cam.focus_dist * w) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    double defocus_radius = cam.focus_dist * tan(degrees_to_radians(cam.defocus_angle / 2));
    defocus_disk_u = u * defocus_radius;
    defocus_disk_v = v * defocus_radius;
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
                pixcol += ray_color(r, cam.max_depth);
            }

            img.at<cv::Vec3b>(cv::Point(i, j)) = pixcol.to_cvColor(cam.samples_per_pixel);
        }
    }

    cv::imshow("test", img);
    cv::imwrite("../results/scene3.png", img);
    cv::waitKey();
}