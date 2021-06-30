/*********************************************************************
 * ** Program Filename:game.h
 * ** Author:XiYuan Huang
 * ** Date:11/25/2018
 * ** Description:This is the header file of game class
 * ** Input:N/A
 * ** Output:N/A
 * *********************************************************************/
#ifndef GAME_H
#define GAME_H

#include "bee.h"
#include "ant.h"
#include "childant.h"

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct board
{
	vector<ant*> ants;
	vector<bee*> bees;
};

class game
{
	private:
		board* array;
		int food_bank;
		harvester* h;
		thrower* t;
		fire* f;
		long_thrower* l;
		short_thrower* s;
		wall* w;
		ninja* n;
		bodyguard* g;
		bee* b;	
	public:
		game();
		~game();
		int get_food_bank();
		void set_food_bank(int);
		void user_menu();
		void menu();
		bool check_input(int);
		void print_ant();
		void print_bee();
		void print_board();
		void add_ant();
		void add_harvester(int, int);
		void check_harvester();
		void add_thrower(int, int);
		void add_fire(int, int);
		void add_long_thrower(int, int);
		void add_short_thrower(int, int);
		void add_wall(int, int);
		void add_ninja(int, int);
		void add_bodyguard(int, int);
		void ant_information();
		bool check_ant_type(int, int);
		void put_ant(int, int);
		void ant_food_cost(int);
		void add_bee();
		void move_bee();
		void check_bee();
		void bee_attack();
		void check_ant();
		void ant_attack();
		void long_thrower_attack(int);
		void short_thrower_attack(int);
		void fire_attack(int);		
		void check_fire();
		void thrower_attack(int);
		void ninja_attack(int);
		bool bee_winner();
		bool ant_winner();
		//void delete_vector();
};

#endif 
