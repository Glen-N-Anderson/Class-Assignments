/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>

using namespace std;
void towers(int disks, int b[][COLS], int from_col, int to_col, int spare);


int main() {



	return 0;
}
void towers(int disks, int b[][COLS], int from_col, int to_col, int spare){
	if ( disks >= 1 )
	{
	
		towers(disks-1, b, from_col, spare, to_col);
		move( b, from_col, to_col);
		print( b, rows );
		towers(disks-1, b, spare, to_col, from_col);
	
	}
}

void print(b, rows){



}
void move(int disks, int b[][COLS], int from_col, int to_col, int spare){






}	
