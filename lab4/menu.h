/*********************************************************************
 * ** Program Filename:menu.h
 * ** Author:XiYuan Huang
 * ** Date:10/22/2018
 * ** Description:This is the header file of menu class
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/	
#ifndef MENU_H
#define MENU_H

#include "pizza.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

class Menu
{
	private:
 		int num_pizzas;
		Pizza* pizzas;
			 
	public:
		Menu();
		~Menu();
		Menu(const Menu &copy);
		Menu& operator = (const Menu &copy);
		void remove_pizza(int);
		int get_num_pizzas();
		void set_num_pizzas(int);
		Pizza* get_pizzas();
		void set_pizza(Pizza*);
		void add_to_menu(Pizza); 
		//void load_pizza();
		void put_pizza_in_file();
		void print_pizza(Pizza*);
};

#endif
