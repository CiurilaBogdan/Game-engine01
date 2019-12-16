#include "shader.h"

namespace engine1 {
	
	unsigned int shader::compile_shader(const char* shader_source,GLenum shader_type)
	{
	
		unsigned int shader_id = glCreateShader(shader_type);
		
		glShaderSource(shader_id, 1, &shader_source, NULL);
		glCompileShader(shader_id);


		return shader_id;
	}

	shader::shader(const char* vertex, const char* fragment)
	{
		vertex_id = compile_shader(vertex,GL_VERTEX_SHADER);
		fragment_id = compile_shader(fragment,GL_FRAGMENT_SHADER);

		program_id = glCreateProgram();
		glAttachShader(program_id, vertex_id);
		glAttachShader(program_id, fragment_id);
		glLinkProgram(program_id);


	}

	void shader::use()
	{
		glUseProgram(program_id);
	}


}