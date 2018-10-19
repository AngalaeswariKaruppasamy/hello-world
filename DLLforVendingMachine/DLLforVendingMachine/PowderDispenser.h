#pragma once
#include"Dispenser.h"
class CPowderDispenser :public CDispenser
{
public:
	CPowderDispenser(int iCapacity, string sName);
	CPowderDispenser();
	~CPowderDispenser();
	void Dispense(int iQuantity);
};

