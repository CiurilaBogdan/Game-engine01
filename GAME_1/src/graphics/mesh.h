#pragma once

#include <cstdio>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <algorithm>

namespace engine1 {

	class mesh {

	public:
		float* vertices;
		unsigned int* indices;
		float* uvCoordinates;

		unsigned int vertices_count;
		unsigned int indices_count;

		unsigned int vertices_size;
		unsigned int indices_size;
		unsigned int uv_size;
		
		mesh();
		mesh(const char* path);
		mesh(const mesh& first,const mesh& other);
		mesh operator+(const mesh& other)const;

		void delete_data();

	};


}