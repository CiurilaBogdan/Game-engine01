#include "transform.h"

void engine1::transform::translate(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void engine1::transform::translate(const vector3& vec)
{
	position.x = vec.x;
	position.y = vec.y;
	position.z = vec.z;

}
