#pragma once

#include <cmath>

#include "../math/matrix4.h"
#include "../math/vector3.h"
#include "../math/vector4.h"

namespace engine1 {

	class camera {
		
	public:
		vector3 position;
		vector3 front;
		vector3 up;
		vector3	right;
		vector3 worldUp;

		float yaw;
		float pitch;

		float movementSpeed;
		float mouseSensitivity;
		float zoom;

		camera(const vector3& pos = vector3(0, 0, 0), const vector3& u = vector3(0, 1, 0), const vector3& forward = vector3(0, 0, -1), float y = -90, float p = 0, float moveSpeed = 2.5f, float mouseSpeed = 0.1f, float z= 45.0f);

		void update(float x,float y);


	private:
		double toRadian = 3.14159265359 / 180;
		void updateVectors();
};

}