#pragma once
#include<string>
using namespace std;
class CDispenser
{
public:
	virtual ~CDispenser();
	CDispenser(const CDispenser& Dispenser);
	CDispenser();
	void operator=(const CDispenser& Dispenser);
	void Fill(int iQuantity);
	virtual void Dispense(int iQuantity);
	int GetCurrentLevel();
	int GetCapacity();
	void ReduceCurrentLevel(int iCurrentLevel);
	void SetName(char* sName);
	CDispenser(int iCapacity, string sName);
	bool CheckExistenceOfDispenser(CDispenser* pDispenser, int iCount, string sName);
	string GetName();
private:
	string m_Name;
	int m_iCapacity;
	int m_iCurrentLevel;
};

