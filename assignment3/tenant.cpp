/*********************************************************************
 * ** Program Filename:tenant.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the tenant class which includes the accessor and
 * 	mutator of agreeability score, budget, size of room, rent and the 
 * 	bool pay_rent to decide whehter the tenant wants to pay their rent.
 * 	This file also include the rand function for agreeability_score and
 * 	budget.
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#include "tenant.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/*********************************************************************
 * ** Function:Tenant()
 * ** Description:This is the default constructor of Tenant class. 
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Tenant::Tenant()
{
	agreeability_score = 0;
	budget = 0;
	size_of_room = " ";
	rent = 0;
	pay_rent = 0;
}
/*********************************************************************
 * ** Function:get_rent()
 * ** Description:This is the accessor of rent
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Tenant::get_rent()
{
	return rent;
}
/*********************************************************************
 * ** Function:set_rent(float newRent)
 * ** Description:This is the mutator of rent
 * ** Parameters:float newRent
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Tenant::set_rent(float newRent)
{
	rent = newRent;
}
/*********************************************************************
 * ** Function:Tenant(const Tenant &copy)
 * ** Description:This is the copy constructor of Tenant class
 * ** Parameters:const Tenant &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Tenant::Tenant(const Tenant &copy)
{
	agreeability_score = copy.agreeability_score;
	budget = copy.budget;
	pay_rent = copy.pay_rent;
	size_of_room = copy.size_of_room;
}
/*********************************************************************
 * ** Function:Tenant& operator = (const Tenant &copy)
 * ** Description:This is the assignment overload(=) of Tenant class
 * ** Parameters:const Tenant &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Tenant& Tenant::operator = (const Tenant &copy)
{
	agreeability_score = copy.agreeability_score;
	budget = copy.budget;
	pay_rent = copy.pay_rent;
	size_of_room = copy.size_of_room;
	
	return *this; 
}
/*********************************************************************
 * ** Function:get_size_of_room()
 * ** Description:This is the accessor of size_of_room
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
string Tenant::get_size_of_room()
{
	return size_of_room;
}
/*********************************************************************
 * ** Function:set_size_of_room(string new_size_of_room)
 * ** Description:This is the mutator of size_of_room
 * ** Parameters:string new_size_of_room
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Tenant::set_size_of_room(string new_size_of_room)
{
	size_of_room = new_size_of_room;
}
/*********************************************************************
 * ** Function:get_agreeability_score()
 * ** Description:This is the accessor of agreeability_score
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int Tenant::get_agreeability_score()
{
	return agreeability_score;
}
/*********************************************************************
 * ** Function:set_agreeability_score(int newAgreeability)
 * ** Description:This is the mutator of agreeability_score
 * ** Parameters:int newAgreeability
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Tenant::set_agreeability_score(int newAgreeability)
{
	agreeability_score = newAgreeability;
}
/*********************************************************************
 * ** Function:get_budget()
 * ** Description:This is the accessor of budget
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Tenant::get_budget()
{
	return budget;
}
/*********************************************************************
 * ** Function:set_budget(float newBudget)
 * ** Description:This is the mutator of budget
 * ** Parameters:float newBudget
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Tenant::set_budget(float newBudget)
{
	budget = newBudget;
}
/*********************************************************************
 * ** Function:rand_agreeability_score()
 * ** Description:This function is used to get a random agreeability score
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Tenant::rand_agreeability_score()
{
	agreeability_score = (rand()% 5 + 1);
}
/*********************************************************************
 * ** Function:rand_budget()
 * ** Description:This function is used to get a random budget
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Tenant::rand_budget()
{
	budget = ((rand()% 30 + 20) * 100);
}
/*********************************************************************
 * ** Function:get_pay_rent()
 * ** Description:This is the accessor of pay_rent
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 	
int Tenant::get_pay_rent()
{
	return pay_rent;
}
/*********************************************************************
 * ** Function:set_pay_rent(int new_pay_rent)
 * ** Description:This is the mutator of pay_rent
 * ** Parameters:int new_pay_rent
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Tenant::set_pay_rent(int new_pay_rent)
{
	pay_rent = new_pay_rent;
}
