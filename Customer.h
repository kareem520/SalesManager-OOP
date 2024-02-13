#include "User.h"

#include "Coupon.h"
#include "Transaction.h"

enum class EntityCustomer{
    person,company
};

class Customer: public User {

protected:

    string phone;
    EntityCustomer customerRole;
    Coupon discount;


public:


    virtual void print()=0;
    virtual void sign_up_address()=0;
    virtual void sign_up_name()=0;

    void setRole(EntityCustomer role){
        this->customerRole = role;
    }

    EntityCustomer getCustomerRole(){
        return customerRole;
    }

    void setCustomerPhone(string phone){
        this->phone = phone;
    }

    string getCustomerPhone() const {
        return phone;
    }

    Customer &getMyCustomer(){
        return *this;
    }



};

ostream&operator<<(ostream &oss,const Customer& customer ){
    oss<<"Customer info:"
       <<"\n\t"<<"Email: "<<customer.getUserEmail()
       <<"\n\t"<<"id: "<<customer.getUserId()
       <<"\n\t"<<"name: "<<customer.getUserName()
       <<"\n\t"<<"Entity: "<<customer.getUserRole()
       <<"\n\t"<<"phone number: "<<customer.getCustomerPhone();


    return oss;
}