class User {
public:
	User(char* cName, char* cPass); //constructor 
	~User(); //destructor 
	char* getuName() const; //get the name of the user
	char* getuPass() const; //get the password of the user
private:
	char* uName; //store the user name
	char* uPass; //store the user password
};