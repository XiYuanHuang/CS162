#include "circle.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

Circle::Circle()
{
	radius = 0;
}
float Circle::get_radius()
{
	return radius;
}
void Circle::set_radius(float newRadius)
{
	radius = newRadius;
}
double Circle::get_area()
{
	return (3.14 * radius * radius);	
}
