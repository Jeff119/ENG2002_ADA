#include <iostream>
#include "complexValue.h"
#include "Login.h"
using namespace std;
bool trylogin();
bool menu();
void ComplexNumdisvision();
void ComplexNumSR();
void printComplexNum(complexNum obj);
int main() {
	//login system
	if (trylogin() == false) 
		return 0; 
	cout << endl; //separate 2 systems

	//complex number algorithm controlled by menu
	cout << "      Welcome to the Complex Number Algorithm      " << endl;
	bool exitflag = false;
	while (exitflag == false)
		exitflag = menu();
	return 0;
	
}

bool trylogin() {
	Login login;
	char uName[50], uPass[50];
	cout << "Please log in before starting the complex number algorithm. " << endl;
	cout << "Username: ";
	cin.getline(uName, 50);
	cout << "Password: ";
	cin.getline(uPass, 50);

	if (login.find(uName) == false) { //find the name in the file and check the existence of the user name 
		cout << "No this user! Create a new user? (y/n) ";
		
		char choice;
		do {
			cin >> (choice);
			if (choice == 'y') { //create a new user
				login.add(uName, uPass); //add the user name and password
				login.write(); //write the data to the file
				cout << "Created sucessfully! " << endl;
				cout << "Welcome " << uName << "!. " << endl;
			}
			else if (choice == 'n') 
				return false; 
			else { //if the user does not input y/n 
				cout << "Wrong input! Plase enter again: ";
			}
		} while (choice != 'y' && choice != 'n');
	}
	else {
		int attempt = 2; //2 more attempts for the user to try the password
		while (attempt >= 0) { //the function will end when attempts = 0 
			if (login.check(uName, uPass) == true) { //check the password that enter by the user
				cout << "Login successfully! " << endl;
				cout << "Welcome " << uName << "! " << endl;
				break; //stop the loop
			}
			else {
				cout << attempt << " attempt left! " << endl; //tell the user how many attempts left
				if (attempt == 0) { //end the loop when no attempt
					cout << "No attempt left! The program will end. " << endl;
					return false; 
				}
				cout << "Please try again: ";
				cin.getline(uPass, 50);
				attempt--;
			}
		}
	}
	return true;
}

bool menu() {
	char choice; 
	cout << "==================== MAIN MENU ====================" << endl
		<< "1. Calculate the division of the complex numbers" << endl
		<< "2. Calculate the square root of the complex number" << endl
		<< "3. Quit" << endl
		<< "===================================================" << endl
		<< "Please enter your choice: ";
	cin >> choice; 
	switch (choice) {
	case '1': 
		ComplexNumdisvision(); 
		break;
	case '2':
		ComplexNumSR();
		break;
	case '3':
		cout << "The algorithm ends." << endl;
		return true;
	default: 
		cout << "Invaild Input, Please enter again." << endl; 
	}
	return false;
}

//disvision of complex Number
void ComplexNumdisvision() {
	double x1, y1, x2, y2; //declare the variables
	//First complex number
	cout << "Please enter the first complex number(real, imaginary): ";
	do {  // check the input value
		cin >> x1 >> y1;
		complexNum c1(x1, y1);
		c1.checkVaild();
		if (c1.ReaderrNum()) { //check the operand 
			cout << "The complex number cannot be 0! Please enter again: ";
		}
	} while (x1 == 0 && y1 == 0); //loop break if x1 and y1 not equal to 0
	complexNum c1(x1, y1);
	cout << "The first complex number is ";
	printComplexNum(c1);

	//Second complex number
	cout << "Plesae enter the complex number to be divided(real, imaginary): ";
	do { // check the input value
		cin >> x2 >> y2;
		complexNum c2(x2, y2);
		c2.checkVaild(); //check the operand 
		if (c2.ReaderrNum()) {
			cout << "This complex number cannot be 0! Please enter again: ";
		}
	} while (x2 == 0 && y2 == 0); //loop break if x2 and y2 not equal to 0
	complexNum c2(x2, y2);
	cout << "The complex number to be divided is ";
	printComplexNum(c2);

	//Division of 2 complex number
	complexNum div = div.division(c1, c2);
	cout << "The result is ";
	printComplexNum(div);
}

//Compute the square root of the complex number
void ComplexNumSR() {
	double x, y; 
	cout << "Please enter the complex number(real, imaginary): ";
	cin >> x >> y;
	complexNum c(x, y);
	complexNum SRresult = SRresult.squareroot(c);
	cout << "The result is ";
	printComplexNum(SRresult);
}

//display the complex number in different condition
void printComplexNum(complexNum obj) {
	if (obj.GetImNum() > 0 && obj.GetReNum() != 0)
		cout << obj.GetReNum() << "+" << obj.GetImNum() << "i " << endl; //print out the positive sign
	if (obj.GetImNum() < 0 && obj.GetReNum() != 0) //if imaginary part is negative
		cout << obj.GetReNum() << obj.GetImNum() << "i " << endl; //print out the negative sign
	if (obj.GetImNum() == 0) //only the real part exist
		cout << obj.GetReNum() << " " << endl; //print out when the imaginary part is zero
	if (obj.GetReNum() == 0) //only the imaginary part exist
		cout << obj.GetImNum() << "i " << endl;//print out when the real part is zero
}
