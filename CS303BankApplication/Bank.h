#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>
#include <map>
#include "Customer.h"
//#include "TransactionStore.h"
using namespace std;

class Bank {

private:

	stack<Customer> customers;
	stack<Customer> helpedCustomers;
	vector<TransactionStore> transactionStorage;


public:

	void createCustomers();
	void printStack();
	void runBank();
	void showAllTransactions();



};