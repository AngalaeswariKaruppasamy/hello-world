#include "stdafx.h"
#include "Recipe.h"


CRecipe::CRecipe()
{
	m_iPureMilkQuantity = 20;
	m_iLightCoffeQuantity = 5;
	m_iLightTeaQuantity = 5;
	m_iHotWaterQuantity = 50;
	m_iSugarQuantityForLight = 5;
	m_iMilkQuantity = 10;
	m_iStrongCoffeQuantity = 10;
	m_iStrongTeaQuantity = 10;
	m_iSugarQuantityForStrong = 10;
	m_iPriceOfMilk = 10;
	m_iPriceOfCoffee = 15;
	m_iPriceOfTea = 15;
	m_iPriceOfHotWater = 5;
	m_iPriceOfBlackTeaOrCoffee = 8;
	m_iPriceOFSnack = 10;
	m_sRecipeList = NULL;
	m_pDispenserNameList = NULL;
}

void CRecipe::CreateDispenserNameList(string sName)
{
	string* sNameList = m_pDispenserNameList;
	m_pDispenserNameList = new string[m_iDispenserCount + 1];
	for (int i = 0; i < m_iDispenserCount; i++)
		m_pDispenserNameList[i] = sNameList[i];
	m_pDispenserNameList[m_iDispenserCount] = sName;
	m_iDispenserCount++;
}
string* CRecipe::GetdispenserNameList()
{
	return m_pDispenserNameList;
}
string* CRecipe::GetRecipeNameList()
{
	return m_sRecipeList;
}
int CRecipe::GetRecipeCount()
{
	return m_iRecipeCount;
}
int CRecipe::GetDespenserCount()
{
	return m_iDispenserCount;
}
void CRecipe::AddRecipeName(string sName)
{
	string* pTempList = m_sRecipeList;
	if ((sName == "Tea"))
	{
		m_sRecipeList = new string[m_iRecipeCount + 3];
		for (int i = 0; i < m_iRecipeCount; i++)
			m_sRecipeList[i] = pTempList[i];
		m_sRecipeList[m_iRecipeCount] = "Light Tea";
		m_sRecipeList[m_iRecipeCount + 1] = "Strong Tea";
		m_sRecipeList[m_iRecipeCount + 2] = "Black Tea";
		m_iRecipeCount = m_iRecipeCount + 3;
	}
	else if (sName == "Coffee")
	{
		m_sRecipeList = new string[m_iRecipeCount + 3];
		for (int i = 0; i < m_iRecipeCount; i++)
			m_sRecipeList[i] = pTempList[i];
		m_sRecipeList[m_iRecipeCount] = "Light Coffee";
		m_sRecipeList[m_iRecipeCount + 1] = "Strong Coffee";
		m_sRecipeList[m_iRecipeCount + 2] = "Black Coffee";
		m_iRecipeCount = m_iRecipeCount + 3;
	}
	else if (sName == "Milk")
	{
		m_sRecipeList = new string[m_iRecipeCount + 1];
		for (int i = 0; i < m_iRecipeCount; i++)
			m_sRecipeList[i] = pTempList[i];
		m_sRecipeList[m_iRecipeCount] = "Milk";
		m_iRecipeCount = m_iRecipeCount + 1;
	}
	else if (sName == "Snack")
	{
		m_sRecipeList = new string[m_iRecipeCount + 1];
		for (int i = 0; i < m_iRecipeCount; i++)
			m_sRecipeList[i] = pTempList[i];
		m_sRecipeList[m_iRecipeCount] = "Snack";
		m_iRecipeCount = m_iRecipeCount + 1;
	}
	else if (sName == "Hot Water")
	{
		m_sRecipeList = new string[m_iRecipeCount + 1];
		for (int i = 0; i < m_iRecipeCount; i++)
			m_sRecipeList[i] = pTempList[i];
		m_sRecipeList[m_iRecipeCount] = "Hot Water";
		m_iRecipeCount = m_iRecipeCount + 1;
	}
}
int CRecipe::GetQuantity(string sRecipe)
{
	if (sRecipe == "Pure Milk")
		return m_iPureMilkQuantity;
	else if (sRecipe == "Milk")
		return m_iMilkQuantity;
	else if (sRecipe == "Light Coffee")
		return m_iLightCoffeQuantity;
	else if (sRecipe == "Strong Coffee")
		return m_iStrongCoffeQuantity;
	else if (sRecipe == "Light Tea")
		return m_iLightTeaQuantity;
	else if (sRecipe == "Strong Tea")
		return m_iStrongTeaQuantity;
	else if (sRecipe == "Black Tea")
		return m_iLightTeaQuantity;
	else if (sRecipe == "Black Coffee")
		return m_iLightCoffeQuantity;
	else if (sRecipe == "Hot Water")
		return m_iHotWaterQuantity;
	else if (sRecipe == "Snack")
		return m_iSnackQuantity;
	else if (sRecipe == "Sugar")
		return m_iSugarQuantityForLight;
	return -1;
}
bool CRecipe::SetQuantity(string sRecipe, int iQuantity)
{
	if (sRecipe == "Milk")
		m_iPureMilkQuantity = iQuantity;
	else if (sRecipe == "Light Coffee")
		m_iLightCoffeQuantity = iQuantity;
	else if (sRecipe == "Strong Coffee")
		m_iStrongCoffeQuantity = iQuantity;
	else if (sRecipe == "Light Tea")
		m_iLightTeaQuantity = iQuantity;
	else if (sRecipe == "Strong Tea")
		m_iStrongTeaQuantity = iQuantity;
	else if (sRecipe == "Black Tea")
		m_iLightTeaQuantity = iQuantity;
	else if (sRecipe == "Black Coffee")
		m_iLightCoffeQuantity = iQuantity;
	else if (sRecipe == "Hot Water")
		m_iHotWaterQuantity = iQuantity;
	else if (sRecipe == "Snack")
		m_iSnackQuantity = iQuantity;
	return true;
}
int CRecipe::GetAmount(string sRecipe)
{
	if (sRecipe == "Milk")
		return m_iPriceOfMilk;
	else if (sRecipe == "Light Coffee")
		return m_iPriceOfCoffee;
	else if (sRecipe == "Strong Coffee")
		return m_iPriceOfCoffee;
	else if (sRecipe == "Light Tea")
		return m_iPriceOfTea;
	else if (sRecipe == "Strong Tea")
		return m_iPriceOfTea;
	else if (sRecipe == "Black Tea")
		return m_iPriceOfBlackTeaOrCoffee;
	else if (sRecipe == "Black Coffee")
		return m_iPriceOfBlackTeaOrCoffee;
	else if (sRecipe == "Hot Water")
		return m_iPriceOfHotWater;
	else if (sRecipe == "Snack")
		return m_iPriceOFSnack;
	return -1;
}
bool CRecipe::SetAmount(string sRecipe, int iPrice)
{
	if (sRecipe == "Milk")
		m_iPriceOfMilk = iPrice;
	else if (sRecipe == "Light Coffee")
		m_iPriceOfCoffee = iPrice;
	else if (sRecipe == "Strong Coffee")
		m_iPriceOfCoffee = iPrice;
	else if (sRecipe == "Light Tea")
		m_iPriceOfTea = iPrice;
	else if (sRecipe == "Strong Tea")
		m_iPriceOfTea = iPrice;
	else if (sRecipe == "Black Tea")
		m_iPriceOfBlackTeaOrCoffee = iPrice;
	else if (sRecipe == "Black Coffee")
		m_iPriceOfBlackTeaOrCoffee = iPrice;
	else if (sRecipe == "Hot Water")
		m_iPriceOfHotWater = iPrice;
	else if (sRecipe == "Snack")
		m_iPriceOFSnack = iPrice;
	return true;
}
CRecipe::~CRecipe()
{
	delete m_pDispenserNameList;
	m_pDispenserNameList = NULL;
	delete m_sRecipeList;
	m_sRecipeList = NULL;
}
