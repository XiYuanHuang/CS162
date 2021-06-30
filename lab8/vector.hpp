#include <iostream>
#include<stdexcept>
#include <stdlib.h>
#include <exception>

using std::cout;
using std::endl;
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	  
      ~vector(){
	     delete [] v;
      }
      vector(const vector<T> &other){
	 s = other.s;
	 v = new T[s];
	 for(int i = 0; i < s; i++){
		v[i] = other.v[i];	
	 }		
      }	
      void operator = (const vector<T> &other){
	 s = other.s;
	 if(v != NULL){
		delete [] v;
	 }	
	 v = new T[s];
	 for(int i = 0; i < s; i++){
		v[i] = other.v[i];		
	 }
      }  
      int size() {
	     return s;
      }
      T operator[] (int n){
		return v[n];
      }
      T at(int n){
		cout << n << " s " << s  << endl;
		if(n < s){
			return v[n];
		}else{
			throw std::out_of_range("out of my vector bounds");
		}
      }	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
	     cout << "size is " << s << endl;
      }
};
