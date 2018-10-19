#pragma once
struct Node
{
	int iEmployeeID;
	int iAmount = 0;
};
class CEmployeeIDManager
{
public:
	CEmployeeIDManager();
	bool  AddEmployeeID(int id);
	Node CreateNewIDNode(int iID);
	bool DeleteEmployeeID(int pinDelete);
	bool SearchID(int iID, int iAmount);
	//bool ReSetAmount(Node nNode, int iAmount);
	~CEmployeeIDManager();
	int GetAmount(Node nNode);
	int* GetEmployeeIDList();
	int* GetEmployeeAmountList();
	int GetEmployeeCount();
private:
	int m_iIDCount;
	Node* m_pHead;
};