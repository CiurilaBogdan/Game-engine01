#include "vector4.h"

engine1::vector4::vector4():x(0.0f),y(0.0f),z(0.0f),w(0.0f)
{
}

engine1::vector4::vector4(float a, float b, float c, float d):x(a),y(b),z(c),w(d)
{
}

engine1::vector4::vector4(const vector4& other):x(other.x),y(other.y),z(other.z),w(other.w)
{
}

engine1::vector4 engine1::vector4::operator*(const mat4& mat) const
{
	vector4 result;
	result.x = (x * mat.data[0])  + (y * mat.data[1])  + (z * mat.data[2])  + (w * mat.data[3]);
	result.y = (x * mat.data[4])  + (y * mat.data[5])  + (z * mat.data[6])  + (w * mat.data[7]);
	result.z = (x * mat.data[8])  + (y * mat.data[9])  + (z * mat.data[10]) + (w * mat.data[11]);
	result.w = (x * mat.data[12]) + (y * mat.data[13]) + (z * mat.data[14]) + (w * mat.data[15]);



	return result;
}
