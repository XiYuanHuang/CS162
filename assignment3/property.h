/*********************************************************************
 * ** Program Filename:property.h
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the header file of property class.
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "tenant.h"

using namespace std;

class Property
{
	protected:
		float value;
		float mortgage;
		float property_tax;
		string location;
		int num_tenant;
		float debt;	
		Tenant* tenants;
		string size_of_room;
	public:
		Property();
		~Property();
		bool operator > (const Property& copy);
		bool operator < (const Property& copy);
		float get_value();
		void set_value(float);
		float get_mortgage();
		void set_mortgage(float);
		float get_debt();
		void set_debt(float);
		float get_property_tax();
		void set_property_tax(float);
		string get_location();
		void set_location(string);
		void rand_location();	
		int get_num_tenant();
		void set_num_tenant(int);	
		Tenant* get_tenants();
		void set_tenants(Tenant*);
		void rand_tenants(Tenant *);	
		void print_tenants();
		void rand_size_of_room(Tenant* );
		void check_rent(float);	
		void set_tenant_rent(float);
		float collect_rent();
};

#endif
