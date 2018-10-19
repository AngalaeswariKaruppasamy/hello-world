#pragma once

#ifdef  CALL_DLL_EXPORTS 
#define DLLCALL __declspec(dllexport)   /* Should be enabled before compiling 
										   .dll project for creating .dll*/
#else
#define DLLCALL __declspec(dllimport)  /* Should be enabled in Application side
										  for using already created .dll*/
#endif

#include"string"
using namespace std;
class DLLCALL IMyVendingMachineDLL {
public:
	virtual ~IMyVendingMachineDLL() { ; }
	virtual bool AddDispenser(int iChoice, int iCapacity) = 0;
	virtual	void Delete() = 0;
	virtual string GetDispenserName(int i)=0;
	virtual bool FillRecipi(string iChoice, int iAmount)=0;
	virtual bool AddEmployee(int iId)=0;
	virtual int GetCurrentLevelOfDispenser(string name)=0;
	virtual int* EmployeeIDList()=0;
	virtual int* EmployeeAmountList()=0;
	virtual int GetEmployeeCount()=0;
	virtual	int GetUsageCount()=0;
	virtual string* GetRecipeNameList()=0;
	virtual int GetRecipeCount()=0;
	virtual int GetAmount(string sRecipe)=0;
	virtual bool SearchID(int iID, int iAmount)=0;
	virtual int GetDispenserCount()=0;
	virtual void SetUsageCount(int iCount)=0;
	virtual bool Triggercontroller(string sChoice)=0;
	virtual bool CheckEnoughMoney(int iNumber, int iCost)=0;
	virtual int CalculateBalance(int iNumber, int iCost)=0;
	virtual string* GetDispenserNameList()=0;
	virtual void UpdateEmployeeAmount(int iAmount)=0;
	virtual bool SetAmount(string sRecipe, int iPrice)=0;
};

extern "C"
{
	DLLCALL IMyVendingMachineDLL* _cdecl CreateVendingMachine();
};

typedef IMyVendingMachineDLL* (*CreateVendingMachineFunPtr)();
