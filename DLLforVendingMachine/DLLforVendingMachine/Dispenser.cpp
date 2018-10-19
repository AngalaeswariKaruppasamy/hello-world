#include "stdafx.h"
#include "Dispenser.h"
#include "string.h"
#include"iostream"
using namespace std;

CDispenser::CDispenser(int iCapacity, string sName)
{
	m_iCapacity = iCapacity;
	m_iCurrentLevel = 0;
	m_Name = sName;
}
CDispenser::CDispenser()
{
	/*m_iCapacity = 0;
	m_iCurrentLevel = 0;
	m_Name = "";*/
}
CDispenser::CDispenser(const CDispenser& Dispenser)
{
	m_iCapacity = Dispenser.m_iCapacity;
	m_iCurrentLevel = Dispenser.m_iCurrentLevel;
	m_Name = Dispenser.m_Name;
}
void CDispenser::operator=(const CDispenser& Dispenser)
{
	//CDispenser Tempdispenser;
	m_iCapacity = Dispenser.m_iCapacity;
	m_iCurrentLevel = Dispenser.m_iCurrentLevel;
	m_Name = Dispenser.m_Name;
	//return Tempdispenser;
}
bool CDispenser::CheckExistenceOfDispenser(CDispenser* pDispenser, int iCount, string sName)
{
	if (pDispenser->GetName() == sName)
		return true;
	return false;
}
string CDispenser::GetName()
{
	return m_Name;
}
void CDispenser::Fill(int iQuantity)
{
	if ((iQuantity + m_iCurrentLevel) < m_iCapacity)
		m_iCurrentLevel = m_iCurrentLevel + iQuantity;
	else
		m_iCurrentLevel = m_iCapacity;
}
void CDispenser::Dispense(int iQuantity)
{

}
void CDispenser::SetName(char* sName)
{
	m_Name = sName;
}
void SetName(string sName);
int CDispenser::GetCurrentLevel()
{
	return m_iCurrentLevel;
}

int CDispenser::GetCapacity()
{
	return m_iCapacity;
}
void CDispenser::ReduceCurrentLevel(int iReduceLevel)
{
	if (m_iCurrentLevel > iReduceLevel)
	{
		m_iCurrentLevel = m_iCurrentLevel - iReduceLevel;
	}
	else
	{
		cout << "Underflow\n";
	}
}
CDispenser::~CDispenser()
{

}
