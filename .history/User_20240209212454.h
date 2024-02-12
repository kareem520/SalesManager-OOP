#include<iostream>
#include<map>
#include<vector>
#include <set>
using namespace std;

enum class Entity{
    admin,person,company
};

class User {

private:

    string email;
    string userName;
    int userId;
    Entity user_role;
    string password;
    static int counter;

public:
  



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
            cout <<"Enter:\n\tYou are a person-> 1\n\tYou are a compant-> 2\n";
            int ch; cin >> ch;
            if (ch==1) {
                setEntity(Entity::person);
                break;
            }
            else if (ch==2) {
                setEntity(Entity::company);
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
    string getUserEmail()const{
        return this->email;
    }
    string getUserName()const{
        return this->userName;
    }
    string getEntity()const{
        if (this->user_role==Entity::person)
            return "person";
        else if (this->user_role==Entity::company)
            return "company";

    }
    int getUserId()const{
        return this->userId;
    }
    const User &getUser()const{
        return *this;
    }


};


