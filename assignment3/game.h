/*********************************************************************
 * ** Program Filename:game.h
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the header file of game class.
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef GAME_H
#define GAME_H

#include "house.h"
#include "apartment.h"
#include "business.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game
{
	private:
		Property** p;//This is the user's proeprty
		Property** l;//This is the information of selling property
		float money;
		int info_house;
		int info_apartment;
		int info_business;
		int type_property;
		int property_locate;
		int current_house;
		int current_apartment;
		int current_business;
		int turn;
		int user_turn;
		int count_turn;	
	public:
		Game();
		~Game();
		bool check_winner();
		int get_turn();
		void set_turn(int);
		void main_user();
		void auto_event();
		void menu();
		void add_mortgage();	
		void add_rent(); 
		void add_property_tax();
		void add_value();
		void build_property();	
		void print_info_property();
		void print_user_property();
		void buy_property();
		void add_house(int);
		void add_apartment(int);
		void add_business(int);
		void remove_info_house();
		void remove_info_apartment();
		void remove_info_business();
		void replace_info_property();
		void sell_property();
		void add_house_value();
		void add_apartment_value();
		void add_business_value();
		void subtract_user_house();
		void subtract_user_apartment();
		void subtract_user_business();
		void adjust_rent();
		void adjust_house_rent();
		void adjust_apartment_rent();
		void adjust_business_rent();
		float get_money();
		void rand_event();
		void hurricane_event();
		void tornado_event();
		void earthquake_event();
		void wildfire_event();
		void market_crash_event();
		string event_location();	
		void gentrification_event();
};

#endif
