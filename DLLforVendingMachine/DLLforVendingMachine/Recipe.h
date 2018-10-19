#pragma once
#include"string"
#include"Dispenser.h"
using namespace std;
class CRecipe
{
public:
	CRecipe();
	~CRecipe();
	int GetAmount(string sRecipe);
	bool SetAmount(string sRecipe, int iPrice);
	bool SetQuantity(string sRecipe, int iQuantity);
	int GetQuantity(string sRecipe);
	void AddRecipeName(string sName);
	string* GetRecipeNameList();
	void CreateDispenserNameList(string sName);
	string* GetdispenserNameList();
	int GetRecipeCount();
	int GetDespenserCount();
private:
	int m_iPureMilkQuantity;
	int m_iLightCoffeQuantity;
	int m_iLightTeaQuantity;
	int m_iHotWaterQuantity;
	int m_iSugarQuantityForLight;
	int m_iMilkQuantity;
	int m_iStrongCoffeQuantity;
	int m_iStrongTeaQuantity;
	int m_iSugarQuantityForStrong;
	int m_iSnackQuantity;
	int m_iPriceOfMilk;
	int m_iPriceOfCoffee;
	int m_iPriceOfTea;
	int m_iPriceOfHotWater;
	int m_iPriceOfBlackTeaOrCoffee;
	int m_iPriceOFSnack;
	string* m_sRecipeList;
	int m_iRecipeCount;
	string* m_pDispenserNameList;
	int m_iDispenserCount;
};

