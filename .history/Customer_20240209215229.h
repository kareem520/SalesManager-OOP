#include "UserManager.h"
#include "Coupon.h"
#include "Transaction.h"
class Customer:public User {

private:

    string phone;
    Coupon discount;
    User currentUser;

public:

Customer(){
    //set discount zero default
}
void createCustomer(const User &MyUser){
    cout <<"Hello, "<< MyUser.getUserName()
        << " Enter your phone number: ";
        cin >> this->phone;
    currentUser = MyUser; 
}


  


};


ostream&operator<<(ostream &oss,const Customer& customer ){
    oss<<"Customer info:"
        <<"\n\t"<<"Email: "<<customer.getUserEmail()
        <<"\n\t"<<"user id: "<<customer.getUserId()
        <<"\n\t"<<"user name: "<<customer.getUserName()
        <<"\n\t"<<"user Entity: "<<customer.getEntity();

        return oss;
}