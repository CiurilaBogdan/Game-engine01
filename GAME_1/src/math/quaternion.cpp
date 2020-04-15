#include "quaternion.h"

engine1::quat::quat() :x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

engine1::quat::quat(float a, float b, float c, float d):x(a),y(b),z(c),w(d)
{
}

engine1::quat::quat(vector3& v):x(v.x),y(v.y),z(v.z),w(0.0f)
{

}



engine1::quat engine1::quat::multiply(quat& q)
{
	float wR = (this->w * q.w) - (this->x * q.x) - (this->y * q.y) - (this->z * q.z);
	float xR = (this->w * q.x) + (this->x * q.w) + (this->y * q.z) - (this->z * q.y);
	float yR = (this->w * q.y) + (this->y * q.w) + (this->z * q.x) - (this->x * q.z);
	float zR = (this->w * q.z) + (this->z * q.w) + (this->x * q.y) - (this->y * q.x);


	return quat(xR,yR,zR,wR);

}

engine1::quat engine1::quat::conjugate()
{
	return quat(this->x * -1.0f, this->y * -1.0f, this->z * -1.0f, this->w );
}

void engine1::quat::rotate(quat& quat, vector3& vec)
{
	float tmpX, tmpY, tmpZ, tmpW;
	tmpX = (((quat.w * vec.x) + (quat.y * vec.z)) - (quat.z * vec.y));
	tmpY = (((quat.w * vec.y) + (quat.z * vec.x)) - (quat.x * vec.z));
	tmpZ = (((quat.w * vec.z) + (quat.x * vec.y)) - (quat.y * vec.x));
	tmpW = (((quat.x * vec.x) + (quat.y * vec.y)) + (quat.z * vec.z));

	
	this->x = (tmpW * quat.x) + (tmpX * quat.w) - (tmpY * quat.z) + (tmpZ * quat.y);
	this->y = (tmpW * quat.y) + (tmpY * quat.w) - (tmpZ * quat.x) + (tmpX * quat.z);
	this->z = (tmpW * quat.z) + (tmpZ * quat.w) - (tmpX * quat.y) + (tmpY * quat.x);
	
}

void engine1::quat::multiplyImg(vector3& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

void engine1::quat::multiplyImg(float a, float b, float c)
{
	x *= a;
	y *= b;
	z *= c;
}

void engine1::quat::multiplyImg(float a)
{
	x *= a;
	y *= a;
	z *= a;
}







