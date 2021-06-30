/*********************************************************************
 * ** Program Filename:property.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the property class which is the parent of house,
 * 	apartment, and business class.
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#include "property.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/*********************************************************************
 * ** Function:Property()
 * ** Description:This is the default constructor of property class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Property::Property()
{
	value = 0;
	mortgage = 0;
	property_tax = 0;
	num_tenant = 0;
	location = " ";
	debt = 0;
	size_of_room = " ";
	tenants = NULL;
}
/*********************************************************************
 * ** Function:~Property()
 * ** Description:This is the destructor of property class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Property::~Property()
{
	if(tenants != NULL){
		delete [] tenants;
		tenants = NULL;
	}
}
bool Property::operator > (const Property& copy)
{ 
	if(value > copy.value){
		return true;
	}else if(num_tenant > copy.num_tenant){
		return true;
	}else{
		return false;
	}
}
bool Property::operator < (const Property& copy)
{
	if(value < copy.value){
		return true;
	}else if(num_tenant < copy.num_tenant){
		return true;
	}else{
		return false;
	}
}
/*********************************************************************
 * ** Function:get_value()
 * ** Description:This is the accessor of value
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Property::get_value()
{
	return value;
}
/*********************************************************************
 * ** Function:set_value(float newValue)
 * ** Description:This is the mutator of value
 * ** Parameters:float newValue
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_value(float newValue)
{
	value = newValue;
}
/*********************************************************************
 * ** Function:get_mortgage()
 * ** Description:This is the accessor of mortgage
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Property::get_mortgage()
{
	return mortgage;
}
/*********************************************************************
 * ** Function:set_mortgage(float newMortgage)
 * ** Description:This is the mutator of mortgage
 * ** Parameters:float newMortgage
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_mortgage(float newMortgage)
{
	mortgage = newMortgage;
}
/*********************************************************************
 * ** Function:get_debt()
 * ** Description:This is the accessor of debt
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Property::get_debt()
{
	return debt;
}
/*********************************************************************
 * ** Function:set-debt(float newDebt)
 * ** Description:This is the mutator of debt
 * ** Parameters:float newDebt
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_debt(float newDebt)
{
	debt = newDebt;
}
/*********************************************************************
 * ** Function:get_property_tax()
 * ** Description:This is the accessor of property tax
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Property::get_property_tax()
{
	return property_tax;
}
/*********************************************************************
 * ** Function:set_property_tax(float new_property_tax)
 * ** Description:This is the mutator of property tax
 * ** Parameters:float new_property_tax
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_property_tax(float new_property_tax)
{
	property_tax = new_property_tax;
}
/*********************************************************************
 * ** Function:get_location()
 * ** Description:This is the accessor of location
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
string Property::get_location()
{
	return location;
}
/*********************************************************************
 * ** Function:set_location(string newLocation)
 * ** Description:This is the mutator of location
 * ** Parameters:string newLocation
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_location(string newLocation)
{
	location = newLocation;
}
/*********************************************************************
 * ** Function:rand_location()
 * ** Description:This function provide a random location for a property.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::rand_location()
{
	int rand_location = rand()% 5 + 1;
	switch(rand_location)
	{
		case 1: location = "SE";
			break;
		case 2: location = "NE";
			break;
		case 3: location = "MW";
			break;
		case 4: location = "SW";
			break;
		case 5: location = "NW";
			break;	
		default:
			cout << "The rand number is not correct" << endl;
	}	
}
/*********************************************************************
 * ** Function:get_num_tenant()
 * ** Description:This is the accessor of num tenant
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int Property::get_num_tenant()
{
	return num_tenant;
}
/*********************************************************************
 * ** Function:set_num_tenant(int tenant_size)
 * ** Description:This is the mutator of num tenant
 * ** Parameters:int tenant_size
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_num_tenant(int tenant_size)
{
	num_tenant = tenant_size;
}
/*********************************************************************
 * ** Function:get_tenants()
 * ** Description:This is the accessor of tenant array
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Tenant* Property::get_tenants()
{
	return tenants;
}
/*********************************************************************
 * ** Function:set_tenants(Tenant* newTenants)
 * ** Description:This is the mutator of tenant array
 * ** Parameters:Tenant* newTenants
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_tenants(Tenant* newTenants)
{
	for(int i = 0; i < num_tenant; i++){
		int agree_score = newTenants[i].get_agreeability_score(); 
		tenants[i].set_agreeability_score(agree_score);
		float tenant_budget = newTenants[i].get_budget();
		tenants[i].set_budget(tenant_budget);	
	}
}
/*********************************************************************
 * ** Function:rand_tenants(Tenant * tenants)
 * ** Description:This function can produce the random information for each tenant
 * ** Parameters:Tenant* tenants
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::rand_tenants(Tenant * tenants)
{
	for(int i = 0; i < num_tenant; i++){
		tenants[i].rand_agreeability_score();
		tenants[i].rand_budget();
		tenants[i].set_pay_rent(1);
		tenants[i].set_rent(0);
	}
}
/*********************************************************************
 * ** Function:print_tenants()
 * ** Description:This function prints the information of each tenant
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::print_tenants()
{
	for(int i = 0; i < num_tenant; i++){
		cout << "tenant " << i + 1<< ": " << "agreeability_score "<< tenants[i].get_agreeability_score() << " ";
		cout << "budget " << tenants[i].get_budget() << " ";
		cout << "Pay or not pay " << tenants[i].get_pay_rent() << " ";
		cout << "rent " << tenants[i].get_rent() << " ";
		cout << tenants[i].get_size_of_room() << endl;;
	}
}
/*********************************************************************
 * ** Function:rand_size_of_room(Tenant* tenants)
 * ** Description:This function creates the random size of room
 * ** Parameters:Tenant* tenants
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::rand_size_of_room(Tenant* tenants)
{
	for(int i = 0; i < num_tenant; i++){
	int roomSize = rand()%3 + 1;
	switch(roomSize)
	{
		case 1: tenants[i].set_size_of_room("small");
			break;
		case 2: tenants[i].set_size_of_room("medium");
			break;
		case 3: tenants[i].set_size_of_room("large");
			break;
		default:
			cout << "the rand number is not correct" << endl; 
	}
	}
}
/*********************************************************************
 * ** Function:check_rent(float player_rent)
 * ** Description:This function check the rent for each tenant
 * ** Parameters:float player_rent
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::check_rent(float player_rent)
{
	Tenant* t = new Tenant[num_tenant];
	int new_tenant = 0;
	for(int i = 0; i < num_tenant; i++){
		if((tenants[i].get_agreeability_score() > 1) && (tenants[i].get_budget() >= player_rent)){
			t[i] = tenants[i];
			new_tenant++;
		}else if((tenants[i].get_agreeability_score() == 1) && (tenants[i].get_budget() >= player_rent)){
			t[i] = tenants[i];
			t[i].set_pay_rent(1);
			new_tenant++;
		}else if((tenants[i].get_agreeability_score() == 1) && (tenants[i].get_budget() < player_rent)){
			t[i] = tenants[i];
			t[i].set_pay_rent(0);
			new_tenant++;}		
	}
	delete [] tenants;int check = 0;
	tenants = new Tenant[new_tenant];
	for(int i = 0; i < num_tenant; i++){
		if((t[i].get_agreeability_score() >= 1) && (t[i].get_budget() > 0)){
			tenants[check]=t[i];
		check++;	}
	}
	delete [] t;
	num_tenant = new_tenant;
		
}
/*********************************************************************
 * ** Function:set_tenant_rent(float player_rent)
 * ** Description:This function change the rent for each tenant
 * ** Parameters:float player_rent
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Property::set_tenant_rent(float player_rent)
{
	for(int i = 0; i < num_tenant; i++){
		tenants[i].set_rent(player_rent);
	}
}
/*********************************************************************
 * ** Function:collect_rent()
 * ** Description:This function collect the rent from each tenant
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Property::collect_rent()
{
	int totalRent = 0;
	for(int i = 0; i < num_tenant; i++){
		if(tenants[i].get_pay_rent() == 1){
			totalRent += tenants[i].get_rent();
		}
	}
	return totalRent;
		
}
