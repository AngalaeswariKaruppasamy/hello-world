#pragma once
#include"Dispenser.h"
#include"Recipe.h"
class CController
{
public:
	CController();
	~CController();
	bool CheckAvailability(CDispenser* pDispenser, int iQuantity);
	bool TriggerDispenser(CDispenser** Dptr, int iCount, string iChoice);
	CRecipe* GetRecipe();
	CDispenser* GetDispenser(CDispenser** Dptr, int iCount, string sName);
private:
	CRecipe* m_pRecipe;
};

