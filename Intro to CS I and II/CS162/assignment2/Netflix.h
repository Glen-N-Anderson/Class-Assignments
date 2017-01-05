#include <iostream>

using namespace std;
class Movie;
class Netflix{
	public:
		Netflix();
		int getNumMovies();
		void setNumMovies();	

		void searchSetup();
		void searchTitle();
		void searchStars();
		void searchCast();
		void searchRating();
	
	private:
		int numMovies;
		char *search;
};	
