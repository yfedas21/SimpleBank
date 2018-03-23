#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>
#include <sstream>
#include "Customer.h"
#include "Transaction.h"

using std::string;

/**
	The Bank has Accounts and an Account belongs to a Customer.
	Additionally, there are specialized types of accounts: Checking_Account and Savings_Account.
	Checking_Account and Savings_Account have specialized ways of adding interest, and describing itself.

	@author: Ed Walker
*/

class Account {

protected:
	Customer *customer;		// The customer who owns this account
	double balance;			// The available balance in this account
	int account_number;		// A unique number identifying this account
	std::vector<Transaction *> transactions;  // The record of transactions that have occured with this account

	/**
		Describe fees associated with the customer who owns this account.
		The fee will depend on the specific type of customer.
		@return string showing checking and overdraft fees
	*/
	std::string get_fees()
	{
		double overdraft, charge;

		// Polymorphism: calls the correct virtual methods from the specific customer type
		overdraft = customer->get_overdraft_penalty();
		charge = customer->get_check_charge();

		std::stringstream ss;
		ss << "Check Charge: " << charge << " Overdraft Fee: " << overdraft;
		return ss.str();
	}

protected:
	/**
		Add interest based on a specified interest rate to account
		@param interest	The interest rate
	*/
	void add_interest(double interest) {
		double amt = balance*interest;
		balance = balance + amt;

		Transaction *tran = new Transaction(customer->get_customer_number(), 
			string("add_interest"), balance, this->get_fees());

		transactions.push_back(tran);
	}

public:
	/**
		Constructor requires a customer to create an account
		Balance always starts with 0 when account is created.
	*/
	Account(Customer *cust, int id) : customer(cust), account_number(id), balance(0) {}

	/**
	Generic accesser and setter methods for properties customer, balance, and account_number
	*/

	Customer *get_customer() {
		return customer;
	}

	void set_customer(Customer *cust) {
		customer = cust;
	}

	int get_account() {
		return account_number;
	}

	void set_balance(double new_balance) {
		balance = new_balance;
	}

	// This function doesn't do anything
	// because of auto-generated ID
	void set_account(int account_number) {
		int useless_function = account_number;
	}

	double get_balance() {
		return balance;
	}

	/**
		Generic method describing the account information.

		Remember that you will need to indicate if an account is Savings or Checking in
		an overridden version of to_string() in the derived classes.

		@return string describing generic information about the account

		Implemented as a pure virtual function
	*/
	virtual std::string to_string() = 0;

	/**
		Deposits amount into account
		@param amt The deposit amount
		
		Implemented deposit to be pure virtual
	*/
	virtual void deposit(double amt) = 0;


	/**
		Withdraws amount from account
		@param amt The withdrawal amount

		Implemented withdraw to be pure virtual
	*/
	virtual void withdraw(double amt) = 0;

	// We want the Savings_Account and Checking_Account to implement this.
	virtual void add_interest() = 0;

};



#endif
