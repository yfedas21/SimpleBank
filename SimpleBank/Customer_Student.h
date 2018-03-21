#ifndef CUSTOMER_STUDENT_H_
#define CUSTOMER_STUDENT_H_

#include "Customer.h"

class Customer_Student : public Customer {
private:
	Customer_Student(string name, string address, int age, string telephone_number) : 
		Customer(name, address, age, telephone_number) {}

	const double SAVINGS_INTEREST = 0.014;
	const double CHECK_INTEREST = 0.0002;
	const double CHECK_CHARGE = 4.75;
	const double OVERDRAFT_PENALTY = 25;

public:

	friend class Customer_Factory;

	string get_customer_type() {
		return string("student");
	}
};

#endif 