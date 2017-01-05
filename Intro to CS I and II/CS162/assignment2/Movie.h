#include <iostream>
#include <string>
using namespace std;
class Movie{
	public:
		Movie();//default constructor
		~Movie(); //DESTRUCTOR
		int getNum();
		string getName();
		int getStars();
		int getNumCast();
		string* getCast();
		string getRating();
		int getCopies();
		

		void setNum();//accessor functions
		void setName();//title
		void setStars();//stars(rating)
		void setNumCast();//number of cast members
		void setCast();//creates array holding names of cast members
		void setRating();//Age reccomendation i.e. PG, PG13, R
		void setCopies();//end accessors	

		void checkInfo();//error handling
		void addMovie();//adds movies to database
	private:
		int num;
		string name;
		int stars;
		int numCast;
		string *cast;
		string rating;
		int copies;
};


