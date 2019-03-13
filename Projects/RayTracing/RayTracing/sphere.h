#ifndef SPHEREH
#define SPHEREH

#include "vec3.h"
#include "ray.h"
#include "hitable.h"

class sphere : public hitable {
public:
	vec3 center;
	float radius;

	sphere() {}
	sphere(vec3 cen, float r) : center(cen), radius(r) {}
	virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
};

// p(t) = A + t * B
// t*t*dot(B,B) + 2*t*dot(A-C,B) + doc(C,C) - R*R = 0

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());	// 这里的b其实是 Ax^2 + BX + C = 0 里的 B/2
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - a * c;

	if (discriminant > 0) {
		float temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		temp = (-b + sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}

#endif // !SPHEREH
