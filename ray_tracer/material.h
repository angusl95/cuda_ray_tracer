//
//  material.h
//  ray_tracer
//
//  Created by Angus Lamb on 31/12/2020.
//  Copyright © 2020 Angus Lamb. All rights reserved.
//

#ifndef material_h
#define material_h

#include "rtweekend.h"

struct hit_record;

class material {
public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

class lambertian: public material {
public:
    lambertian(const color& a) : albedo(a) {}
    
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
        auto scatter_direction = rec.normal + random_unit_vector();
        if (scatter_direction.near_zero()){
            scatter_direction = rec.normal;
        };
        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }
public:
    color albedo;
};

class metal: public material {
public:
    metal(const color& a) : albedo(a) {}
    
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }
public:
    color albedo;
};
    
#endif /* material_h */
