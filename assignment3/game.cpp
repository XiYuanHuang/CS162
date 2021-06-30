/*********************************************************************
 * ** Program Filename:game.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the main class of the tycoon game. It 
 * 	provides the menu for the player and output the result as the player wish
 * ** Input:the user input(It will be number all the time)
 * ** Output:the result as the player excepted
 * *********************************************************************/
#include "game.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/*********************************************************************
 * ** Function:Game()
 * ** Description:This is the constructor of game class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Game::Game()
{
	l = new Property* [3];
	l[0] = new House[3];
	l[1] = new Apartment[3];
	l[2] = new Business[3];	
	p = new Property* [3];
	p[0] = new House[100];
	p[1] = new Apartment[100];
	p[2] = new Business[100];
	info_house = 0;info_apartment = 0;
	info_business = 0;
	type_property = 0;property_locate = 0;
	current_house = 0;current_apartment = 0;
	current_business = 0; money = 500000;	
	turn = 0;user_turn = 0;	
}
/*********************************************************************
 * ** Function:~Game()
 * ** Description:This is the destructor of game class
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
Game::~Game()
{
	if(l != NULL){
		for(int i = 0; i < 3; i++)
		{
			if(l[i] != NULL){
				delete [] l[i];
			}
		}
		delete [] l;
		l = NULL;
	}
	if(p != NULL){
		for(int i = 0; i < 3; i++)
		{
			if(p[i] != NULL){
				delete [] p[i];
			}
		}
		delete [] p;
		p = NULL;
	}
}
/*********************************************************************
 * ** Function:get_money()
 * ** Description:This the accessor of money
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
float Game::get_money()
{
	return money;
}
/*********************************************************************
 * ** Function:get_turn()
 * ** Description:This is the accessor of turn
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
int Game::get_turn()
{
	return turn;
}
/*********************************************************************
 * ** Function:set_turn(int newTurn)
 * ** Description:This is the mutator of turn
 * ** Parameters:int newTurn
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::set_turn(int newTurn)
{
	turn = newTurn;
}
/*********************************************************************
 * ** Function:main_user()
 * ** Description:This is the menu of tycoon game
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::main_user()
{ 	int user_input = 0;bool winner = false;
	cout << "Welcome to real estate tycoon!" << endl;
	build_property();
	do{	
		replace_info_property();
		cout << "/***************************************/" << endl; 
		cout << "This is " << get_turn() << " turn" << endl;
		cout << "Your bank account balance is " << get_money() << endl;
		menu();
		cin >> user_input;
			switch(user_input){
				case 1:buy_property();break;
				case 2:sell_property();winner = check_winner();break;
				case 3:adjust_rent();break;
				case 4:print_user_property();break;
				case 5:auto_event();winner = check_winner();break;
				case 6:user_input = 6;break;
				default:
					cout << "Please enter the correct value" << endl;
			}
			if(user_input == 6){
				cout << "You quit the game" << endl;break;}
			if(winner == true){
				cout << "You are the winner!!!" << endl;break;}
	}while(user_input != 6);	
}
/*********************************************************************
 * ** Function:auto_event()
 * ** Description:This function will run all the random and auto events
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::auto_event()
{
	user_turn += 1;
	count_turn +=1;
	set_turn(user_turn);
	add_rent();
	if(count_turn == 12){
		add_property_tax();
		count_turn = 0;
	}
	add_value();
	add_mortgage();
	rand_event();

}
/*********************************************************************
 * ** Function:add_value()
 * ** Description:This function increases the value of each property
 * 	by 1% after the turn over.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_value()
{
	float add_value = 0;
	for(int i = 0; i < current_house; i++){
		add_value = (p[0][i].get_value() * 0.01) + p[0][i].get_value();
		p[0][i].set_value(add_value);
	}	
	for(int i = 0; i < current_apartment; i++){
		add_value = (p[1][i].get_value() * 0.01) + p[1][i].get_value();
		p[1][i].set_value(add_value);
	}
	for(int i = 0; i < current_business; i++){
		add_value = (p[2][i].get_value() * 0.01) + p[2][i].get_value();
		p[2][i].set_value(add_value);
	}


}
/*********************************************************************
 * ** Function:add_property_tax()
 * ** Description:This function adds the property tax of each property
 * 	to the user's bank account after 12 turns
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_property_tax()
{
	float total_property_tax = 0;
	float user_money = 0;
	for(int i = 0; i < current_house; i++){
		total_property_tax += p[0][i].get_property_tax();
	}	
	for(int i = 0; i < current_apartment; i++){
		total_property_tax += p[1][i].get_property_tax();
	}
	for(int i = 0; i < current_business; i++){
		total_property_tax += p[2][i].get_property_tax();
	}
	cout << "/****************************************/" << endl;
	cout << "total_property_tax " << total_property_tax << endl;
	user_money = money - total_property_tax;
	money = user_money;
 
}
/*********************************************************************
 * ** Function:check_winner()
 * ** Description:This function checks whether the player's bank account
 * 	balance reaches 1 million.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
bool Game::check_winner()
{
	if(money > 1000000){
		return true;
	}
	return false;
}
/*********************************************************************
 * ** Function:menu()
 * ** Description:The function prints out the main menu for the player
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::menu()
{
	cout << "What do you want to do? (Enter the number below) " << endl;
	cout << "1.Buy property" << endl;
	cout << "2.Sell property" << endl;
	cout << "3.adjust rent of a property" << endl;
	cout << "4.Check you properties" << endl;
	cout << "5.Next turn" << endl;
	cout << "6.Quit" << endl;
}
/*********************************************************************
 * ** Function:add_mortgage()
 * ** Description:This function adds the mortgage of all properties
 * 	to the user's bank account after a turn over.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_mortgage()
{
	float total_mortgage = 0;
	float user_money = 0;
	for(int i = 0; i < current_house; i++){
		total_mortgage += p[0][i].get_mortgage();
	}	
	for(int i = 0; i < current_apartment; i++){
		total_mortgage += p[1][i].get_mortgage();
	}
	for(int i = 0; i < current_business; i++){
		total_mortgage += p[2][i].get_mortgage();
	}
	cout << "/****************************************/" << endl;
	cout << "total_mortgage " << total_mortgage << endl;
	user_money = money - total_mortgage;
	money = user_money;
			
}
/*********************************************************************
 * ** Function:add_rent()
 * ** Description:This function add the rent of all properties to the 
 * 	user's bank account after a turn over.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_rent()
{
	float total_rent = 0;
	for(int i = 0; i < current_house; i++){	
		total_rent += p[0][i].collect_rent();
	}
	for(int i = 0; i < current_apartment; i++){
		total_rent += p[1][i].collect_rent();
	}
	for(int i = 0; i < current_business; i++){
		total_rent += p[2][i].collect_rent();
	}
	cout << "/***************************************/" << endl;	
	cout << "total_rent" << total_rent << endl;
	money += total_rent;
}
/*********************************************************************
 * ** Function:build_property()
 * ** Description:This function creates the infomation of selling properties
 * 	for the player
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::build_property()
{
	info_house = 3;
	info_apartment = 3;
	info_business = 3;
	for(int i = 0; i < 3; i++){
		((House**)l)[0][i].build_house();	
		((Apartment**)l)[1][i].build_apartment();
		((Business**)l)[2][i].build_business();
	}
}
/*********************************************************************
 * ** Function:print_info_property()
 * ** Description:This function prints out the information of selling properties
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::print_info_property()
{
	for(int i = 0; i < info_house; i++){
		cout << i+1 << " house value " << l[0][i].get_value() << " ";
		cout << " mortgage " << l[0][i].get_mortgage() << " ";
		cout << " property_tax " << l[0][i].get_property_tax() << " ";		
		cout << " location " << l[0][i].get_location() << endl;;	
	}
	for(int i = 0; i < info_apartment; i++){	
		cout << i+1 << " apartment value " << l[1][i].get_value() << " ";
		cout << " mortgage " << l[1][i].get_mortgage() << " ";
		cout << " property_tax " << l[1][i].get_property_tax() << " ";
		cout << " location " << l[1][i].get_location() << endl;;
	}
	for(int i = 0; i < info_business; i++){
		cout << i+1 << " business value " << l[2][i].get_value() << " ";
		cout << " mortgage " << l[2][i].get_mortgage() << " ";
		cout << " property_tax " << l[2][i].get_property_tax() << " ";
		cout << " location " << l[2][i].get_location() << endl;
	}

}
/*********************************************************************
 * ** Function:print_user_property()
 * ** Description:This function prints out how many properties the player own
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::print_user_property()
{
	for(int i = 0; i < current_house; i++){	
		cout << i+1 << " house value " << p[0][i].get_value() << " ";
		cout << " mortgage " << p[0][i].get_mortgage() << " ";
		cout << " property_tax " << p[0][i].get_property_tax() << " ";		
		cout << " location " << p[0][i].get_location() << endl;	
		p[0][i].print_tenants(); cout << endl;
	}
	for(int i = 0; i < current_apartment; i++){	
		cout << i+1 << " apartment value " << p[1][i].get_value() << " ";
		cout << " mortgage " << p[1][i].get_mortgage() << " ";
		cout << " property_tax " << p[1][i].get_property_tax() << " ";
		cout << " location " << p[1][i].get_location() << endl;
		p[1][i].print_tenants(); cout << endl;
	}
	for(int i = 0; i < current_business; i++){
		cout << i+1 << " business value " << p[2][i].get_value() << " ";
		cout << " mortgage " << p[2][i].get_mortgage() << " ";
		cout << " property_tax " << p[2][i].get_property_tax() << " ";
		cout << " location " << p[2][i].get_location() << endl;
		p[2][i].print_tenants(); cout << endl;
	}

}
/*********************************************************************
 * ** Function:buy_property()
 * ** Description:This function lets the player to choose which selling property
 * 	they want to buy.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::buy_property()
{
	print_info_property();
	cout << "choose which type of property you want to buy. 1.House 2.Apartment 3.Business" << endl;
	cin >> type_property;
	cout << "Which property do you want to buy? " << endl;
	cin >> property_locate;
	if(type_property == 1){
		add_house(property_locate);
	}else if(type_property == 2){
		add_apartment(property_locate);
	}else if(type_property == 3){
		add_business(property_locate);
	}else{
		cout << "Please enter the correct input!" << endl;
	}
}
/*********************************************************************
 * ** Function:add_house(int property_locate)
 * ** Description:This function adds the house which is bought by the player 
 * 	to the player's house array
 * ** Parameters:int property_locate
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_house(int property_locate)
{
	p[0][current_house] = l[0][property_locate-1];
	current_house++;
	remove_info_house();
}
/*********************************************************************
 * ** Function:add_apartment(int property_locate)
 * ** Description:This function adds the apartment which is brought by the player
 * 	to the player's apartment array
 * ** Parameters:int property_locate
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_apartment(int property_locate)
{
	p[1][current_apartment] = l[1][property_locate-1];
	current_apartment++;
	remove_info_apartment();
}
/*********************************************************************
 * ** Function:add_business(int property_locate)
 * ** Description:This function adds the business which is brought by the player 
 * 	to the player's business array.
 * ** Parameters:int property_locate
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_business(int property_locate)
{
	p[2][current_business] = l[2][property_locate-1];
	current_business++;
	remove_info_business();
}
/*********************************************************************
 * ** Function:replace_info_property()
 * ** Description:This function renews the array of selling property
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::replace_info_property()
{
	if(info_business == 0 && info_house == 0 && info_house == 0){
		for(int i = 0; i < 3; i++){
			delete [] l[i];
		}
		delete [] l;	
		l = new Property* [3];
		l[0] = new House[3];
		l[1] = new Apartment[3];
		l[2] = new Business[3];	
		info_house = 3,info_apartment = 3,info_business = 3;
		for(int i = 0; i < 3; i++){
		((House**)l)[0][i].build_house();	
		((Apartment**)l)[1][i].build_apartment();
		((Business**)l)[2][i].build_business();
		}

	}
}
/*********************************************************************
 * ** Function:remove_info_house()
 * ** Description:This function removes the house which is brought by the 
 * 	player from the selling property's array.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::remove_info_house()
{
	for(int i = property_locate; i < info_house; i++){
		l[0][i-1] = l[0][i];
	}
	info_house--;
}
/*********************************************************************
 * ** Function:remove_info_apartment()
 * ** Description:This function removes the apartment which is brought by the
 * 	player from the selling proeprty's array
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::remove_info_apartment()
{
	for(int i = property_locate; i < info_apartment; i++){
		l[1][i-1] = l[1][i];
	}
	info_apartment--;
}
/*********************************************************************
 * ** Function:remove_info_business()
 * ** Description:This function removes the business which is brought by the 
 * 	player from the selling property's array
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::remove_info_business()
{
	for(int i = property_locate; i < info_business; i++){
		l[2][i-1] = l[2][i];
	}
	info_business--;
}
/*********************************************************************
 * ** Function:sell_property()
 * ** Description:This function allows the player to sell their property
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::sell_property()
{
	print_user_property();
	cout << "choose which type of property you want to sell. 1.House 2.Apartment 3.Business" << endl;
	cin >> type_property;
	cout << "Which property do you want to sell? " << endl;
	cin >> property_locate;
	if(type_property == 1){
		if(p[0][property_locate-1].get_num_tenant() == 0){
			add_house_value();
			subtract_user_house();
		}else{cout << "This house still has tenant" << endl;}
	}else if(type_property == 2){
		if(p[1][property_locate-1].get_num_tenant() == 0){
			add_apartment_value();
			subtract_user_apartment();
		}else{cout << "This apartment still has tenant" << endl;}
	}else if(type_property == 3){
		if(p[2][property_locate-1].get_num_tenant() == 0){
			add_business_value();
			subtract_user_business();
		}else{cout << "This business still has tenant" << endl;}
	}else{cout << "Please enter the correct input!" << endl;}
}
/*********************************************************************
 * ** Function:add_house_value()
 * ** Description:This function will produce a random price for the 
 * 	house which is selled by the player
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_house_value()
{
	float house_value = 0, user_input = 0;int rand_price = 0;
	cout << "Please enter the value you want" << endl;
	cin >> user_input;
	rand_price = rand()%3 + 1;
	switch(rand_price){
		case 1: house_value = user_input;
			cout << "You get the wish price" << endl; 
			break;
		case 2: house_value = p[0][property_locate-1].get_value();
			cout << "You get the price of this house value" << endl;
			break;
		case 3: house_value = (p[0][property_locate-1].get_value() * 0.9);
			cout << "You get 10% less than the property value" << endl;
			break;
		default:
			cout << "the rand number is not correct" << endl;
	}
	money = money + house_value;
}
/*********************************************************************
 * ** Function:add_apartment_value()
 * ** Description:This function will produce a random price for the 
 * 	apartment which is selled by the player
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_apartment_value()
{
	float apartment_value = 0, user_input = 0;int rand_price = 0;
	cout << "Please enter the value you want" << endl;
	cin >> user_input;
	rand_price = rand()%3 + 1;
	switch(rand_price){
		case 1: apartment_value = user_input;
			cout << "You get the wish price" << endl;
			break;
		case 2: apartment_value = p[1][property_locate-1].get_value();
			cout << "You get the price of the apartment value" << endl;
			break;
		case 3: apartment_value = (p[1][property_locate-1].get_value() * 0.9);
			cout << "You get 10% less than the property value" << endl;
			break;
		default:
			cout << "the rand number is not correct" << endl;
	}

	money = money + apartment_value;
}
/*********************************************************************
 * ** Function:add_business_value()
 * ** Description:This function will produce a random price for the 
 * 	apartment which is selled by the player
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::add_business_value()
{
	float business_value = 0, user_input = 0;int rand_price = 0;
	cout << "Please enter the value you want" << endl;
	cin >> user_input;
	rand_price = rand()%3 + 1;
	switch(rand_price){
		case 1: business_value = user_input;
			cout << "You get the wish price" << endl;
			break;
		case 2: business_value = p[2][property_locate-1].get_value();
			cout << "You get the price of the business value" << endl;
			break;
		case 3: business_value = (p[2][property_locate-1].get_value() * 0.9);
			cout << "You get 10% less than the property value" << endl;
			break;
		default:
			cout << "the rand number is not correct" << endl;
	}

	money = money + business_value;
}
/*********************************************************************
 * ** Function:substract_user_house()
 * ** Description:This function decreases the number of house after 
 * 	the player sells a house.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::subtract_user_house()
{
	for(int i = property_locate; i < current_house; i++){
		p[0][i-1] = p[0][i];
	}
	current_house--;
}
/*********************************************************************
 * ** Function:substract_user_apartment()
 * ** Description:This function decreases the number of apartment after 
 * 	the player sells an apartment
 * ** Parameters:
 * ** Pre-Conditions:
 * ** Post-Conditions:
 * *********************************************************************/ 
