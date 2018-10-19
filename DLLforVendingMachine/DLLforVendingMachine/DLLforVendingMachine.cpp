// DLLforVendingMachine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "VendingMachine.h"
#include"Header.h"

DLLCALL IMyVendingMachineDLL* _cdecl CreateVendingMachine()
{
	return new CVendingMachine();
}
