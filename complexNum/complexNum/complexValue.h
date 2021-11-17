class complexNum
{
public:
	complexNum(double r, double i);
	~complexNum();
	void SetReNum(double Re);
	void SetImNum(double Im);
	double GetReNum();
	double GetImNum();
	bool ReaderrNum();
	bool checkVaild();
	complexNum division(complexNum obj, complexNum obj1); 
	complexNum squareroot(complexNum);

private:
	double x ; //real part
	double y ; //imaginary part 
	bool errNum; 
	int sign; //store the value for the sign;
};
