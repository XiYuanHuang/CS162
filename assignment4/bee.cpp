/*********************************************************************
 * ** Program Filename:bee.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/25/2018
 * ** Description:This is the cpp file of bee class
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#include "bee.h"

#include <iostream>
#include <cstring>

using namespace std;

/*********************************************************************
 * ** Function:bee()
 * ** Description:This is the default constructor of bee class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
bee::bee()
{
	armor = 3;
	name = "B";
}
/*********************************************************************
 * ** Function:get_armor()
 * ** Description:This is the accessor of armor
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int bee::get_armor()
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
void bee::set_armor(int new_armor)
{
	armor = new_armor;
}
/*********************************************************************
 * ** Function:get_name()
 * ** Description:This is the accessor of name
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
string bee::get_name()
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
void bee::set_name(string new_name)
{
	name = new_name;
}
