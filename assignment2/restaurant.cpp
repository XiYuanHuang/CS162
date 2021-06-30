#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "restaurant.h"

using namespace std;

Restaurant::Restaurant()
{
	//menu = NULL;
	employees = NULL;
	week = NULL;	
 	name = " ";
 	phone = " ";
 	address = " "; 

}	
Restaurant::~Restaurant()
{
	delete [] employees;
	employees = NULL;
	delete [] week;
	week = NULL;	
}
/*Restaurant::Restaurant(const Restaurant &)
{
	
}
Restaurant::Restaurant& operator=(const Restaurant &)
{

}*/
string Restaurant::get_name()
{
	return name;
}
string Restaurant::get_phone()
{
	return phone;
}
string Restaurant::get_address()
{
	return address;
}
/*void Restaurant::get_menu()
{
	
}
void Restaurant::set_menu()
{

}*/
void Restaurant::get_employee(employee* array, int employeeNum, ifstream& infile)
{
	for(int i = 0; i < employeeNum; i++){
		infile >> array[i].id;
		infile >> array[i].first_name;
		infile >> array[i].last_name;
		infile >> array[i].password;
	}
}
void Restaurant::set_employee()
{
	ifstream employee_file;
	employee_file.open("employee.txt");
	if(employee_file.is_open()){
		cout << "the employee file is opened now" << endl;
		employee_file >> num_employee;
		employee* employeeArray = new employee[num_employee];
		get_employee(employeeArray, num_employee, employee_file);
				
	}	

}
void Restaurant::get_week(hours* array, int weekNum, ifstream& infile)
{

	for(int i = 0; i < weekNum; i++){
		infile >> array[i].day;
		infile >> array[i].open_hour;
		infile >> array[i].close_hour;
	}	
}
void Restaurant::set_week()
{
	ifstream week_file;
	week_file.open("restaurant_info.txt");
	if(week_file.is_open()){
		cout << "the week file is opened now" << endl;
		int num_week = 0;
		week_file >> name;
		week_file >> phone;
		week_file >> address;
		week_file >> num_days;
		hours* weekArray = new hours[num_week];
		get_week(weekArray, num_days, week_file);
	}
}
void Restaurant::load_data()
{
	Pizza p;
	for(int i = 0; i < num_employee; i++){
		set_employee();
	}
	for(int i = 0; i < num_days; i++){
		week[i].set_week();
	}
	menu.load_pizza_data(Pizza &p);	
}
/*bool Restaurant::login(string id, string password)
{

}
void Restaurant::view_menu()
{

}
void Restaurant::view_hours()
{

}
void Restaurant::view_address()
{

}
void Restaurant::view_phone()
{

}
void Restaurant::search_menu_by_price()
{

}
void Restaurant::search_by_ingredients()
{

}
void Restaurant::place_order(Pizza* selection)
{

}
void Restaurant::change_hours()
{

}
void Restaurant::add_to_menu()
{

}
void Restaurant::remove_from_menu()
{

}
void Restaurant::view_orders()
{

}
void Restaurant::remove_orders()
{

}*/

