#include "stdafx.h"
#include "DispenserFactory.h"
#include<iostream>
#include"Recipe.h"
using namespace std;

CDispenserFactory::CDispenserFactory()
{

}


CDispenser* CDispenserFactory::CreateDispenser(int iChoice, string sName, int iCapacity)
{
	CDispenser* pTemp = NULL;
	switch (iChoice)
	{
	case 1:
		pTemp = new CLiquidDispenser(iCapacity, sName);
		break;
	case 2:
		pTemp = new CPowderDispenser(iCapacity, sName);
		break;
	case 3:
		pTemp = new CSnackDispenser(iCapacity, sName);
		break;
	}
	return pTemp;
}

CDispenserFactory::~CDispenserFactory()
{
}
