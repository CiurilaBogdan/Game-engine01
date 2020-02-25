#pragma once


namespace engine1 {

	class vector2 {

	public:
		float x, y;

		vector2() {
			x = 1.0f;
			y = 1.0f;
		}
		vector2(float a, float b) {
			x = a;
			y = b;
		}

		void scale(float a,float b);
		void scale(vector2& other);

		
};


}