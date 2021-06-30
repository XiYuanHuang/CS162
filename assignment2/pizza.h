#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>


using namespace std;



class Pizza {
	 private:
 		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
 		int num_ingredients;
 		string* ingredients;
 	 public:	
		Pizza();
		//Pizza();	
		~Pizza();
		Pizza(const Pizza &);
		Pizza & operator = (const Pizza &);
		void load_pizza_info(ifstream &f);			
		void print_pizza();
		void set_name(string name);
		string get_name();
		void set_small_cost(int );
		int get_small_cost();
		void set_medium_cost(int );	
		int get_medium_cost();
		void set_large_cost(int );
		int get_large_cost();
		void set_num_ingredients(int );
		int get_num_ingredients();
		string* get_ingredients();
		void set_ingredients(string* );	
 };

#endif

