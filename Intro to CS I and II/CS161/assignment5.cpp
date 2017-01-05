/******************************************************
 **** Program: Assignment #5 
 **** Author: Glen Anderson
 **** Date: 03/04/15
 **** Description: Prints an array with values 1-50 and finds the greatest product of 4 of various shapes
 **** Input: Rows and columns for size of array, either from user or file
 **** Output: Array, max product, shape of 4 that result in max product, and the location in the array
 ********************************************************/



#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
int** create_array(int rows, int cols, int **a, int argc);
void get_input(int argc, char *argv[]);
void initialize_array(int rows, int cols, int **a);
void initialize_array2(int rows, int cols, int **a);
void greatest_product(int rows, int cols, int **a);

int main(int argc, char *argv[]) {
	int num;
	srand(time(NULL));
	num - rand() % 50 + 1; //should return ints 0-50
	get_input(argc, argv);

	return 0;
}
int** create_array(int rows, int cols, int **a, int argc){
	int **array = new int *[rows];
        for(int i = 0; i < rows; i++){
		array[i] = new int[cols];
        } 
	if(argc == 2){
		initialize_array(rows, cols, array);
	}
	else if(argc == 1){
		initialize_array2(rows, cols, array);
	}

	return array;

}


void get_input(int argc, char *argv[]){
	int rows, cols, **a;
	cout << "argv[0]" << argv[0] << endl;	
	if(argc == 2){
		if(strcmp(argv[1], "-test") == 0){

			cin >> rows;
			cin >> cols;
			a = create_array(rows, cols, a, argc);
		}
		else{
			cout << "Input error" << endl;
			exit(0);
		}
	}

	else if(argc == 1){
			cout << "enter rows(valid integer): " << endl;
        		cin >> rows;
        		cout << "enter cols(valid integer): " << endl;
        		cin >> cols;
			
		a = create_array(rows, cols, a, argc);			
			
		

	
	}
}

void initialize_array(int rows, int cols, int **a){
	int i = 0, j = 0;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			cin >> a[i][j];
		
		}
	}
	greatest_product(rows, cols, a);
}

void initialize_array2(int rows, int cols, int **a){
        int i = 0, j = 0;
        for(i = 0; i < rows; i++){
                for(j = 0; j < cols; j++){
                        a[i][j] = rand() % 50 + 1;
			cout << a[i][j] << "\t"; 
                }
	cout << endl;
	}
	greatest_product(rows, cols, a);
}






void greatest_product(int rows, int cols, int **a){
	int horizontal = 0, vertical = 0, diagonal = 0, zigzag = 0, LShape = 0, Box = 0;
	int maxh = 0, maxv = 0, maxd = 0, maxz = 0, maxb = 0, maxl = 0; 
	int largest = 0;
	string shape;
	//horizontal
        for(int i = 0; i < rows - 3; i++){
		
			for(int j = 0; j < cols; j++){
                                vertical = a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j];
				if(vertical > maxv){
                                        maxv = vertical;
				}
			}
                
	}
	//vertical
	for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols - 3; j++){
                        
                                horizontal = a[i][j] *a[i][j+1] * a[i][j+2] * a[i][j+3];
                                if(horizontal > maxh){
                                        maxh = horizontal;
                               		 
                        }
		}
        }

	//diagonal
	for(int i = 0; i < rows - 3; i++){
                
                        for(int j = 0; j < cols - 3; j++){
                                
                                        diagonal = a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3];
                                        if(diagonal > maxd){
                                                maxd = diagonal;
                                        }
                                
			}
                
        }
	//zigzag now working
	for(int i = 0; i < rows - 2; i++){
                
                        for(int j = 0; j < cols - 1; j++){
                               
                                        zigzag = a[i][j] * a[i+1][j] * a[i+1][j+1] * a[i+2][j+1];
                                        if(zigzag > maxz){
                                                maxz = zigzag;
                                        }
                                
        		}
		
	}
	//LShape now working
	for(int i = 0; i < rows - 2; i++){
                
                        for(int j = 0; j < cols - 2; j++){
                               
                                        LShape = a[i][j] * a[i+1][j] * a[i+2][j] * a[i+2][j+1];
                                        if(LShape > maxl){
                                                maxl = LShape;
                                        }
                               
					
				
			}
               
        }
	//box working
	for(int i = 0; i < rows - 2; i++){
                
                        for(int j = 0; j < cols - 2; j++){
                                
                                        Box = a[i][j] * a[i+1][j] * a[i+1][j+1] * a[i][j+1];
                                        if(Box > maxb){
                                                maxb = Box;
                                        }
                                
			}
                
        }
	largest = maxh;
	shape = "Horizontal";
        if(maxv > largest){
                largest = maxv;
                shape = "Vertical";
        }
        if(maxd > largest){
                largest = maxd;
                shape = "Diagonal";
        }
        if(maxz > largest){
                largest = maxz;
                shape = "Zigzag";
        }
        if(maxl > largest){
                largest = maxl;
                shape = "L-Shape";
        }
	if(maxb > largest){
                largest = maxb;
                shape = "Box";
	}

        cout << "Your shape is: " << shape << ".";
        cout << " Your greatest product is: " << largest << endl;

}











