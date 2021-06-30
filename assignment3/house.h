/*********************************************************************
 * ** Program Filename:house.h
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the header file of house class
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef HOUSE_H
#define HOUSE_H

#include "property.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class House:public Property
{
	public:
		House();
		~House();
		House(const House &copy);
		House& operator = (const House &copy);
		void build_house();

};

#endif
