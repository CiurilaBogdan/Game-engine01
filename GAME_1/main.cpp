#include <glew.h>
#include <glfw3.h>
#include <cstdio>
#include <fstream>
#include <string>

#include "src/graphics/shader.h"

using namespace std;
using namespace engine1;

int main(void)
{
	/*ifstream file_to_read;
	string fileTxt = "";
	
	file_to_read.open("GoodFile.txt",std::ios_base::in);
	
	if (file_to_read.is_open()) {
		
		while (file_to_read.good()) {
			
			getline(file_to_read, fileTxt);

		}
		file_to_read.close();
	}

	printf(fileTxt.c_str());*/


	//second attempt

	/*FILE* file;
	char buffer[256];
	
	fopen_s(&file, "GoodFile.txt", "r");
	
	if (file == nullptr) {
		printf("ERROR\n");
	}
	else {

	}
	

	fclose(file);
	
	printf(buffer);*/

	FILE* f;
	fopen_s(&f,"GoodFile.txt", "rt");

	// Determine file size
	fseek(f, 0, SEEK_END);
	unsigned long size = ftell(f);
	
	char* where = new char[size+1];
	memset(where, 0, size + 1);

	rewind(f);
	fread(where, sizeof(char), size, f);

	//process file and break it into different shaders
	string shad(where);
	 
	const char* shader_vertex_source = shad.c_str();
	delete[] where;
	
	//read from file
	


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


	/*const char* shader_vertex_source = R"(#version 330 core
		layout(location = 0) in vec3 aPos;
		void main()
	{
		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	})";*/

	
	

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