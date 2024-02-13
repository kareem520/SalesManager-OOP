#include "SalesManager.h"

class Administrator: public User{

    int admin_id;
    string admin_fullName;



public:



    void setAdminFullName(string name){
        this->admin_fullName = name;
    }

    string getAdminFullName()const{
        return admin_fullName;
    }


    virtual void print()override {
        cout <<this;
    }



};

ostream&operator<<(ostream &oss,const Administrator& admin ){
    oss<<"Admin info:"
       <<"\n\t"<<"Email: "<<admin.getUserEmail()
       <<"\n\t"<<"id: "<<admin.getUserId()
       <<"\n\t"<<"name: "<<admin.getUserName()
       <<"\n\t"<<"admin full name: "<<admin.getAdminFullName();


    return oss;
}