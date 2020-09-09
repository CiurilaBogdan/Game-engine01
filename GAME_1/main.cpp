#include <glew.h>
#include <glfw3.h>
#include <cstdio>
#include <chrono>
#include <cmath>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "src/graphics/shader.h"
#include "src/graphics/texture.h"
#include "src/graphics/mesh.h"

#include "src/math/vector3.h"
#include "src/math/matrix4.h"
#include "src/math/Quaternion_v2.h"
#include "src/math/vector4.h"

#include "src/gameOjbects/camera.h"
#include "src/gameOjbects/transform.h"

#include "stb_image.h"


using namespace std;
using namespace engine1;
//ALWAYS WRITE HERE WHAT YOU ARE CURRENTLY WORKING ON
//working on the matrices and transformations
//next: profiling and timing performance




void mat4_vec4(float *mat4,float *vec4,float *result) {

	int matIndex = 0;
	for (int i = 0; i < 4; i++) {

		for (int x = 0; x < 4; x++) {

			result[i] +=(mat4[matIndex] * vec4[x]);
			matIndex++;
		}
	}
	
}
const unsigned int screenWidth = 1024;
const unsigned int screenHeight = 1024;

double cameraX = screenWidth / 2;
double cameraY = screenHeight / 2;
bool firstMouse = true;

camera cam;

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	if (firstMouse) {
		cameraX = xpos;
		cameraY = ypos;
		firstMouse = false;
	}
	float xoffset = xpos - cameraX;
	float yoffset = cameraY - ypos; // reversed since y-coordinates go from bottom to top

	


	cameraX = xpos;
	cameraY = ypos;

	cam.update(xoffset,yoffset);
	
}



