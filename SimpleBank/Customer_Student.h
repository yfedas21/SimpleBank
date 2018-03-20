#ifndef CUSTOMER_STUDENT_H_
#define CUSTOMER_STUDENT_H_

#include "Customer.h"

class Customer_Student : public Customer {
private:
	Customer_Student() : Customer() {}

	const double SAVINGS_INTEREST = 3.14;
	const double CHECK_INTEREST = 3.14;
	const double CHECK_CHARGE = 2.17;
	const double OVERDRAFT_PENALTY = 88;

public:
	friend class Customer;

};

#endif 