#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main() {
    hittable_list world;

    auto  material_ground  =  make_shared<lambertian>(color(0.8,  0.8,  0.0));
    auto  material_center  =  make_shared<lambertian>(color(0.1,  0.2,  0.5));
    auto  material_left    =  make_shared<metal>(color(0.8,  0.8,  0.8));
    auto  material_right   =  make_shared<metal>(color(0.8,  0.6,  0.2));

    auto  sphere_g  =  make_shared<sphere>(point3(0.0,   -99.6,  -1.0),  99.0,  material_ground);
    auto  sphere_c  =  make_shared<sphere>(point3(0.0,   0.0,    -1.2),  0.6,   material_center);
    auto  sphere_l  =  make_shared<sphere>(point3(-1.0,  0.0,    -1.0),  0.6,   material_left);
    auto  sphere_r  =  make_shared<sphere>(point3(1.0,   0.0,  -1.0),  0.6,   material_right);

    world.add(sphere_g);
    world.add(sphere_c);
    world.add(sphere_l);
    world.add(sphere_r);

    camera cam;

    cam.aspect_ratio       =  16.0  /  9.0;
    cam.image_width        =  900;
    cam.samples_per_pixel  =  800;
    cam.max_depth          =  50;

    cam.render(world);

    return 0;
}
