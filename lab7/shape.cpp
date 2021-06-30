#include "shape.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

Shape::Shape()
{
	name = " ";
	color = " ";
}
string Shape::get_name()
{
	return name;
}
void Shape::set_name(string newName)
{
	name = newName;
}
string Shape::get_color()
{
	return color;
}
void Shape::set_color(string newColor)
{
	color = newColor;
}
	
