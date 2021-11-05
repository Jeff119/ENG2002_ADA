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
	void print() const;
	void division(complexNum obj, complexNum obj1);


private:
	double x = 0.0; //real part
	double y = 0.0; //imaginary part 
	bool errNum = false;
};
