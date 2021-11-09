#include "complexvalue.h"
#include <math.h>

//constructor 
complexNum::complexNum(double r = 0.0, double i = 0.0)
{
	x = r; //initialization 
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
	if (x == 0 && y == 0) {
		errNum = true; // change the value of errNum
		return errNum;
	}
	else
		return errNum;
}

// division of 2 objects of complex number 
complexNum complexNum::division(complexNum obj, complexNum obj1)  {
	x = ((obj.x * obj1.x) + (obj.y * obj1.y)) / ((obj1.x * obj1.x) + (obj1.y * obj1.y)); //real
	y = ((obj.y * obj1.x) - (obj.x * obj1.y)) / ((obj1.x * obj1.x) + (obj1.y * obj1.y)); //imaginary
	complexNum div(x, y); //store the division result 
	return div;
}

//square root of the complex number
complexNum complexNum::squareroot(complexNum obj){
	int sign; //store the value for the sign
	if (obj.y > 0)
		sign = -1;
	if (obj.y < 0)
		sign = 1;
	if (obj.y == 0)
		sign = 0;

	x = sqrt((obj.x + sqrt(obj.x * obj.x + obj.y * obj.y)) / 2);
	y = sign * sqrt(((-1 * obj.x) + sqrt(obj.x * obj.x + obj.y * obj.y)) / 2);
	complexNum sroot(x, y); // store the result 
	return sroot;
}