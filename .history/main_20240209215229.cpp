#include "Customer.h"
int main(){

    cout <<"Hellokkkooooooo"<<endl;
    User user;
    Customer cs;
    user.setUserName("a");
    user.setEntity(Entity::person);
    user.setUserEmail("kak@");
    user.setUserName("karim");
     cout <<"a"<<endl;
     cout<<user.getUserName();
     cout <<endl;
     UserManager mg;
     cs.createCustomer(user.getUser());
     cout <<cs;

}