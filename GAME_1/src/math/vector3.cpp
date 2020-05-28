#include "vector3.h"


engine1::vector3::vector3():x(0.0f),y(0.0f),z(0.0f)
{

}

engine1::vector3::vector3(float a, float b, float c):x(a),y(b),z(c)
{
}

engine1::vector3::vector3(vector3& other):x(other.x),y(other.y),z(other.z)
{
}

float engine1::vector3::dot(vector3& first, vector3& second)
{

	return (first.x*second.x)+ (first.y * second.y)+ (first.z * second.z);
}

float engine1::vector3::mag(vector3& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float engine1::vector3::distance(vector3& first, vector3& second)
{
	float a = first.x - second.x;
	float b = first.y - second.y;
	float c = first.z - second.z;

	return sqrt(a*a +b*b+ c*c);
}

engine1::vector3* engine1::vector3::get_cross(vector3& first, vector3& second)
{
	return new vector3(first.y * second.z - first.z * second.y,first.z * second.x - first.x * second.z,first.x * second.y - first.y*second.x);
}

void engine1::vector3::cross(vector3& first, vector3& second, vector3& result)
{
	result.x = first.y * second.z - first.z * second.y;
	result.y = first.z * second.x - first.x * second.z;
	result.z = first.x* second.y - first.y * second.x;
}

void engine1::vector3::norm(vector3& vec, vector3& result)
{
	float length = vector3::mag(vec);
	result.x = vec.x / length;
	result.y = vec.y / length;
	result.z = vec.z / length;
}

engine1::vector3* engine1::vector3::get_norm(vector3& vec)
{
	float length = vector3::mag(vec);
	return  new vector3(vec.x/length, vec.y / length, vec.z / length);
}

void engine1::vector3::print() const
{
	printf("%.2f %.2f %.2f\n", x, y, z);
}



