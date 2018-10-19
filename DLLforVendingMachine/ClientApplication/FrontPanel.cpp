#include "stdafx.h"
#include "FrontPanel.h"
#include<iostream>
using namespace std;

CFrontPanel::CFrontPanel()
{

}
void CFrontPanel::DisplayString(string sString)
{
	cout << sString;
}
void CFrontPanel::DisplayCurrentLevelOfItem(char* pItemName, int iCurrent)
{
	cout << "The Current Level OF Item ";
	DisplayString(pItemName);
	cout << iCurrent;
}
string CFrontPanel::GetChoice()
{
	int choice;
	bool flag = false;
	cout << "1.Admin\n2.User\n";
	do
	{
		cout << "Enter Your Choice\n";
		cin >> choice;
		if (choice > 2)
		{
			cout << "ReEnter the correct choice\n";
			flag = true;
		}
		else
			flag = false;
	} while (flag);
	switch (choice)
	{
	case 1:
		return "Admin";
	case 2:
		return "User";
	}
	return "";
}
string CFrontPanel::DisplayDispenserName(string* sItem, int iCount)
{
	int ichoice;
	for (int i = 0; i < iCount; i++)
	{
		DisplayInteger(i + 1);
		cout << "." << sItem[i];
		cout << "\n";
	}
	cout << "Enter your choice\n";
	cin >> ichoice;
	while (ichoice > iCount)
	{
		cout << "Pleas ReEnter correct choice\n";
		cin >> ichoice;
	}
	return sItem[ichoice - 1];
}

string CFrontPanel::GetAdminChoice()
{
	int choice;
	bool flag = false;
	cout << "\nAdmin Menu \n=======================\n1.Fill Dispenser\n2.Add Employee\n3.view Current Level Of Item\n4.View All Employee\n5.view total number of Usage\n";
	cout << "6.Fix Rate for Recipe.\n7.Admin Logout.\n8.Switch OFF Machine\n";
	do
	{
		cout << "Enter your choice\n";
		cin >> choice;
		if (choice > 8)
		{
			cout << "ReEnter the correct choice\n";
			flag = true;
		}
		else
			flag = false;
	} while (flag);
	switch (choice)
	{
	case 1:
		return "Fill Dispenser";
	case 2:
		return "Add Employee";
	case 3:
		return "View Current Level Of Item";
	case 4:
		return "View All Employee";
	case 5:
		return "View total number of Usage";
	case 6:
		return "Fix Rate for Recipe";
	case 7:
		return "Admin Logout";
	case 8:
		return "Switch OFF Machine";

	}
	return "";
}
string CFrontPanel::GetUserChoice()
{
	int choice;
	bool flag = false;
	cout << "1.Card User\n2.Coin User\n";
	do
	{
		cout << "Enter your choice\n";
		cin >> choice;
		if (choice > 2)
		{
			cout << "ReEnter the correct choice\n";
			flag = true;
		}
		else
			flag = false;
	} while (flag);
	switch (choice)
	{
	case 1:
		return "Card";
	case 2:
		return "Coin";
	}
	return "";
}

void CFrontPanel::DisplayInteger(int iValue)
{
	cout << iValue;
}

int CFrontPanel::GetReFillAmount()
{
	int iRefillAmount;
	cout << "How much amount of item you want to refill\n";
	cin >> iRefillAmount;
	return iRefillAmount;
}
int CFrontPanel::DisplayUserMenu(string sChoice)
{
	int iCardNumber, iCoin;
	if (sChoice == "Card")
	{
		cout << "Please insert your card number\n";
		cin >> iCardNumber;
		return iCardNumber;
	}
	if (sChoice == "Coin")
	{
		cout << "Please insert your cash amount\n";
		cin >> iCoin;
		return iCoin;
	}

	return 0;
}
int CFrontPanel::GetEmployeeID()
{
	cout << "Enter the id you want to add\n";
	int id;
	cin >> id;
	return id;
}
int CFrontPanel::GetValue()
{
	cout << "Enter the  your choice\n";
	int ichoice;
	cin >> ichoice;
	return ichoice;
}
int CFrontPanel::GetAmountForRecipe()
{
	cout << "Enter the amount to be reset to the recipe\n";
	int iAmount;
	cin >> iAmount;
	return iAmount;
}
CFrontPanel::~CFrontPanel()
{
}