int main(void)
{

	

	//transform scene[100];
	//for (int i = 0; i < 100; i++) {
	//	scene[i].translate(i, i, i);
	//}
	//
	//int ix = 0;
	//int bfn = 1000000;
	//using namespace std::chrono;
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//
	//for (int i = 0; i < bfn; i++) {
	//	
	//}
	//

	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//
	//auto time_span = duration_cast<microseconds>(t2 - t1);
	//printf("MICROSECONDS: %d\n", time_span.count());
	//
	//return 0;
	mesh cube("C:/dev/GAME_1/resources/monkey.obj");
	
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile("C:/dev/GAME_1/resources/cube.obj", aiProcessPreset_TargetRealtime_MaxQuality);
	if (!scene) {
		printf(importer.GetErrorString());
	}


	
	 unsigned int noVerts = scene->mMeshes[0]->mNumVertices;
	
	 float *cubeObj = new float[noVerts*3];
	 float* cubeUV = new float[noVerts * 2];

	 for (int i = 0; i < noVerts; i++) {
		 cubeObj[(i * 3)] = scene->mMeshes[0]->mVertices[i].x;
		 cubeObj[(i * 3) +1] = scene->mMeshes[0]->mVertices[i].y;
		 cubeObj[(i * 3) +2] = scene->mMeshes[0]->mVertices[i].z;

		 cubeUV[(i * 2)] = scene->mMeshes[0]->mTextureCoords[0][i].x;
		 cubeUV[(i * 2)+1] = scene->mMeshes[0]->mTextureCoords[0][i].y;


	 }
	 

	 int noFaces = scene->mMeshes[0]->mNumFaces;
	 int noInds = noFaces * 3;
	 unsigned int* cubeInds = new unsigned int[noInds];
	 int ti = 0;
	 for (int i = 0; i < noFaces; i++) {

		 ti = i*3;
		 cubeInds[ti+0] = scene->mMeshes[0]->mFaces[i].mIndices[0];
		 cubeInds[ti+1] = scene->mMeshes[0]->mFaces[i].mIndices[1];
		 cubeInds[ti+2] = scene->mMeshes[0]->mFaces[i].mIndices[2];

	 }

	
	 //delete[] cubeInds;
	//unsigned int cube_ind[] = {
	//		    0, 2, 1,
	//			0, 3, 2,

	//			1,2,6,
	//			6,5,1,

	//			4,5,6,
	//			6,7,4,

	//			2,3,6,
	//			6,3,7,

	//			0,7,3,
	//			0,4,7,

	//			0,1,5,
	//			0,5,4
	//};

	////NEW CUBE
	//float nextCube[4 * 4 * 2] = {

	//	-1.0, -1.0,  1.0, 1.0,
	//	 1.0, -1.0,  1.0, 1.0,
	//	 1.0,  1.0,  1.0, 1.0,
	//	-1.0,  1.0,  1.0, 1.0,
	//	// back			  
	//	-1.0, -1.0, -1.0, 1.0,
	//	 1.0, -1.0, -1.0, 1.0,
	//	 1.0,  1.0, -1.0, 1.0,
	//	-1.0,  1.0, -1.0, 1.0,

	//};

	//float newSize = 0.1;

	//float nextCube2[4 * 4 * 2];

	//for (int i = 0; i <8*4; i+=4) {

	//	nextCube[i+0] *= newSize;
	//	nextCube[i+1] *= newSize;
	//	nextCube[i+2] *= newSize;

	//	nextCube2[i + 0] = nextCube[i + 0];
	//	nextCube2[i + 1] = nextCube[i + 1];
	//	nextCube2[i + 2] = nextCube[i + 2];
	//	nextCube2[i + 3] = nextCube[i + 3];

	//}
	//NEW CUBE UV
	/*float nextCubeUV[2 * 4 * 6] = {
		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		1.0f , 1.0f,
		1.0f , 0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f

	};
*/


	///*Resize cube*/
	//for (int i = 0; i < 8 * 5; i += 5) {

	//	cube[i] *=	    newSize;
	//	cube[i + 1] *=  newSize;
	//	cube[i + 2] *=  newSize;

	//	cube2[i] *=     newSize;
	//	cube2[i + 1] *= newSize;
	//	cube2[i + 2] *= newSize;
	//}
	

	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(screenWidth, screenHeight, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {

		return 0;
	}
	glfwSetCursorPosCallback(window, mouse_callback);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	
	//glBufferData(GL_ARRAY_BUFFER, sizeof(nextCube), nextCube, GL_DYNAMIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, 3*noVerts*sizeof(float),cubeObj, GL_DYNAMIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, cube.vertices_size, cube.vertices, GL_DYNAMIC_DRAW);


	glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);



	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_ind), cube_ind, GL_DYNAMIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, noInds * sizeof(unsigned int), cubeInds, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube.indices_size, cube.indices, GL_DYNAMIC_DRAW);



	unsigned int TBO;
	glGenBuffers(1, &TBO);
	glBindBuffer(GL_ARRAY_BUFFER, TBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(nextCubeUV), nextCubeUV, GL_DYNAMIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, 2*noVerts*sizeof(float), cubeUV, GL_DYNAMIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, cube.uv_size, cube.uvCoordinates, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));

	
	cube.delete_data();
	 delete[]cubeObj;

	 delete[] cubeInds;
	 delete[]cubeUV;
	texture myTexture("../resources/uv_grid.jpg");
	myTexture.set_active();

	shader myShader("../shaders/MathPractice3.txt");
	myShader.set_active();

	int mvpId = glGetUniformLocation(myShader.get_id(), "mvp");


	
	double toRadian = 3.14159265359 / 180;

	
	 float degree = 0.0f;
	 float degrees[3] = { 0.0f,0.0f,0.0f };

	float oldTime = 0.0f, currentTime = 0.0f, deltaTime = 0.0f;
	bool rotate = true;

	vector3 axis(0.0f, 1.0f, 0.0f);
	vector3 cubePos(0.0f, 0.0f, -10.0f);
	vector3 cubeSize(1.0f, 1.0f, 1.0f);
	
	quaternion cubeOrientation(0, 0, 0, 1);//useless
	quaternion newR;
	quaternion oldRotation;
	mat4 perspMat;
	mat4 mvpMat;

	quaternion rotation(0,0,0,1);
	vector3 XAxis(1, 0, 0);
	vector3 YAxis(0, 1, 0);
	vector3 rotationAngles;


	perspMat = mat4::perspective(45, 1024 / 1024, 0.00000001, 100);

	glEnable(GL_DEPTH_TEST);
	
	
	mat4 camMat;
	
	while (!glfwWindowShouldClose(window))
	{


		glfwPollEvents();
		
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);//nice
		}

		currentTime = glfwGetTime();
		deltaTime = currentTime - oldTime;
		oldTime = currentTime;
		//rotate = false;
		
		//Get camera input

		/*axis.set_scalar(0.0f);*/
		rotate = false;
		

		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			/*axis.y = -1.0;
			rotate = true;*/
			/*if (cubePos.x > -0.5f) {
				cubePos.x -= deltaTime * 0.5;

			}*/
			
			cam.position.x -= deltaTime * 0.5;
			//degree += deltaTime * 50 ;
			//axis.set_scalar(0.0f);
			/*degrees[1] += deltaTime * 50;
			axis.y = 1;
			rotate = true;*/
			
			rotationAngles.y += deltaTime * 0.5;
			//proto_rotate(rotation, rotationAngles, degrees[1]);
			rotation.from_euler(rotationAngles);

		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			/*axis.y = 1.0;
			rotate = true;*/
			/*if (cubePos.x < 0.5f) {
				cubePos.x += deltaTime * 0.5;

			}*/
			cam.position.y += deltaTime * 0.5;
			

			//degrees[1] += deltaTime * 50 * -1;
			////axis.set_scalar(0.0f);
			//axis.y = 1;
			//rotate = true;
			
			rotationAngles.y -= deltaTime * 0.5;
			//proto_rotate(rotation, rotationAngles, degrees[1]);
			rotation.from_euler(rotationAngles);


		}
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			/*axis.x = -1.0;
			rotate = true;*/
			/*if (cubePos.y < 0.5f) {
				cubePos.y += deltaTime * 0.5;

			}*/
			cam.position.z -= deltaTime * 0.5;
			//degrees[0] += deltaTime * 50;
			////axis.set_scalar(0.0f);
			//axis.x = 1;
			//rotate = true;

			rotationAngles.x += deltaTime * 0.5;
			//proto_rotate(rotation, rotationAngles, degrees[0]);
			rotation.from_euler(rotationAngles);

		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			/*axis.x = 1.0;
			rotate = true;*/
			/*if (cubePos.y > -0.5f) {
				cubePos.y -= deltaTime * 0.5;

			}*/
			cam.position.z += deltaTime * 0.5;


			//degrees[0] += deltaTime * 50*-1;
			////axis.set_scalar(0.0f);
			//axis.x = 1;
			//rotate = true;
			rotationAngles.x -= deltaTime * 0.5;
			
			//proto_rotate(rotation, rotationAngles, degrees[0]);
			rotation.from_euler(rotationAngles);
		}

	
		/*if (rotate) {
			degree += deltaTime * 50;
		}*/



		float halfSine = sin(degree * toRadian * 0.5);
		float halfCosine = cos(degree * toRadian * 0.5);
		
		

		
		
		//if (axis.is_zero()) {

		/*if (rotate == false){

			rotation.set_quat(oldRotation);
			
		}
		else {

			float axisLength = vector3::mag(axis);
			axis.x /= axisLength;
			axis.y /= axisLength;
			axis.z /= axisLength;
			
			rotation.set_vector(axis);
			oldRotation.set_quat(rotation);

		}
		*/

		/*rotation.x *= halfSine;
		rotation.y *= halfSine;
		rotation.z *= halfSine;
		rotation.w = halfCosine;*/
		//newR = rotation * cubeOrientation;
		newR = rotation;
		
		mat4 sM;
		sM = mat4::scale(cubeSize);

		mat4 rM;
		newR = newR.normalized();
		rM = mat4::rotate2(newR);
		

		mat4 tM;
		tM = mat4::translate(cubePos);


		
		camMat = mat4::lookat(cam.position, cam.position + cam.front, cam.up);
		
	
		//mvpMat = perspMat * camMat* tM * rM * sM;
		mvpMat = perspMat * tM * rM * sM;
		
		

		//glBufferData(GL_ARRAY_BUFFER, sizeof(nextCube), nextCube, GL_DYNAMIC_DRAW);
		glUniformMatrix4fv(mvpId, 1, GL_FALSE, mvpMat.data);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, cube.indices_count, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);


	}


	
	glfwTerminate();
	return 0;
}