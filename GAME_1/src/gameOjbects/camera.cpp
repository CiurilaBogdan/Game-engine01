#include "camera.h"

engine1::camera::camera(const vector3& pos, const vector3& u, const vector3& forward, float y, float p, float moveSpeed, float mouseSpeed, float z)
{
	position = pos;
	worldUp = u;
	front = forward;

	yaw = y;
	pitch = p;
	movementSpeed = moveSpeed;
	mouseSensitivity = mouseSpeed;
	zoom = z;


	updateVectors();
}

void engine1::camera::update(float x,float y)
{
	x *= mouseSensitivity;
	y *= mouseSensitivity;

	yaw += x;
	pitch += y;

	if (pitch > 89)pitch = 89;
	if (pitch < -89)pitch = -89;

	updateVectors();
	
}


void engine1::camera::updateVectors()
{

	
	float pitchC = cos(pitch * toRadian);
	float pitchS = sin(pitch * toRadian);

	float yawC = cos(yaw * toRadian);
	float yawS = sin(yaw * toRadian);

	front.x = pitchC * yawC;
	front.y = pitchS;
	front.z = yawS * pitchC;

	front.normalize();

	right = vector3::cross(front, worldUp);
	right.normalize();

	up = vector3::cross(right, front);
	up.normalize();

	


}
