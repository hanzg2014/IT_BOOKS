// 6_1.cpp 213/P441

#include <iostream>
#include "sphere.h"
#include "hitable_list.h"
// #include "ray.h"   //"hitable_list.h" #included "hitable.h" #included "ray.h"
#include "float.h"
#include "camera.h"
using namespace std;

vec3 random_in_unit_sphere(){
	vec3 p;
	do{
		p = 2.0 * vec3(drand48(),drand48(),drand48()) - vec3(1,1,1); // random float number in the range [0,1]   
	} while (p.squared_length()>=1.0);
	return p;
}

vec3 color(const ray& r, hitable *world){
	hit_record rec; //hit_record&
	if(world->hit(r, 0.0, MAXFLOAT, rec)){
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		return 0.5 * color(ray(rec.p, target-rec.p), world);   //50% reflector absorb half of the light
	}
	else{
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5 * (unit_direction.y() + 1.0); 
		return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
}

int main(){
	int nx = 200;
	int ny = 100;
	int ns = 100;

	cout<<"P3\n"<<nx<<" "<<ny<<"\n255\n";

	hitable *list[2];
	list[0] = new sphere(vec3(0,0,-1),0.5,NULL);
	list[1] = new sphere(vec3(0,-100.5,-1),100,NULL);
	hitable *world = new hitable_list(list, 2); //hitable_list class inherited hetable class, here hitable* type is OK
	
	camera cam;

	for(int j = ny-1; j >= 0; j--){
		for(int i = 0; i < nx; i++){
			vec3 col(0,0,0);
			for(int s = 0; s < ns; s++){
				// float u = float(i + drand48()) / float(nx);
				// float v = float(j + drand48()) / float(ny);
				float u = float(i + drand48()) / float(nx);
				float v = float(j + drand48()) / float(ny);
				ray r = cam.get_ray(u, v);
				// vec3 p = r.point_at_parameter(2.0);
				col += color(r, world);
			}
			col /= float(ns);      //pixel value averaging
			int ir = int(255.99 * col.r()); //col[0]
			int ig = int(255.99 * col.g()); //col[1]
			int ib = int(255.99 * col.b()); //col[2]
			cout<<ir<<" "<<ig<<" "<<ib<<"\n";
		}
	}
}

