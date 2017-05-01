#ifndef HITABLEH
#define HITABLEH 

#include "ray.h"

class material;

struct hit_record
{
    float t;  //A + t*B
    vec3 p; //intersection point of hitable and ray
    vec3 normal; //normal vector at intersection point p
    material *mat_ptr;
};

class hitable  {
    public:
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};
#endif




