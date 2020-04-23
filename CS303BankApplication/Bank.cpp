#include <vector>
#include <stack>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include "Bank.h"
#include "Customer.h"
#include "TransactionStore.h"
using namespace std;

//Reads in names and values from "Names.txt" into a vector which then pushes them onto the stack in order
void Bank::createCustomers() {

	vector<Customer> printVector;
	fstream openFile;
	openFile.open("Names.txt");
	for (int i = 0; i < 10; i++)
	{
		string temp;
		float tempVal;
		openFile >> temp >> tempVal;
		//Customer(temp, tempVal);
		printVector.push_back(Customer(temp, tempVal));
	}

	for (int i = 0; i < 10; i++)
		customers.push(printVector[i]);
}

//Prints the stack, current customer and amount of customers left
void Bank::printStack()
{
	if (customers.size() != 0)
	{
		Customer temp = customers.top();
		cout << "The next customer waiting is: " << temp.getName() << endl;
		cout << "The current amount of customers waiting is.. " << customers.size() << endl;
		cout << "* ----------------------------------------------- * " << endl;
	}

	else {
		cout << "There are no more customers." << endl;
	}
}

//The main function of the program. Goes through the stack and performs a withdrawal
//or deposit for every customer.
void Bank::runBank()
{
	int counter = 100; //used for reference number and when to display stack
	while (customers.size() != 0)
	{
		int random = rand() % 2; //used for bool decision in withdraw of deposit

		if (counter % 5 == 0)
			printStack();

		Customer temp = customers.top();
		customers.pop();

		cout << "Welcome to the Foster Bank, " << temp.getName() << "!" << endl;
		cout << "Would you like to make a deposit or withdrawal?" << endl;

		if (random == 1) //deposit
		{
			cout << "Looks like you will be depositing, must be nice!" << endl;
			cout << "* ----------------------------------------------------- *" << endl;
			TransactionStore tempTransaction;
			float reference = 1000 + counter;
			counter++;
			temp.setBalance(temp.getBalance() + 500);
			temp.setBool(random);
			tempTransaction.setTransaction(temp.getBalance(), random, reference, temp.getName());
			transactionStorage.push_back(tempTransaction);
			helpedCustomers.push(temp);
		}

		if (random == 0) //withdrawal
		{
			cout << "You will be withdrawing, don't spend it all in one place." << endl;
			cout << "* ----------------------------------------------------- *" << endl;
			TransactionStore tempTransaction;
			float reference = 1000 + counter;
			counter++;
			temp.setBalance(temp.getBalance() - 500);
			temp.setBool(random);
			tempTransaction.setTransaction(temp.getBalance(), random, reference, temp.getName());
			transactionStorage.push_back(tempTransaction);
			helpedCustomers.push(temp);
		}

	}
}

//Shows all of the transactions that the runBank() function performed
void Bank::showAllTransactions()
{
	cout << "Printing all transactions that occured today. " << endl;
	cout << "* ------------------------------------------ *" << endl;
	const int size = transactionStorage.size();
	for (int i = 0; i < size; i++)
	{
		transactionStorage[i].printTransaction();
	}




}