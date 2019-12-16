#include <glew.h>
#include <glfw3.h>
#include <cstdio>

#include "src/graphics/shader.h"

using namespace std;
using namespace engine1;

int main(void)
{


	//read from file
	

	return 0;
	float triangle[] = {
	-0.5f, -0.5f, 
	 0.5f, -0.5f, 
	 0.0f,  0.5f
	};

	

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

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


	const char* shader_vertex_source = R"(#version 330 core
		layout(location = 0) in vec3 aPos;
		void main()
	{
		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	})";

	
	

	const char* shader_fragment_source = R"(#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
} )";
	
	

	shader myShader(shader_vertex_source, shader_fragment_source);
	myShader.use();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);


		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}