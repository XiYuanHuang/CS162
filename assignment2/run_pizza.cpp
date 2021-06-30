#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
//#include "restaurant.h"
#include "pizza.h"
using namespace std;

/*bool employee_log_in()
{
	bool valid_log_in = false;
	Restaurant employee;
	ifstream employee_file;
	employee_file.open("employee.txt");
	if(employee_file.is_open()){
		cout << "the employee file is opened now" << endl;
		int num_employee = 0;
		employee_file >> num_employee;
		employee* employeeArray = new employee[num_employee];
		employee.set_employee(employeeArray, num_employee, employee_file);
				
	}	
	return valid_log_in;
}*/
char welcome_prompt()
{
	char input = ' ';
	cout << "Welcome to Bytes Pizza!" << endl;
	cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)?" << endl;
	cin >> input;
	if(input == 'C' || input == 'c'){
		cout << "you are customer" << endl;
	}else if(input == 'E' || input == 'e'){
		cout << "you are employee" << endl;
	}else if(input == 'Q' || input == 'q'){
		cout << "you quit the program" << endl;
	}else{
		cout << "Please enter the valid input" << endl;
	}
	return input;	
}

int main()
{
	char user_input = ' ';

	do{
		user_input = welcome_prompt();

	}while(user_input != 'Q' && user_input != 'q'); 	
	cout << "user_input " << user_input << endl;
	cout << "now you end the program" << endl;
	/*Pizza p1;
	ifstream pizza_file;
	pizza_file.open("menu.txt");
	p1.load_pizza_info(pizza_file);*/
					
return 0;
}	

