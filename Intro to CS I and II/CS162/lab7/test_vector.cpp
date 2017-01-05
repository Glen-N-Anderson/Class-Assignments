#include "./vector.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main (){
	vector<int> v;   //Our vector class
	std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
	v.push_back(23);
	stdv.push_back(23);
   
        return 0;
}
