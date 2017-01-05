#include <iostream>

int main() {
	using namespace std;
	float cereal_weight, cereal_tons, boxes, lifeboxes;
	int lifespan, weekly;
	
	cout << "Enter the weight (ounces) of a box of cereal: ";
	cin >> cereal_weight;
	cereal_tons = cereal_weight / 35273.92;
	boxes = 1 / cereal_tons;
	cout << "Enter the number of boxes eaten per week: ";
	cin >> weekly;
	cout << "Enter your expected lifespan: ";
	cin >> lifespan;
	lifeboxes = lifespan * 52.1775 * weekly;
	cout << "Weight in tons: " << cereal_tons << endl;
	cout << "Number of boxes for a ton: " << boxes << endl;
	cout << "Number of boxes for life: " << lifeboxes << endl;
	
	
	return 0;
}
