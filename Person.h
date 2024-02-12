//#include ".h"
    #include "CompanyManager.h"

struct Address{
    string City,state,street,postal_code;
};
class Person: public Customer{

private:
    Address address;
    string fullName;

public:

    void readPerson(Customer &customer){
        cout <<"Enter Your City: ";
        getline(cin,address.City);

        cout <<"Enter Your State: ";
        getline(cin,address.state);

        cout <<"Enter Your Street: ";
        getline(cin,address.street);

        cout <<"Enter Your postal code: ";
        getline(cin,address.postal_code);

        cout <<"Enter full name: ";
        string name;
        getline(cin,name);
        fullName = name;

        this->phone = customer.getCustomerPhone();
        this->customerRole =customer.getCustomerRole();
        this->userName =customer.getUserName();
        this->email = customer.getUserEmail();
        this->userId = customer.getUserId();
        this->user_role = customer.getEntity();
        this->password = customer.getUserPassword();
    }

    Address getAddress()const{
        return address;
    }

};


ostream&operator<<(ostream &oss,const Person& person ){
    oss<<"Person info:"
       <<"\n\t"<<"Email: "<<person.getUserEmail()
       <<"\n\t"<<"id: "<<person.getUserId()
       <<"\n\t"<<"name: "<<person.getUserName()
       <<"\n\t"<<"Entity: "<<person.getUserRole()
       <<"\n\t"<<"phone number: "<<person.getCustomerPhone()
       <<"\n\t"<<"City: "<<person.getAddress().City
       <<"\n\t"<<"State: "<<person.getAddress().state
       <<"\n\t"<<"Street: "<<person.getAddress().street
       <<"\n\t"<<"postal code: "<<person.getAddress().postal_code;

    return oss;
}
