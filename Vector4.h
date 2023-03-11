#pragma once
#include <cmath>
#include <ostream>

class Vector4
{
public:
	float x, y, z, w;


	Vector4() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	Vector4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	Vector4(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		w = 0;
	}

	float Magnitude() {
		return sqrt
		(
		pow(x,2) +
		pow(y, 2) +
		pow(z, 2));
	}
	void Normalize() {
		float mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
	}

	float Dot(Vector4 other) {
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	Vector4 Cross(Vector4 other) {
		return Vector4(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
	}

	friend std::ostream& operator<<(std::ostream& output, const Vector4& v) {
		output << "x:" << v.x << " y:" << v.y << " z:" << v.z << " w:" << v.w;
		return output;
	}
};

