#ifndef ACCOUNT_CHECKING_H_
#define ACCOUNT_CHECKING_H_

#include "Account.h"

class Account_Checking : public Account {
private:
	Account_Checking(Customer* cust, int id) :
		Account(cust, id) {
		this->account_number = id;
	};

public:

	friend class Account_Factory;

	string get_account_type() {
		return string("checking");
	}

	void add_interest() {

	}
};

#endif 