#pragma once
#include "Customer.h"
#include "TransactionStore.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void TransactionStore::printTransaction()
{
	cout << "Client: " << accountName << endl;
	if (withdrawOrDeposit == 1)
		cout << "Amount Withdrawn: $" << amount << endl;

	if (withdrawOrDeposit == 0)
		cout << "Amount Deposited: $" << amount << endl;

	cout << "Transaction Reference Number: #" << reference << endl;
	cout << "End of this transaction. Thank you. " << endl;
	cout << "* -------------------------------- *" << endl;
}