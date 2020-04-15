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
		quaternion(vector3& vec);

		quaternion get_conjugate();
		quaternion multiply(quaternion& q);

		void print();
	};

}