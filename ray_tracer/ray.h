//
//  ray.h
//  ray_tracer
//
//  Created by Angus Lamb on 28/12/2020.
//  Copyright © 2020 Angus Lamb. All rights reserved.
//

#ifndef ray_h
#define ray_h

#include "vec3.h"

class ray {
public:
    ray() {}
    ray(const point3& origin, const vec3& direction)
    :   orig(origin), dir(direction)
    {}
    
    point3 origin() const {return orig;}
    vec3 direction() const {return dir;}
    
    point3 at(double t) const {
        return orig + t*dir;
    }
public:
    point3 orig;
    vec3 dir;
};

#endif /* ray_h */
