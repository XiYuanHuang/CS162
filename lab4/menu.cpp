/*********************************************************************
 * ** Program Filename:menu.cpp
 * ** Author:XiYuan Huang
 * ** Date:10/22/2018
 * ** Description:This file inclues all menu public function
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/	
#include "menu.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>


using namespace std;

Menu::Menu()
{
	num_pizzas = 0;
	pizzas = NULL;		
}
Menu::~Menu()
{
	delete [] pizzas;
	pizzas = NULL;	

}
Menu::Menu(const Menu &copy)
{
	num_pizzas = copy.num_pizzas;
	if(num_pizzas != 0){
		pizzas = new Pizza[num_pizzas];
		for(int i = 0; i < num_pizzas; i++){
			pizzas[i] = copy.pizzas[i];
		}
	}else{
		pizzas = NULL;
	}
}
Menu& Menu::operator = (const Menu &copy)
{
	num_pizzas = copy.num_pizzas;
	if(num_pizzas != 0){
		if(this -> pizzas != NULL){
			delete [] pizzas;
		} 
		pizzas = new Pizza[num_pizzas];
		for(int i = 0; i < num_pizzas; i++){
		
		}
	}else{
		pizzas = NULL;	
	}
	return *this;
} 	
int Menu::get_num_pizzas()
{
	return num_pizzas;
}
void Menu::set_num_pizzas(int new_num_pizzas)
{
	num_pizzas = new_num_pizzas;
}
Pizza* Menu::get_pizzas()
{
	return pizzas;
}
void Menu::set_pizza(Pizza* array)
{
	for(int i = 0; i < num_pizzas; i++){
		pizzas[i] = array[i];		
	}
}
/*********************************************************************
 * ** Function:add_to_menu
 * ** Description:This function add a line of pizza info and add to 
 * 	the menu object.
 * ** Parameters:a pizza object
 * ** Pre-Conditions:pizza nondefault constructor(loading data one)
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Menu::add_to_menu(Pizza pizza_to_add)
{	
	Pizza* newArray = new Pizza[num_pizzas + 1];
	for(int i = 0; i < num_pizzas; i++){
		newArray[i] = pizzas[i];		
	}	
	newArray[num_pizzas] = pizza_to_add;
	delete [] pizzas;
	pizzas = newArray;
	num_pizzas++;
}
/*********************************************************************
 * ** Function:remove_pizza
 * ** Description:This function remove a specific pizza, which based on 
 * 	the user's option
 * ** Parameters:int
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Menu::remove_pizza(int remove_pizza)
{
	for(int i = remove_pizza; i < num_pizzas; i++){
		pizzas[i-1] = pizzas[i];
	}
	num_pizzas--;
}
/*********************************************************************
 * ** Function:put_pizza_in_file
 * ** Description:This function rewrite the menu.txt after removing the
 * 	pizza
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Menu::put_pizza_in_file()
{
	ofstream menu_file;
	menu_file.open("menu.txt");
	if(menu_file.is_open()){
			menu_file << num_pizzas << endl;
		for(int i = 0; i < (num_pizzas-1); i++){
			menu_file << pizzas[i].get_name() << " ";
			menu_file << pizzas[i].get_small_cost() << " ";
			menu_file << pizzas[i].get_medium_cost() << " ";
			menu_file << pizzas[i].get_large_cost() << " ";
			menu_file << pizzas[i].get_num_ingredients() << " ";
			for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
				menu_file << pizzas[i].get_ingredients()[j] << endl;
			}		
		}
	}
}
/*void Menu::load_pizza()
{
	string name = " "; int price = 0, num_i = 0;	
	Pizza* new_pizza = new Pizza[num_pizzas + 1];
	for(int i = 0; i < (num_pizzas-1); i++){
		name = pizzas[i].get_name();new_pizza[i].set_name(name);
		price = pizzas[i].get_small_cost();new_pizza[i].set_small_cost(price);
		price = pizzas[i].get_medium_cost();new_pizza[i].set_medium_cost(price);
		price = pizzas[i].get_large_cost();new_pizza[i].set_large_cost(price);
		num_i = pizzas[i].get_num_ingredients();new_pizza[i].set_num_ingredients(num_i);
			for(int j = 0; j < new_pizzas[i].get_num_ingredients(); j++){
				new_pizza[i].set_ingredients(pizzas[i].get_ingredients()[j])[j];
			}		
		}
 	//Pizza p2;
	//p2.add_pizza();
	ofstream my_file("menu.txt", ios::app);
	if(my_file.is_open()){
		my_file << p2.get_name() << " ";
		my_file << p2.get_small_cost() << " ";
		my_file << p2.get_medium_cost() << " ";
		my_file << p2.get_large_cost() << " ";
		my_file << p2.get_num_ingredients() << " ";
		for(int j = 0; j < p2.get_num_ingredients(); j++){
			my_file << p2.get_ingredients()[j] << endl;
		}	
	}				
}*/
/*********************************************************************
 * ** Function:print_pizza
 * ** Description:this function print out the data of the pizza array.
 * ** Parameters:pizza array
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Menu::print_pizza(Pizza* pizza_to_print)
{
	cout << "num_pizza" << num_pizzas << endl;
	for(int i = 0; i < (num_pizzas-1); i++){
		cout << i+1 << ". " << pizza_to_print[i].get_name() << " ";
		cout << pizza_to_print[i].get_small_cost() << " ";
		cout << pizza_to_print[i].get_medium_cost() << " ";
		cout << pizza_to_print[i].get_large_cost() << " ";
		cout << pizza_to_print[i].get_num_ingredients() << " ";
		for(int j = 0; j < pizza_to_print[i].get_num_ingredients(); j++){
			cout << pizza_to_print[i].get_ingredients()[j] << " ";
		}
		cout << endl;
	}
}
