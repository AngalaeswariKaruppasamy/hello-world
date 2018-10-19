#pragma once

class CCashManager
{
public:
	CCashManager();
	~CCashManager();
	bool checkEnoughMoney(int iGivenAmount, int iRateOfItem);
	int CalculateBalance(int iGivenAmount, int iRateOfItem);
};