void Game::subtract_user_apartment()
{
	for(int i = property_locate; i < current_apartment; i++){
		p[1][i-1] = p[1][i];
	}
	current_apartment--;
}
/*********************************************************************
 * ** Function:substract_user_business()
 * ** Description:This function decreases the number of business after
 * 	the player sells a business
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::subtract_user_business()
{
	for(int i = property_locate; i < current_business; i++){
		p[2][i-1] = p[2][i];
	}
	current_business--;
}
/*********************************************************************
 * ** Function:adjust_rent()
 * ** Description:This function allows the player to adjust the rent
 * 	of a property
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::adjust_rent()
{
	print_user_property();
	cout << "choose which type of property you want to adjust. 1.House 2.Apartment 3.Business" << endl;
	cin >> type_property;
	cout << "Which property do you want to adjust? " << endl;
	cin >> property_locate;
	if(type_property == 1){
		adjust_house_rent();	
	}else if(type_property == 2){
		adjust_apartment_rent();
	}else if(type_property == 3){
		adjust_business_rent();
	}else{
		cout << "Please enter the correct input!" << endl;
	}

}
/*********************************************************************
 * ** Function:adjust_house_rent()
 * ** Description:This function adjusts the rent of a house, which bases
 * 	on the player decision.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::adjust_house_rent()
{
	float player_rent = 0;
	cout << "enter the rent you want" << endl;	
	cin >> player_rent;
	p[0][property_locate-1].check_rent(player_rent);
	if(p[0][property_locate-1].get_num_tenant() > 0){
		p[0][property_locate-1].set_tenant_rent(player_rent);
	}	
}
/*********************************************************************
 * ** Function:adjust_apartment_rent()
 * ** Description:This function adjusts the rent of a apartment, which bases
 * 	on the player decision.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::adjust_apartment_rent()
{
	float player_rent = 0;
	cout << "enter the rent you want" << endl;	
	cin >> player_rent;
	p[1][property_locate-1].check_rent(player_rent);
	if(p[1][property_locate-1].get_num_tenant() > 0){
		p[1][property_locate-1].set_tenant_rent(player_rent);	
	}
}
/*********************************************************************
 * ** Function:adjust_business_rent()
 * ** Description:This function adjusts the rent of a business,which bases 
 * 	on the player decision
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::adjust_business_rent()
{
	float player_rent = 0;
	cout << "enter the rent you want" << endl;	
	cin >> player_rent;
	p[2][property_locate-1].check_rent(player_rent);
	if(p[2][property_locate-1].get_num_tenant() > 0){
		p[2][property_locate-1].set_tenant_rent(player_rent);	
	}
}
/*********************************************************************
 * ** Function:rand_event()
 * ** Description:This function produces a random disaster after
 * 	a turn over.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::rand_event()
{
	cout << "/**********************************/" << endl;;
	int event = 0;
	event = rand()%6 + 1;
	switch(event){
		case 1: hurricane_event();
			break;
		case 2: tornado_event();
			break;
		case 3: earthquake_event();
			break;
		case 4: wildfire_event();
			break;
		case 5: market_crash_event();
			break;
		case 6: gentrification_event();
			break;
		default:
			cout << "The rand number is not correct" << endl;
	}
	print_user_property();

}
/*********************************************************************
 * ** Function:hurricane_event()
 * ** Description:This function decreases the value of properties
 * 	which is on SE by 50%.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::hurricane_event()
{
	int total_property = 0;
	float decrease_value = 0;
	total_property = current_house + current_apartment + current_business;
	cout << "hurricane occurs in SE" << endl;
	for(int i = 0; i < total_property; i++)
	{
		if(p[0][i].get_location() == "SE"){
			decrease_value = p[0][i].get_value() * 0.5;
			p[0][i].set_value(decrease_value);
		}
		if(p[1][i].get_location() == "SE"){
			decrease_value = p[1][i].get_value() * 0.5;
			p[1][i].set_value(decrease_value);
		}
		if(p[2][i].get_location() == "SE"){
			decrease_value = p[2][i].get_value() * 0.5;
			p[2][i].set_value(decrease_value);
		}
	
	}
}
/*********************************************************************
 * ** Function:tornado_event()
 * ** Description:This function decreases the value of properties
 * 	which is on MW by 30%.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::tornado_event()
{
	int total_property = 0;
	float decrease_value = 0;
	total_property = current_house + current_apartment + current_business;
	cout << "tornado occurs in MW" << endl;
	for(int i = 0; i < total_property; i++)
	{
		if(p[0][i].get_location() == "MW"){
			decrease_value = p[0][i].get_value() * 0.7;
			p[0][i].set_value(decrease_value);
		}
		if(p[1][i].get_location() == "MW"){
			decrease_value = p[1][i].get_value() * 0.7;
			p[1][i].set_value(decrease_value);
		}
		if(p[2][i].get_location() == "MW"){
			decrease_value = p[2][i].get_value() * 0.7;
			p[2][i].set_value(decrease_value);
		}
	
	}
}
/*********************************************************************
 * ** Function:earthquake_event()
 * ** Description:This function decreases the value of properties 
 * 	which is on NW by 10%.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::earthquake_event()
{
	int total_property = 0;
	float decrease_value = 0;
	total_property = current_house + current_apartment + current_business;
	cout << "earthquake occurs in NW" << endl;
	for(int i = 0; i < total_property; i++)
	{
		if(p[0][i].get_location() == "NW"){
			decrease_value = p[0][i].get_value() * 0.9;
			p[0][i].set_value(decrease_value);
		}
		if(p[1][i].get_location() == "NW"){
			decrease_value = p[1][i].get_value() * 0.9;
			p[1][i].set_value(decrease_value);
		}
		if(p[2][i].get_location() == "NW"){
			decrease_value = p[2][i].get_value() * 0.9;
			p[2][i].set_value(decrease_value);
		}
	
	}
}
/*********************************************************************
 * ** Function:wildfire_event()
 * ** Description:This function decreases the value of properties
 * 	which is on SW by 25%.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::wildfire_event()
{
	int total_property = 0;
	float decrease_value = 0;
	total_property = current_house + current_apartment + current_business;
	cout << "wildfire occurs SW" << endl;
	for(int i = 0; i < total_property; i++)
	{
		if(p[0][i].get_location() == "SW"){
			decrease_value = p[0][i].get_value() * 0.75;
			p[0][i].set_value(decrease_value);
		}
		if(p[1][i].get_location() == "SW"){
			decrease_value = p[1][i].get_value() * 0.75;
			p[1][i].set_value(decrease_value);
		}
		if(p[2][i].get_location() == "SW"){
			decrease_value = p[2][i].get_value() * 0.75;
			p[2][i].set_value(decrease_value);
		}
	
	}
}
/*********************************************************************
 * ** Function:market_crash_event()
 * ** Description:This function decreases the value of properties
 * 	which is on all location by 30%.
 * ** Parameters: N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::market_crash_event()
{
	int total_property = 0;
	float decrease_value = 0;
	total_property = current_house + current_apartment + current_business;
	cout << "stock market crash" << " ";
	cout << "and it affects all the location" << endl;
	for(int i = 0; i < total_property; i++)
	{
		decrease_value = p[0][i].get_value() * 0.7;
		p[0][i].set_value(decrease_value);
		decrease_value = p[1][i].get_value() * 0.7;
		p[1][i].set_value(decrease_value);
		decrease_value = p[2][i].get_value() * 0.7;
		p[2][i].set_value(decrease_value);
	}
}
/*********************************************************************
 * ** Function:event_location
 * ** Description:This function will produce a location for the 
 * 	gentrification_event.
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
string Game::event_location()
{
	int event_location = rand()% 5 + 1;
	string lucky_location = " ";
	switch(event_location){
		case 1: lucky_location = "SW";
			break;
		case 2: lucky_location = "NE";
			break;
		case 3: lucky_location = "MW";
			break;
		case 4: lucky_location = "SW";
			break;
		case 5: lucky_location = "NW";
			break;
		default:
			cout << "the rand number is not correct" << endl;
	}
	return lucky_location;
}
/*********************************************************************
 * ** Function:gentrification_event()
 * ** Description:This function will choose a location and increases
 * 	the value of properties on that location by 20%
 * ** Parameters:N/A
 * ** Pre-Conditions:N/A
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void Game::gentrification_event()
{
	int total_property = 0;
	float increase_value = 0;
	total_property = current_house + current_apartment + current_business;
	cout << "gentrification!!!" << endl;
	string lucky_location = event_location();
	cout << "The lucky location is " << lucky_location << endl;
	for(int i = 0; i < total_property; i++)
	{
		if(p[0][i].get_location() == lucky_location){
			increase_value = p[0][i].get_value() * 1.2;
			p[0][i].set_value(increase_value);
		}
		if(p[1][i].get_location() == lucky_location){
			increase_value = p[1][i].get_value() * 1.2;
			p[1][i].set_value(increase_value);
		}
		if(p[2][i].get_location() == lucky_location){
			increase_value = p[2][i].get_value() * 1.2;
			p[2][i].set_value(increase_value);
		}
	
	}
}

