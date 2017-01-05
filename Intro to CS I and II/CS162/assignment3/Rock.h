#include <iostream>
#include "./Tool.h"

class Rock : public Tool{
	public:
		Rock();
		Rock(int);
		bool fight(Tool);		
		~Rock();

}; 
