// ClientApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"..\DLLforVendingMachine\Header.h"
#include <iostream>
#include <windows.h>
#include"FrontPanel.h"
#pragma comment(lib, "C:\\Users\\AngaleswariK\\Documents\\Visual Studio 2015\\Projects\\DLLforVendingMachine\\Debug\\DLLforVendingMachine.lib")

using namespace std;

int main()
{

	HINSTANCE hDLL = LoadLibrary(L"DLLforVendingMachine.dll");

	if (hDLL == NULL) {
		cout << "Failed to load library.\n";
	}
	else
	{
		CFrontPanel *pPanelObject = new CFrontPanel;
		CreateVendingMachineFunPtr pEntryFunction = (CreateVendingMachineFunPtr)GetProcAddress(hDLL, "CreateVendingMachine");
		IMyVendingMachineDLL* pVendingMachine = pEntryFunction();
		if (pVendingMachine) 
		{
			char cChoice;
			int iChoice;
			int iCapacity;
			int iCount = 0;
			do
			{
				cout << " \nDISPENSER MENU\n---------------------\n1.Milk\n2.Coffee\n3.Tea\n4.HotWater\n5.Snack\n";
				//pVendingMachine->DisplayDispenserType();
				cout << "Which dispenser is need to add \n";
				cin >> iChoice;
				cout << "Enter the capacity of the dispenser\n";
				cin >> iCapacity;
				pVendingMachine->AddDispenser(iChoice, iCapacity);
				cout << "Do you want to add any other dispenser(y/n)\n";
				cin >> cChoice;
			} while (cChoice == 'y');
		}
		for (;;)
		{
			string iChoice = pPanelObject->GetChoice();
			if (iChoice == "Admin")
			{
				string iAdminChoice = "";
				do {
					iAdminChoice = pPanelObject->GetAdminChoice();
					if (iAdminChoice == "Fill Dispenser")
					{
						string* pName = pVendingMachine->GetDispenserNameList();
						int iDispensercount = pVendingMachine->GetDispenserCount();
						pPanelObject->DisplayString("\nDispenser Menu\n=============================\n");
						for (int i = 0; i < iDispensercount; i++)
						{
							pPanelObject->DisplayInteger(i + 1);
							pPanelObject->DisplayString(". ");
							pPanelObject->DisplayString(pName[i]);
							pPanelObject->DisplayString("\n");
						}
						int ichoice = pPanelObject->GetValue();
						string name = pVendingMachine->GetDispenserName(ichoice);
						int iAmount = pPanelObject->GetReFillAmount();
						bool flag = pVendingMachine->FillRecipi(name, iAmount);
						pPanelObject->DisplayString(name);
						if (flag)
							pPanelObject->DisplayString(" Filled\n");
						else
							pPanelObject->DisplayString(" Dispenser Overflow\n");
					}
					if (iAdminChoice == "Fix Rate for Recipe")
					{
						string *pRecipeNameList = pVendingMachine->GetRecipeNameList();
						int iCount = pVendingMachine->GetRecipeCount();
						for (int i = 0; i < iCount; i++)
						{
							pPanelObject->DisplayInteger(i + 1);
							pPanelObject->DisplayString(". ");
							pPanelObject->DisplayString(pRecipeNameList[i]);
							pPanelObject->DisplayString("\t");
							pPanelObject->DisplayInteger(pVendingMachine->GetAmount(pRecipeNameList[i]));
							pPanelObject->DisplayString("\n");
						}
						int iChoice = pPanelObject->GetValue();
						string sChoice = pRecipeNameList[iChoice - 1];
						int iAmount=pPanelObject->GetAmountForRecipe();
						bool flag=pVendingMachine->SetAmount(sChoice,iAmount);
						if (flag)
						{
							pPanelObject->DisplayString(sChoice);
							pPanelObject->DisplayString(" rate was reseted successfully\n");
						}
						else
						{
							pPanelObject->DisplayString(sChoice);
							pPanelObject->DisplayString(" rate was not reseted successfully\n");
						}
					}
					else if (iAdminChoice == "Add Employee")
					{
						int id = pPanelObject->GetEmployeeID();
						bool flag = pVendingMachine->AddEmployee(id);
						if (flag)
						{
							pPanelObject->DisplayString("Given employee id was successfully inserted\n");
						}
						else
						{
							pPanelObject->DisplayString("Given employee id was already in list\n");
						}
					}
					else if (iAdminChoice == "View Current Level Of Item")
					{
						string* pName = pVendingMachine->GetDispenserNameList();
						int iDispensercount = pVendingMachine->GetDispenserCount();
						for (int i = 0; i < iDispensercount; i++)
						{
							int iCurrentLevel = pVendingMachine->GetCurrentLevelOfDispenser(pName[i]);
							pPanelObject->DisplayString(pName[i]);
							pPanelObject->DisplayString(" Level \t ");
							pPanelObject->DisplayInteger(iCurrentLevel);
							pPanelObject->DisplayString("\n");
						}
					}
					else if (iAdminChoice == "View All Employee")
					{
						int *piIdList = pVendingMachine->EmployeeIDList();
						int *piAmountList = pVendingMachine->EmployeeAmountList();
						int iCount = pVendingMachine->GetEmployeeCount();
						if (iCount != 0)
						{
							pPanelObject->DisplayString("Employee details\n");
							pPanelObject->DisplayString("Employee ID\tAmount\n");
							for (int i = 0; i < iCount; i++)
							{
								pPanelObject->DisplayInteger(piIdList[i]);
								pPanelObject->DisplayString("\t\t");
								pPanelObject->DisplayInteger(piAmountList[i]);
								pPanelObject->DisplayString("\n");
							}
						}
						else
						{
							pPanelObject->DisplayString("The employee List is empty\n");
						}
					}
					else if (iAdminChoice == "View total number of Usage")
					{
						pPanelObject->DisplayString("The total number of usage is ");
						int iCount = pVendingMachine->GetUsageCount();
						pPanelObject->DisplayInteger(iCount);
						pPanelObject->DisplayString("\n");
					}
					else if (iAdminChoice == "Switch OFF Machine")
					{
						pPanelObject->DisplayString("Exit from the machine....\n");
						exit(0);
					}
				} while (iAdminChoice != "Admin Logout");
				pPanelObject->DisplayString("Admin Loggedout....\n");
			}
			else
			{
				string iUserCateogory = pPanelObject->GetUserChoice();
				string *pRecipeNameList = pVendingMachine->GetRecipeNameList();
				int iCount = pVendingMachine->GetRecipeCount();
				for (int i = 0; i < iCount; i++)
				{
					pPanelObject->DisplayInteger(i + 1);
					pPanelObject->DisplayString(". ");
					pPanelObject->DisplayString(pRecipeNameList[i]);
					pPanelObject->DisplayString("\t");
					pPanelObject->DisplayInteger(pVendingMachine->GetAmount(pRecipeNameList[i]));
					pPanelObject->DisplayString("\n");
				}
				
				int iChoice=pPanelObject->GetValue();
				string sChoice = pRecipeNameList[iChoice - 1];
				int iNumber = pPanelObject->DisplayUserMenu(iUserCateogory);
				if (iUserCateogory == "Card")
				{
					int iAmount = pVendingMachine->GetAmount(sChoice);
					bool flag = pVendingMachine->SearchID(iNumber, iAmount);
					if (flag)
					{
						pPanelObject->DisplayString("Welcome\n");
						int iSize = pVendingMachine->GetDispenserCount();
						bool flag = pVendingMachine->Triggercontroller(sChoice);
						if (flag)
						{
							pPanelObject->DisplayString(sChoice);
							pPanelObject->DisplayString(" has been Dispensed\n");
							pPanelObject->DisplayString("Thank You!\n");
							int iUsagecount = pVendingMachine->GetUsageCount();
							pVendingMachine->SetUsageCount(iUsagecount + 1);
						}
						else
						{
							pPanelObject->DisplayString("Error on dispensing please call Admin\n");
						}
					}
					else
					{
						pPanelObject->DisplayString("Please enter the correct id number\n");
					}
				}
				else if (iUserCateogory == "Coin")
				{
					int iCost = pVendingMachine->GetAmount(sChoice);
					bool flag = pVendingMachine->CheckEnoughMoney(iNumber, iCost);
					if (flag)
					{
						pPanelObject->DisplayString("Welcome\n");
						int iSize = pVendingMachine->GetDispenserCount();
						bool flag = pVendingMachine->Triggercontroller(sChoice);
						if (flag)
						{
							int iBalance = pVendingMachine->CalculateBalance(iNumber, iCost);
							pPanelObject->DisplayString(sChoice);
							pPanelObject->DisplayString(" has been Dispensed\n");
							if (iBalance != 0)
							{
								pPanelObject->DisplayString("Please collect the remaining\t");
								pPanelObject->DisplayInteger(iBalance);
								pPanelObject->DisplayString(" rupees\n");
							}
							pPanelObject->DisplayString("Thank You!\n");
							int iUsagecount = pVendingMachine->GetUsageCount();
							pVendingMachine->SetUsageCount(iUsagecount + 1);
						}
						else
						{
							pPanelObject->DisplayString("Error on dispensing please call Admin\n");
							pPanelObject->DisplayString("Please collect the cash\t");
							pPanelObject->DisplayInteger(iNumber);
							pPanelObject->DisplayString(" rupees\n");
						}
					}
					else
					{
						pPanelObject->DisplayString("Sorry please give enough money\n");
					}
				}
			}
		}
		pVendingMachine->Delete();
		FreeLibrary(hDLL);
	}
	std::cin.get();
	return 0;
}

