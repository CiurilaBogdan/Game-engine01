#include <glew.h>
#include <glfw3.h>

int main(void)
{
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

	unsigned int shader_vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader_vertex, 1, &shader_vertex_source, NULL);
	glCompileShader(shader_vertex);


	const char* shader_fragment_source = R"(#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
} )";

	unsigned int shader_fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader_fragment, 1, &shader_fragment_source, NULL);
	glCompileShader(shader_fragment);

	unsigned int shader_program = glCreateProgram();
	glAttachShader(shader_program, shader_vertex);
	glAttachShader(shader_program, shader_fragment);
	glLinkProgram(shader_program);
	glUseProgram(shader_program);


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