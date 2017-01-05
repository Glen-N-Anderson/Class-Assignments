class Floor;
class Roomba {
	private:
		int battery; //how many moves it can make
		int total_moves; //total moves needed to clean
	public:
		Roomba();
		void clean_floor(Floor f);
		void move_left();
		void move_right();
		void move_up();
		void move_down();

		int get_batt();
		int get_total();



//The Roomba needs to be able to clean a floor, and
////move left, right, up, down
// …
};

