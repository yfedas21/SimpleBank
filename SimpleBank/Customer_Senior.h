#ifndef CUSTOMER_SENIOR_H_
#define CUSTOMER_SENIOR_H_

#include "Customer.h"

class Customer_Senior : public Customer {
private:
	Customer_Senior(string name, string address, int age, string telephone_number) : 
		Customer(name, address, age, telephone_number) {}

	const double SAVINGS_INTEREST = 0.011;
	const double CHECK_INTEREST = 0.00019;
	const double CHECK_CHARGE = 5.25;
	const double OVERDRAFT_PENALTY = 40;

public:
	
	friend class Customer_Factory;

	const double get_savings_interest() {
		return this->SAVINGS_INTEREST;
	}

	const double get_check_interest() {
		return this->CHECK_INTEREST;
	}

	const double get_check_charge() {
		return this->CHECK_CHARGE;
	}

	const double get_overdraft_penalty() {
		return this->OVERDRAFT_PENALTY;
	}

	string get_customer_type() {
		return string("senior");
	}
};

#endif 