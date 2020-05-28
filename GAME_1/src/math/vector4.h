#pragma once
#include <cmath>
#include <cstdio>

#include "matrix4.h"

namespace engine1 {

	class vector4 {

	public:

		float x, y, z, w;

		vector4();
		vector4(float a, float b, float c, float d);
		vector4(const vector4& other);

		vector4 operator*(const mat4& mat)const;


	};

}