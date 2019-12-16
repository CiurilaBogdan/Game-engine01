#pragma once
#include <glew.h>
#include <glfw3.h>
#include <cstdio>

namespace engine1 {

	class shader {

	private:

		unsigned int vertex_id;
		unsigned int fragment_id;
		unsigned int program_id;
	
		unsigned int compile_shader(const char* shader_source,GLenum shader_type);
	public:
		
		shader(const char* vertex, const char* fragment);
		
		void use();

	};
}