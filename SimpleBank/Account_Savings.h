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
		Account::add_interest(this->get_customer()->get_savings_interest());
	}

	// Inherited from the Account base class
	std::string to_string() {
		std::stringstream ss; // for composing the string that describes this account

		ss << "  Customer number: " << this->get_customer()->get_customer_number() << std::endl;
		ss << "  Customer name: " << this->get_customer()->get_name() << std::endl;
		ss << "  Account Type: " << this->get_account_type() << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		ss << "  Balance: " << this->get_balance() << std::endl;
		ss << "  Number of Transactions: " << this->transactions.size() << std::endl;
		return ss.str();
	}

	/**
		Deposits amount into account
		@param amt The deposit amount
	*/
	void deposit(double amt) {
		balance += amt;

		Transaction *tran = new Transaction(this->get_customer()->get_customer_number(),
			string("deposit"), this->get_balance(), this->get_fees());

		transactions.push_back(tran);
	}

	/**
		Withdraws amount from account
		@param amt The withdrawal amount
	*/
	void withdraw(double amt) {
		balance -= amt;

		Transaction *tran = new Transaction(customer->get_customer_number(),
			string("withdraw"), balance, this->get_fees());

		transactions.push_back(tran);
	}
};

#endif 
