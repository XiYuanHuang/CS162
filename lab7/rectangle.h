#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "shape.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Rectangle:public Shape
{
	private:
		float length;
		float width;
	public:
		Rectangle();
		float get_length();
		float get_width();	
		void set_length(float);
		void set_width(float);
		double get_area();
};

#endif
