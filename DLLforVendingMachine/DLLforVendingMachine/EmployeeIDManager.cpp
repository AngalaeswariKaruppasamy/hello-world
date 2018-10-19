#include "stdafx.h"
#include "EmployeeIDManager.h"


CEmployeeIDManager::CEmployeeIDManager()
{
	m_pHead = NULL;
	m_iIDCount = 0;
}
int* CEmployeeIDManager::GetEmployeeIDList()
{
	Node* pTemp = m_pHead;
	int* piIdList = new int[m_iIDCount];
	for (int i = 0; i < m_iIDCount; i++)
	{
		piIdList[i] = (*(pTemp + i)).iEmployeeID;
	}
	return piIdList;
}
int* CEmployeeIDManager::GetEmployeeAmountList()
{
	Node* pTemp = m_pHead;
	int* piAmountList = new int[m_iIDCount];
	for (int i = 0; i < m_iIDCount; i++)
	{
		piAmountList[i] = (*(pTemp + i)).iAmount;
	}
	return piAmountList;
}

int CEmployeeIDManager::GetEmployeeCount()
{
	return m_iIDCount;
}
bool CEmployeeIDManager::AddEmployeeID(int id)
{
	bool flag = SearchID(id, 0);
	if (flag)
		return false;
	Node iNewNode = CreateNewIDNode(id);
	Node *pTemp = m_pHead;

	if (pTemp == NULL)
	{
		m_pHead = new Node[m_iIDCount + 1];
		*m_pHead = iNewNode;
	}
	else
	{
		m_pHead = new Node[m_iIDCount + 1];
		for (int i = 0; i <m_iIDCount; i++)
		{
			*(m_pHead + i) = *(pTemp + i);
		}
		*(m_pHead + m_iIDCount) = iNewNode;
	}
	m_iIDCount++;
	delete[] pTemp;
	pTemp = NULL;
	return true;
}
bool CEmployeeIDManager::DeleteEmployeeID(int IDDelete)
{
	bool occur = false;
	for (int i = 0; i <m_iIDCount; i++)
	{
		if ((*(m_pHead + i)).iEmployeeID == IDDelete)
		{
			*(m_pHead + i) = *(m_pHead + i + 1);
			occur = true;
			break;
		}
		if (occur == true)
		{
			*(m_pHead + i) = *(m_pHead + i + 1);
		}
	}
	return occur;
}
bool CEmployeeIDManager::SearchID(int iSearchID, int iAmount)
{         
	for (int i = 0; i <m_iIDCount; i++)
	{
		if ((*(m_pHead + i)).iEmployeeID == iSearchID)
		{
			(*(m_pHead + i)).iAmount = (*(m_pHead + i)).iAmount + iAmount;
			return true;
		}
	}
	return false;
}
int CEmployeeIDManager::GetAmount(Node nNode)
{
	return nNode.iAmount;
}
Node CEmployeeIDManager::CreateNewIDNode(int iID)
{
	Node pNewNode;
	pNewNode.iEmployeeID = iID;
	pNewNode.iAmount = 0;
	return pNewNode;
}
CEmployeeIDManager::~CEmployeeIDManager()
{
	delete m_pHead;
	m_pHead = NULL;
}
