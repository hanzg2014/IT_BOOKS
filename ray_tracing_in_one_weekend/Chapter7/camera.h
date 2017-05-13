#ifndef CAMERAH
#define CAMERAH
#include "ray.h"

// vec3 random_in_unit_disk() {
//     vec3 p;
//     do {
//         p = 2.0*vec3(drand48(),drand48(),0) - vec3(1,1,0);
//     } while (dot(p,p) >= 1.0);
//     return p;
// }

class camera {
    public:
        camera(){
            lower_left_corner = vec3(-2.0, -1.0, -1.0);
            horizontal = vec3(4.0, 0.0, 0.0);
            vertical  = vec3(0.0, 2.0, 0.0);
            origin = vec3(0.0, 0.0, 0.0);
        }

        ray get_ray(float u, float v) {
            return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin); 
        }

        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
};
#endif




