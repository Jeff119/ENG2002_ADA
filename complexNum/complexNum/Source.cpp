#include "complexvalue.h"


complexNum::complexNum()
{
	ReNum = 0;
	ImNum = 0;
	errNum = false;
}

complexNum::~complexNum()
{
}

void complexNum::SetReNum(double RNum) {
	ReNum = RNum;
}

void complexNum::SetImNum(double INum) {
	ImNum = INum;
}

int complexNum::GetReNum() {
	return ReNum;
}

int complexNum::GetImNum() {
	return ImNum;
}

bool GeterrNum() {
	return true;
}
