#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "pizza.h"

using namespace std;



Pizza::Pizza()
{
	name = " ";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;
}
/*Pizza::Pizza()
{


}*/
void Pizza::load_pizza_info(ifstream &f)
{
	name << f;
	small_cost << f;
	medium_cost << f;
	large_cost << f;
	num_ingredients << f;			
	ingredients = new string[num_ingredients];
		for(int j = 0; j < num_ingredients; j++){
			ingredients[j] << f;
		}
	
}	
Pizza::~Pizza()
{
	delete [] ingredients;
	ingredients = NULL;
}
Pizza::Pizza(const Pizza &copy)
{
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	ingredients = new string[num_ingredients];
	for(int i = 0; i < num_ingredients; i++){
		ingredients[i] = copy.ingredients[i];
	}				
}
void Pizza::print_pizza()
{
	cout << name << endl;
	cout << small_cost << endl;
	cout << medium_cost << endl;
	cout << large_cost << endl;
	cout << num_ingredients << endl;
	for(int i = 0; i < num_ingredients; i++){
		cout << ingredients[i] << endl;
	} 
}
Pizza::Pizza & operator = (const Pizza &copy)
{
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	delete [] ingredients;
	ingredients = new string[num_ingredients];
	for(int i = 0; i < num_ingredients; i++){
		ingredients[i] = copy.ingredients[i];
	}				

}
void Pizza::set_name(string newName)
{
	name = newName;
}
string Pizza::get_name()
{
	return name;
}
void Pizza::set_small_cost(int new_small_cost)
{
	small_cost = new_small_cost;
}
int Pizza::get_small_cost()
{
	return small_cost;
}
void Pizza::set_medium_cost(int new_medium_cost)
{
	medium_cost = new_medium_cost;
}
int Pizza::get_medium_cost()
{
	return medium_cost;	
}
void Pizza::set_large_cost(int new_large_cost)
{
	large_cost = new_large_cost;
}
int Pizza::get_large_cost()
{
	return large_cost;	
}
void Pizza::set_num_ingredients(int new_num_ingredients)
{
	num_ingredients = new_num_ingredients;
}
int Pizza::get_num_ingredients()
{
	return num_ingredients;
}
string* Pizza::get_ingredients()
{
	return ingredients;
}
void Pizza::set_ingredients(string* new_ingredients)
{
	for(int i = 0; i < get_num_ingredients(); i++){ 
		ingredients[i] = new_ingredients;
	}
}	
