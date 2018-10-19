#include "stdafx.h"
#include "PowderDispenser.h"
#include"iostream"
using namespace std;

CPowderDispenser::CPowderDispenser(int iCapacity, string sName) :CDispenser(iCapacity, sName)
{
}
void CPowderDispenser::Dispense(int iQuantity)
{
	ReduceCurrentLevel(iQuantity);
}

CPowderDispenser::~CPowderDispenser()
{
}
CPowderDispenser::CPowderDispenser() :CDispenser(1000, "")
{
}
