#include <iostream>
#include "Vector4.h"
#include "Matrix4.h"

int main()
{
    Vector4 vec = Vector4(3,4,1,2);
    Vector4 vec1 = Vector4(0,2,7);
    std::cout << Matrix4::RotateZ(-90) * Matrix4::RotateZ(90) * vec;
}

