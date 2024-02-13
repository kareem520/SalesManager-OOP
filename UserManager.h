#include "AdministratorManager.h"

enum class MODLE{
    ADMIN,
    CUSTOMER,
    PERSON,
    COMPANY
};


class UserManager
{

    set<int>all_users_id;
    set<string>all_users_name;
    set<string>all_users_email;
    map<string,int>id_by_email;
    map<string ,string>all_pass_by_email;
    map<int,Person>person_from_id;
    map<int,Company>company_from_id;
    map<int,Administrator>admin_from_id;


    User *new_user;
    Customer *new_customer;
    Administrator *new_admin;
    Person *new_person;
    Company *new_compay;
    AdministratorManager currenAMG;

    MODLE model;





    void sign_up_email(){
        string user_email;
        cout << "Enter user email: " << endl;
        while (cin >> user_email) {
            if (all_users_email.count(user_email)) {
                cout << "Already used. Try again\n";
            }
            else {
                new_user->setUserEmail(user_email);
                break;
            }
        }
    }

    void sign_up_password() {
        string password;
        cout << "Enter your password. (No Spaces): " << endl;
        cin >> password;
        new_user->setUserPasswprd(password);
    }

    void sign_up_user_entity(){

        ask_for_user_entity();
        if (model == MODLE::ADMIN){
            //an admin
            new_admin = new Administrator;
            new_user = new_admin;
            new_user->setEntity(Entity::admin);
        }
        else {
            sign_up_Entity_customer();
        }
    }

    void sign_up_user_name() {
        string user_name;
        cout << "Enter user name. (No Spaces): " << endl;
        while (cin >> user_name) {
            if (all_users_name.count(user_name)) {
                cout << "Already used. Try again\n";
            }
            else {
                new_user->setUserName(user_name);
                break;
            }
        }
    }

    void sign_up_id() {
        new_user->setUserId(all_users_id.size() + 1);
    }

    void ask_for_user_entity(){
        cout <<"Enter:\n\t Your are an admin->1\n\t"
             <<"You are a Customer->2\n";
        int ch;
        while (cin >> ch) {
            if (ch == 1){
                model = MODLE::ADMIN;
                break;
            }
            else if (ch == 2){
                model = MODLE::CUSTOMER;
                break;
            }
            else{
                cout <<"Enter:\n\t Your are an admin->1\n\t"
                     <<"You are a Customer->2\n";
                continue;
            }
        }
    }

///////////////////////////////Op With Customers (PRIVATE)--------------------------------------------------------------------




public:







    void doLogin() {

        while (true)
        {
            string email , pass;
            cout <<"Enter user email: ";
            cin >> email;
            cout <<"Enter user Password: ";
            cin >> pass;

            if (!all_pass_by_email.count((email))){
                cout <<"\"email or are password is invalid.\"\n";
                if (!tryAgain())
                    break;
                else
                    continue;
            }

              if (all_pass_by_email[email] != pass ){
                cout <<"\"email or are password is invalid.\"\n";
                if (!tryAgain())
                    break;
                else continue;
            }

            int user_id = id_by_email[email];

            cout <<"\"------Login successful----------------\"\n";

            // if user-> customer
            if (person_from_id.count(user_id) || company_from_id.count(user_id)){
                if (company_from_id.count(user_id)) {
                    new_customer = &company_from_id[user_id];
                }
                else{
                    new_customer = &person_from_id[user_id];
                }
                Run_market();
            }
            else{
                //admin
                new_admin = &admin_from_id[user_id];
                control();
            }

            cout <<"Out."<<endl;
            break;
        }
    }



    void sign_up(){

        sign_up_user_entity();  //----admin or customer


        sign_up_email();

        sign_up_user_name();

        sign_up_password();

        sign_up_id();

        if (new_user->getEntity() == Entity::Customer) {
            complete_as_customer();
        }
        else{
            complete_as_admin();
        }

        handleData();



    }





    void handleData(){
       all_pass_by_email[new_user->getUserEmail()] = new_user->getUserPassword();
       all_users_id.insert(new_user->getUserId());
       all_users_name.insert(new_user->getUserName());
       all_users_email.insert(new_user->getUserEmail());
       id_by_email[new_user->getUserEmail()] = new_user->getUserId();

       if (model == MODLE::PERSON)
           person_from_id[new_user->getUserId()] = *new_person;

        if (model == MODLE::COMPANY)
            company_from_id[new_user->getUserId()] = *new_compay;

        if (model == MODLE::ADMIN)
            admin_from_id[new_user->getUserId()] = *new_admin;

    }







    bool tryAgain()const{

        bool choice;
        cout <<"Press 1 to try again or zero to cancel: ";
        cin >> choice;
        bool you_want_to_try_again = choice;

        switch (you_want_to_try_again)
        {
        case true: return true;
        default:
             cout <<"Cancelled\n";
             return false;
        }
    }




///////////////////////////////Op With Customers(PUBLIC)--------------------------------------------------------------------

private:
    void  ask_for_customer_entity(){
        cout <<"Enter:\n\t Your are a person->1\n\t"
             <<"You are a company->2\n";
        int ch;
        while (cin >> ch) {
           if (ch = 1){
               model = MODLE::PERSON;
               break;
           }
           else if (ch == 2){
               model = MODLE::COMPANY;
               break;
           }
            else {
                cout << "Enter:\n\t Your are a person->1\n\t"
                     << "You are a company->2\n";
                continue;
            }
        }
    }

    void setCustomerEntity(){
        if (model == MODLE::PERSON){
            new_customer->setRole(EntityCustomer::person);
        }
        else{
            new_customer->setRole(EntityCustomer::company);
        }
    }

    void sign_up_phone(){
        string phone;

        cout <<"Enter phone number: ";
        cin >> phone;

        new_customer->setCustomerPhone(phone);
    }

    void sign_up_Entity_customer(){
        ask_for_customer_entity();

        if (model == MODLE::PERSON){
            // a person
            new_person = new Person;
            new_user = new_person;
            new_user->setEntity(Entity::Customer);
        }
        else {
            // a company
            new_compay = new Company;
            new_user = new_compay;
            new_user->setEntity(Entity::Customer);
        }
    }

public:

    void complete_as_customer(){
        new_customer = static_cast<Customer*>(new_user);


        sign_up_phone();
        setCustomerEntity();
        new_customer->sign_up_address();
        new_customer->sign_up_name();



    }


    void Run_market(){

        /////////////////////////////////////////////
    }





/////////////////////////Op with admin-------------------------------------------------------------------------


    void sign_up_admin_name(){
        string name;
        cout <<"Enter admin full name: ";
        getline(cin,name);

        new_admin->setAdminFullName(name);
    }

    void complete_as_admin(){
        new_admin = static_cast<Administrator*>(new_user);
        sign_up_admin_name();

    }



    void control(){

    }

/////////////////////////Op with Person-------------------------------------------------------------------------

    void complete_as_person(){

        new_person = static_cast<Person*>(new_customer);


    }

/////////////////////////Op with Company-------------------------------------------------------------------------
    void complete_as_company(){

        new_compay = static_cast<Company*>(new_customer);


    }
};








