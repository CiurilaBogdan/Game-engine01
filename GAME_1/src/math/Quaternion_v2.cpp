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

engine1::quaternion::quaternion(const vector3& vec)
{
	
	
		x = vec.x;
		y = vec.y;
		z = vec.z;
	

		w = 0;

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

engine1::quaternion engine1::quaternion::operator*(const quaternion& q) const
{
	float wR = (this->w * q.w) - (this->x * q.x) - (this->y * q.y) - (this->z * q.z);
	float xR = (this->w * q.x) + (this->x * q.w) + (this->y * q.z) - (this->z * q.y);
	float yR = (this->w * q.y) + (this->y * q.w) + (this->z * q.x) - (this->x * q.z);
	float zR = (this->w * q.z) + (this->z * q.w) + (this->x * q.y) - (this->y * q.x);

	quaternion res(xR, yR, zR, wR);

	return res;
}

float engine1::quaternion::mag() const
{

	return sqrt(x*x+y*y+z*z+w*w);
}

engine1::quaternion engine1::quaternion::normalized() const
{
	quaternion res;
	float mag = this->mag();
	res.x = x / mag;
	res.y = y / mag;
	res.z = z / mag;
	res.w = w / mag;



	return res;
}

void engine1::quaternion::set_identity()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 1.0f;
}

void engine1::quaternion::set_vector(const vector3& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = 1.0f;
}

void engine1::quaternion::set_quat(const quaternion& qt)
{
	x = qt.x;
	y = qt.y;
	z = qt.z;
	w = qt.w;
}




void engine1::quaternion::print()
{
	std::printf("x: %.2f y: %.2f z: %.2f w: %.2f\n", x, y, z, w);
}
