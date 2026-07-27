#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

int main() {
    hittable_list world;

    auto sphere1 = make_shared<sphere>(point3(0, 0, -1), 0.6);
    auto sphere2 = make_shared<sphere>(point3(0, -99.6, -1), 99);
    world.add(sphere1);
    world.add(sphere2);

    camera cam;

    cam.aspect_ratio       =  16.0  /  9.0;
    cam.image_width        =  900;
    cam.samples_per_pixel  =  800;

    cam.render(world);

    return 0;
}
