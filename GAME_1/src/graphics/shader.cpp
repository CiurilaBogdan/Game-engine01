#include "shader.h"

namespace engine1 {

	unsigned int shader::compile_shader(const char* shader_source, GLenum shader_type)
	{

		unsigned int shader_id = glCreateShader(shader_type);

		glShaderSource(shader_id, 1, &shader_source, NULL);
		glCompileShader(shader_id);


		return shader_id;
	}

	shader::shader(const char* vertex, const char* fragment)
	{
		vertex_id = compile_shader(vertex, GL_VERTEX_SHADER);
		fragment_id = compile_shader(fragment, GL_FRAGMENT_SHADER);

		program_id = glCreateProgram();
		glAttachShader(program_id, vertex_id);
		glAttachShader(program_id, fragment_id);
		glLinkProgram(program_id);

		glDeleteShader(vertex_id);
		glDeleteShader(fragment_id);
	}

	shader::shader(const char* shader_path)
	{
		//Read a shader from a file and into a string
		FILE* f;
		fopen_s(&f, shader_path, "r");

		fseek(f, 0, SEEK_END);
		unsigned long size = ftell(f);

		char* shader_text = new char[size + 1];
		memset(shader_text, 0, size + 1);

		rewind(f);
		fread(shader_text, sizeof(char), size, f);

		
		int tilda_pos = 0;
		for (int i = 0; i < size + 1; i++) {
			if (shader_text[i] == '~') {
				tilda_pos = i;
				break;

			}
		}
			
		
			char* vertex = new char[tilda_pos + 1];
			memset(vertex, 0, tilda_pos + 1);
			memcpy(vertex, shader_text, sizeof(char) * tilda_pos);
		
			char* fragment = new char[(size - tilda_pos)+1];
			memcpy(fragment, shader_text + tilda_pos + 2, sizeof(char) * ((size - tilda_pos) + 1));

			vertex_id = compile_shader(vertex, GL_VERTEX_SHADER);
			fragment_id = compile_shader(fragment, GL_FRAGMENT_SHADER);

			program_id = glCreateProgram();
			glAttachShader(program_id, vertex_id);
			glAttachShader(program_id, fragment_id);
			glLinkProgram(program_id);

			
			delete[] shader_text;
			delete[] vertex;
			delete[] fragment;


		}

		void shader::use()
		{
			glUseProgram(program_id);
		}


	}
