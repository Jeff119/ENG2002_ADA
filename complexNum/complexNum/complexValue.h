class complexNum
{
public:
	complexNum();
	~complexNum();
	void SetReNum(double RNum);
	void SetImNum(double INum);
	int GetImNum();
	int GetReNum();
	bool GeterrNum();

private:
	double ReNum;
	double ImNum;
	bool errNum;
};
