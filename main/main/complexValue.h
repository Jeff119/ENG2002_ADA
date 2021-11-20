class complexNum
{
public:
	complexNum(double r, double i); //constructor 
	~complexNum(); //destructor
	void SetReNum(double r); //set the real part only
	void SetImNum(double i); //set the imaginary part only
	double GetReNum(); //show the real part
	double GetImNum(); //show the imaginary part
	bool ReaderrNum(); //read the value of errNum
	bool checkVaild(); //check the operand
	complexNum division(complexNum obj, complexNum obj1); //divsion of 2 complex number
	complexNum squareroot(complexNum); //square root of a complex number

private:
	double x ; //real part
	double y ; //imaginary part 
	bool errNum; 

};
