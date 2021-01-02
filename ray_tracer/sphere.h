//
//  sphere.h
//  ray_tracer
//
//  Created by Angus Lamb on 29/12/2020.
//  Copyright © 2020 Angus Lamb. All rights reserved.
//

#ifndef sphere_h
#define sphere_h

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
    sphere() {}
    sphere(point3 cen, double r, shared_ptr<material> m): center(cen), radius(r), mat_ptr(m) {};
    
    bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
    
public:
    point3 center;
    double radius;
    shared_ptr<material> mat_ptr;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const{
    vec3 a_c = r.origin() - center;
    const double a = r.direction().length_squared();
    const double half_b = dot(r.direction(), a_c);
    const double c = a_c.length_squared() - radius * radius;
    const double disc = half_b * half_b - a * c;
    if (disc < 0) return false;
    auto sqrtd = sqrt(disc);
    auto root = (-half_b - sqrtd) / a;
    
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || root > t_max) return false;
    }
    
    rec.t = root;
    rec.p = r.at(root);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;
    
    return true;
}


#endif /* sphere_h */
