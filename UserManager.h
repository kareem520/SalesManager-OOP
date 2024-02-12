#include "AdministratorManager.h"
class UserManager
{

    set<int>all_users_id;
    map<string,string>current_useres_pass_by_email;
    map<int,User>all_users_by_id;
    map<string,User>all_users_by_email;
    set<string>all_users_name;

    User currentUser;
    CustomerManager currentCMG;
    AdministratorManager currenAMG;

    int last_id;


public:


    UserManager(){
        last_id =0;
    }

    void doLogin() {

        while (true)
        {
            string email , pass;
            cout <<"Enter user email: ";
            cin >> email;
            currentUser.setUserEmail(email);
            cout <<"Enter user Password: ";
            cin >> pass;
            currentUser.setUserPasswprd(pass);

            if (!current_useres_pass_by_email.count(currentUser.getUserEmail())){
                cout <<"\"email or are password is invalid.\"\n";
                if (!tryAgain())
                    break;
                else
                    continue;
            }

              if (current_useres_pass_by_email[currentUser.getUserEmail()] != pass ){
                cout <<"\"email or are password is invalid.\"\n";
                if (!tryAgain())
                    break;
            }

           const User &exist_user = all_users_by_email[currentUser.getUserEmail()];
           currentUser = exist_user;

            cout <<"\"Login successful\"\n";
            break;
        }
    }


    void sign_up(){

        string user_email,user_name;
        while (true){

            cout <<"Enter user email: "<<endl;
            cin >> user_email;
            if (current_useres_pass_by_email.count(user_email)){
                cout << "Already used. Try again\n";
            }

            cout <<"Enter user name. (No Spaces): "<<endl;
            cin >> user_name;
            if (all_users_name.count(user_email)){
                cout << "Already used. Try again\n";
            }

            currentUser.signYourEntity();
            currentUser.readUser(user_email,user_name,++last_id);

            //submit it in map;
            handleData();

            IsA();//create Customer or administrator
            break;


        }


    }

    void IsA(){
        if (currentUser.getEntity()==Entity::Customer){
            currentCMG.createCustomer(currentUser);
        }
        else if (currentUser.getEntity() == Entity::admin){
            currenAMG.createAdminstrator(currentUser);
        }
    }
    void handleData(){
        all_users_name.insert(currentUser.getUserName());
        current_useres_pass_by_email[currentUser.getUserEmail()] = currentUser.getUserPassword();
        all_users_id.insert(currentUser.getUserId());
        all_users_by_email[currentUser.getUserEmail()] = currentUser;
        this->all_users_by_id[currentUser.getUserId()] = currentUser;

    }


    bool username_is_there(string userName) const{
        return (all_users_name.count(userName));
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


     const User &getCurrentUser() const {
        return currentUser;
    }


    void printAllCurrentUseres(){
        for (auto&usr: this->all_users_by_id)
            cout <<usr.second<<endl;
    }

    CustomerManager&get_current_customer_manager(){
        return currentCMG;
    }


};








