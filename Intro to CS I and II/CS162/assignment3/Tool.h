#include <iostream>
class Tool {
	
	protected:
		//int strength;
		//char aiType;
		int srock;
		int ssci;
		int spap;

	public:
		Tool();
		Tool(char);
		void setType(char);
		
		void setStrength(int); //sets strength 
		int getStrength();
		int fight(char, char);	
		~Tool();


};
