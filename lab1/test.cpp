#include <iostream>
#include <string.h>
#include <cstdlib>
//#include "mult_div.h"
#include <new>

using std::cout;
using std::endl;
using std::cin;

bool is_valid_diminsions(char *m, char *n)
{
	bool rowValid = false, colValid = false;
		
		for(int i = 0; i < strlen(m);i++){
			if(m[i] >= '0' && m[i] <= '9'){
				rowValid = true;
			}
		}
		for(int i = 0; i < strlen(n); i++){
			if(n[i] >= '0' && n[i] <= '9'){
			        colValid = true;
			}
		}
	  

return rowValid && colValid;
}

int main(int argc, char* argv[]){
	
	char* row = new char[2];
	char* col = new char[2];

	if(argc <= 3){
		row = argv[1];
		col = argv[2];
		
		bool isValid = is_valid_diminsions(row, col);
				
			while(isValid == false){
				cout << "please enter an intenger greater than 0 for column" << endl;
				cin >> col;

				cout << "please enter an integer greater than 0 for row" << endl;
				cin >> row;
	 	
			if(is_valid_diminsions(row, col) == true){

				isValid = true;

			}else{

					cout << "Not valid inputs. Please enter non-zero integers" << endl;
				}
			}
		

	}	

return 0;
}

