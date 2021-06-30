/*********************************************************************
 * ** Program Filename:ant.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/25/2018
 * ** Description:This is the cpp file of ant class
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#include "ant.h"

#include <iostream>
#include <cstring>

using namespace std;

/*********************************************************************
 * ** Function:ant()
 * ** Description:This is the default constructor of ant class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
ant::ant()
{
	armor = 0;
	food_cost = 0;
	name = " ";
	damage = 0;
}
/*********************************************************************
 * ** Function:get_armor()
 * ** Description:This is the accessor of armor
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int ant::get_armor()
{
	return armor;
}
/*********************************************************************
 * ** Function:set_armor(int new_armor)
 * ** Description:This is the mutator of armor
 * ** Parameters:int new_armor
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void ant::set_armor(int new_armor)
{
	armor = new_armor;
}
/*********************************************************************
 * ** Function:get_food_cost()
 * ** Description:This is the accessor of food cost
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int ant::get_food_cost()
{
	return food_cost;
}
/*********************************************************************
 * ** Function:set_food_cost(int new_food_cost)
 * ** Description:This is the mutator of food cost
 * ** Parameters:int new_food_cost
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void ant::set_food_cost(int new_food_cost)
{
	food_cost = new_food_cost;
}
/*********************************************************************
 * ** Function:get_name()
 * ** Description:This is the accessor of name
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
string ant::get_name()
{
	return name;
}
/*********************************************************************
 * ** Function:set_name(string new_name)
 * ** Description:This is the mutator of name
 * ** Parameters:string new_name
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void ant::set_name(string new_name)
{
	name = new_name;
}
/*********************************************************************
 * ** Function:get_damage()
 * ** Description:This is the accessor of damage
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int ant::get_damage()
{
	return damage;
}
/*********************************************************************
 * ** Function:set_damage(int new_damage)
 * ** Description:This is mutator of damage
 * ** Parameters:int new_damage
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void ant::set_damage(int new_damage)
{
	damage = new_damage;
}

