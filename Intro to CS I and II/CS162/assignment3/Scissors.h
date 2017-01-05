#include <iostream>
#include "./Tool.h"

class Scissors : public Tool{
        public:
                Scissors();
                Scissors(int);
		bool fight(Tool);


};

