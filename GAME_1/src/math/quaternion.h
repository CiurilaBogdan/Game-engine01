#pragma once
#include <cmath>

#include "vector3.h"

namespace engine1 {

	class quat {

	public:
		float x, y, z, w;
		quat();
		quat(float a,float b,float c,float d);

		quat(vector3& v);
		

		 quat multiply(quat& q);
		 quat conjugate();
		 void rotate(quat& q, vector3& vec);
		 void multiplyImg(vector3& v);
		 void multiplyImg(float a,float b,float c);
		 void multiplyImg(float a);

};

}