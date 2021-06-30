/*********************************************************************
 * ** Program Filename:apartment.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the apartment class which is the child of 
 * 	property class. It re-defines the protected members from the 
 * 	property class and has its own big three. 
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#include "apartment.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/*********************************************************************
 * ** Function:Apartment()
 * ** Description:This is the default constructor of apartment class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Apartment::Apartment()
{
	value = 0;
	mortgage = 0;
	property_tax = 0;
	debt = 0;
	num_tenant = 0;	
	tenants = NULL;		
}
/*********************************************************************
 * ** Function:build_apartment()
 * ** Description:This is the constructor of apartment class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Apartment::build_apartment()
{
	value = (rand()%4 + 3) * 100000;
	debt = 0;
	mortgage = (rand()%46 + 5) * 100;
	property_tax = value * 0.015;
	num_tenant = rand()%10 + 1;	
	tenants = new Tenant[num_tenant]; 		
	rand_tenants(tenants);
	rand_location();
}
/*********************************************************************
 * ** Function:~Apartment()
 * ** Description:This is the destructor of apartment class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Apartment::~Apartment()
{
	if(tenants != NULL){
		delete [] tenants;
		tenants = NULL;
	}
}
/*********************************************************************
 * ** Function:apartment(const Apartment &copy)
 * ** Description:This is the copy constructor of apartment class
 * ** Parameters:const Apartment &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Apartment::Apartment(const Apartment &copy)
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
 * ** Function:Apartment& operator = (const Apartment &copy)
 * ** Description:This is the assignment overload(=) of apartment class
 * ** Parameters:const apartment &copy
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Apartment& Apartment::operator = (const Apartment &copy)
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
