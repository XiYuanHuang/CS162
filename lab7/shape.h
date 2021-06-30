#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Shape
{
	private:
		string name;
		string color;
	public:
		Shape();
		string get_name();
		void set_name(string);
		string get_color();
		void set_color(string);		
		virtual double get_area() = 0;
};

#endif
