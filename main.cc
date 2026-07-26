#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

int main() {
    // world
    // 2 sphere, 1 visible obj, 2nd ground, very large

    hittable_list world;

    shared_ptr<hittable> sphere1 = make_shared<sphere>(point3(0, 0, -1), 0.6);
    shared_ptr<hittable> sphere2 = make_shared<sphere>(point3(0, -99.6, -1), 99);
    world.add(sphere1);
    world.add(sphere2);

    camera cam;

    cam.aspect_ratio  =  16.0  /  9.0;
    cam.image_width   =  900;

    cam.render(world);

    return 0;

}
