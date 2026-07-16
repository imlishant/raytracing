#include "color.h"
#include "ray.h"
#include "vec3.h"
#include <iostream>

int main() {

    color ray_color(const ray& r) {
        return color(0, 0, 0);
    }

    // image

    // int image_height = 256;
    // int image_width = 256;

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = int(image_width / aspect_ratio);
    image_height = image_height < 1 ? 1 : image_height;

    // camera/eye
    // viewport
    // real 3d, 4th quad
    auto focal_length = 1.0; // z-axis
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    // define horizontal & vertical vp vectors edges
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // define square-pixel delta unit
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // define vp top-left corner & pixel P(0, 0, 0);
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v  / 2;
    auto pixel00_loc = viewport_upper_left + (pixel_delta_u + pixel_delta_v) / 2;

    // render

    std::cout << "P3\n" << image_height << ' ' << image_width << "\n255\n";

    // this is the canvas/screen, so the coords are like 
    // that with top-left corner is (0,0,0), as is (i,j,0);
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            // ray_direction = ray_direction.unit_length();
            ray r(camera_center, ray_direction);
            
            color pixel_color = ray_color(r);
            // auto pixels = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rdone.                                   \n";

    return 0;

}
