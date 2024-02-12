#include "Customer.h"

class Person: public Customer{

private:
    string address;
    string fullName;

public:
    Person(string address,string fullName){
        this->address = address;
        this->fullName = fullName;
    }
};

