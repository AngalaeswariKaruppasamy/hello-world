#include "stdafx.h"
#include "SnackDispenser.h"


CSnackDispenser::CSnackDispenser(int iCapacity, string sName) :CDispenser(iCapacity, sName)
{
}
CSnackDispenser::CSnackDispenser() : CDispenser(100, "Snack")
{
}
void CSnackDispenser::Dispense(int iQuantity)
{
	ReduceCurrentLevel(iQuantity);
}

CSnackDispenser::~CSnackDispenser()
{
}
