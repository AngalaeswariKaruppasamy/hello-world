#include "stdafx.h"
#include "VendingMachine.h"
#include"iostream"
#include"DispenserFactory.h"
using namespace std;

CVendingMachine::CVendingMachine()
{
	m_ppDispenser = NULL;
	//m_pPanelObject = NULL;
	m_EmployeeObject = new CEmployeeIDManager;
	m_pControllerObject = new CController;
	m_iUsageCount = 0;
	m_pRecipe = m_pControllerObject->GetRecipe();
	m_pFactory = new CDispenserFactory;
}
bool CVendingMachine::Triggercontroller(string sChoice)
{
	bool flag=m_pControllerObject->TriggerDispenser(m_ppDispenser, m_iDispenserCount, sChoice);
	return flag;
}
void CVendingMachine::UpdateEmployeeAmount(int iAmount)
{
	//m_EmployeeObject->ReSetAmount(iAmount);
}

void CVendingMachine::SetUsageCount(int iCount)
{
	m_iUsageCount = iCount;
}
string* CVendingMachine::GetDispenserNameList()
{
	return(m_pRecipe->GetdispenserNameList());
}
string CVendingMachine::GetDispenserName(int i)
{
	string* name = m_pRecipe->GetdispenserNameList();
	return name[i - 1];
}
bool CVendingMachine::AddEmployee(int iId)
{
	bool flag = m_EmployeeObject->AddEmployeeID(iId);
	return flag;
}
int CVendingMachine::GetCurrentLevelOfDispenser(string name)
{
	CDispenser* Dispenser = GetDispenser(name);
	int iCurrentLevel = Dispenser->GetCurrentLevel();
	return iCurrentLevel;
}

