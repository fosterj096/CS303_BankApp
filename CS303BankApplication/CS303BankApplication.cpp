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

int main()
{

	srand(time(NULL)); //setting random time
	Bank test;
	test.createCustomers();
	test.runBank();
	test.showAllTransactions();
	
    
}


