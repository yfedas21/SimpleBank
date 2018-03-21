#ifndef CUSTOMER_SENIOR_H_
#define CUSTOMER_SENIOR_H_

#include "Customer.h"

class Customer_Senior : public Customer {
private:
	Customer_Senior(string name, string address, int age, string telephone_number) : 
		Customer(name, address, age, telephone_number) {}

	const double SAVINGS_INTEREST = 3.14;
	const double CHECK_INTEREST = 3.14;
	const double CHECK_CHARGE = 2.17;
	const double OVERDRAFT_PENALTY = 88;

public:
	
	friend class Customer_Factory;

	string get_customer_type() {
		return string("senior");
	}
};

#endif 