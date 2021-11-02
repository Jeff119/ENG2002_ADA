#pragma once

class complexNum
{
public:
	complexNum();
	~complexNum();
	void SetReNum(double );
	void SetImNum(double);
	int GetImNum();
	int GetReNum();


private:
	double ReNum;
	double ImNum;
};
