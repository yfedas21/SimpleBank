#ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_

#include "Customer.h"
#include "Customer_Adult.h"
#include "Customer_Senior.h"
#include "Customer_Student.h"

using std::string;

class Customer_Factory {
public:
	static Customer *factory(string customer_type, string name, string address, int age, string telephone_number) {
		if (customer_type == "senior")
			return new Customer_Senior(name, address, age, telephone_number);
		else if (customer_type == "student")
			return new Customer_Student(name, address, age, telephone_number);
		else if (customer_type == "adult")
			return new Customer_Adult(name, address, age, telephone_number);
		else throw std::invalid_argument(
			customer_type + " is invalid!");
		
		return NULL;
	}
};

#endif 
