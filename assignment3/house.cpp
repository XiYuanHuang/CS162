/*********************************************************************
 * ** Program Filename:house.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the house class which is the child of 
 * 	property class. It re-defines the protected members from the 
 * 	property class and has its own big three. 
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/	
#include "house.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/*********************************************************************
 * ** Function:House()
 * ** Description:This is the default constructor of house class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
House::House()
{
	value = 0;
	mortgage = 0;
	property_tax = 0;
	debt = 0;
	num_tenant = 0;	
	tenants = NULL; 		
}
/*********************************************************************
 * ** Function:build_house()
 * ** Description:This is the constructor of house class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void House::build_house()
{
	value = (rand()%6 + 1) * 100000;
	debt = 0;
	mortgage = (rand()%46 + 5) * 100;
	property_tax = value * 0.015;
	num_tenant = 1;	
	tenants = new Tenant[num_tenant]; 		
	rand_tenants(tenants);
	rand_location();
		
}
/*********************************************************************
 * ** Function:~House()
 * ** Description:This is the destructor of house class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
House::~House()
{	
	if(tenants != NULL){
		delete [] tenants;
		tenants = NULL;
	}
}
/*********************************************************************
 * ** Function:House(const House &copy)
 * ** Description:This is the copy constructor of house class
 * ** Parameters:const House &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
House::House(const House &copy)
{
	value = copy.value;
	mortgage = copy.mortgage;
	property_tax = copy.property_tax;
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
 * ** Function:House& operator = (const House &copy)
 * ** Description:This is the assignment overload(=) of house class
 * ** Parameters:const House &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
House& House::operator = (const House &copy)
{
	value = copy.value;
	mortgage = copy.mortgage;
	property_tax = copy.property_tax;
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

