/*********************************************************************
 * ** Program Filename:ant.h
 * ** Author:XiYuan Huang
 * ** Date:11/25/2018
 * ** Description:This is the header file of ant class
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class ant
{
	protected:
		int armor;
		int food_cost;
		string name;
		int damage;
	public:
		ant();
		int get_armor();
		void set_armor(int);
		int get_food_cost();
		void set_food_cost(int);
		string get_name();
		void set_name(string);
		int get_damage();
		void set_damage(int);
		//virtual int cal_food_cost(int) = 0;
};

#endif
