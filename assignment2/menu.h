#ifndef MENU_H
#define MENU_H
#include "pizza.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Menu {

 	 private:
    		int num_pizzas;
   		Pizza* pizzas;
	 public:
		Menu();
		~Menu();
		int get_num_pizzas();
		void set_num_pizzas(int );	
		Menu search_pizza_by_cost(int upper_bound, string size);
 		Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
		Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
 		void add_to_menu(Pizza pizza_to_add);
		void load_pizza_data(Pizza& pizza_to_load);
 		void remove_from_menu(int index_of_pizza_on_menu);
		void print_menu(Pizza& );
}; 

	
#endif
