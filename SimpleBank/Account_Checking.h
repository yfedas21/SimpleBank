#ifndef ACCOUNT_CHECKING_H_
#define ACCOUNT_CHECKING_H_

#include "Account.h"

class Account_Checking : public Account {
private:
	Account_Checking(Customer* cust) :
		Account(cust) {};

public:

	friend class Account_Factory;

	string get_account_type() {
		return string("checking");
	}
};

#endif 