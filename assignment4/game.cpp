/*********************************************************************
 * ** Program Filename:game.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/25/2018
 * ** Description:This is the main class of the game, and all the functions
 * 	will be called and used here.
 * ** Input:user's option
 * ** Output:It depends on the user's option
 * *********************************************************************/
#include "game.h"

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*********************************************************************
 * ** Function:game()
 * ** Description:This is the default constructor of game class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
game::game()
{
	array = new board[10];
	food_bank = 50;
}
game::~game()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].ants.size(); j++){
			if(array[i].ants.size() > 0){	
				delete array[i].ants[j];
				
			}
			array[i].ants[j] = NULL;
		}
		for(int k = 0; k < array[i].bees.size(); k++){
			if(array[i].bees.size() > 0){
				delete array[i].bees[k];
			
			}
			array[i].bees[k] = NULL;
		}
		
	}
	/*if(h != NULL){
		delete h;h = NULL;
	}
	if(f != NULL){
		delete f;f = NULL;}
	if(t != NULL){
		delete t;t = NULL;}
	if(l !=NULL){
		delete l;l = NULL;}
	if(s != NULL){
		delete s;s = NULL;}
	if(w != NULL){
		delete w;w = NULL;}
	if(n != NULL){
		delete n;n = NULL;}
	if(g != NULL){
		delete g;g = NULL;}*/
	
	delete [] array;
	
}
/*********************************************************************
 * ** Function:get_food_bank()
 * ** Description:This is the accessor of food_bank
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int game::get_food_bank()
{
	return food_bank;
}
/*********************************************************************
 * ** Function:set_food_bank(int new_food_bank)
 * ** Description:This is the mutator of food_bank
 * ** Parameters:int new_food_bank
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::set_food_bank(int new_food_bank)
{
	food_bank = new_food_bank;
}
/*********************************************************************
 * ** Function:user_menu()
 * ** Description:This is the main part of the game
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::user_menu()
{
	int user_option = 0, turn = 0;
	bool ant_win = false, bee_win = false, check_user_input = false;
	cout << "Welcome Ants vs. Bees" << endl;
	do{
		cout << "This is " << turn << " turn" << endl;add_bee();
		cout << "After add a bee" << endl; print_board();
		cout << "food in the food bank is " << food_bank << endl;
		do{menu();cin >> user_option;check_user_input = check_input(user_option);
			if(user_option == 1){
				do{
					cout << "food in the food bank is " << food_bank << endl;add_ant();
					do{	cout << "Do you want to add more?(Yes:1 or No:2) " << endl;
						cin >> user_option;check_user_input = check_input(user_option);
					}while(check_user_input == false);
				}while(user_option == 1);}}while(check_user_input == false);
		ant_attack();bee_attack();check_harvester();	
		cout << "After the attack of ant and bee" << endl;
		print_board();print_bee();
		move_bee();
		bee_win = bee_winner();ant_win = ant_winner();
		if(bee_win == true){break;}
		if(ant_win == true){break;}
		cout << "After the bee move" << endl;print_board();turn++;		
	}while(ant_win == false && bee_win == false);
}
/*********************************************************************
 * ** Function:check_input(int user_input)
 * ** Description:This function checks the user's input in the menu
 * ** Parameters:int user_input
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
bool game::check_input(int user_input)
{
	if(user_input == 1 || user_input == 2){
		return true;
	}
	return false;
}
/*********************************************************************
 * ** Function:menu()
 * ** Description:This function includes the information of the menu
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::menu()
{
		cout << "what do you want to do? " << endl;
		cout << "1.add an ant on the board " << endl;
		cout << "2.next turn" << endl;

}
/*********************************************************************
 * ** Function:add_ant()
 * ** Description:This function adds an ant on the board
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_ant()
{
	print_board();
	int ant_position = 0, ant = 0;
	do{
		cout << "which position do you want to put ant? (1 to 8) " << endl;
		cin >> ant_position;
	}while(ant_position < 1 || ant_position > 8); 
	do{
		cout << "what kinds of ant do you want? (1 to 8)" << endl;
		ant_information();
		cin >> ant;
	}while(ant < 1 || ant > 8);
	
	put_ant(ant_position, ant);
	
}
/*********************************************************************
 * ** Function:ant_information()
 * ** Description:This function includes the information of all 
 * 	different kinds of ant
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::ant_information()
{
	cout << "1.Harvester" << endl;
	cout << "2.Thrower" << endl;
	cout << "3.Fire" << endl;
	cout << "4.Long Thrower" << endl;
	cout << "5.Short Thrower" << endl;
	cout << "6.Wall" << endl;
	cout << "7.Ninja" << endl;
	cout << "8.Bodyguard" << endl;
}
/*********************************************************************
 * ** Function:add_harvest(int ant_position, int ant)
 * ** Description:This function adds a harvester on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_harvester(int ant_position, int ant)
{
	if(food_bank >= 2){
		array[ant_position].ants.push_back(new harvester);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}
}
/*********************************************************************
 * ** Function:check_harvester()
 * ** Description:This function adds the food from the harvesters to 
 * 	the food bank
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::check_harvester()
{
	int num_harvester = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].ants.size(); j++){
			if(array[i].ants.at(j)->get_name() == "H"){
				num_harvester++;
			}
		}
	}
	food_bank = food_bank + num_harvester;
}
/*********************************************************************
 * ** Function:add_thrower(int ant_position, int ant)
 * ** Description:This function adds a thrower on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_thrower(int ant_position, int ant)
{
	if(food_bank >= 4){	
		array[ant_position].ants.push_back(new thrower);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}
}
/*********************************************************************
 * ** Function:add_fire(int ant_position, int ant)
 * ** Description:This function adds a fire on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_fire(int ant_position, int ant)
{
	if(food_bank >= 4){
		array[ant_position].ants.push_back(new fire);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}
}
/*********************************************************************
 * ** Function:add_long_thrower(int ant_position, int ant)
 * ** Description:This function adds a long thrower on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_long_thrower(int ant_position, int ant)
{
	if(food_bank >= 3){
		array[ant_position].ants.push_back(new long_thrower);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}
}
/*********************************************************************
 * ** Function:add_short_thrower(int ant_position, int ant)
 * ** Description:This function adds a short thrower on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_short_thrower(int ant_position, int ant)
{
	if(food_bank >= 3){
		array[ant_position].ants.push_back(new short_thrower);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}
}
/*********************************************************************
 * ** Function:add_wall(int ant_position, int ant)
 * ** Description:This function adds a wall on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_wall(int ant_position, int ant)
{
	if(food_bank >= 4){
		array[ant_position].ants.push_back(new wall);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}

}
/*********************************************************************
 * ** Function:add_ninja(int ant_position, int ant)
 * ** Description:This function adds a ninja on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_ninja(int ant_position, int ant)
{
	if(food_bank >= 6){
		array[ant_position].ants.push_back(new ninja);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}

}
/*********************************************************************
 * ** Function:add_bodyguard(int ant_position, int ant)
 * ** Description:This function adds a bodyguard on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_bodyguard(int ant_position, int ant)
{
	if(food_bank >= 4){	
		array[ant_position].ants.push_back(new bodyguard);
		ant_food_cost(ant);
	}else{
		cout << "food is not enough" << endl;
	}
}
/*********************************************************************
 * ** Function:put_add(int ant_position, int ant)
 * ** Description:This is the main funciton of adding an ant on the board
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::put_ant(int ant_position, int ant)
{
	if(ant == 1){
		if(check_ant_type(ant_position, ant) == true){
			add_harvester(ant_position, ant);}	
	}else if(ant == 2){
		if(check_ant_type(ant_position, ant) == true){
			add_thrower(ant_position, ant);}
	}else if(ant == 3){
		if(check_ant_type(ant_position, ant) == true){
			add_fire(ant_position, ant);}
	}else if(ant == 4){
		if(check_ant_type(ant_position, ant) == true){
			add_long_thrower(ant_position, ant);}
	}else if(ant == 5){
		if(check_ant_type(ant_position, ant) == true){
			add_short_thrower(ant_position, ant);}
	}else if(ant == 6){
		if(check_ant_type(ant_position, ant) == true){
			add_wall(ant_position, ant);}
	}else if(ant == 7){
		if(check_ant_type(ant_position, ant) == true){
			add_ninja(ant_position, ant);}
	}else if(ant == 8){
		if(check_ant_type(ant_position, ant) == true){
			add_bodyguard(ant_position, ant);}
	}
}
/*********************************************************************
 * ** Function:ant_food_cost(int ant)
 * ** Description:This function minus the food cost of an ant on the food
 * 	bank
 * ** Parameters:int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::ant_food_cost(int ant)
{
	if(ant == 1){
		//harvester h;
		//food_bank = h.cal_food_cost(food_bank);
		food_bank = food_bank - 2;
	}else if(ant == 2){
		food_bank = food_bank - 4;
	}else if(ant == 3){
		food_bank = food_bank - 4;
	}else if(ant == 4){
		food_bank = food_bank - 3;
	}else if(ant == 5){
		food_bank = food_bank - 3;
	}else if(ant == 6){
		food_bank = food_bank - 4;
	}else if(ant == 7){
		food_bank = food_bank - 6;
	}else if(ant == 8){
		food_bank = food_bank - 4;
	}
}
/*********************************************************************
 * ** Function:check_ant_type(int ant_position, int ant)
 * ** Description:This function checks the type of ant on a spot when
 * 	the user puts an ant on that spot
 * ** Parameters:int ant_position, int ant
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
bool game::check_ant_type(int ant_position, int ant)
{
	if(ant != 8){
		if(array[ant_position].ants.size() == 0){
			return true;
		}else if(array[ant_position].ants.size() == 1){
			for(int i = 0; i < array[ant_position].ants.size(); i++){
				if(array[ant_position].ants.at(i)->get_name() == "G")
					return true;
			}
		}
	}else if(ant == 8){
		if(array[ant_position].ants.size() == 0){
			return true;
		}else if(array[ant_position].ants.size() == 1){
			for(int i = 0; i < array[ant_position].ants.size(); i++){
				if(array[ant_position].ants.at(i)->get_name() != "G")
					return true;
			}
		}
	}	
	return false;
}
/*********************************************************************
 * ** Function:ant_attack()
 * ** Description:This is the main function of ant attack
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::ant_attack()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].ants.size(); j++){
		 	if(array[i].ants.at(j)->get_name() == "T"){
				thrower_attack(i);	 
			}else if(array[i].ants.at(j)->get_name() == "L"){
				long_thrower_attack(i);
			}else if(array[i].ants.at(j)->get_name() == "S"){
				short_thrower_attack(i);
			}else if(array[i].ants.at(j)->get_name() == "N"){
				ninja_attack(i);
			}
		}
	}
}
/*********************************************************************
 * ** Function:long_thrower_attack(int position)
 * ** Description:This is the attack function of long thrower
 * ** Parameters:int position
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::long_thrower_attack(int position)
{
	int new_armor = 0, attack_position = 0;
	for(int i = 4; i < 8 ; i++){
		attack_position = position + i;
		
		if(array[attack_position].bees.size() > 0 && attack_position < 10)
		{
			for(int j = 0; j < array[attack_position].bees.size(); j++){
				new_armor = array[attack_position].bees.at(j)->get_armor();
				array[attack_position].bees.at(j)->set_armor(new_armor-1);
				check_bee();
			}
			break;
		}
		
	}
		
}
/*********************************************************************
 * ** Function:short_thrower_attack(int position)
 * ** Description:This is the attack function of short thrower
 * ** Parameters:int position
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::short_thrower_attack(int position)
{
	int new_armor = 0, attack_position = 0;
	for(int i = 0; i < 3; i++){
		attack_position = position + i;
			if(array[attack_position].bees.size() > 0 && attack_position < 10){
				for(int j = 0; j < array[attack_position].bees.size(); j++){
					new_armor = array[attack_position].bees.at(j)->get_armor();
					array[attack_position].bees.at(j)->set_armor(new_armor-1);
					check_bee();
				}
				break;
			}
	}
}
/*********************************************************************
 * ** Function:ninja_attack(int position)
 * ** Description:This is the attack function of ninja
 * ** Parameters:int position
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::ninja_attack(int position)
{
	int new_armor = 0;
	for(int i = 0; i < array[position].bees.size(); i++){
		new_armor = array[position].bees.at(i)->get_armor();	
		array[position].bees.at(i)->set_armor(new_armor - 1);
		check_bee();
	}
}
/*********************************************************************
 * ** Function:fire_attack(int position)
 * ** Description:This is the attack function of fire
 * ** Parameters:int position
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::fire_attack(int position)
{
	int new_armor = 0;
	for(int i = 0; i < array[position].bees.size(); i++){
		array[position].bees.at(i)->set_armor(new_armor);		
		check_bee();
	}
}
/*********************************************************************
 * ** Function:check_fire()
 * ** Description:This function checks whether the fire can attack
 *  the bee 
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::check_fire()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].ants.size(); j++){
			if(array[i].ants.at(j)->get_name() == "F"){
				if(array[i].ants.at(j)->get_armor() == 0){
					fire_attack(i);
				}
			}
		}
	}	
}
/*********************************************************************
 * ** Function:thrower_attack(int position)
 * ** Description:This is the attack function of thrower
 * ** Parameters:int position
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::thrower_attack(int position)
{
	int new_armor = 0;
	if(array[position].bees.size() > 0){
		new_armor = array[position].bees.at(0)->get_armor();
		array[position].bees.at(0)->set_armor(new_armor-1);
		check_bee();
	}
}
/*********************************************************************
 * ** Function:check_ant()
 * ** Description:This function checks whehter the armor of an ant 
 * 	reaches zero and erases the dead ant
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::check_ant()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].ants.size(); j++){
			if(array[i].ants.at(j)->get_armor() <= 0){
				array[i].ants.erase(array[i].ants.begin() + j);

			}
		}
	}
}
/*********************************************************************
 * ** Function:add_bee()
 * ** Description:This function adds a bee on the board
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::add_bee()
{
	array[9].bees.push_back(new bee);
}
/*********************************************************************
 * ** Function:bee_attack()
 * ** Description:This is the attack function of bee
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::bee_attack()
{
	int new_armor = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].bees.size(); j++){
			if(array[i].ants.size() == 1){
				if(array[i].ants.at(0)->get_name() != "N"){
					new_armor = array[i].ants.at(0)->get_armor();
					array[i].ants.at(0)->set_armor(new_armor - 1);
				}
				check_fire();
				check_ant();
			}else if(array[i].ants.size() == 2){
				if(array[i].ants.at(1)->get_name() == "G"){
					new_armor = array[i].ants.at(1)->get_armor();
					array[i].ants.at(1)->set_armor(new_armor - 1);
				}else{
					new_armor = array[i].ants.at(0)->get_armor();
					array[i].ants.at(0)->set_armor(new_armor - 1);
				}
				check_fire();
				check_ant();
			}
		}
	}		
}
/*********************************************************************
 * ** Function:move_bee()
 * ** Description:This function moves the bee from right to left
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::move_bee()
{
	for(int i = 1; i < 10; i++){
		if(array[i].ants.size() == 0){
			for(int j = 0; j < array[i].bees.size(); j++){
				array[i-1].bees.push_back(array[i].bees.at(j));
			}
			array[i].bees.clear();
		}else if(array[i].ants.size() == 1){
			if(array[i].ants.at(0)->get_name() == "N"){
				for(int j = 0; j < array[i].bees.size(); j++){
					array[i-1].bees.push_back(array[i].bees.at(j));
				}
				array[i].bees.clear();
			}
		}
	}

}
/*********************************************************************
 * ** Function:check_bee()
 * ** Description:This function checks whether the armor of an bee 
 * 	reaches zero, and erases the dead bee
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::check_bee()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].bees.size(); j++){
			if(array[i].bees.at(j)->get_armor() <= 0){
				array[i].bees.erase(array[i].bees.begin() + j);
			}
		}
	}
}
/*********************************************************************
 * ** Function:print_ant()
 * ** Description:This function prints the information of ants on each spot
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::print_ant()
{
	cout << "ant" << endl;
	for(int i = 0; i < 10; i++){
		if(array[i].ants.size() > 0){
		for(int j = 0; j < array[i].ants.size(); i++){
			cout << "name: " << array[i].ants.at(j)->get_name() <<" ";	
			cout << "armor: " << array[i].ants.at(j)->get_armor() << " ";
			cout << "food cost: " << array[i].ants.at(j)->get_food_cost() << " ";
		}
		cout << "num_ant: " << array[i].ants.size() << endl;
		}
	}
}
/*********************************************************************
 * ** Function:print_bee()
 * ** Description:This function prints the information of bees on each spot
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::print_bee()
{
	cout << "bee" << endl;
	for(int i = 0; i < 10; i++){
		if(array[i].bees.size() > 0){
		cout << "this is " << i << " spot" << endl;
		for(int j = 0; j < array[i].bees.size(); j++){
			cout << "name: " << array[i].bees.at(j)->get_name() << " ";
			cout << "armor: " << array[i].bees.at(j)->get_armor() << " ";
		}
		cout << "num_bee: " << array[i].bees.size() << endl;
		}
	}
}
/*********************************************************************
 * ** Function:print_board()
 * ** Description:This function prints out the board with the name of 
 * 	ants and bees
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void game::print_board()
{
	cout << "/***********************************************************************/" << endl;
	for(int i = 0; i < 10; i++){
		if(i == 0){
			cout << " Queen" <<" ";
		}  
		if(array[i].ants.size() > 0){ 
		for(int j = 0; j < array[i].ants.size(); j++){
			cout << array[i].ants.at(j)->get_name() << " ";
		}
		}
		if(array[i].bees.size() > 0){
		for(int j = 0; j < array[i].bees.size(); j++){
			cout << array[i].bees.at(j)->get_name() << " ";
		}
		}
		cout << " | ";
		if(i == 9){
			cout << "Hive " << endl;
		}
	}
	cout << "/**********************************************************************/" << endl;
	
}
/*********************************************************************
 * ** Function:bee_winner()
 * ** Description:This funciton checks whether the bee is winner
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
bool game::bee_winner()
{
	if(array[0].bees.size() > 0){
		cout << "bee is the winner" << endl;
		return true;
	}
	return false;
}
/*********************************************************************
 * ** Function:ant_winner()
 * ** Description:This function checks whether the ant is winner
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
bool game::ant_winner()
{
	int num_bee = 0;
	for(int i = 0; i < 10; i++){
		if(array[i].bees.size() == 0){
			num_bee++;
		}
	}
	if(num_bee == 10){
		cout << "ant is the winner" << endl;
		return true;
	}
	return false;
}
/*********************************************************************
 * ** Function:delete_vector()
 * ** Description:This function deletes all the vector on the board
 * 	after running the program
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
/*void game::delete_vector()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i].ants.size(); j++){
			if(array[i].ants.size() > 0){	
				delete array[i].ants[j];
				
			}
			array[i].ants[j] = NULL;
		}
		for(int k = 0; k < array[i].bees.size(); k++){
			if(array[i].bees.size() > 0){
				delete array[i].bees[k];
			
			}
			array[i].bees[k] = NULL;
		}
		
	}
	
}*/
