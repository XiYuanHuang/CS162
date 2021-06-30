/*********************************************************************
 * ** Program Filename:tenant.h
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the header file of tenant class.
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef TENANT_H
#define TENANT_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tenant
{
	private:
		int agreeability_score;
		float budget;
		float rent;
		string size_of_room;
		int pay_rent;
	public:
		Tenant();
		Tenant(const Tenant &copy);
		Tenant& operator = (const Tenant &copy);
		string get_size_of_room();
		void set_size_of_room(string);
		int get_agreeability_score();
		void set_agreeability_score(int);
		float get_budget();
		void set_budget(float);
		void rand_agreeability_score();
		void rand_budget();	
		int get_pay_rent();
		void set_pay_rent(int);
		float get_rent();
		void set_rent(float);

};

#endif
