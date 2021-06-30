#include <iostream>
#include <string.h>
#include <cstdlib>
#include "mult_div.h"

using std::endl;
using std::cout;
using std::cin;
using namespace std;

bool isNonZeroInteger(char *row, char *col){
	bool rowCheck = false;
	bool colCheck = false;
	for(int i = 0 ; i <strlen(row);i++){
		if(row[i] > '0' && row [i] <= '9'){
			rowCheck = true;
		}
	}
	for(int i = 0; i < strlen(col); i++){
		if(col[i] > '0' && col [i] <= '9'){
			colCheck = true;
		}
	}
return rowCheck && colCheck;
}

mult_div_values** create_table(int r, int c){
	
mult_div_values** array = new mult_div_values*[r];
	for(int i = 0; i < c; i++){
		array[i] = new mult_div_values[i];
	}
return array;
}

void set_mult_values(mult_div_values** mult_Array, int r, int c){
		
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++){
			int product = (i+1) * (j+1);
			mult_Array[i][j].mult = product;

			cout << mult_Array[i][j].mult <<  "  ";
		}
		cout << endl;
	}


}

int main(int argc, char*argv[]){
	char *col = new char[2];
	char *row = new char[2];
	bool is_valid = false;
	while(!is_valid){
		cout << "please enter an intenger greater than 0 for column" << endl;
		cin >> col;
		cout << "please enter an integer greater than 0 for row" << endl;
		cin >> row;
	 
		if(isNonZeroInteger(row, col) == 1){
			is_valid = true;
		}else{
			cout << "Not valid inputs. Please enter non-zero integers" << endl;
		}
	}
	int rowInt = atoi(row);
	int colInt = atoi(col);
	mult_div_values** table = create_table (rowInt, colInt);
	set_mult_values(table, rowInt, colInt);

return 0;
}
