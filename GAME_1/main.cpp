#include <glew.h>
#include <glfw3.h>
#include <cstdio>


#include "src/graphics/shader.h"
#include "src/graphics/texture.h"

#include "stb_image.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"

#include <chrono>

using namespace std;
using namespace engine1;
//ALWAYS WRITE HERE WHAT YOU ARE CURRENTLY WORKING ON
//Working on the vector class





int main(void)
{

	


	float result = 0.0f;

	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	
	auto time_span = duration_cast<microseconds>(t2 - t1);

	printf("%d\n", time_span.count());
	//printf("%f\n", result);

	return 0;
	float zoom_level = 1.0f;
	float vertices[] = {
	     1.0f,  1.0f, 0.0f,   1.0f*zoom_level, 1.0f*zoom_level, // top right
		 1.0f, -1.0f, 0.0f,   1.0f*zoom_level, 0.0f, // bottom right
		-1.0f, -1.0f, 0.0f,   0.0f, 0.0f, // bottom left
		-1.0f,  1.0f, 0.0f,   0.0f, 1.0f*zoom_level
	};
		unsigned int indices[] = { 
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	//float cube[] = {
	//-1.0, -1.0,  1.0,	   1.0f , 1.0f,
	// 1.0, -1.0,  1.0,	   1.0f , 0.0f,
	// 1.0,  1.0,  1.0,	   0.0f, 0.0f,
	//-1.0,  1.0,  1.0,	   0.0f, 1.0f,
	//// back
	//-1.0, -1.0, -1.0,	   1.0f ,1.0f,
	// 1.0, -1.0, -1.0,	   1.0f ,0.0f,
	// 1.0,  1.0, -1.0,	   0.0f, 0.0f,
	//-1.0,  1.0, -1.0,	   0.0f, 1.0f,
	//
	//};

	/*unsigned int cube_ind[] = {
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
	};*/



	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_ind), cube_ind, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5,(void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));

	
	texture myTexture("../resources/tropical.jpg");
	myTexture.set_active();

	shader myShader("../shaders/TextureShader.txt");
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

		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);


	}

	glfwTerminate();
	return 0;
}