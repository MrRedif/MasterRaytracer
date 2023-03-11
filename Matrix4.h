#pragma once
#include <corecrt_math_defines.h>
class Matrix4
{
public:
	float mdata[4][4];

	static Matrix4 Translate(float x,float y = 0,float z = 0) {
		Matrix4 m = Matrix4();
		m.mdata[0][0] = 1;
		m.mdata[1][1] = 1;
		m.mdata[2][2] = 1;
		m.mdata[3][3] = 1;
		m.mdata[0][3] = x;
		m.mdata[1][3] = y;
		m.mdata[2][3] = z;
		return m;
	}

	static Matrix4 Scale(float x, float y = 0, float z = 0) {
		Matrix4 m = Matrix4();
		m.mdata[0][0] = x;
		m.mdata[1][1] = y;
		m.mdata[2][2] = z;
		m.mdata[3][3] = 1;
		return m;
	}

	static Matrix4 RotateX(float angle) {
		Matrix4 m = Matrix4();
		float rad =  M_PI / 180 * angle;
		float c = cos(rad);
		float s = sin(rad);
		m.mdata[0][0] = 1;
		m.mdata[3][3] = 1;
		m.mdata[1][1] = c;
		m.mdata[2][2] = c;
		m.mdata[2][1] = s;
		m.mdata[1][2] = -s;
		return m;
	}
	static Matrix4 RotateY(float angle) {
		Matrix4 m = Matrix4();
		float rad = M_PI / 180 * angle;
		float c = cos(rad);
		float s = sin(rad);
		m.mdata[0][0] = c;
		m.mdata[2][2] = c;
		m.mdata[0][2] = s;
		m.mdata[2][0] = -s;
		m.mdata[1][1] = 1;
		m.mdata[3][3] = 1;

		return m;
	}
	static Matrix4 RotateZ(float angle) {
		Matrix4 m = Matrix4();
		float rad = M_PI / 180 * angle;
		float c = cos(rad);
		float s = sin(rad);
		m.mdata[0][0] = c;
		m.mdata[0][1] = -s;
		m.mdata[1][0] = s;
		m.mdata[1][1] = c;
		m.mdata[2][2] = 1;
		m.mdata[3][3] = 1;
		return m;
	}



	friend Vector4 operator*(const Matrix4& m,const Vector4& v) {
		float x = v.x * m.mdata[0][0] + v.y * m.mdata[0][1] + v.z * m.mdata[0][2] + v.w * m.mdata[0][3];
		float y = v.x * m.mdata[1][0] + v.y * m.mdata[1][1] + v.z * m.mdata[1][2] + v.w * m.mdata[1][3];
		float z = v.x * m.mdata[2][0] + v.y * m.mdata[2][1] + v.z * m.mdata[2][2] + v.w * m.mdata[2][3];
		float w = v.x * m.mdata[3][0] + v.y * m.mdata[3][1] + v.z * m.mdata[3][2] + v.w * m.mdata[3][3];

		return Vector4(x,y,z,w);
	}

	friend Matrix4 operator*(const Matrix4 &a,const Matrix4 &b) {
		Matrix4 res = Matrix4();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				res.mdata[i][j] = 
					a.mdata[i][0] * b.mdata[0][j] +
					a.mdata[i][1] * b.mdata[1][j] +
					a.mdata[i][2] * b.mdata[2][j] +
					a.mdata[i][3] * b.mdata[3][j];
			}
		}
		return res;
	}

	friend std::ostream& operator<<(std::ostream& output, const Matrix4& v) {
		int p = output.precision();
		output.precision(2);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				output << v.mdata[i][j] << " ";
			}
			output << std::endl;
		}
		output.precision(p);
		return output;
	}
};

