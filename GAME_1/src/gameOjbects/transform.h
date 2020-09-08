#pragma once


#include "../math/vector3.h"
#include "../math/Quaternion_v2.h"
#include "../math/matrix4.h"
//THIS COULD BE USELESS

namespace engine1 {

	class transform {

	private:
		/* mat4 size_m4;
		 mat4 position_m4;
		 mat4 orientation_m4;
	
		 mat4 transform_m4;
		
		have these as single instances and use them as temp objects when sending data to gpu
		*/

	public:
			//public functions that take transform data and place it in matrix form
			quaternion orientation;
			vector3 position;
			vector3 size;

			//must add rotation somehow
			//transform(const vector3& position = vector3(0, 0, 0),const vector3& size=vector3(1,1,1));

		   /* void translate(float x , float y, float z);
			void translate(const vector3& vec);

			void rotate(float x, float y, float z);
			void rotate(const vector3& vec);

			void scale(float x, float y, float z);
			void scale(const vector3& vec);*/



	};

}