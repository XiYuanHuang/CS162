#include "rectangle.h"


#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

Rectangle::Rectangle()
{
	width = 0;
	length = 0;	
}
float Rectangle::get_length()
{
	return length;
}
float Rectangle::get_width()
{
	return width;
}
void Rectangle::set_length(float newLength)
{
	length = newLength;
}
void Rectangle::set_width(float newWidth)
{
	width = newWidth;
}
double Rectangle::get_area()
{
	return width * length;
}

