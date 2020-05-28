#include <glew.h>
#include <glfw3.h>
#include <cstdio>
#include <chrono>
#include <cmath>


#include "src/graphics/shader.h"
#include "src/graphics/texture.h"
#include "src/math/vector3.h"
#include "src/math/matrix4.h"
//#include "src/math/quaternion.h"
#include "src/math/Quaternion_v2.h"
#include "src/math/vector4.h"
#include "stb_image.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"


using namespace std;
using namespace engine1;
//ALWAYS WRITE HERE WHAT YOU ARE CURRENTLY WORKING ON
//working on the matrices and transformations
//next: profiling and timing performance


void mat4_vec4(float *mat4,float *vec4,float *result) {

	int matIndex = 0;
	for (int i = 0; i < 4; i++) {

		for (int x = 0; x < 4; x++) {

			result[i] +=(mat4[matIndex] * vec4[x]);
			matIndex++;
		}
	}
	
}




int main(void)
{
	//mat4 m1 ;
	//mat4 m2 ;
	//mat4 m3 ;
	//
	//vector3 pos(1, 2, 3);
	//vector3 scl(2, 3, 4);
	//vector3 rot(3, 4, 5);
	//
	//int ix = 0;
	//int bfn = 1000000;
	//using namespace std::chrono;
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//
	//for (int i = 0; i < bfn; i++) {
	//	
	//	


	//}
	//

	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//
	//auto time_span = duration_cast<microseconds>(t2 - t1);
	//printf("MICROSECONDS: %d\n", time_span.count());
	////printf("%f\n", res);
	//
	/*mat4 m;
	vector4 v(1,2,3,4);
	for (int i = 0; i < 16; i++) {
		m.data[i] = i;
	}
	vector4 res = v * m;
	printf("%.2f %.2f %.2f %.2f", res.x, res.y, res.z, res.w);

	return 0;*/

	

	
	//float cube[] = {
	//-1.0, -1.0,  1.0,	   1.0f , 1.0f,
	// 1.0, -1.0,  1.0,	   1.0f , 0.0f,
	// 1.0,  1.0,  1.0,	   0.0f,  0.0f,
	//-1.0,  1.0,  1.0,	   0.0f,  1.0f,
	//// back
	//-1.0, -1.0, -1.0,	   1.0f ,1.0f,
	// 1.0, -1.0, -1.0,	   1.0f ,0.0f,
	// 1.0,  1.0, -1.0,	   0.0f, 0.0f,
	//-1.0,  1.0, -1.0,	   0.0f, 1.0f,
	//
	//};

	//float cube2[] = {
	//-1.0, -1.0,  1.0,	   1.0f , 1.0f,
	// 1.0, -1.0,  1.0,	   1.0f , 0.0f,
	// 1.0,  1.0,  1.0,	   0.0f, 0.0f,
	//-1.0,  1.0,  1.0,	   0.0f, 1.0f,
	//// back
	//-1.0, -1.0, -1.0,	   1.0f ,1.0f,
	// 1.0, -1.0, -1.0,	   1.0f ,0.0f,
	// 1.0,  1.0, -1.0,	   0.0f, 0.0f,
	//-1.0,  1.0, -1.0,	   0.0f, 1.0f,

	//};


	unsigned int cube_ind[] = {
			    0, 2, 1,
				0, 3, 2,

				1,2,6,
				6,5,1,

				4,5,6,
				6,7,4,

				2,3,6,
				6,3,7,

				0,7,3,
				0,4,7,

				0,1,5,
				0,5,4
	};

	//NEW CUBE
	float nextCube[4 * 4 * 2] = {

		-1.0, -1.0,  1.0, 1.0,
		 1.0, -1.0,  1.0, 1.0,
		 1.0,  1.0,  1.0, 1.0,
		-1.0,  1.0,  1.0, 1.0,
		// back			  
		-1.0, -1.0, -1.0, 1.0,
		 1.0, -1.0, -1.0, 1.0,
		 1.0,  1.0, -1.0, 1.0,
		-1.0,  1.0, -1.0, 1.0,

	};

	float newSize = 0.1;

	float nextCube2[4 * 4 * 2];

	for (int i = 0; i <8*4; i+=4) {

		nextCube[i+0] *= newSize;
		nextCube[i+1] *= newSize;
		nextCube[i+2] *= newSize;

		nextCube2[i + 0] = nextCube[i + 0];
		nextCube2[i + 1] = nextCube[i + 1];
		nextCube2[i + 2] = nextCube[i + 2];
		nextCube2[i + 3] = nextCube[i + 3];

	}
	//NEW CUBE UV
	float nextCubeUV[2 * 4 * 6] = {
		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f

	};



	///*Resize cube*/
	//for (int i = 0; i < 8 * 5; i += 5) {

	//	cube[i] *=	    newSize;
	//	cube[i + 1] *=  newSize;
	//	cube[i + 2] *=  newSize;

	//	cube2[i] *=     newSize;
	//	cube2[i + 1] *= newSize;
	//	cube2[i + 2] *= newSize;
	//}
	

	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(1024, 1024, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {

		return 0;
	}
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(nextCube), nextCube, GL_DYNAMIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)0);



	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_ind), cube_ind, GL_DYNAMIC_DRAW);


	unsigned int TBO;
	glGenBuffers(1, &TBO);
	glBindBuffer(GL_ARRAY_BUFFER, TBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(nextCubeUV), nextCubeUV, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));

	
	texture myTexture("../resources/tropical.jpg");
	myTexture.set_active();

	shader myShader("../shaders/MathPractice2.txt");
	myShader.set_active();


	
	float toRadian = 3.14 / 180;

	
	 float degree = 0.0f;

	float oldTime = 0.0f, currentTime = 0.0f, deltaTime = 0.0f;
	bool rotate = true;
	vector3 axis(1.0f, 1.0f, 0.0f);
	vector3 cubePos(0.0f, 0.0f, 0.0f);
	vector3 cubeSize(1.0f, 1.0f, 1.0f);
	quaternion cubeOrientation(0, 0, 0, 1);
	mat4 perspMat;
	perspMat = perspMat.perspective(45, 1024 / 1024, 0.001, 100);

	glEnable(GL_DEPTH_TEST);
	

	while (!glfwWindowShouldClose(window))
	{


		glfwPollEvents();
		
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);//nice
		}

		currentTime = glfwGetTime();
		deltaTime = currentTime - oldTime;
		oldTime = currentTime;
		//rotate = false;
		

		
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			/*axis.y = -1.0;
			rotate = true;*/
			if (cubePos.x > -0.5f) {
				cubePos.x -= deltaTime * 0.5;

			}
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			/*axis.y = 1.0;
			rotate = true;*/
			if (cubePos.x < 0.5f) {
				cubePos.x += deltaTime * 0.5;

			}

		}
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			/*axis.x = -1.0;
			rotate = true;*/
			if (cubePos.y < 0.5f) {
				cubePos.y += deltaTime * 0.5;

			}
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			/*axis.x = 1.0;
			rotate = true;*/
			if (cubePos.y > -0.5f) {
				cubePos.y -= deltaTime * 0.5;

			}
		}

		if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
			/*axis.x = 1.0;
			rotate = true;*/
				cubePos.z -= deltaTime * 0.5;

		}
		if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
			/*axis.x = 1.0;
			rotate = true;*/
			cubePos.z += deltaTime * 0.5;

		}


		
		if (rotate) {

		degree += deltaTime *50;
		float c = cos(degree * toRadian*0.5);
		float s = sin(degree * toRadian*0.5);

		float halfSine = sin(degree* toRadian * 0.5);
		float halfCosine = cos(degree * toRadian * 0.5);

		
		float axisLength = vector3::mag(axis);
		axis.x /= axisLength;
		axis.y /= axisLength;
		axis.z /= axisLength;

		quaternion rotation(axis);
		

		rotation.x *= halfSine;
		rotation.y *= halfSine;
		rotation.z *= halfSine;
		rotation.w = halfCosine;
		
		quaternion rotationConjugate = rotation.get_conjugate();
	

		quaternion newR = rotation.multiply(cubeOrientation);
		
		mat4 sM;
		sM = sM.scale(cubeSize);

		mat4 rM;
		newR = newR.normalized();
		rM = rM.rotate2(newR);
		
		mat4 tM;
		tM = tM.translate(cubePos);

			for (int i = 0; i < 8 * 4; i += 4) {

				quaternion pure((nextCube2[i] * cubeSize.x), (nextCube2[i + 1] * cubeSize.y) , (nextCube2[i + 2] * cubeSize.z));


				quaternion rotRes = pure.multiply(rotation);

				rotRes = rotationConjugate.multiply(rotRes);

				rotRes.x += cubePos.x;
				rotRes.y += cubePos.y;
				rotRes.z += cubePos.z;



				
				/*nextCube[i + 0] = rotRes.x + cubePos.x;
				nextCube[i + 1] = rotRes.y + cubePos.y;
				nextCube[i + 2] = rotRes.z + cubePos.z;*/

			

					/*nextCube[i + 0] = rotRes.x ;
					nextCube[i + 1] = rotRes.y ;
					nextCube[i + 2] = rotRes.z ;*/
				
				vector4 vRes(nextCube2[i], nextCube2[i + 1], nextCube2[i + 2], nextCube2[i + 3]);

				vRes = vRes * sM*rM*tM*perspMat;
				

				nextCube[i] = vRes.x;
				nextCube[i+1] = vRes.y;
				nextCube[i+2] = vRes.z;
				nextCube[i + 3] = vRes.w;
			}
		}
		//cubePos.x += deltaTime * 0.1;
		//projection
		//for (int i = 0; i < 8 * 4; i += 4) {
		//	

		//	//nextCube[i + 3] = nextCube[i + 2] * -1;//division by z

		//}
		
		/*float oc = 1 - c;
		float rx = 1.0f, ry = 0.0f, rz = 0.0f;
		float rxry = rx * ry, rxrz = rx * rz, ryrz = ry * rz;
	

		for (int i = 0; i < 8 * 5; i += 5) {
			cube[i]     = cube2[i] * (c + rx * rx * oc)   + cube2[i + 1] * (rxry * oc - rz * s) + cube2[i + 2] * (rxrz * oc + ry * s);
			cube[i + 1] = cube2[i] * (rxry * oc + rz * s) + cube2[i + 1] * (c * ry * ry * oc)   + cube2[i + 2] * (ryrz * oc - rx * s);
			cube[i + 2] = cube2[i] * (rxrz * oc - ry * s) + cube2[i + 1] * (ryrz * oc + rx * s) + cube2[i + 2] * (c + rz * rz * oc);

		}*/
		


		glBufferData(GL_ARRAY_BUFFER, sizeof(nextCube), nextCube, GL_DYNAMIC_DRAW);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);


	}

	glfwTerminate();
	return 0;
}