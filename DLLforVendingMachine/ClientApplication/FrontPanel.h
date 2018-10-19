#pragma once
#include "string"
using namespace std;
class CFrontPanel
{
public:
	CFrontPanel();
	~CFrontPanel();
	void DisplayInteger(int iValue);
	int DisplayUserMenu(string sChoice);
	void DisplayCurrentLevelOfItem(char* pItemName, int iCurrent);
	string DisplayDispenserName(string* sItem, int icount);
	string GetAdminChoice();
	int GetReFillAmount();
	string GetChoice();
	string GetUserChoice();
	int GetValue();
	void DisplayString(string sString);
	int GetEmployeeID();
	int GetAmountForRecipe();
};

