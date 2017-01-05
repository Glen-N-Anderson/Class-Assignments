#include <iostream>
#include <cstring>
#include "./mult_div.h"


using namespace std;


int main(int argc, char *argv[]) {
	if(strcmp(argv[0], "./prog") == 0) {
		char *m, *n;		
		m = argv[1];
		n = argv[2];
		is_valid_dimensions(m, n);	
		create_table(m, n);
	}
	else {
		cout << "error" << endl;	
	}
	return 0;
}
 




