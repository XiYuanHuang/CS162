#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::atoi;

int main(int argc, char *argv[])
{
	bool valid_input = true;
        int col = 0, row = 0;
	do{
		if(argc > 3){
			cout << "Please enter the value greater than 0 for col: " << endl;
			cin >> col;
			cout << "Please enter the value greater than 0 for row: " << endl;
			cin >> row;
			valid_input = false;
		}else{
		    cout << argv[1] << endl;
		}
	}while(valid_input == false);		
return 0;
}
