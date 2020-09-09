#include "mesh.h"

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

void engine1::mesh::delete_data()
{

	delete[] vertices;
	delete[] indices;
	delete[] uvCoordinates;
}
