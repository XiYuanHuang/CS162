#include <iostream>
#include <string.h>

using namespace std;


int main(int argc, char *argv[]){
#ifdef DEBUG
	//char *input = NULL;
	char input[50];
	int i = 0;
	cin >> input;
	cout << "Debugging on" << endl;
	for(i = strlen(input); i >= 0; i--){
		 cout << input[i];
	}
	cout << endl;
#else
	cout << "Debugging off!" << endl;
#endif
	return 0;
}

