#pragma once
#include"Dispenser.h"
class CLiquidDispenser :public CDispenser
{
public:
	CLiquidDispenser(int iCapacity, string sName);
	CLiquidDispenser();
	~CLiquidDispenser();
	void Dispense(int iQuantity);
};

