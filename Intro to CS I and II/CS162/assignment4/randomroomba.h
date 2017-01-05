#include "./roomba.h"
class RandomRoomba : public Roomba {
	private:
		int r;
	public:
		RandomRoomba();
		int get_r();
		void set_rand();
};