bool CVendingMachine::CheckEnoughMoney(int iNumber, int iCost)
{
	bool flag=m_CashManagerObject.checkEnoughMoney(iNumber, iCost);
	return flag;
}
bool CVendingMachine::SetAmount(string sRecipe, int iPrice)
{
	m_pRecipe->SetAmount(sRecipe, iPrice);
}
int CVendingMachine::CalculateBalance(int iNumber, int iCost)
{
	int iBalance= m_CashManagerObject.CalculateBalance(iNumber, iCost);
	return iBalance;
}
void CVendingMachine::Delete()
{
	delete this;
}
bool CVendingMachine::CheckExistence(CDispenser** ppDispenser, int m_iDispenserCount, string sName)
{
	bool flag = false;
	for (int i = 0; i < m_iDispenserCount; i++)
	{
		flag = ppDispenser[i]->CheckExistenceOfDispenser(ppDispenser[i], m_iDispenserCount, sName);
		if (flag == true)
			return flag;
	}
	return flag;
}
bool CVendingMachine::SearchID(int iID, int iAmount)
{
	bool flag = m_EmployeeObject->SearchID(iID, iAmount);
	return flag;
}
int CVendingMachine::GetDispenserCount()
{
	return m_iDispenserCount;
}
int CVendingMachine::GetAmount(string sRecipe)
{
	int iAmount = m_pRecipe->GetAmount(sRecipe);
	return iAmount;
}
string* CVendingMachine::GetRecipeNameList()
{
	string* pstrRecipeList = m_pRecipe->GetRecipeNameList();
	return pstrRecipeList;
}
int CVendingMachine::GetRecipeCount()
{
	int iCount = m_pRecipe->GetRecipeCount();
	return iCount;
}
int  CVendingMachine::GetUsageCount()
{
	return m_iUsageCount;
}
int* CVendingMachine::EmployeeIDList()
{
	int* piIdList = m_EmployeeObject->GetEmployeeIDList();
	return piIdList;
}
int* CVendingMachine::EmployeeAmountList()
{
	int *piAmountList = m_EmployeeObject->GetEmployeeAmountList();
	return piAmountList;
}
int CVendingMachine::GetEmployeeCount()
{
	int iCount = m_EmployeeObject->GetEmployeeCount();
	return iCount;
}
bool CVendingMachine::AddDispenser(int iChoice, int iCapacity)
{
	CDispenser** ppTemp = m_ppDispenser;
	switch (iChoice)
	{
	case 1:
	{
		bool flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Milk");
		if (flag)
			cout << "Already Exist\n";
		else
		{
			flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Coffee");
			if (flag)
				cout << "Already Exist\n";
			else
			{
				flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Tea");
				if (flag)
					cout << "Already Exist\n";
				if (!flag)
				{

					flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Hot Water");
					if (flag)
					{
						m_ppDispenser = new CDispenser*[m_iDispenserCount + 2];
						for (int i = 0; i < m_iDispenserCount; i++)
							m_ppDispenser[i] = ppTemp[i];
						m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Milk", iCapacity);
						m_pRecipe->CreateDispenserNameList("Milk");
						m_pRecipe->AddRecipeName("Milk");
						m_ppDispenser[m_iDispenserCount + 1] = m_pFactory->CreateDispenser(2, "Sugar", iCapacity);
						m_pRecipe->CreateDispenserNameList("Sugar");
						m_pRecipe->AddRecipeName("Sugar");
						m_iDispenserCount = m_iDispenserCount + 2;
					}
					else
					{
						m_ppDispenser = new CDispenser*[m_iDispenserCount + 3];
						for (int i = 0; i < m_iDispenserCount; i++)
							m_ppDispenser[i] = ppTemp[i];
						m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Milk", iCapacity);
						m_pRecipe->CreateDispenserNameList("Milk");
						m_pRecipe->AddRecipeName("Milk");
						m_ppDispenser[m_iDispenserCount + 1] = m_pFactory->CreateDispenser(2, "Sugar", iCapacity);
						m_pRecipe->CreateDispenserNameList("Sugar");
						m_pRecipe->AddRecipeName("Sugar");
						m_ppDispenser[m_iDispenserCount + 2] = m_pFactory->CreateDispenser(1, "Hot Water", iCapacity);
						m_pRecipe->CreateDispenserNameList("Hot Water");
						m_pRecipe->AddRecipeName("Hot Water");
						m_iDispenserCount = m_iDispenserCount + 3;
					}
				}
			}
		}
	}
	break;
	case 2:
	{
		bool flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Coffee");
		if (flag)
			cout << "Already Exist\n";
		else
		{
			flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Milk");
			if (flag)
			{
				m_ppDispenser = new CDispenser*[m_iDispenserCount + 1];
				for (int i = 0; i < m_iDispenserCount; i++)
					m_ppDispenser[i] = ppTemp[i];
				m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Coffee", iCapacity);
				m_pRecipe->CreateDispenserNameList("Coffee");
				m_pRecipe->AddRecipeName("Coffee");
				m_iDispenserCount = m_iDispenserCount + 1;
			}
			else
			{
				flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Tea");
				if (flag)
				{
					m_ppDispenser = new CDispenser*[m_iDispenserCount + 1];
					for (int i = 0; i < m_iDispenserCount; i++)
						m_ppDispenser[i] = ppTemp[i];
					m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Coffee", iCapacity);
					m_pRecipe->CreateDispenserNameList("Coffee");
					m_pRecipe->AddRecipeName("Coffee");
					m_iDispenserCount = m_iDispenserCount + 1;
				}
				if (!flag)
				{
					flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Hot Water");
					if (flag)
					{
						m_ppDispenser = new CDispenser*[m_iDispenserCount + 3];
						for (int i = 0; i < m_iDispenserCount; i++)
							m_ppDispenser[i] = ppTemp[i];
						m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Milk", iCapacity);
						m_pRecipe->CreateDispenserNameList("Milk");
						m_pRecipe->AddRecipeName("Milk");
						m_ppDispenser[m_iDispenserCount + 1] = m_pFactory->CreateDispenser(2, "Sugar", iCapacity);
						m_pRecipe->CreateDispenserNameList("Sugar");
						m_pRecipe->AddRecipeName("Sugar");
						m_ppDispenser[m_iDispenserCount + 2] = m_pFactory->CreateDispenser(2, "Coffee", iCapacity);
						m_pRecipe->CreateDispenserNameList("Coffee");
						m_pRecipe->AddRecipeName("Coffee");
						m_iDispenserCount = m_iDispenserCount + 3;
					}
					else
					{
						m_ppDispenser = new CDispenser*[m_iDispenserCount + 4];
						for (int i = 0; i < m_iDispenserCount; i++)
							m_ppDispenser[i] = ppTemp[i];
						m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Milk", iCapacity);
						m_pRecipe->CreateDispenserNameList("Milk");
						m_pRecipe->AddRecipeName("Milk");
						m_ppDispenser[m_iDispenserCount + 1] = m_pFactory->CreateDispenser(2, "Sugar", iCapacity);
						m_pRecipe->CreateDispenserNameList("Sugar");
						m_pRecipe->AddRecipeName("Sugar");
						m_ppDispenser[m_iDispenserCount + 2] = m_pFactory->CreateDispenser(2, "Coffee", iCapacity);
						m_pRecipe->CreateDispenserNameList("Coffee");
						m_pRecipe->AddRecipeName("Coffee");
						m_ppDispenser[m_iDispenserCount + 2] = m_pFactory->CreateDispenser(1, "Hot Water", iCapacity);
						m_pRecipe->CreateDispenserNameList("Hot Water");
						m_pRecipe->AddRecipeName("Hot Water");
						m_iDispenserCount = m_iDispenserCount + 4;
					}
				}
			}
		}
	}
	break;
	case 3:
	{
		bool flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Tea");
		if (flag)
			cout << "Already Exist\n";
		else
		{
			flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Milk");
			if (flag)
			{
				m_ppDispenser = new CDispenser*[m_iDispenserCount + 1];
				for (int i = 0; i < m_iDispenserCount; i++)
					m_ppDispenser[i] = ppTemp[i];
				m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Tea", iCapacity);
				m_pRecipe->CreateDispenserNameList("Tea");
				m_pRecipe->AddRecipeName("Tea");
				m_iDispenserCount = m_iDispenserCount + 1;
			}
			else
			{
				flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Coffee");
				if (flag)
				{
					m_ppDispenser = new CDispenser*[m_iDispenserCount + 1];
					for (int i = 0; i < m_iDispenserCount; i++)
						m_ppDispenser[i] = ppTemp[i];
					m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Tea", iCapacity);
					m_pRecipe->CreateDispenserNameList("Tea");
					m_pRecipe->AddRecipeName("Tea");
					m_iDispenserCount = m_iDispenserCount + 1;
				}
				if (!flag)
				{
					flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Hot Water");
					if (flag)
					{
						m_ppDispenser = new CDispenser*[m_iDispenserCount + 3];
						for (int i = 0; i < m_iDispenserCount; i++)
							m_ppDispenser[i] = ppTemp[i];
						m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Milk", iCapacity);
						m_pRecipe->CreateDispenserNameList("Milk");
						m_pRecipe->AddRecipeName("Milk");
						m_ppDispenser[m_iDispenserCount + 1] = m_pFactory->CreateDispenser(2, "Sugar", iCapacity);
						m_pRecipe->CreateDispenserNameList("Sugar");
						m_pRecipe->AddRecipeName("Sugar");
						m_ppDispenser[m_iDispenserCount + 2] = m_pFactory->CreateDispenser(2, "Tea", iCapacity);
						m_pRecipe->CreateDispenserNameList("Tea");
						m_pRecipe->AddRecipeName("Tea");
						m_iDispenserCount = m_iDispenserCount + 3;
					}
					else
					{
						m_ppDispenser = new CDispenser*[m_iDispenserCount + 4];
						for (int i = 0; i < m_iDispenserCount; i++)
							m_ppDispenser[i] = ppTemp[i];
						m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(2, "Milk", iCapacity);
						m_pRecipe->CreateDispenserNameList("Milk");
						m_pRecipe->AddRecipeName("Milk");
						m_ppDispenser[m_iDispenserCount + 1] = m_pFactory->CreateDispenser(2, "Sugar", iCapacity);
						m_pRecipe->CreateDispenserNameList("Tea");
						m_pRecipe->AddRecipeName("Sugar");
						m_ppDispenser[m_iDispenserCount + 2] = m_pFactory->CreateDispenser(2, "Tea", iCapacity);
						m_pRecipe->CreateDispenserNameList("Tea");
						m_pRecipe->AddRecipeName("Tea");
						m_ppDispenser[m_iDispenserCount + 2] = m_pFactory->CreateDispenser(1, "Hot Water", iCapacity);
						m_pRecipe->CreateDispenserNameList("Hot Water");
						m_pRecipe->AddRecipeName("Hot Water");
						m_iDispenserCount = m_iDispenserCount + 2;
					}
				}
			}
		}
	}
	break;
	case 4:
	{
		bool flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Hot Water");
		if (flag)
			cout << "Already Exist\n";
		else
		{
			m_ppDispenser = new CDispenser*[m_iDispenserCount + 1];
			for (int i = 0; i < m_iDispenserCount; i++)
				m_ppDispenser[i] = ppTemp[i];
			m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(1, "Hot Water", iCapacity);
			m_pRecipe->CreateDispenserNameList("Hot Water");
			m_pRecipe->AddRecipeName("Hot Water");
			m_iDispenserCount = m_iDispenserCount + 1;
		}
	}
	break;
	case 5:
	{
		bool flag = CheckExistence(m_ppDispenser, m_iDispenserCount, "Snack");
		if (flag)
			cout << "Already Exist\n";
		else
		{
			m_ppDispenser = new CDispenser*[m_iDispenserCount + 1];
			for (int i = 0; i < m_iDispenserCount; i++)
				m_ppDispenser[i] = ppTemp[i];
			m_ppDispenser[m_iDispenserCount] = m_pFactory->CreateDispenser(3, "Snack", iCapacity);
			m_pRecipe->CreateDispenserNameList("Snack");
			m_pRecipe->AddRecipeName("Snack");
			m_iDispenserCount = m_iDispenserCount + 1;
		}
	}
	break;
	}

	return true;
}

