#include "UserManager.h"

class SystemManager {

    UserManager UMG;
    SalesManager SLMG;

    void get_into_market(){
        UMG.sign_up();

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

            UMG.doLogin();
            UMG.sign_up();
            UMG.doLogin();


        }
    }




};


