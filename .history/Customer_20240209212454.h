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
void createCustomer(const User *MyUser){
    cout <<"Hello, "<< MyUser->getUserName()
        << " Enter your phone number: ";
        cin >> this->phone;
    currentUser = *MyUser; 
}

ostream&operator<<(ostream &oss){
    oss<<"Customer info:"
        <<"\n\t"<<"Email: "<<currentUser.getUserEmail()
        <<"\n\t"<<"user id: "<<currentUser.getUserId()
        <<"\n\t"<<"user name: "<<currentUser.getUserName()
        <<"\n\t"<<"user Entity: "<<currentUser.getEntity();

        return oss;
}
  
};