CDispenser* CVendingMachine::GetDispenser(string sName)
{
	int iSize = m_pRecipe->GetDespenserCount();
	for (int i = 0; i < iSize; i++)
	{
		string sTempName = m_ppDispenser[i]->GetName();
		if (sName == sTempName)
			return m_ppDispenser[i];
	}
	return NULL;
}
bool CVendingMachine::CreateEmployeeList(int iId)
{
	bool flag = m_EmployeeObject->AddEmployeeID(iId);
	return flag;
}

CVendingMachine::~CVendingMachine()
{
	int iSize = m_pRecipe->GetDespenserCount();
	for (int i = 0; i < iSize; i++)
		delete[] m_ppDispenser[i];
	delete[] m_ppDispenser;
	m_ppDispenser = NULL;
	delete m_EmployeeObject;
	m_EmployeeObject = NULL;
	delete m_pControllerObject;
	m_pControllerObject = NULL;
	delete m_pRecipe;
	m_pRecipe = NULL;
}
bool CVendingMachine::FillRecipi(string iChoice, int iAmount)
{
	int iCurrent, iCapacity;
	CDispenser* pTemp = GetDispenser(iChoice);
	iCurrent = pTemp->GetCurrentLevel();
	iCapacity = pTemp->GetCapacity();
	if ((iCurrent + iAmount) <= iCapacity)
	{
		pTemp->Fill(iAmount);
		return true;
	}
	else
	{
		pTemp->Fill(iAmount);
		return false;
	}
}
