#include <iostream>
#include "complexValue.h"
using namespace std;


int main() {
	double x1, y1, x2, y2; //declare the variables 

	//The first complex number
	cout << "Please enter the first complex number: ";
	cin >> x1 >> y1;
	do {  // check the input value 
		complexNum c1(x1, y1);
		c1.checkVaild(); 
		if (c1.ReaderrNum()) {
			cout << "Wrong input! Please enter again: ";
			cin >> x1 >> y1;
		}
	} while (x1 == 0 || y1 == 0); //loop break if x1, y2 not equal to 0
	complexNum c1(x1, y1);
	if (c1.GetImNum() < 0) //if imaginary part is negative 
		cout << "The first complex number is " << c1.GetReNum() << c1.GetImNum() << "i. " << endl; //print out the negative sign
	else 
		cout << "The first complex number is " << c1.GetReNum() << "+" << c1.GetImNum() << "i. " << endl; //print out the positive sign

	//The second complex number
	cout << "Plesae enter the second complex number: ";
	cin >> x2 >> y2;
	do { // check the input value
		complexNum c2(x2, y2);
		c1.checkVaild();
		if (c1.ReaderrNum()) {
			cout << "Wrong input! Please enter again: ";
			cin >> x2 >> y2;
		}
	} while (x2 == 0 || y2 == 0); //loop break if x1, y2 not equal to 0
	complexNum c2(x2, y2);
	if (c2.GetImNum() < 0) //if imaginary part is negative 
		cout << "The first complex number is " << c2.GetReNum() << c2.GetImNum() << "i. " << endl; //print out the negative sign
	else
		cout << "The first complex number is " << c2.GetReNum() << "+" << c2.GetImNum() << "i. " << endl; //print out the positive sign
	
	//Division of 2 complex number
	double x3 = 0, y3 = 0; //declare and initalize for c3 
	complexNum c3(x3, y3); //inital object to use the function
	complexNum c4 = c3.division(c1, c2); //store the return object to object c4 
	cout << "The division result is " << c4.GetReNum() << "+" << c4.GetImNum() << "i." << endl;
	return 0;
}