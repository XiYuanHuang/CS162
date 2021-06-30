/*********************************************************************
 * ** Program Filename:bee.h
 * ** Author:XiYuan Huang
 * ** Date:11/25/2015
 * ** Description:This is the header file of bee class
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef BEE_H
#define BEE_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class bee
{
	private:
		int armor;
		string name;
	public:
		bee();
		int get_armor();
		void set_armor(int);
		string get_name();
		void set_name(string);
};

#endif 
