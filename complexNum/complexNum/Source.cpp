#include <iostream>
#include "complexvalue.h"

//constructor 
complexNum::complexNum(double r, double i)
{
	x = r;
	y = i;
}

//destructor 
complexNum::~complexNum()
{
}


//change the real part only
void complexNum::SetReNum(double Re) {
	x = Re;
}


//change the imaginary part only
void complexNum::SetImNum(double Im) {
	y = Im;
}

//Get the value of real part
double complexNum::GetReNum() {
	return x;
}

//Get the value of imaginary part
double complexNum::GetImNum() {
	return y;
}

//real value of errNum
bool complexNum::ReaderrNum() {
	return errNum;
}

//check the operand 
bool complexNum::checkVaild() {
	if (x == 0 || y == 0) {
		errNum = true; // change the value of errNum
		return errNum;
	}
	else
		return errNum;
}

//print the complex number
void complexNum::print() const {
	std::cout << x << " + " << y << "i" << std::endl;
}

// division of 2 objects of complex number 
void complexNum::division(complexNum obj, complexNum obj1) {
	x = (obj.x * obj1.x + obj.y * obj1.y) / (obj1.x * obj1.x + obj1.y * obj1.y);
	y = (obj.y * obj1.x - obj.x * obj1.y) / (obj1.x * obj1.x + obj1.y * obj1.y);
}
