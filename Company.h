
#include "Customer.h"


class Company:public Customer{

private:
    string location;
    string company_name;

public:

    virtual void print()override{
        cout <<this;
    }

    virtual void sign_up_name()override{
        string name;
        cout <<"Enter company name: ";
        getline(cin,name);
        setName(name);
    }
    virtual void sign_up_address()override{

        string add;
        cout <<"Enter company location: ";
        getline(cin,add);
        setAddress(add);
    }

    void setAddress(string add){
        this->location = add;
    }

    void setName(string name){
        this->company_name = name;
    }

    string getLocation()const{
        return location;
    }
};


ostream&operator<<(ostream &oss,const Company& company ){
    oss<<"Company info:"
       <<"\n\t"<<"Email: "<<company.getUserEmail()
       <<"\n\t"<<"id: "<<company.getUserId()
       <<"\n\t"<<"name: "<<company.getUserName()
       <<"\n\t"<<"Entity: "<<company.getUserRole()
       <<"\n\t"<<"phone number: "<<company.getCustomerPhone()
       <<"\n\t"<<"address: "<<company.getLocation();

    return oss;
}