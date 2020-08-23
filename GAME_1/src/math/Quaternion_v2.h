#pragma once
#include <cmath>
#include <cstdio>

#include "vector3.h"

namespace engine1 {

	class quaternion {

	private:

	public:
		float x, y, z, w;

		quaternion();
		quaternion(float scalar);
		quaternion(float a, float b, float c);
		quaternion(float a, float b, float c, float d);
		quaternion(const vector3& vec);

		quaternion get_conjugate();
		quaternion multiply(quaternion& q);
		quaternion operator*(const quaternion& q)const;
		float mag()const;
		quaternion normalized()const;
		void set_identity();
		void set_vector(const vector3& vec);
		void set_quat(const quaternion& qt);

		void print();
	};

}