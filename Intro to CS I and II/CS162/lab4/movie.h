#include <iostream>
#include <string>
#ifndef MOVIE_H
#define MOVIE_H
using namespace std;
class movie {
	public:
		movie();
		movie(int); //This will set num_cast and create cast array
		 //Define any other constructors and the Big Three
		movie(const movie&);
		~movie();	
		void getCast();	
	private:
		string name;
		int stars;
		int num_cast;
		string *cast; //This is a dynamic array of strings
		string rating;
		int copies;
};
#endif 
