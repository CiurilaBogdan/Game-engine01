#pragma once
#include <cstdio>

#include "vector3.h"
#include "Quaternion_v2.h"

namespace engine1 {

	class mat4 {

	public:

		float data[16];

		mat4();

		//mat4 multiply(const mat4& other);
		mat4 operator*(const mat4& other)const;
		
		static mat4 rotate(const quaternion& quat);
		static mat4 rotate2(const quaternion& quat);
		static mat4 scale(const vector3& vec);
		static mat4 translate(const vector3& vec);
		static mat4 perspective(float fov, float aspectRatio, float near, float far);
		
		static mat4 lookat(const vector3& eye,const vector3& target,const vector3& up);


		void multiply(const mat4& other1, const mat4& other2);
		void set_transform(const vector3& trans, const vector3& scale, const vector3& rot,const float& angle);
		void set_translation(const vector3& vec);
		void set_identity();
		void set_data(const float* otherData);
		//divide, add ,subtract,==,*=,vector
		
		void print()const;
	};


}