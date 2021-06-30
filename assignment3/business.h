/*********************************************************************
 * ** Program Filename:business.h
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the header file of business class.
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef BUSINESS_H
#define BUSINESS_H

#include "property.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class Business:public Property
{
	public:
		Business();
		~Business();	
		void build_business();
		Business(const Business &copy);
		Business& operator = (const Business &copy);
};

#endif
