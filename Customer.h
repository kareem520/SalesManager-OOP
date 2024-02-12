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
    set<string>all_orderes_ids;
    map<string,Order>all_orderes_by_id;


public:

    Customer(){
        //set discount zero default
    }
    void readCustomer(const User &MyUser){
        string str;
        cout <<"Hello, "<< MyUser.getUserName()
            << " Enter your phone number: ";
            cin >> str;
        cout <<endl;
        cout <<"Enter:\n\t Your are a person->1\n\t"
            <<"You are a company->2\n";
        int ch;
        while (cin >> ch) {
            if (ch == 1) {
                setRole(EntityCustomer::person);
                break;
            }
            else if (ch==2) {
                setRole(EntityCustomer::company);
                break;
            }
            else continue;
        }
        this->phone = str;
        this->userName =MyUser.getUserName();
        this->email = MyUser.getUserEmail();
        this->userId = MyUser.getUserId();
        this->user_role = MyUser.getEntity();
        this->password = MyUser.getUserPassword();
    }

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