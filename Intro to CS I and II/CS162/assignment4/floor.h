#include <vector>
#include <string>
using std::vector;
using std::string;
class Floor {
	private:
		//vector < vector <char> > v;
		int obj_row; //Holds an object’s current row position
		int obj_col; //Holds an object’s current col position
		int objx;
		int objy;
	public:
		vector < vector <char> > v;

		Floor();
		void init_v(string);
		void check_edge();
		int get_objx();
		int get_objy();
		void view();

//The functionality of a floor is to create the floor
// //plan, as well as determining if an object’s
// //position is at the edge of the room
//  …
};
//
