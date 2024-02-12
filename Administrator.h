#include "CustomerManager.h"
class Administrator: public User{

    string admin_id;
    string admin_fullName;



public:

    void readAdmin(const User&MyUser){
        string str;

        cout <<"Enter admin id: ";
        cin>> str;
        this->admin_id = str;

        cout <<"Enter admin full name: ";
        getline(cin,str);

        this->userName =MyUser.getUserName();
        this->email = MyUser.getUserEmail();
        this->userId = MyUser.getUserId();
        this->user_role = MyUser.getEntity();
        this->password = MyUser.getUserPassword();
    }


    string getAdminId()const{
        return admin_id;
    }
    string getAdminFullName()const{
        return admin_fullName;
    }



    //operations as an admin




};

ostream&operator<<(ostream &oss,const Administrator& admin ){
    oss<<"Admin info:"
       <<"\n\t"<<"Email: "<<admin.getUserEmail()
       <<"\n\t"<<"id: "<<admin.getUserId()
       <<"\n\t"<<"name: "<<admin.getUserName()
       <<"\n\t"<<"Entity: "<<admin.getUserRole()
       <<"\n\t"<<"admin id: "<<admin.getAdminId()
       <<"\n\t"<<"admin full name: "<<admin.getAdminFullName();


    return oss;
}