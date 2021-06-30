/*********************************************************************
 * ** Program Filename:run_tycoon.cpp
 * ** Author:XiYuan Huang
 * ** Date:11/11/2018
 * ** Description:This is the main running file of real estate tycoon
 * 	and it will call the menu from game class to start the game.	
 * ** Input: The input is the user options on the menu.
 * ** Output:It depends on the user option.
 * *********************************************************************/


#include "game.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	srand(time(NULL));

	Game player;
	player.main_user();
return 0;
}
