#include <iostream>
#include "complexValue.h"
#include "Login.h"
using namespace std;
int loginManager();

int main() {
	//login system
	loginManager();
	cout << endl; //separate 2 systems

	//complex number algorithm
	double x1, y1, x2, y2; //declare the variables 
	//The first complex number
	cout << "Please enter the first complex number(real, imaginary): ";
	do {  // check the input value 
		cin >> x1 >> y1;
		complexNum c1(x1, y1);
		c1.checkVaild(); 
		if (c1.ReaderrNum()) {
			cout << "Wrong input! Please enter again: ";
		}
	} while (x1 == 0 && y1 == 0); //loop break if x1, y1 not equal to 0
	complexNum c1(x1, y1);
	if (c1.GetImNum() < 0 && c1.GetReNum() != 0) //if imaginary part is negative 
		cout << "The first complex number is " << c1.GetReNum() << c1.GetImNum() << "i. " << endl; //print out the negative sign
	if (c1.GetImNum() > 0 && c1.GetReNum() != 0)
		cout << "The first complex number is " << c1.GetReNum() << "+" << c1.GetImNum() << "i. " << endl; //print out the positive sign
	if (c1.GetImNum() == 0)
		cout << "The first complex number is " << c1.GetReNum() << ". " << endl; //print out when the imaginary part is zero
	if (c1.GetReNum() == 0)
		cout << "The first complex number is " << c1.GetImNum() << "i. " << endl;//print out when the real part is zero


	//The second complex number
	cout << "Plesae enter the second complex number(real, imaginary): ";
	do { // check the input value
		cin >> x2 >> y2;
		complexNum c2(x2, y2);
		c2.checkVaild();
		if (c2.ReaderrNum()) {
			cout << "Wrong input! Please enter again: ";
		}
	} while (x2 == 0 && y2 == 0); //loop break if x2, y2 not equal to 0
	complexNum c2(x2, y2);
	if (c2.GetImNum() < 0 && c2.GetReNum() != 0) //if imaginary part is negative 
		cout << "The second complex number is " << c2.GetReNum() << c2.GetImNum() << "i. " << endl; //print out the negative sign
	if (c2.GetImNum() > 0 && c2.GetReNum() != 0)
		cout << "The second complex number is " << c2.GetReNum() << "+" << c2.GetImNum() << "i. " << endl; //print out the positive sign
	if (c2.GetImNum() == 0)
		cout << "The second complex number is " << c2.GetReNum() << ". " << endl; //print out when the imaginary part is zero
	if (c2.GetReNum() == 0)
		cout << "The second complex number is " << c2.GetImNum() << "i. " << endl;//print out when the real part is zero
	

	//Division of 2 complex number
	complexNum div(0, 0); //inital object to use the function
	complexNum c4 = div.division(c1, c2);
	if (c4.GetImNum() < 0 && c4.GetReNum() != 0)
		cout << "The division result is " << c4.GetReNum() << c4.GetImNum() << "i." << endl; //print out the negative sign
	if (c4.GetImNum() > 0 && c4.GetReNum() != 0)
		cout << "The division result is " << c4.GetReNum() << "+" << c4.GetImNum() << "i." << endl; //print out the negative sign 
	if (c4.GetImNum() == 0)
		cout << "The division result is " << c4.GetReNum() << ". " << endl; // when 2 complex number is the same 
	if (c4.GetReNum() == 0)
		cout << "The division result is " << c4.GetImNum() << "i. " << endl;//print out when the real part is zero

	//the square root of the first complex number 
	complexNum sroot(0,0); //inital object to use the function
	complexNum srresult = sroot.squareroot(c1); // store the result of the comeplex number
	if (srresult.GetImNum() < 0  && srresult.GetReNum() != 0)
		cout << "The square root of the first complex number is " << srresult.GetReNum() << srresult.GetImNum() << "i. " << endl; //print out the negative sign
	if (srresult.GetImNum() > 0  && srresult.GetReNum() != 0)
		cout << "The square root of the first complex number is " << srresult.GetReNum() << "+" << srresult.GetImNum() << "i. " << endl; //print out the negative sign
	if (srresult.GetImNum() == 0)
		cout << "The square root of the first complex number is " << srresult.GetReNum() << ". " << endl; //print out the number if imaginary part is 0
	if (srresult.GetReNum() == 0)
		cout << "The square root of the first complex number is " << srresult.GetImNum() << "i. " << endl; //print out the number if real part is 0

	//the square root of the second complex number 
	complexNum sroot1(0, 0); //inital object to use the function
	complexNum srresult1 = sroot1.squareroot(c2); // store the result of the comeplex number
	if (srresult1.GetImNum() < 0  && srresult1.GetReNum() != 0)
		cout << "The square root of the second complex number is " << srresult1.GetReNum() << srresult1.GetImNum() << "i. " << endl; //print out the negative sign
	if (srresult1.GetImNum() > 0  && srresult1.GetReNum() != 0)
		cout << "The square root of the second complex number is " << srresult1.GetReNum() << "+" << srresult1.GetImNum() << "i. " << endl;//print out the negative sign
	if (srresult1.GetImNum() == 0)
		cout << "The square root of the second complex number is " << srresult1.GetReNum() << ". " << endl; //print out the number if imaginary part is 0
	if (srresult1.GetReNum() == 0)
		cout << "The square root of the second complex number is " << srresult1.GetImNum() << "i. " << endl; //print out the number if real part is 0
	return 0;
	
}

int loginManager() {
	Login login;
	char uName[50], uPass[50];
	cout << "Please log in before starting the complex number algorithm. " << endl;
	cout << "Username: ";
	cin.getline(uName, 50);
	cout << "Password: ";
	cin.getline(uPass, 50);

	if (login.find(uName) == 0) { //find the name in the file and check the existence of the user name 
		cout << "No this user! Create a new user? (y/n) ";
		char choice;
		cin >> (choice);
		if (choice == 'y') { //create a new user
			login.add(uName, uPass); //add the user name and password
			login.write(); //write the data to the file
			cout << "Created sucessfully! " << endl;
			cout << "Welcome " << uName << "!. " << endl;
		}
	}
	else {
		int attempt = 2; //2 more attempts for the user to try the password
		while (attempt >= 0) { //the function will end when attempts = 0 
			if (login.check(uPass) == true) { //check the password that enter by the user
				cout << "Login successfully! " << endl;
				cout << "Welcome " << uName << "! " << endl;
				break;
			}
			else {
				cout << attempt << " attempt left! " << endl; //tell the user how many attempts left
				if (attempt == 0) { //end the loop when no attempt
					cout << "No attempt left! The program will end. " << endl;
					break;
				}
				cout << "Please try again: ";
				cin.getline(uPass, 50);
				attempt--;
			}
		}
	}
	return 0;
}