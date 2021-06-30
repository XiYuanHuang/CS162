#include "menu.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>


using namespace std;

Menu::Menu()
{
	pizzas = NULL;	
	num_pizzas = 0;	
}
Menu::~Menu()
{
	delete [] pizzas;
	pizzas = NULL;
}
int Menu::get_num_pizzas()
{
	return num_pizzas;
}
void Menu::set_num_pizzas(int new_num_pizzas)
{
	num_pizzas = new_num_pizzas;
}	

/*Menu Menu::search_pizza_by_cost(int upper_bound, string size)
{

}
Menu Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients)
{

}
Menu Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients)
{

}
void Menu::add_to_menu(Pizza pizza_to_add)
{
	
}*/
void Menu::load_pizza_data(Pizza &pizza_to_load)
{
	ifstream menu_file;
	menu_file.open("menu.txt");
	int pizzaNum;
	menu_file >> pizzaNum;
	set_num_pizzas(pizzaNum);
	if(menu_file.is_open()){
		for(int i = 0; i < num_pizzas; i++){
			pizza_to_load.load_pizza_info(menu_file);			
		}
	}
	
}
/*void Menu::remove_from_menu(int index_of_pizza_on_menu)
{

}*/	
void Menu::print_menu(Pizza& pizza_to_show)
{
		for(int i = 0; i < num_pizzas; i++){
			pizza_to_show.print_pizza();
		}

}

