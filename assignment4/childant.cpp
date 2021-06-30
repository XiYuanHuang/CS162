/*********************************************************************
 * ** Program Filename:childant.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/25/2018
 * ** Description:This is the cpp file of ant children
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#include "childant.h"

#include <iostream>

using namespace std;

/*********************************************************************
 * ** Function:harvester()
 * ** Description:This is the default constructor of harvester class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
harvester::harvester()
{
	name = "H";
	armor = 1;
	food_cost = 2;
	damage = 0;
}
/*int harvester::cal_food_cost(int food_cost)
{
	food_cost = food_cost - 2;
}*/
/*********************************************************************
 * ** Function:thrower()
 * ** Description:This is the default constructor of thrower class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
thrower::thrower()
{
	name = "T";
	armor = 1;
	food_cost = 4;
	damage = 1;
}
/*********************************************************************
 * ** Function:fire()
 * ** Description:This is the default constructor of fire class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
fire::fire()
{
	name = "F";
	armor = 1;
	food_cost = 4;
}
/*********************************************************************
 * ** Function:long_thrower()
 * ** Description:This is the default constructor of long thrower class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
long_thrower::long_thrower()
{
	name = "L";
	armor = 1;
	food_cost = 3;
	damage = 1;
}
/*********************************************************************
 * ** Function:short_thrower()
 * ** Description:This is the default constructor of short thrower class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
short_thrower::short_thrower()
{
	name = "S";
	armor = 1;
	food_cost = 3;
	damage = 1;
}
/*********************************************************************
 * ** Function:wall()
 * ** Description:This is the default constructor of wall class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
wall::wall()
{
	name = "W";
	armor = 4;
	food_cost = 4;
	damage = 0;
}
/*********************************************************************
 * ** Function:ninja()
 * ** Description:This is the default constructor of ninja class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
ninja::ninja()
{
	name = "N";
	armor = 1;
	food_cost = 6;
	damage = 1;
}
/*********************************************************************
 * ** Function:bodyguard()
 * ** Description:This is the default constructor of bodyguard class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
bodyguard::bodyguard()
{
	name = "G";
	armor = 2;
	food_cost = 4;
	damage = 0;
}
