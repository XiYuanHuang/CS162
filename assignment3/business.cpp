/*********************************************************************
 * ** Program Filename:business.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the business class which is the child of 
 * 	property class. It re-defines the protected members from the 
 * 	property class and has its own big three. 
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#include "business.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/*********************************************************************
 * ** Function:Business()
 * ** Description:This is the default constructor of business class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Business::Business()
{
	value = 0;
	mortgage = 0;
	property_tax = 0;
	debt = 0;
	size_of_room = " ";
	num_tenant = 0;	
	tenants = NULL; 		
}
/*********************************************************************
 * ** Function:build_business()
 * ** Description:This is the constructor of business class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Business::build_business()
{
	value = (rand()%3 + 4) * 100000;
	debt = 0;
	mortgage = (rand()%46 + 5) * 100;
	property_tax = value * 0.015;
	num_tenant = rand()%5 + 1;	
	tenants = new Tenant[num_tenant]; 		
	rand_tenants(tenants);
	rand_location();
	rand_size_of_room(tenants);
}
/*********************************************************************
 * ** Function:~Business()
 * ** Description:This is the destructor of business class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Business::~Business()
{
	if(tenants != NULL){	
		delete [] tenants;
		tenants = NULL;
	}
}
/*********************************************************************
 * ** Function:Business(const Business &copy)
 * ** Description:This is the copy constructor of Business class
 * ** Parameters:const Business &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Business::Business(const Business &copy)
{
	value = copy.value;
	mortgage = copy.mortgage;
	property_tax = copy.property_tax;
	size_of_room = copy.size_of_room;
	num_tenant = copy.num_tenant;
	if(num_tenant != 0){
		tenants = new Tenant[num_tenant];
		for(int i = 0; i < num_tenant; i++){
			tenants[i] = copy.tenants[i];
		}
	}else{
		tenants = NULL;
	}
}
/*********************************************************************
 * ** Function:Business& operator = (cost Business &copy)
 * ** Description:This is the assignment overload(=) of business class
 * ** Parameters:const Business &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Business& Business::operator = (const Business &copy)
{
	value = copy.value;
	mortgage = copy.mortgage;
	property_tax = copy.property_tax;
	size_of_room = copy.size_of_room;
	num_tenant = copy.num_tenant;
	if(num_tenant != 0){
		if(this-> tenants != NULL){
			delete [] tenants;
		}
		tenants = new Tenant[num_tenant];
		for(int i = 0; i < num_tenant; i++){
			tenants[i] = copy.tenants[i];
		}
	}else{
		tenants = NULL;
	}
	return *this;
}
