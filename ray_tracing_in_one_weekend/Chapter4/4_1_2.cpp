// 4_1_2.cpp (t of intersection < 0; sphere center at Z=1)	164/P441

#include <iostream>
#include "ray.h"
using namespace std;

bool hit_space(const vec3& center, float radius, const ray& r){
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction()); //a*t*t; a = dot(B,B)
	float b = 2.0 * dot(oc, r.direction()); //2*b*t; b = dot(A-C,B)
	float c = dot(oc, oc) - radius * radius; //; c = dot(A-C,A-C)-R*R
	float discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

vec3 color(const ray& r){
	if (hit_space(vec3(2,-1,1), 0.5, r)) //the center of the sphere is placed at the plane Z = 1
		return vec3(1,0,0); // pure red color
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5 * (unit_direction.y() + 1.0); // scaling so that  0.0 < t < 1.0
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) /* white at start point*/ + t * vec3(0.5, 0.7, 1.0) /* blueish color at end point*/;
}

int main(){
	int nx = 200;
	int ny = 100;
	cout<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical (0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);

	for(int j = ny-1; j>=0; j--){
		for(int i = 0; i < nx; i++){
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			vec3 col = color(r);
			int ir = int(255.99 * col.r());
			int ig = int(255.99 * col.g());
			int ib = int(255.99 * col.b());
			cout<<ir<<" "<<ig<<" "<<ib<<"\n";
		}
	}
}
