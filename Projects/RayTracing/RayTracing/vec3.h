#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
public:
	float e[3];

	vec3() {};
	vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }

	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	friend inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
		return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
	}
	friend inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
		return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
	}
	friend inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
		return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
	}
	friend inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
		return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
	}
	friend inline vec3 operator/(const vec3 &v, const float t) {
		return vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
	}
	friend vec3 operator*(const float t, const vec3 &v) {
		return v * t;
	}
	friend vec3 operator*(const vec3 &v, const float t) {
		return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
	}

	inline vec3& operator+=(const vec3 &v2) {
		e[0] += v2.e[0]; e[1] += v2.e[1]; e[2] += v2.e[2];
		return *this;
	}
	inline vec3& operator-=(const vec3 &v2) { 
		e[0] -= v2.e[0]; e[1] -= v2.e[1]; e[2] -= v2.e[2];
		return *this;
	}
	inline vec3& operator*=(const vec3 &v2) { 
		e[0] *= v2.e[0]; e[1] *= v2.e[1]; e[2] *= v2.e[2];
		return *this;
	}
	inline vec3& operator/=(const vec3 &v2) { 
		e[0] /= v2.e[0]; e[1] /= v2.e[1]; e[2] /= v2.e[2];
		return *this;
	}
	inline vec3& operator*=(const float t)  { 
		e[0] *= t; e[1] *= t; e[2] *= t;
		return *this;
	}
	inline vec3& operator/=(const float t)  { 
		e[0] /= t; e[1] /= t; e[2] /= t;
		return *this;
	}

	inline float length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline float squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }
	inline vec3 unit_vector() {
		return *this / length();
	}
	inline void make_unit_vector() {
		float len = length();
		e[0] /= len; e[1] /= len; e[2] /= len;
	}
};


inline float dot(const vec3 &v1, const vec3 &v2) {
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
	return vec3(
		v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
		-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0]),
		v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]
	);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

#endif
