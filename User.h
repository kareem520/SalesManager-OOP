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
    static int counter;

public:
  
    User(){
        userId =0;
    }


    void readUser(string email,string userName,int id){
       this->email = email;
       this->userName = userName;
       this->userId = id;
       string str; 
       cout <<"Enter password: ";
       cin >> str;
       setUserPasswprd(str);

        
    }
    void signYourEntity(){
        while (true){
            cout <<"Enter:\n\tYou are a Customer-> 1\n\tYou are a administrator-> 2\n";
            int ch; cin >> ch;
            if (ch==1) {
                setEntity(Entity::Customer);
                break;
            }
            else if (ch==2) {
                setEntity(Entity::admin);
                break;
            }
        }
    }

    
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
    Entity getEntity() const {
        return this->user_role;

    }
    int getUserId()const{
        return this->userId;
    }
    const User &getUser()const{
        return *this;
    }


    string getUserEmail()const{
        return this->email;
    }

};


ostream&operator<<(ostream &oss,const User& user ){
    oss<<"User info:"
       <<"\n\t"<<"Email: "<<user.getUserEmail()
       <<"\n\t"<<"user id: "<<user.getUserId()
       <<"\n\t"<<"user name: "<<user.getUserName()
       <<"\n\t"<<"user Entity: "<<user.getUserRole();


    return oss;
}
