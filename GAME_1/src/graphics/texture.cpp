#include "texture.h"

namespace engine1 {

	texture::texture(const char* texture_path):
		texture_id(0),texture_buffer(nullptr),width(0),height(0),bpp(0)
	{
		stbi_set_flip_vertically_on_load(1);
		texture_buffer = stbi_load(texture_path, &width, &height, &bpp, 0);//might have to change to 4 channels when using png
		
		if (!texture_buffer) {
			printf("TEXTURE ERROR\n");
			return;
		}

		glGenTextures(1, &texture_id);
		glBindTexture(GL_TEXTURE_2D, texture_id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_buffer);

		stbi_image_free(texture_buffer);
		glBindTexture(GL_TEXTURE_2D, NULL);

	}

	void texture::set_active()const
	{
		glBindTexture(GL_TEXTURE_2D, texture_id);

	}
	void texture::set_inactive()const
	{
		glBindTexture(GL_TEXTURE_2D, NULL);

	}
}