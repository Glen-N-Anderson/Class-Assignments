/******************************************************
 **** Program: 
 **** Author: 
 **** Date:
 **** Description: 
 **** Input:
 **** Output:
 ********************************************************/



#include <iostream>
#include "./bike.h"
#include "./vehicle.h"
#include "./car.h"
#include "./motorcycle.h"
using namespace std;

int main() {
	int d, month, y;
	vehicle v(3);
	bike b(2);
	car c(5);
	motorcycle m(1);
	cout << "Set the date!" << endl << "Enter day: ";
	cin >> d;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter year: ";
	cin >> y;


	v.day.set_day(d);
	v.day.set_month(month);
	v.day.set_year(y);

	if(v.day.get_day_of_week() == 5){
		cout << "Special discount for car: " << c.get_toll()/2 << endl;
	}
	else{
		cout << "Car toll: " << c.get_toll() << endl;
	}
	if(v.day.get_day_of_week() == 0){
		cout << "Special discount for motorcycle: " << m.get_toll()/2 << endl;
	}
	else{
		cout << "Motorcyle toll: " << m.get_toll() << endl;
	}

	vehicle *vptr = &b;

	cout << "Vehicle seats: " << v.get_seats() << endl;
	cout << "Bike seats: " << b.get_seats() << endl;
	cout << "Vehicle toll: " << v.get_toll() << endl;
	cout << "Bike toll: " << b.get_toll() << endl;
	cout << "Motorcycle seats: " << m.get_seats() << endl;
	cout << vptr->get_seats() << endl;
	cout << vptr->get_toll() << endl;
	
	vehicle *v_array[4] = {new bike(1), new car(3), new motorcycle(2)};

	cout << v_array[1]->get_toll() << endl;

	

	
	return 0;
}

