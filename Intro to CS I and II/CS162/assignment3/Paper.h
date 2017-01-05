#include <iostream>
#include "./Tool.h"

class Paper : public Tool{
        public:
                Paper();
                Paper(int);
		bool fight(Tool);


};

