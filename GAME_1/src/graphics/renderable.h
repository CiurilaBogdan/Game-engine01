#pragma once
#include <glew.h>
#include <glfw3.h>

#include "texture.h"
#include "shader.h"
#include "mesh.h"

#include "../math/matrix4.h"
#include "../math/Quaternion_v2.h"
#include "..//math/vector3.h"


namespace engine1 {

	class renderable {

	public:


		unsigned int VAO;
		unsigned int VBOs;
		unsigned int EBOs;
		unsigned int TBOs;

		
		//HAVE A POINTER TO TEXTURES AND SHADERS BUT:...
		//HOW MANY TEXTURES CAN BE ACTIVE?
		//HOW MANY SHADERS CAN BE ACTIVE AT ONE TIME?


		//mat4 transform_m4;//used for sending data to gpu.When doing any kind of transformation this can be updated


	};
}