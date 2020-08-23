#include "vector3.h"


engine1::vector3::vector3():x(0.0f),y(0.0f),z(0.0f)
{

}

engine1::vector3::vector3(float a, float b, float c):x(a),y(b),z(c)
{
}

engine1::vector3::vector3(const vector3& other):x(other.x),y(other.y),z(other.z)
{
}

engine1::vector3 engine1::vector3::get_normalize() const
{
	
	float l = sqrt(x*x+y*y+z*z);
	vector3 res(x / l, y / l, z / l);

	return  res;
}

void engine1::vector3::normalize()
{
	float length = sqrt(x*x+y*y+z*z);
	x = x / length;
	y = y / length;
	z = z / length;
}

void engine1::vector3::set_scalar(float scalar)
{
	x = y = z = scalar;
}

bool engine1::vector3::is_zero()
{
	if (x == y == z == 0.0f)return true;

	return false;
}

engine1::vector3 engine1::vector3::operator-(const vector3& other) const
{
	return vector3(x-other.x,y-other.y,z-other.z);
}

engine1::vector3 engine1::vector3::operator+(const vector3& other) const
{

	return vector3(x+other.x,y+other.y,z+other.z);
}

float engine1::vector3::dot(const vector3& first, const vector3& second)
{

	return (first.x*second.x)+ (first.y * second.y)+ (first.z * second.z);
}

float engine1::vector3::mag(const vector3& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float engine1::vector3::distance(const vector3& first, const  vector3& second)
{
	float a = first.x - second.x;
	float b = first.y - second.y;
	float c = first.z - second.z;

	return sqrt(a*a +b*b+ c*c);
}

engine1::vector3* engine1::vector3::get_cross(const vector3& first, const  vector3& second)
{
	return new vector3(first.y * second.z - first.z * second.y,first.z * second.x - first.x * second.z,first.x * second.y - first.y*second.x);
}

engine1::vector3 engine1::vector3::cross(const vector3& first, const vector3& second){
	vector3 res(first.y * second.z - first.z * second.y, first.z * second.x - first.x * second.z, first.x * second.y - first.y * second.x);
	
	return res;
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



