//#include ".h"
    #include "CompanyManager.h"


class Person: public Customer{

private:
    string address;
    string fullName;

public:



    virtual void print()override{
        cout <<this;
    }

    virtual void sign_up_name()override{
        string name;
        cout <<"Enter Your full name: ";
        cin.ignore();
        getline(cin,name);
        cout <<endl;
        setName(name);
    }
    virtual void sign_up_address()override{

        string add;
        cout <<"Enter Your Address: ";
        cin.ignore();
        getline(cin,add);
        setAddress(add);
    }


    void setAddress(string add){
        this->address = add;
    }
    void setName(string name){
        this->fullName = name;
    }


    string getAddress()const{
        return address;
    }
    string getFullName()const{
        return this->fullName;
    }

};


ostream&operator<<(ostream &oss,const Person& person ){
    oss<<"Person info:"
       <<"\n\t"<<"Email: "<<person.getUserEmail()
       <<"\n\t"<<"id: "<<person.getUserId()
       <<"\n\t"<<"user name: "<<person.getUserName()
       <<"\n\t"<<"full name: "<<person.getFullName()
       <<"\n\t"<<"phone number: "<<person.getCustomerPhone()
       <<"\n\t"<<"address: "<<person.getAddress();


    return oss;
}
