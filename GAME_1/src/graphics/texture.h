#pragma once
#include <glew.h>
#include <glfw3.h>
#include <cstdio>

#include "stb_image.h"


namespace engine1 {

	class texture {

	private:
		unsigned int texture_id;
		unsigned char* texture_buffer;
		int width, height, bpp;

	public:
		texture(const char* texture_path);
		unsigned int get_id() { return texture_id; }
		void set_active()const;
		void set_inactive()const;
	};
}