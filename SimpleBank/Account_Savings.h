#ifndef ACCOUNT_SAVINGS_H_
#define ACCOUNT_SAVINGS_H_

#include "Account.h"

class Account_Savings : public Account {
private:
	Account_Savings(Customer* cust, int id) :
		Account(cust, id) {
		this->account_number = id;
	};

public:

	friend class Account_Factory;

	string get_account_type() {
		return string("savings");
	}

	void add_interest() {

	}
};

#endif 
