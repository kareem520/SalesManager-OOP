#include "OrderManager.h"

enum class Entity{
    admin,Customer
};

class User {

protected:

    string email;
    string userName;
    int userId;
    Entity user_role;
    string password;

public:
  


    virtual void print() = 0;


    void setEntity(const Entity choice){
        this->user_role = choice;
    }
    void setUserEmail(const string &email){
        this->email = email;
    }
    void setUserPasswprd(const string &pass){
        password = pass;
    }
    void setUserName(const string &userName){
        this->userName = userName;
    }
    void setUserId(int id) {
        this->userId = id;
    }

    string getUserPassword()const{
        return this->password;
    }
    string getUserName()const{
        return this->userName;
    }
    string getUserRole() const {
        if (this->user_role==Entity::Customer)
            return "Customer";
        else if (this->user_role==Entity::admin)
            return "admin";
        else "null";

    }
    string getUserEmail()const{
        return this->email;
    }
    Entity getEntity() const {
        return this->user_role;

    }
    int getUserId()const{
        return this->userId;
    }
};


ostream&operator<<(ostream &oss,User* user ){
    user->print();
    oss<<"User info:"
       <<"\n\t"<<"Email: "<<user.getUserEmail()
       <<"\n\t"<<"user id: "<<user.getUserId()
       <<"\n\t"<<"user name: "<<user.getUserName()
       <<"\n\t"<<"user Entity: "<<user.getUserRole();


    return oss;
}
