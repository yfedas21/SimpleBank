#ifndef CUSTOMER_ADULT_H_
#define CUSTOMER_ADULT_H_

#include "Customer.h"

class Customer_Adult : public Customer {
	Customer_Adult() {
		// Default constructor
	}

	const double SAVINGS_INTEREST = 3.14;
	const double CHECK_INTEREST = 3.14;
	const double CHECK_CHARGE = 2.17;
	const double OVERDRAFT_PENALTY = 88;
};

#endif 