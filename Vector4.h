#pragma once
#include <cmath>
#include <ostream>

class Vector4
{
public:
	double x, y, z, w;
	

	Vector4() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	Vector4(double x, double y, double z, double w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	Vector4(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
		w = 0;
	}

	float Magnitude() {
		return sqrt
		(
			pow(x, 2) +
			pow(y, 2) +
			pow(z, 2));
	}
	void Normalize() {
		double mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
	}

	float Dot(Vector4 other) {
		return x * other.x + y * other.y + z * other.z;
	}

	Vector4 Cross(Vector4 other) {
		return Vector4(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
	}

	#pragma region Operator Overloads
	friend Vector4 operator*(const double& d, const Vector4& v) {
		return Vector4(v.x * d, v.y * d, v.z * d, v.w * d);
	}

	friend Vector4 operator*(const Vector4& v, const double& d) {
		return Vector4(v.x * d, v.y * d, v.z * d, v.w * d);
	}

	friend Vector4 operator*(const int& i, const Vector4& v) {
		return Vector4(v.x * i, v.y * i, v.z * i, v.w * i);
	}

	friend Vector4 operator*(const Vector4& v, const int& i) {
		return Vector4(v.x * i, v.y * i, v.z * i, v.w * i);
	}

	friend Vector4 operator+(const Vector4& v1, const Vector4& v2) {
		return Vector4(v2.x + v1.x, v2.y + v1.y, v2.z + v1.z, v2.w + v1.w);
	}

	friend Vector4 operator-(const Vector4& v1, const Vector4& v2) {
		return Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
	}

	friend std::ostream& operator<<(std::ostream& output, const Vector4& v) {
		output << "x:" << v.x << " y:" << v.y << " z:" << v.z << " w:" << v.w;
		return output;
	}
	#pragma endregion

	
};




