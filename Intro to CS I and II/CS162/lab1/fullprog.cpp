/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>
#include <cstring>



using namespace std;

bool is_valid_dimensions(char *m, char *n);
struct mult_div_values** create_table(char *m, char *n);
void set_mult_values(int **array, int rows, int cols);
void set_div_values(int **array, int rows, int cols);

struct mult_div_values{
	int mult;
	float div;
};

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
 


bool is_valid_dimensions(char *m, char *n){ 
	while((*m <= '0' || *m >= '9') && (*n <= '0' || *n >= '9')){
		cout << "Enter valid integer for m: " << endl;
		cin >> *m;
		cout << "Enter valid integer for n: " << endl;
		cin >> *n;
	}
	return 1;
}
struct mult_div_values** create_table(char *m, char *n){
	int rows, cols;
	rows = *m - '0' + 1;
	cols = *n - '0' + 1;

	int **array = new int *[rows];
	for(int i = 0; i < rows; i++){
		array[i] = new int[cols];
	}	
	set_mult_values(array, rows, cols);
}
void set_mult_values(int **array, int rows, int cols){
	cout << "Multiplication table: " << endl;	
	for(int i = 1; i < rows; i++){
		for(int j = 1; j < cols; j++){	
		 	array[i][j] = i * j;
			cout << array[i][j] << "\t";
		}	
	cout << endl;
	}	
	set_div_values(array, rows, cols);
}
void set_div_values(int **array, int rows, int cols){
	cout << "Division table: " << endl;
	for(int i = 1; i < rows; i++){
                for(int j = 1; j < cols; j++){
                        array[i][j] = i / j;
                        cout << array[i][j] << "\t";
                }
        cout << endl;
        }
}




