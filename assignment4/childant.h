/*********************************************************************
 * ** Program Filename:childant.h
 * ** Author:XiYuan Huang
 * ** Date:11/25/2018
 * ** Description:This is the header file of ant child
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef CHILDANT_H
#define CHILDANT_H

#include "ant.h"

#include <iostream>
#include <cstring>

using namespace std;

class harvester:public ant
{
	public:
		harvester();
		//int cal_food_cost(int);
};

class thrower:public ant
{
	public:
		thrower();
};

class fire:public ant
{
	public:
		fire();
};

class long_thrower:public ant
{
	public:
		long_thrower();	
};

class short_thrower:public ant
{
	public:
		short_thrower();
};

class wall:public ant
{
	public:
		wall();
};

class ninja:public ant
{
	public:
		ninja();
};

class bodyguard:public ant
{
	public:
		bodyguard();
};
#endif
