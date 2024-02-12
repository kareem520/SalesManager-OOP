
#include "Customer.h"

struct Location{
    string city,state,street,postal_code;
};
class Company:public Customer{

private:
    Location location;
    string company_name;

public:
    void readCompany(Customer &customer){
        cout <<"Enter Your City: ";
        getline(cin,location.city);

        cout <<"Enter Your State: ";
        getline(cin,location.state);

        cout <<"Enter Your Street: ";
        getline(cin,location.street);

        cout <<"Enter Your postal code: ";
        getline(cin,location.postal_code);

        cout <<"Enter company name: ";
        string name;
        getline(cin,name);
        company_name = name;

        this->phone = customer.getCustomerPhone();
        this->customerRole =customer.getCustomerRole();
        this->userName =customer.getUserName();
        this->email = customer.getUserEmail();
        this->userId = customer.getUserId();
        this->user_role = customer.getEntity();
        this->password = customer.getUserPassword();

    }

    Location getLocation()const{
        return location;
    }
};


ostream&operator<<(ostream &oss,const Company& company ){
    oss<<"Person info:"
       <<"\n\t"<<"Email: "<<company.getUserEmail()
       <<"\n\t"<<"id: "<<company.getUserId()
       <<"\n\t"<<"name: "<<company.getUserName()
       <<"\n\t"<<"Entity: "<<company.getUserRole()
       <<"\n\t"<<"phone number: "<<company.getCustomerPhone()
       <<"\n\t"<<"City: "<<company.getLocation().city
       <<"\n\t"<<"State: "<<company.getLocation().state
       <<"\n\t"<<"Street: "<<company.getLocation().street
       <<"\n\t"<<"postal code: "<<company.getLocation().postal_code;

    return oss;
}