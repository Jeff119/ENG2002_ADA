#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include "Login.h"
using namespace std;

//constructor of User
User::User(char* cName, char* cPass) {
	uName = new char[50]; //Max. length of the user name and password is 50 and create both in the heap
	uPass = new char[50]; 
	strcpy(uName, cName); //update the User name and the password
	strcpy(uPass, cPass);
}

//destructor of User
User::~User() {
	delete[] uName; //remove the User in heap
	delete[] uPass;
}

//get the User name
char* User::getuName() const {
	return uName;
}

//get the password of the user
char* User::getuPass() const {
	return uPass;
}

//constructor of Login
Login::Login() {
	ofstream file("password.txt", ios::app); //ensure there is a file
	file.close();
	pUser = 0;
}

//destructor
Login::~Login() {
	delete pUser; //delete the object in the heap which created by add()
	pUser = 0; //reset the pointer
}

//write the data to the file
void Login::write() {
	ofstream file("password.txt", ios::app);
	file << pUser->getuName() << endl
		<< pUser->getuPass() << endl;
	file.close();
}

//find the data in the data
bool Login::find(char* name) {
	ifstream file("password.txt");
	char checkName[50]; //declare a char array for checking user name
	while (true) {
		file.getline(checkName, 50);
		if (strcmp(name, checkName) == 0) {
			file.close();
			return true;
		}
		if (file.fail()) //stop the search 
			break;
	}
	file.close();
	return false;
}

//add the data to the file
void Login::add(char* name, char* pass) {
	pUser = new User(name, pass); //create a user 
}

//check the password in the file
bool Login::check(char* name, char* pass) {
	ifstream file("password.txt");
	char checkName[50]; //declare a char array for checking user
	char checkPass[50]; //declare a char array for checking password
	while (true) {
		file.getline(checkName, 50); //search the user name
		if (strcmp(name, checkName) == 0) { //match the user name
			file.getline(checkPass, 50);  //get the password from the file
			if (strcmp(pass, checkPass) == 0) {
				file.close();
				return true;
			}
		}
		if (file.fail()) //stop the search 
			break;
	}
	file.close();
	return false;
}
