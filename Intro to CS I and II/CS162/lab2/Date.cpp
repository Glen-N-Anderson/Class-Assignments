#include "./Date.h"
#include <string>
#include <iostream>

using namespace std;

Date::Date(){
	month = "January";
	day = 1;
	year = 2001;
	num = 1;
	year2 = 01;


}

void Date::Get(){
	cout << "Enter month (number): " << endl;
	cin >> num;
	if(num == 1){
		month = "January";
	}
	else if(num == 2){
		month = "Febuary";
	}
	else if(num == 3){
		month = "March";
	}
	else if(num == 4){
		month = "April";
	}
	else if(num == 5){
		month = "May";
	}
	else if(num == 6){
		month = "June";
	}
	else if(num == 7){
		month = "July";
	}
	else if(num == 8){
		month = "August";
	}
	else if(num == 9){
		month = "September";
	}
	else if(num == 10){
		month = "October";
	}
	else if(num == 11){
		month = "November";
	}
	else if(num == 12){
		month = "December";
	}

	cout << "Enter day (number): " << endl;
	cin >> day;
	cout << "Enter year: " << endl;
	cin >> year;
	year2 = year - 2000; 		

	//print date in 3 different ways
	cout << "Date: " << endl;
        cout << day << "/" << num << "/" << year2 << endl;
        cout << month << " " << day << ", " << year << endl;
        cout << day << " " << month << " " << year << endl;


}



