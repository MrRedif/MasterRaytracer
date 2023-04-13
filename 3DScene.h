#pragma once
#include "Ray.h"
#include <vector>
#include <math.h>
#include "json.hpp"
using json = nlohmann::json;

class Object3D
{
public:
	Vector4 color;

	virtual void Intersect(Ray& ray, Hit& hit, double tmin)
	{

	}
};

class Sphere : public Object3D {
public:
	double radius;
	Vector4 center;

	void Intersect(Ray& ray, Hit& hit, double tmin) override
	{
		Vector4 m = ray.origin - center;
		double a = ray.direction.Dot(ray.direction);
		double b = 2 * m.Dot(ray.direction);
		double c = m.Dot(m) - radius * radius;
		double disc = b * b - c;
		if (disc < 0) return;
		double t0 = (-b - sqrt(disc)) / 2 * a;
		double t1 = (-b + sqrt(disc)) / 2 * a;

		if (t0 < t1 && hit.t > t0 && t0 > tmin) {
			hit.t = t0;
			hit.color = color;
		}
		else if (hit.t > t1 && t1 > tmin) {
			hit.t = t1;
			hit.color = color;
		}

	}

	Sphere(Vector4 center,double radius,Vector4 col = Vector4()) {
		this->center = center;
		this->radius = radius;
		this->color = col;
	}

};

class ObjectGroup : public Object3D {
public:
	std::vector<Object3D*> childs;

	void Intersect(Ray& ray, Hit& hit, double tmin) override
	{
		for (Object3D* obj : childs)
		{
			obj->Intersect(ray, hit, tmin);
		}
	}

};

class Camera {
public:
	/// <summary>
	/// Creates ray from camera given coordinates x,y
	/// </summary>
	/// <param name="x">Horizontal screen coordinate in range (0,1)</param>
	/// <param name="y">Vertical screen coordinate in range (0,1)</param>
	/// <returns>Ray from camera</returns>
	virtual Ray GenerateRay(double x, double y) {
		return Ray(Vector4(), Vector4());
	}
};

class OrthographicCamera : public Camera {
public:
	Vector4 center;
	Vector4 direction;
	Vector4 up;
	double size;

	Ray GenerateRay(double x, double y) override
	{
		Vector4 horizontal = direction.Cross(up);
		Vector4 rayOrigin = center + ((x - 0.5) * horizontal + (y - 0.5) * up) * size;
		return Ray(rayOrigin, direction);
	}

	OrthographicCamera(double size,Vector4 up, Vector4 dir, Vector4 center = Vector4()) {
		this->size = size;
		this->up = up;
		this->direction = dir;
		this->center = center;
	}

};


void from_json(const json& j, Sphere& p) {
	double cen[3];
	double col[3];

	j.at("sphere").at("center").get_to(cen);
	j.at("sphere").at("radius").get_to(p.radius);
	j.at("sphere").at("color").get_to(col);

	p.center = Vector4(cen[0], cen[1], cen[2]);
	p.color = Vector4(col[0], col[1], col[2]);
}
