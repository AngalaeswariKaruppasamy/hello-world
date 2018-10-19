#pragma once
#include"Dispenser.h"
class CSnackDispenser :public CDispenser
{
public:
	CSnackDispenser(int iCapacity, string sName);
	CSnackDispenser();
	~CSnackDispenser();
	void Dispense(int iQuantity);
};

