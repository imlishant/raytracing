#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include "rtweekend.h"

#include <vector>

class hittable_list : public hittable {
    public:
        std::vector<shared_ptr<hittable>> objects;

        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear() {
            objects.clear();
        }

        void add(shared_ptr<hittable> obj) {
            objects.push_back(obj);
        }

        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
            hit_record  tmp_rec;
            bool        hit_anything  =  false;
            double      closest_till  =  ray_tmax;
            
            for (auto obj : objects) {
                if (obj->hit(r, ray_tmin, closest_till, tmp_rec)) {
                    hit_anything  =  true;
                    closest_till  =  tmp_rec.t;
                    rec           =  tmp_rec;
                }
            }

            return hit_anything;
        }
};

#endif
