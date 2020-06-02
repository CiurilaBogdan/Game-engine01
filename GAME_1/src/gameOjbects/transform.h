#pragma once
#include "../math/vector3.h"
#include "../math/Quaternion_v2.h"

namespace engine1 {

	class transform {
		
	private:

		quaternion orientation;
	
	public:
			vector3 position;
			vector3 size;

			//must add rotation somehow
			transform(const vector3& position = vector3(0, 0, 0),const vector3& size=vector3(1,1,1));


		    void translate(float x , float y, float z);
			void translate(const vector3& vec);


	};

}