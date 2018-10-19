#include "stdafx.h"
#include "LiquidDispenser.h"
#include"iostream"
using namespace std;

CLiquidDispenser::CLiquidDispenser(int iCapacity, string sName) :CDispenser(iCapacity, sName)
{
}
void CLiquidDispenser::Dispense(int iQuantity)
{
	ReduceCurrentLevel(iQuantity);
}

CLiquidDispenser::~CLiquidDispenser()
{
}
CLiquidDispenser::CLiquidDispenser() :CDispenser(1000, "")
{
}
