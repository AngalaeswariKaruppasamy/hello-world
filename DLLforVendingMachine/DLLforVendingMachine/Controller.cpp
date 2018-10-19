#include "stdafx.h"
#include "Controller.h"
#include"iostream"
using namespace std;

CController::CController()
{
	m_pRecipe = new CRecipe;
}
bool CController::CheckAvailability(CDispenser* pDispenser, int iQuantity)
{
	if (pDispenser->GetCurrentLevel() >= iQuantity)
		return true;
	else
		return false;
}
CRecipe* CController::GetRecipe()
{
	return m_pRecipe;
}
CDispenser* CController::GetDispenser(CDispenser** Dptr, int iCount, string sName)
{
	for (int i = 0; i < iCount; i++)
	{
		string sTempName = Dptr[i]->GetName();
		if (sName == sTempName)
			return Dptr[i];
	}
	return NULL;
}
bool CController::TriggerDispenser(CDispenser** Dptr, int iCount, string iChoice)
{
	bool flag = false;
	if (iChoice == "Milk")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Pure Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);
		if (!flag)
			return false;
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Light Coffee")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);
		if (!flag)
			return false;
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iLightCoffeeQuantity = m_pRecipe->GetQuantity("Light Coffee");
		CDispenser* pTempCoffee = GetDispenser(Dptr, iCount, "Coffee");
		flag = CheckAvailability(pTempCoffee, iLightCoffeeQuantity);
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempCoffee->Dispense(iLightCoffeeQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Strong Coffee")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);
		if (!flag)
			return false;
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iStrongCoffeeQuantity = m_pRecipe->GetQuantity("Strong Coffee");
		CDispenser* pTempCoffee = GetDispenser(Dptr, iCount, "Coffee");
		flag = CheckAvailability(pTempCoffee, iStrongCoffeeQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempCoffee->Dispense(iStrongCoffeeQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Light Tea")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);//   *((*(Dptr + 1)) + 0)) act  as a Milk Dispenser
		if (!flag)
			return false;
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iLightTeaQuantity = m_pRecipe->GetQuantity("Light Tea");
		CDispenser* pTempTea = GetDispenser(Dptr, iCount, "Tea");
		flag = CheckAvailability(pTempTea, iLightTeaQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempTea->Dispense(iLightTeaQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Strong Tea")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);//   *((*(Dptr + 1)) + 0)) act  as a Milk Dispenser
		if (!flag)
			return false;
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iStrongTeaQuantity = m_pRecipe->GetQuantity("Strong Tea");
		CDispenser* pTempTea = GetDispenser(Dptr, iCount, "Tea");
		flag = CheckAvailability(pTempTea, iStrongTeaQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempTea->Dispense(iStrongTeaQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}

	else if (iChoice == "Black Coffee")
	{
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iLightCoffeeQuantity = m_pRecipe->GetQuantity("Light Coffee");
		CDispenser* pTempCoffee = GetDispenser(Dptr, iCount, "Coffee");
		flag = CheckAvailability(pTempCoffee, iLightCoffeeQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempCoffee->Dispense(iLightCoffeeQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Black Tea")
	{
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iLightTeaQuantity = m_pRecipe->GetQuantity("Light Tea");
		CDispenser* pTempTea = GetDispenser(Dptr, iCount, "Tea");
		flag = CheckAvailability(pTempTea, iLightTeaQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempTea->Dispense(iLightTeaQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Hot Water")
	{
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Milk Without Sugar")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);//   *((*(Dptr + 1)) + 0)) act  as a Milk Dispenser
		if (!flag)
			return false;
		int iSugarQuantityForLight = m_pRecipe->GetQuantity("Sugar");
		CDispenser* pTempSugar = GetDispenser(Dptr, iCount, "Sugar");
		flag = CheckAvailability(pTempSugar, iSugarQuantityForLight);
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempSugar->Dispense(iSugarQuantityForLight);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Light Coffee Without Sugar")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);//   *((*(Dptr + 1)) + 0)) act  as a Milk Dispenser
		if (!flag)
			return false;
		int iLightCoffeeQuantity = m_pRecipe->GetQuantity("Light Coffee");
		CDispenser* pTempCoffee = GetDispenser(Dptr, iCount, "Coffee");
		flag = CheckAvailability(pTempCoffee, iLightCoffeeQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempCoffee->Dispense(iLightCoffeeQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Strong Coffee Without Sugar")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);//   *((*(Dptr + 1)) + 0)) act  as a Milk Dispenser
		if (!flag)
			return false;
		int iStrongCoffeeQuantity = m_pRecipe->GetQuantity("Strong Coffee");
		CDispenser* pTempCoffee = GetDispenser(Dptr, iCount, "Coffee");
		flag = CheckAvailability(pTempCoffee, iStrongCoffeeQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempCoffee->Dispense(iStrongCoffeeQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Light Tea Without Sugar")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);//   *((*(Dptr + 1)) + 0)) act  as a Milk Dispenser
		if (!flag)
			return false;
		int iLightTeaQuantity = m_pRecipe->GetQuantity("Light Tea");
		CDispenser* pTempTea = GetDispenser(Dptr, iCount, "Tea");
		flag = CheckAvailability(pTempTea, iLightTeaQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempTea->Dispense(iLightTeaQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Strong Tea Without Sugar")
	{
		int iMilkQuantity = m_pRecipe->GetQuantity("Milk");
		CDispenser* pTempMilk = GetDispenser(Dptr, iCount, "Milk");
		flag = CheckAvailability(pTempMilk, iMilkQuantity);//   *((*(Dptr + 1)) + 0)) act  as a Milk Dispenser
		if (!flag)
			return false;
		int iStrongTeaQuantity = m_pRecipe->GetQuantity("Strong Tea");
		CDispenser* pTempTea = GetDispenser(Dptr, iCount, "Tea");
		flag = CheckAvailability(pTempTea, iStrongTeaQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempMilk->Dispense(iMilkQuantity);
		pTempTea->Dispense(iStrongTeaQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}

	else if (iChoice == "Black Coffee Without Sugar")
	{
		int iLightCoffeeQuantity = m_pRecipe->GetQuantity("Light Coffee");
		CDispenser* pTempCoffee = GetDispenser(Dptr, iCount, "Coffee");
		flag = CheckAvailability(pTempCoffee, iLightCoffeeQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempCoffee->Dispense(iLightCoffeeQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Light Tea Without Sugar")
	{
		int iLightTeaQuantity = m_pRecipe->GetQuantity("Light Tea");
		CDispenser* pTempTea = GetDispenser(Dptr, iCount, "Tea");
		flag = CheckAvailability(pTempTea, iLightTeaQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		int iWaterQantity = m_pRecipe->GetQuantity("Hot Water");
		CDispenser* pTempWater = GetDispenser(Dptr, iCount, "Hot Water");
		flag = CheckAvailability(pTempWater, iWaterQantity);
		if (!flag)
			return false;
		pTempTea->Dispense(iLightTeaQuantity);
		pTempWater->Dispense(iWaterQantity);
		return true;
	}
	else if (iChoice == "Snack")
	{
		int iSnackQuantity = m_pRecipe->GetQuantity("Snack");
		CDispenser* pTempSnack = GetDispenser(Dptr, iCount, "Snack");
		flag = CheckAvailability(pTempSnack, iSnackQuantity);//   *((*(Dptr + 1)) + 2)) act  as a coffee Dispenser
		if (!flag)
			return false;
		pTempSnack->Dispense(iSnackQuantity);
		return true;
	}
	return true;
}
CController::~CController()
{
	delete m_pRecipe;
	m_pRecipe = NULL;
}
