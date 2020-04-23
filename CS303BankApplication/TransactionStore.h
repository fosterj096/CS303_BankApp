#pragma once
//#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//This class is used an object that stores the transactions of a certain individual

class TransactionStore {

private:
	float amount;
	bool withdrawOrDeposit; //false for deposit, true for withdrawal
	float reference;
	string accountName;


public:
	//constructor
	TransactionStore() {

		accountName = "0";
		withdrawOrDeposit = false;
		amount = 0; //money customer will be using
		float reference = 0; //random number for reference
	}

	void printTransaction();

	//Getters
	string getName() { return accountName; }
	float getAmount() { return amount; }
	bool getWithorDraw() { return  withdrawOrDeposit; }
	int getReference() { return reference; }

	//Call this function to set the reference for most recent transaction
	TransactionStore(float tempAmount, bool var, float tempRef, string name)
	{
		amount = tempAmount;
		withdrawOrDeposit = var;
		reference = tempRef;
		accountName = name;
	}

	void setTransaction(float tempAmount, bool var, float tempRef, string name)
	{
		amount = tempAmount;
		withdrawOrDeposit = var;
		reference = tempRef;
		accountName = name;
	}

};