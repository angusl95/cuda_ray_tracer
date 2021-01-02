//
//  rtweekend.h
//  ray_tracer
//
//  Created by Angus Lamb on 30/12/2020.
//  Copyright © 2020 Angus Lamb. All rights reserved.
//

#ifndef rtweekend_h
#define rtweekend_h

#include <cstdlib>
#include <cmath>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    return min + (max-min) * random_double();
}

inline double clamp(double x, double min, double max) {
    if (x<min) return min;
    if (x>max) return max;
    return x;
}

#include "ray.h"
#include "vec3.h"

#endif /* rtweekend_h */
