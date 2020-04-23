#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "TransactionStore.h"

class Customer {

private:

	string customerName;
	float balance;
	vector<TransactionStore> storage;
	bool withOrDraw;

public:

	Customer()
	{
		customerName = "";
		balance = 0;
	}

	Customer(string name, float value)
	{
		customerName = name;
		balance = value;
	}

	//Setter and Getter Functions
	string getName() { return customerName; }
	float getBalance() { return balance; }
	void setBalance(float num) { balance = num; }
	void setBool(bool temp) { withOrDraw = temp; }
};