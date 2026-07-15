#include "color.h"
#include "vec3.h"
#include <iostream>

int main() {

    // image

    int image_height = 256;
    int image_width = 256;

    // render

    std::cout << "P3\n" << image_height << ' ' << image_width << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
        for (int i = 0; i < image_width; i++) {

            auto pixels = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.0);
            write_color(std::cout, pixels);

        }
    }

    std::clog << "\rdone.                                   \n";

    return 0;

}
