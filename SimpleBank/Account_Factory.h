#ifndef ACCOUNT_FACTORY_H_
#define ACCOUNT_FACTORY_H_

#include "Account.h"
#include "Account_Checking.h"
#include "Account_Savings.h"

class Account_Factory {
	
	static Account *factory(string acct_type) {
		
		if (acct_type == "savings") {
			// return new Account_Savings();
		}

		else if (acct_type == "checking") {
			// return new Account_Checking();
		}

		else throw std::invalid_argument(
			acct_type + " is invalid!");
			
		return NULL;
	}
};

#endif 
