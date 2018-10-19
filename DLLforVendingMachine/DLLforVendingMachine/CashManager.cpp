#include "stdafx.h"
#include "CashManager.h"


CCashManager::CCashManager()
{
}

bool CCashManager::checkEnoughMoney(int iGivenAmount, int iRateOfItem)
{
	if (iGivenAmount >= iRateOfItem)
		return true;
	else
		return false;
}
int CCashManager::CalculateBalance(int iGivenAmount, int iRateOfItem)
{
	int iBalance = iGivenAmount - iRateOfItem;
	return iBalance;
}
CCashManager::~CCashManager()
{
}
