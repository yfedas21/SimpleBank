#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

using std::string;
/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // FIXME: Complete the implementation!
{
private:
	string name;
	string address;
	int age;
	string telephone_number;
	int customer_number;

public:
	Customer() {

	}

	// Mutator functions
	void set_name(string name) {
		this->name = name;
	}

	void set_address(string address) {
		this->address = address;
	}

	void set_age(int age) {
		this->age = age;
	}

	void set_telephone_number(string telephone_number) {
		this->telephone_number = telephone_number;
	}

	void set_customer_number(int customer_number) {
		this->customer_number = customer_number;
	}

	// Accessor functions
	string get_name() { return name; }
	string get_address() { return address; }
	int get_age() { return age; }
	string get_telephone_number() { return telephone_number; }
	int get_customer_number() { return customer_number; }


};


#endif
