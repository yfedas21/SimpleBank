#ifndef ACCOUNT_FACTORY_H_
#define ACCOUNT_FACTORY_H_

#include "Account.h"
#include "Account_Checking.h"
#include "Account_Savings.h"

class Account_Factory {
public:
	static Account *factory(Customer *cust, string acct_type, int id) {
		if (acct_type == "savings") 
			return new Account_Savings(cust, id);
		else if (acct_type == "checking")
			return new Account_Checking(cust, id);
		else throw std::invalid_argument(
			acct_type + " is invalid!");
			
		return NULL;
	}
};

#endif 
