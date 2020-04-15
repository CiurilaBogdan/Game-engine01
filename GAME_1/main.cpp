#include <glew.h>
#include <glfw3.h>
#include <cstdio>


#include "src/graphics/shader.h"
#include "src/graphics/texture.h"
#include "src/math/vector3.h"
#include "src/math/matrix4.h"
//#include "src/math/quaternion.h"
#include "src/math/Quaternion_v2.h"

#include "stb_image.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"

#include <chrono>
#include <cmath>

using namespace std;
using namespace engine1;
//ALWAYS WRITE HERE WHAT YOU ARE CURRENTLY WORKING ON
//working on the matrices and transformations
//next: profiling and timing performance

//class v {
//public:
//
//	float x, y;
//	
//	
//	v(float a, float b) {
//		x = a;
//		y = b;
//	}
//
//	
//};

//class matV {
//public:
//	union  {
//		v rows;
//		float data[2];
//	};
//
//	matV(float a, float b) {
//		/*rows.x = a;
//		rows.y = b;*/
//		
//		data[0] = a;
//		data[1] = b;
//	}
//};
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
	

	///*vector3 vec1(2, 1, 0);
	//vector3 vec2(1, 2, 0);
	//vector3 vec3;*/
	///*v myV(1, 2);
	//matV myMat(6, 9);
	//printf("%f %f \n", myMat.rows.x, myMat.rows.y);
	//printf("%f %f \n", myMat.data[0], myMat.data[1]);*/



	//float result = 0.0f;
	//mat4 myMat;
	//
	//
	//int x = 0;
	//using namespace std::chrono;
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//
	//for (int i = 0; i < 1000000; i++) {
	//	//result = myMat.data[0] + myMat.rows.x;
	//	//result += addTWO();
	//	//result += 2.0f;
	//	
	//
	//}


	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//
	//auto time_span = duration_cast<microseconds>(t2 - t1);
	//
	//printf("%d\n", time_span.count());
	////printf("%f\n", result);
	//printf("%f\n", result);
	
	//float zoom_level = 1.0f;
	//float vertices[] = {
	//     1.0f,  1.0f, 0.0f,   1.0f*zoom_level, 1.0f*zoom_level, // top right
	//	 1.0f, -1.0f, 0.0f,   1.0f*zoom_level, 0.0f, // bottom right
	//	-1.0f, -1.0f, 0.0f,   0.0f, 0.0f, // bottom left
	//	-1.0f,  1.0f, 0.0f,   0.0f, 1.0f*zoom_level
	//};
	//float vertices2[20];
	//for (int i = 0; i < 20; i++) {
	//	vertices2[i] = vertices[i];
	//}
	//	unsigned int indices[] = { 
	//	0, 1, 3,   // first triangle
	//	1, 2, 3    // second triangle
	//};

	
	float cube[] = {
	-1.0, -1.0,  1.0,	   1.0f , 1.0f,
	 1.0, -1.0,  1.0,	   1.0f , 0.0f,
	 1.0,  1.0,  1.0,	   0.0f, 0.0f,
	-1.0,  1.0,  1.0,	   0.0f, 1.0f,
	// back
	-1.0, -1.0, -1.0,	   1.0f ,1.0f,
	 1.0, -1.0, -1.0,	   1.0f ,0.0f,
	 1.0,  1.0, -1.0,	   0.0f, 0.0f,
	-1.0,  1.0, -1.0,	   0.0f, 1.0f,
	
	};

	float cube2[] = {
	-1.0, -1.0,  1.0,	   1.0f , 1.0f,
	 1.0, -1.0,  1.0,	   1.0f , 0.0f,
	 1.0,  1.0,  1.0,	   0.0f, 0.0f,
	-1.0,  1.0,  1.0,	   0.0f, 1.0f,
	// back
	-1.0, -1.0, -1.0,	   1.0f ,1.0f,
	 1.0, -1.0, -1.0,	   1.0f ,0.0f,
	 1.0,  1.0, -1.0,	   0.0f, 0.0f,
	-1.0,  1.0, -1.0,	   0.0f, 1.0f,

	};


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



	/*Resize cube*/
	for (int i = 0; i < 8 * 5; i += 5) {

		cube[i] *= 0.5;
		cube[i + 1] *= 0.5;
		cube[i + 2] *= 0.5;

		cube2[i] *= 0.5;
		cube2[i + 1] *= 0.5;
		cube2[i + 2] *= 0.5;
	}
	

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_DYNAMIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_ind), cube_ind, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));

	
	texture myTexture("../resources/tropical.jpg");
	myTexture.set_active();

	shader myShader("../shaders/MathPractice.txt");
	myShader.set_active();

	//glm::mat4 trMat(1.0f);
	//trMat = glm::scale(trMat, glm::vec3(0.25f));
	//trMat = glm::translate(trMat, glm::vec3(0.0f, 0.0f, -10.0f));
	//trMat = glm::rotate(trMat, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 1.0f));
	//glm::mat4 proj;
	//proj = glm::perspective(glm::radians(65.0f), 640.0f / 480.0f, 0.1f, 100.0f);

	//trMat = proj * trMat;
	//unsigned int transformationLocation = glGetUniformLocation(myShader.get_id(), "transform");
	//glUniformMatrix4fv(transformationLocation, 1, GL_FALSE, glm::value_ptr(trMat));
	//
	//glEnable(GL_DEPTH_TEST);
	////camera
	//
	//glm::vec3 cameraPos(0.0f, 0.0f, 3.0f);
	//glm::vec3 cameraDir = glm::normalize(cameraPos - glm::vec3(0.0f, 0.0f, 0.0f));
	//glm::vec3 cameraRight = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), cameraDir));
	//glm::vec3 cameraUp = glm::cross(cameraDir, cameraRight);
	//
	//glm::mat4 view;
	/*float degree = 0.0f;
	for (int i = 0; i < 4 * 5; i += 5) {
		vertices2[i] *= 0.5;
		vertices2[i + 1] *= 0.5;
	}*/

	/*vector3 rotAxis(1.0f, 1.0f, 0.0f);
	quat pureQuaternion;
	quat rotationQuaternion(rotAxis);
	quat conjugateQuaternion;
	quat resultQuaternion;

	quat testQuat;
	*/
	float toRadian = 3.14 / 180;

	


	

	 float degree = 0.0f;
	glEnable(GL_DEPTH_TEST);

	float oldTime = 0.0f, currentTime = 0.0f, deltaTime = 0.0f;
	
	while (!glfwWindowShouldClose(window))
	{

		glfwPollEvents();
		
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);//nice
		}

		currentTime = glfwGetTime();
		deltaTime = currentTime - oldTime;
		oldTime = currentTime;

		///*2d rotation*/
		//degree += deltaTime * 150;
		//float toRadian = 3.14 / 180;
		//float c = cos(degree * toRadian);
		//float s = sin(degree * toRadian);

		//for (int i = 0; i < 4 * 5; i += 5) {
		//	vertices[i] = (vertices2[i] * c) - (vertices2[i + 1] * s);
		//	vertices[i + 1] = (vertices2[i] * s) + (vertices2[i + 1] * c);
		//	
		//}
		//
		//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		
		/*if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			trMat = glm::rotate(trMat, glm::radians(45.0f * deltaTime), glm::vec3(-1.0f, 0.0f, 0.0f));

		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			trMat = glm::rotate(trMat, glm::radians(45.0f * deltaTime), glm::vec3(1.0f, 0.0f, 0.0f));
		}
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			trMat = glm::rotate(trMat, glm::radians(45.0f * deltaTime), glm::vec3(0.0f, 1.0f, 0.0f));

		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			trMat = glm::rotate(trMat, glm::radians(45.0f * deltaTime), glm::vec3(0.0f, -1.0f, 0.0f));
		}



		glUniformMatrix4fv(transformationLocation, 1, GL_FALSE, glm::value_ptr(trMat));*/


		/*Rotate cube*/
		//void rotate_vector_by_quaternion(const Vector3 & v, const Quaternion & q, Vector3 & vprime)
		//{
		//	// Extract the vector part of the quaternion
		//	Vector3 u(q.x, q.y, q.z);

		//	// Extract the scalar part of the quaternion
		//	float s = q.w;

		//	// Do the math
		//	vprime = 2.0f * dot(u, v) * u
		//		+ (s * s - dot(u, u)) * v
		//		+ 2.0f * s * cross(u, v);
		//}

		degree += deltaTime *50;
		float c = cos(degree * toRadian*0.5);
		float s = sin(degree * toRadian*0.5);

		float halfSine = sin(degree* toRadian * 0.5);
		float halfCosine = cos(degree * toRadian * 0.5);


		vector3 axis(1.0f, 1.0f, 1.0f);
		float axisLength = vector3::mag(axis);
		axis.x /= axisLength;
		axis.y /= axisLength;
		axis.z /= axisLength;

		quaternion rotation(axis);
		//float rotQuat[4] = { axis.x,axis.y,axis.z ,0.0f};
		

		rotation.x *= halfSine;
		rotation.y *= halfSine;
		rotation.z *= halfSine;
		rotation.w = halfCosine;
		
		quaternion rotationConjugate = rotation.get_conjugate();

		/*rotationQuaternion.w = c;
		rotationQuaternion.multiplyImg(s);
		conjugateQuaternion = rotationQuaternion.conjugate();*/

		for (int i = 0; i < 8 * 5; i += 5) {
		

			quaternion pure(cube2[i],cube2[i+1],cube2[i+2]);
			

			//quaternion rotRes = rotation.multiply(pure);
			quaternion rotRes = pure.multiply(rotation);

			//rotRes = rotRes.multiply(rotationConjugate);
			rotRes = rotationConjugate.multiply(rotRes);


			cube[i] = rotRes.x;
			cube[i+1] = rotRes.y;
			cube[i+2] = rotRes.z;

			
		}
		
		/*float oc = 1 - c;
		float rx = 1.0f, ry = 0.0f, rz = 0.0f;
		float rxry = rx * ry, rxrz = rx * rz, ryrz = ry * rz;
	

		for (int i = 0; i < 8 * 5; i += 5) {
			cube[i]     = cube2[i] * (c + rx * rx * oc)   + cube2[i + 1] * (rxry * oc - rz * s) + cube2[i + 2] * (rxrz * oc + ry * s);
			cube[i + 1] = cube2[i] * (rxry * oc + rz * s) + cube2[i + 1] * (c * ry * ry * oc)   + cube2[i + 2] * (ryrz * oc - rx * s);
			cube[i + 2] = cube2[i] * (rxrz * oc - ry * s) + cube2[i + 1] * (ryrz * oc + rx * s) + cube2[i + 2] * (c + rz * rz * oc);

		}*/
		


		glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_DYNAMIC_DRAW);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);


	}

	glfwTerminate();
	return 0;
}