#include "Quaternion_v2.h"

engine1::quaternion::quaternion():x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

engine1::quaternion::quaternion(float scalar): x(scalar), y(scalar), z(scalar), w(0.0f)
{
}

engine1::quaternion::quaternion(float a, float b, float c):x(a),y(b),z(c),w(0.0f)
{
}

engine1::quaternion::quaternion(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
{
}

engine1::quaternion::quaternion(vector3& vec):x(vec.x), y(vec.y), z(vec.z), w(0.0f)
{
}

engine1::quaternion engine1::quaternion::get_conjugate()
{

	return quaternion(-x,-y,-z,w);
}

engine1::quaternion engine1::quaternion::multiply(quaternion& q)
{
	float wR = (this->w * q.w) - (this->x * q.x) - (this->y * q.y) - (this->z * q.z);
	float xR = (this->w * q.x) + (this->x * q.w) + (this->y * q.z) - (this->z * q.y);
	float yR = (this->w * q.y) + (this->y * q.w) + (this->z * q.x) - (this->x * q.z);
	float zR = (this->w * q.z) + (this->z * q.w) + (this->x * q.y) - (this->y * q.x);


	return quaternion(xR,yR,zR,wR);
}




void engine1::quaternion::print()
{
	std::printf("x: %.2f y: %.2f z: %.2f w: %.2f\n", x, y, z, w);
}
