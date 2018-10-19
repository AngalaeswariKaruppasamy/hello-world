#include "stdafx.h"
#include "FrontPanel.h"
#include<iostream>
using namespace std;

CFrontPanel::CFrontPanel()
{

}
void CFrontPanel::DisplayMessage(char* pMessage)
{
	int length = strlen(pMessage);
	for (int i = 0; i < length; i++)
	{
		cout << pMessage[i];
	}
}
void CFrontPanel::DisplayString(string sString)
{
	cout << sString;
}
void CFrontPanel::DisplayCurrentLevelOfItem(char* pItemName, int iCurrent)
{
	cout << "The Current Level OF Item ";
	DisplayMessage(pItemName);
	cout << iCurrent;
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
	cout << "Enter the  your \n";
	int ichoice;
	cin >> ichoice;
	return ichoice;
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
	cout << "1.Fill Recipi\n2.Add Employee\n3.view Current Level Of Item\n4.View All Employee\n5.view total number of Usage\n";
	cout << "6.Add Dispenser\n.7.Remove dispenser.\n8.Fix Rate for Recipe.\n9.Admin Logout.\n10.Switch OFF Machine\n";
	do
	{
		cout << "Enter your choice\n";
		cin >> choice;
		if (choice > 10)
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
		return "Fill Recipi";
	case 2:
		return "Add Employee";
	case 3:
		return "View Current Level Of Item";
	case 4:
		return "View All Employee";
	case 5:
		return "View total number of Usage";
	case 6:
		return "Add Dispenser";
	case 7:
		return "Remove dispenser";
	case 8:
		return "Fix Rate for Recipe";
	case 9:
		return "Admin Logout";
	case 10:
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

CFrontPanel::~CFrontPanel()
{
}
