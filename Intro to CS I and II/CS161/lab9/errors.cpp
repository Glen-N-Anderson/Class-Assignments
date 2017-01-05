#include <iostream>
using namespace std;
bool is_equal(char *str1, char *str2){ 
 int i;
 for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++)
 if(str1[i]!=str2[i])
 return false;

 if(str1[i]!='\0' || str2[i]!='\0')
 return false;
 return true;
}
int main(int argc, char *argv[]) {
 if(argc >= 3)
 cout << is_equal(argv[1], argv[2]) << endl;
 return 0;
}
/* Removed semicolon: The line does not end, so compiler gives error that tells
 * me that I need to add one before the } bracket at the end of is_equal().
 * Removed curly brace: Lots of errors, including expected constructor, 
 * unqualified ID, and declaration. This is because the compiler is attempting 
 * to read code that has no scope, and so there will be an error for almost
 * everything inside of what the scope should be. 
 * Removed brackets: Compiler reads them as variables and throws back an error 
 * because argv1 and argv2 are not declared in that scope. 
 * Remove splat from argv: Invalid conversion from *char to char. This is 
 * because char and *char are two different types, and the prototype does
 * not match up with the function types when the * is removed.
 * Remove return type: Compiler throws error saying it forbids function without
 * a type. 
 * Remove one of the parameters: Error said the parameter was not declared in
 * scope. This is because its declaration was in the prototype. It also gave
 * error of too many arguements, because the prototype and function no longer
 * matched. 
 * Comment out declaration of i, move it to the loop: Since we also use i 
 * outside of loop, compiler gives a warning but says we can override it to
 * run the program anyway. 
 *
 * Extra splats and ampersand: Program runs, but logic error occurs. It changes
 * the values of the variables as the ampersand uses the same previous value
 * while the double splat causes it to point one more "arrow" over in memory.
 * Comment out line 10: No longer an if statement to check arguements, so 
 * program does not execute as expected. Could use gdb's display and watch 
 * functions to see what happens step by step, as this would likely make the 
 * logic error easier to find. 
 * Comment out line 16: Again, we could use gdb to discover this error by
 * using its next and step functions or by using watch and display.      
