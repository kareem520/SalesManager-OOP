#include "UserManager.h"

class SystemManager {

    //ProductManager PDMG;
    UserManager UMG;

    User *ourUser;
    void get_into_market(){

        CustomerManager *CMG = &UMG.get_current_customer_manager();

        if (ourUser->getEntity() == Entity::Customer){
            Customer ourCustomer = CMG->getCustomer_by_id(ourUser->getUserId());
            ourUser = &ourCustomer;
        }
        else{

        }
    }
public:

    void Run(){
        Help::welcome();

        while (true) {
            cout << "You have an account? (yes or no): ";
            string str;
            cin >> str;

            //check input and be sure that it yes or no
            bool flag = 1;
            flag &=Help::toLower(str);
            if (!flag)continue; //Wrong input

            if (str == "yes") {
                UMG.doLogin();
            } else {
                UMG.sign_up();
            }



        }
    }




};


