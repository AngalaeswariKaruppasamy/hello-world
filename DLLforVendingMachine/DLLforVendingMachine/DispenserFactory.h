#pragma once
#include"LiquidDispenser.h"
#include"PowderDispenser.h"
#include"SnackDispenser.h"
#include"string"
#include"Recipe.h"
using namespace std;
class CDispenserFactory
{
public:
	CDispenserFactory();
	~CDispenserFactory();
	CDispenser* CreateDispenser(int iChoice, string sName, int iCapacity);
};

