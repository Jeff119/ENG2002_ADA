#include "User.h"
class Login {
public:
	Login(); //construstor
	~Login(); //destrustor
	void write(); //write the data to the file
	bool find(char* name); //find the data in the file
	void add(char* name, char* pass); //add the data to the file
	bool check(char* name, char* pass); //check the password in the file
private:
	User* pUser; //create a pointer that points to User
};