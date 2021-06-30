#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "menu.h"

using namespace std;

struct employee {
	
	 string id;
	 string first_name;
	 string last_name;
	 string password;
};

struct hours {
	 string day;
 	 string open_hour;
	 string close_hour;
};


class Restaurant {
	 private:
		 Menu menu;
		 employee* employees;
		 hours* week;
		 int num_employee;
		 int num_days;
 		 string name;
 		 string phone;
 		 string address; 
 	 public:
		string get_name();
		string get_phone();
		string get_address();
		Restaurant();	
		~Restaurant();
		Restaurant(const Restaurant &);
		Restaurant& operator=(const Restaurant &);
		void get_menu();
		void set_menu();
		void get_employee(employee*, int, ifstream&);
		void set_employee();
		void get_week(hours*, int , ifstream& );
		void set_week();		
		void load_data(); 
		bool login(string id, string password);
 		void view_menu();
 		void view_hours();
 		void view_address();
 		void view_phone();
 		void search_menu_by_price();
 		void search_by_ingredients();
 		void place_order(Pizza* selection);
 		void change_hours();
 		void add_to_menu();
 		void remove_from_menu();
 		void view_orders();
 		void remove_orders();
}; 


#endif
