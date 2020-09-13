#include "mesh.h"

engine1::mesh engine1::mesh::operator+(const mesh& other) const
{
	
	return mesh(*this, other);
}

engine1::mesh::mesh(const char* path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcessPreset_TargetRealtime_MaxQuality);
	if (!scene) {
		printf(importer.GetErrorString());
	}

	vertices_count = scene->mMeshes[0]->mNumVertices;
	vertices_size = vertices_count * sizeof(float) * 3;
	uv_size = vertices_count * sizeof(float) * 2;

	vertices = new float[vertices_count * 3];
	uvCoordinates = new float[vertices_count * 2];

	for (int i = 0; i < vertices_count; i++) {
		vertices[(i * 3)] = scene->mMeshes[0]->mVertices[i].x;
		vertices[(i * 3) + 1] = scene->mMeshes[0]->mVertices[i].y;
		vertices[(i * 3) + 2] = scene->mMeshes[0]->mVertices[i].z;

		uvCoordinates[(i * 2)] = scene->mMeshes[0]->mTextureCoords[0][i].x;
		uvCoordinates[(i * 2) + 1] = scene->mMeshes[0]->mTextureCoords[0][i].y;
	

	}


	
	int noFaces = scene->mMeshes[0]->mNumFaces;
	indices_count = noFaces * 3;
	indices_size = indices_count * sizeof(unsigned int);

	indices= new unsigned int[indices_count];
	
	int ti = 0;
	for (int i = 0; i < noFaces; i++) {

		ti = i * 3;
		indices[ti + 0] = scene->mMeshes[0]->mFaces[i].mIndices[0];
		indices[ti + 1] = scene->mMeshes[0]->mFaces[i].mIndices[1];
		indices[ti + 2] = scene->mMeshes[0]->mFaces[i].mIndices[2];

	}



}

engine1::mesh::mesh()
{	/*
	vertices = nullptr;
	indices = nullptr;
	uvCoordinates = nullptr;

	vertices_count = 0;
	indices_count = 0;

	vertices_size = 0;
	indices_size = 0;
	uv_size = 0;*/
}


engine1::mesh::mesh(const mesh& first, const mesh& other)
{

	vertices_count =first.vertices_count + other.vertices_count;
	vertices_size = first.vertices_size + other.vertices_size;
	uv_size = first.uv_size + other.uv_size;

	vertices = new float[vertices_count * 3];
	uvCoordinates = new float[vertices_count * 2];
	std::copy(first.vertices, first.vertices + (first.vertices_count * 3), vertices);
	std::copy(other.vertices, other.vertices + (other.vertices_count * 3), vertices+(first.vertices_count * 3));
	std::copy(first.uvCoordinates, first.uvCoordinates + (first.vertices_count * 2), uvCoordinates);
	std::copy(other.uvCoordinates, other.uvCoordinates + (other.vertices_count * 2), uvCoordinates+(first.vertices_count * 2));
	

	indices_count = first.indices_count + other.indices_count;
	indices_size = first.indices_size + other.indices_size;


	indices = new unsigned int[indices_count];
	std::copy(first.indices, first.indices + first.indices_count, indices);
	std::copy(other.indices, other.indices + other.indices_count, indices+first.indices_count);
	
	

	for (int i = first.indices_count; i < indices_count; i++) {
		indices[i] += first.vertices_count;
	}
	
}


void engine1::mesh::delete_data()
{

	delete[] vertices;
	delete[] indices;
	delete[] uvCoordinates;
}
