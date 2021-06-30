#include "shape.h"
#include "circle.h"
#include "rectangle.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void print_shape_info(Shape& p1)
{
	cout << "name " << p1.get_name() << endl;
	cout << "color " << p1.get_color() << endl;
	cout << "area of shape " << p1.get_area() << endl;
}

int main()
{
	Circle c1;
	c1.set_name("circle");
	c1.set_color("white");
	c1.set_radius(3);
	print_shape_info(c1);
	Rectangle r1;
	r1.set_name("rectangle");
	r1.set_color("black");
	r1.set_length(2);
	r1.set_width(3);
	print_shape_info(r1);		
	
	return 0;
}
