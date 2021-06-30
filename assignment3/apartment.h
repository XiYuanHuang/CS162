/*********************************************************************
 * ** Program Filename:apartment.h
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the header file of apartment class.
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef APARTMENT_H
#define APARTMENT_H

#include "property.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class Apartment:public Property
{
	public:
		Apartment();
		~Apartment();
		void build_apartment();
		Apartment(const Apartment &copy);
		Apartment& operator = (const Apartment &copy); 
};

#endif
