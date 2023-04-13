#include <iostream>
#include "Vector4.h"
#include "Matrix4.h"
#include "3DScene.h"
#include "json.hpp"
#include <fstream>
using jsonF = nlohmann::json;



const int width = 200, height = 200;
Vector4 result[height][width];
const Vector4 VECTOR_UP = Vector4(0, 1, 0, 0);
const Vector4 VECTOR_RIGHT = Vector4(1, 0, 0);
const Vector4 COLOR_YELLOW = Vector4(200, 200, 50);
const Vector4 COLOR_RED = Vector4(255, 0, 0);

int main()
{
	//std::ifstream inputFile("scene1.json");
	//jsonF data = jsonF::parse(inputFile);

	OrthographicCamera cam(5,VECTOR_UP,Vector4(0,0,-1),Vector4());


	ObjectGroup group;
	group.childs = std::vector<Object3D*>();

	Sphere s = Sphere(Vector4(),2,COLOR_YELLOW);
	Sphere s1 = Sphere(Vector4(1,0,0), 2, COLOR_RED);
	group.childs.push_back(&s);
	group.childs.push_back(&s1);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Ray ray = cam.GenerateRay(static_cast<double>(j) / static_cast<double>(width), static_cast<double>(i) / static_cast<double>(height)); 
			Hit h(Vector4(),99999999);
			group.Intersect(ray, h, 0);
			result[i][j] = h.color;
		}
	}





	//Saving
	std::ofstream image("output.ppm");
	image << "P3" << std::endl;
	image << width << " " << height << std::endl;
	image << "255" << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int r = result[i][j].x;
			int g = result[i][j].y;
			int b = result[i][j].z;
			image << r << " " << g << " " << b << std::endl;
		}
	}
}

