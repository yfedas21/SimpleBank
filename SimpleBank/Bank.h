#ifndef BANK_H_
#define BANK_H_
#include <vector>
#include <stdexcept>
#include "Account.h"
#include "Account_Factory.h"
#include "Customer.h"
#include "Customer_Factory.h"

/**
The CS273 Bank has Accounts and Customers

@author: Ed Walker
*/
class Bank
{
private:

	// Auto-generate an ID for accounts and customers
	int acct_id;
	int cust_id;

	std::vector<Account *> accounts; // Bank HAS accounts
	std::vector<Customer *> customers;  // Bank HAS customers


	/**
	Return a vector of accounts owned by the specified name of the customer.
	Remember a customer can have many accounts.
	@param name The customer name
	@return vector of account ids
	*/
	std::vector<int> find_accounts_by_name(std::string name)
	{
		std::vector<int> user_accounts;

		for (auto acct : accounts) {
			if (acct->get_customer()->get_name() == name) {
				user_accounts.push_back(acct->get_account());
			}
		}

		return user_accounts;
	}

	/**
	Find a customer based on his/her name
	@param name The customer name
	@return customer object if found, NULL otherwise
	*/
	Customer *find_customer(std::string name)
	{
		for (auto cust : customers) {
			if (cust->get_name() == name) {
				return cust;
			}
		}

		return NULL;
	}

	/**
	Add a new account to a customer object (irrespective of its specific type: adult, senior, or student)
	@param cust The customer object
	@param account_type The account type, i.e. "savings" or "checking"
	@return the newly created account object
	*/
	Account * add_account(Customer *cust, std::string account_type)
	{
		Account *acct = Account_Factory::factory(cust, account_type, acct_id);
		increment(acct_id);

		return acct;
	}

public:
	/** 
		Constructor
	*/
	Bank() : acct_id(1000), cust_id(1000) {}

	/**
	Add account for an existing user
	@param name The customer name
	@param account_type The account type, i.e. "checking" or "savings"
	@return the newly created account object if the customer exist, or NULL otherwise
	*/
	Account* add_account(std::string name, std::string account_type)
	{
		Customer *cust = find_customer(name);
		if (cust == NULL)
			return NULL;

		increment(acct_id);

		return add_account(cust, account_type);
	}

	/**
	Add account for new user.  This creates a new customer and adds an account to him/her.
	@param name Customer name
	@param address Customer address
	@param telephone Customer telephone number
	@param age Customer age
	@param cust_type Customer type, i.e. "adult", "senior" or "student"
	@param account_type Account type, i.e. "checking" or "savings"
	@return the newly created account object
	*/
	Account* add_account(std::string name, std::string address, std::string telephone, int age,
		std::string cust_type, std::string account_type, int id)
	{
		Customer *cust = Customer_Factory::factory(cust_type, name, address, age, telephone, id);

		increment(cust_id);
		increment(acct_id);

		customers.push_back(cust);

		return add_account(cust, account_type);
	}

	/**
	Make a deposit in an account identified by the account id
	@param acct_number	The account id
	@param amt			The amount to deposit
	*/
	void make_deposit(int acct_number, double amt)
	{
		// Don't increment acct_id here, the variable
		// acct is a local variable that gets destroyed
		// once the function is out of scope
		Account *acct = get_account(acct_number);
		if (acct) {
			// FIXME: Deposit the amt in the accountamt
		}
	}

	/**
	Make a withdrawal in an account identified by the account id
	@param acct_number	The account id
	@param amt			The amount to withdraw
	*/
	void make_withdrawal(int acct_number, double amt)
	{
		// See above comment
		Account *acct = get_account(acct_number);
		if (acct) {
			// FIXME: Withdraw the amt from the account
		}
	}

	/**
	Get the list of account numbers associated with a user, identified by his/her name
	@param name The customer name
	@return vector of account ids
	*/
	std::vector<int> get_account(std::string name)
	{
		return find_accounts_by_name(name);
	}

	/**
	Get the account object for an account identified by an account id
	@param acct_name The account id
	@return the account object if it exists, NULL otherwise
	*/
	Account *get_account(int acct_number)
	{
		for (size_t i = 0; i < accounts.size(); i++) {
			if (accounts[i]->get_account() == acct_number)
				return accounts[i];
		}
		return NULL;
	}

	/**
		Increment the acct_id or cust_id by an arbitrary amount
	*/
	void increment(int &id_counter) {
		id_counter += 7;
	}

	/**
		Used in Banking_Application.cpp
		@return The current cust_id
	*/
	int get_cust_id() {
		return cust_id;
	}
};

#endif

