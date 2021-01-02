//
//  hittable.h
//  ray_tracer
//
//  Created by Angus Lamb on 29/12/2020.
//  Copyright © 2020 Angus Lamb. All rights reserved.
//

#ifndef hittable_h
#define hittable_h

#include "ray.h"
#include "rtweekend.h"

class material;

struct hit_record{
    point3 p;
    double t;
    shared_ptr<material> mat_ptr;
    vec3 normal;
    bool front_face;
    
    inline void set_face_normal(const ray& r, vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};

class hittable{
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif /* hittable_h */
