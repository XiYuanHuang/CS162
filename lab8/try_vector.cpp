#include "vector.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <exception>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
	vector<int> v;   //Our vector class
      	std::vector<int> stdv; //Standard vector

      //Compare operation of our vector to std
        v.push_back(23);
        stdv.push_back(23);
                 
 	cout << "Our vector size: " << v.size() << endl;
	cout << "STL vector size: " << stdv.size() << endl;

	try{
		v.at(2);	
	}catch(std::out_of_range &e){
		 cout << e.what() << endl;
	} 
return 0;
}
