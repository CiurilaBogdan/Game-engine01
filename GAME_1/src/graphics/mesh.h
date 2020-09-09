#pragma once

#include <cstdio>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace engine1 {

	class mesh {

	public:
		float* vertices;
		unsigned int* indices;
		float* uvCoordinates;

		unsigned int vertices_count;
		unsigned int indices_count;

		size_t vertices_size;
		size_t indices_size;
		size_t uv_size;
		

		mesh(const char* path);
		void delete_data();

	};


}