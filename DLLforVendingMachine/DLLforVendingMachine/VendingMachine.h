#pragma once
#include "Controller.h"
#include"LiquidDispenser.h"
#include"PowderDispenser.h"
#include"EmployeeIDManager.h"
#include"CashManager.h"
#include"SnackDispenser.h"
#include"DispenserFactory.h"
#include"Recipe.h"
#include"Header.h"
class CVendingMachine :public IMyVendingMachineDLL
{
public:
	CVendingMachine();
	~CVendingMachine();
	bool FillRecipi(string iChoice, int iAmount);
	bool CreateEmployeeList(int iId);
	bool SearchID(int iID, int iAmount);
	CDispenser* GetDispenser(string sName);
	bool AddDispenser(int iChoice, int iCapacity);
	bool CheckExistence(CDispenser** ppDispenser, int iCount, string sName);
	void Delete();
	string GetDispenserName(int i);
	string* GetDispenserNameList();
	bool AddEmployee(int iId);
	int GetCurrentLevelOfDispenser(string name);
	int* EmployeeIDList();
	int* EmployeeAmountList();
	int GetEmployeeCount();
	int GetUsageCount();
	void SetUsageCount(int iCount);
	int GetDispenserCount();
	string* GetRecipeNameList();
	int GetRecipeCount();
	int GetAmount(string sRecipe);
	bool Triggercontroller(string sChoice);
	bool CheckEnoughMoney(int iNumber, int iCost);
	int CalculateBalance(int iNumber, int iCost);
	void UpdateEmployeeAmount(int iAmount);
	bool SetAmount(string sRecipe, int iPrice);
private:
	CDispenser** m_ppDispenser;
	CController* m_pControllerObject;
	CEmployeeIDManager* m_EmployeeObject;
	CCashManager m_CashManagerObject;
	CRecipe* m_pRecipe;
	int m_iUsageCount;
	int m_iDispenserCount;
	CDispenserFactory* m_pFactory;
};

