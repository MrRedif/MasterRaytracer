#include "Vector4.h"

class Ray {
	public:
		Vector4 origin;
		Vector4 direction;
	
		Ray(Vector4 origin, Vector4 direction) 
		{
			this->direction = direction;
			this->origin = origin;
		}
};

class Hit {
	public:
		Vector4 color;
		double t = 99999999;

		Hit(Vector4 color, double t) {
			this->color = color;
			this->t = t;
		}

		Hit() {
			color = Vector4();
			t = 99999999;
		}

};