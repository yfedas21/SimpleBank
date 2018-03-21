#ifndef CUSTOMER_ADULT_H_
#define CUSTOMER_ADULT_H_

#include "Customer.h"

class Customer_Adult : public Customer {
private:
	Customer_Adult(string name, string address, int age, string telephone_number) : 
		Customer(name, address, age, telephone_number) {};

	const double SAVINGS_INTEREST = 0.009;
	const double CHECK_INTEREST = 0.00011;
	const double CHECK_CHARGE = 9.75;
	const double OVERDRAFT_PENALTY = 75;

public:
	
	friend class Customer_Factory;

	string get_customer_type() {
		return string("adult");
	}
};

#endif 