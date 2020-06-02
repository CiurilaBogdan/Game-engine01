#pragma once
#include <cmath>
#include <cstdio>
namespace engine1 {

	class vector3 {

	public:
		float x, y, z;

		vector3();
		vector3(float a, float b, float c);
		vector3(const vector3& other);

		vector3 get_normalize()const;
		void normalize();

		vector3 operator-(const vector3& other)const;
		vector3 operator+(const vector3& other)const;


		static float dot(const vector3& first, const vector3& second);
		static float mag(const vector3& vec);
		static float distance(const vector3& first, const vector3& second);
		static vector3* get_cross(const vector3& first,const vector3& second);
		static vector3 cross(const vector3& first, const vector3& second);


		static void cross(vector3& first,vector3& second,vector3 & result);
		static void norm(vector3& vec, vector3& result);
		static vector3* get_norm(vector3& vec);

		void print()const;
	};


}