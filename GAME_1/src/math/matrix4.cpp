#include "matrix4.h"

engine1::mat4::mat4()
{
	set_identity();
}

engine1::mat4 engine1::mat4::multiply(const mat4& other) const
{
	mat4 result;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			float tmpRes = 0;

			for (int k = 0; k < 4; k++) {
				tmpRes += data[k + (i * 4)] * other.data[k * 4 + j];
			}

			result.data[i * 4 + j] = tmpRes;
		}


	}


	return result;
}

engine1::mat4 engine1::mat4::operator*(const mat4& other) const
{
	mat4 result;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			float tmpRes = 0;

			for (int k = 0; k < 4; k++) {
				tmpRes += data[k + (i * 4)] * other.data[k * 4 + j];
			}

			result.data[i * 4 + j] = tmpRes;
		}


	}



	return result;
}

engine1::mat4 engine1::mat4::rotate(const quaternion& quat) const
{
	mat4 result;

	float qx, qy, qz, qw, qx2, qy2, qz2, qxqx2, qyqy2, qzqz2, qxqy2, qyqz2, qzqw2, qxqz2, qyqw2, qxqw2;
	qx = quat.x;
	qy = quat.y;
	qz = quat.z;
	qw = quat.w;
	qx2 = (qx + qx);
	qy2 = (qy + qy);
	qz2 = (qz + qz);
	qxqx2 = (qx * qx2);
	qxqy2 = (qx * qy2);
	qxqz2 = (qx * qz2);
	qxqw2 = (qw * qx2);
	qyqy2 = (qy * qy2);
	qyqz2 = (qy * qz2);
	qyqw2 = (qw * qy2);
	qzqz2 = (qz * qz2);
	qzqw2 = (qw * qz2);

	result.data[0] = ((1.0f - qyqy2) - qzqz2);
	result.data[1] = (qxqy2 - qzqw2);
	result.data[2] = (qxqz2 + qyqw2);
	result.data[3] = 0.0f;

	result.data[4] = (qxqy2 + qzqw2);
	result.data[5] = ((1.0f - qxqx2) - qzqz2);
	result.data[6] = (qyqz2 - qxqw2);
	result.data[7] = 0.0f;

	result.data[8] = (qxqz2 - qyqw2);
	result.data[9] = (qyqz2 + qxqw2);
	result.data[10] = ((1.0f - qxqx2) - qyqy2);
	result.data[11] = 0.0f;


	return result;
}

engine1::mat4 engine1::mat4::rotate2(const quaternion& quat) const
{
	float x, y, z, w;
	x = quat.x;
	y = quat.y;
	z = quat.z;
	w = quat.w;

	mat4 result;

	result.data[0] = 1 - (2 *y*y) - (2 * z*z);
	result.data[1] = (2 * x*y) + (2 * w*z);
	result.data[2] = (2 * x*z) - (2 * w*y);
	result.data[3] = 0.0f;

	result.data[4] = (2 * x*y) - (2 * w*z);
	result.data[5] = 1 - (2 * x * x) - (2 * z * z);
	result.data[6] = (2 * y * z) + (2 * w * x);
	result.data[7] = 0.0f;

	result.data[8] = (2 * x * z) + (2 * w * y);
	result.data[9] = (2 * y * z) - (2 * w * x);
	result.data[10] = 1 - (2 * x * x) - (2 * y * y);
	result.data[11] = 0.0f;


	return result;

}

engine1::mat4 engine1::mat4::scale(const vector3& vec) const
{
	mat4 res;
	res.data[0] = vec.x;
	res.data[5] = vec.y;
	res.data[10] = vec.z;

	return res;
}

engine1::mat4 engine1::mat4::translate(const vector3& vec) const
{
	mat4 res;
	res.data[3] = vec.x;
	res.data[7] = vec.y;
	res.data[11] = vec.z;

	return res;
}

engine1::mat4 engine1::mat4::perspective(float fov, float aspectRatio, float near, float far) const
{
	mat4 res;
	float toRadian = 3.14 / 180;
	float q = 1.0f / tan(toRadian*(0.5f * fov));
	float a = q / aspectRatio;

	float b = (near + far) / (near - far);
	float c = (2.0f * near * far) / (near - far);

	res.data[0 + 0 * 4] = a;
	res.data[1 + 1 * 4] = q;
	res.data[2 + 2 * 4] = b;
	res.data[2 + 3 * 4] = -1.0f;
	res.data[3 + 2 * 4] = c;


	return res;
}

void engine1::mat4::multiply(const mat4& other1, const mat4& other2)
{
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			float tmpRes = 0;

			for (int k = 0; k < 4; k++) {
				tmpRes += other1.data[k + (i * 4)] * other2.data[k * 4 + j];
			}

			data[i * 4 + j] = tmpRes;
		}


	}
}



void engine1::mat4::set_transform(const vector3& trans, const vector3& scale, const vector3& rot,const float& angle)
{
	set_identity();
	//scale rotate translate
	


}

void engine1::mat4::set_identity()
{
	for (int i = 0; i < 16; i++) {
		data[i] = 0;

	}

	for (int j = 0; j < 4; j++) {

		data[j + (j * 4)] = 1;
	}

}


void engine1::mat4::print() const
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.2f\t", data[i * 4 + j]);

		}
		printf("\n");

	}
}



