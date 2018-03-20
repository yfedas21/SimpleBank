#ifndef CUSTOMER_SENIOR_H_
#define CUSTOMER_SENIOR_H_

#include "Customer.h"

class Customer_Senior : public Customer {
	Customer_Senior() {
		// Default constructor
	}

	const double SAVINGS_INTEREST = 3.14;
	const double CHECK_INTEREST = 3.14;
	const double CHECK_CHARGE = 2.17;
	const double OVERDRAFT_PENALTY = 88;
};

#endif 