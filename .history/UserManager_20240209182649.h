#include "user.h"

class UserManager
{

vector <User>current_useres;
map<string,string>current_useres_email;
map<string,User>get_user_with_email_map;
set<string>current_useres_name;
User current_user;
int last_id;
public:


UserManager(){
    last_id =0;
}

bool login() {

    while (true)
    {

        string email , pass;
        cout <<"Enter user email and password: ";
        cin >> email >> pass;

        current_user.setUserEmail(email);
        current_user.setUserPasswprd(pass);

        if (!current_useres_email.count(current_user.getUserEmail())){
            cout <<"\"email or are password is invalid.\"\n";
            if (!try_again())
                break;
        }

          if (current_useres_email[current_user.getUserEmail()] != pass ){
            cout <<"\"email or are password is invalid.\"\n";
            if (!try_again())
                break;
        }

       const User &exist_user = get_user_with_email_map[current_user.getUserEmail()];
       current_user = exist_user;

        cout <<"\"Login successful\"\n";
        break;


    }
}


void sign_up(){

    string user_email,user_name;
    while (true){

        cout <<"Enter user email: "<<endl;
        cin >> user_email;
        if (current_useres_email.count(user_email)){
            cout << "Already used. Try again\n";
        }

        cout <<"Enter user name. (No Spaces): "<<endl;
        cin >> user_name;
        if (current_useres_name.count(user_email)){
            cout << "Already used. Try again\n";
        }

        current_user.signYourEntity();
        current_user.readUser(user_email,user_name,++last_id);

        //submit it in map;
        handle_data(current_user.getUserEmail(),current_user.getUserPassword()
        ,current_user.getUserName());


        

    }
    

}

void handle_data(const string &email,const string &password,const string &userName){
    current_useres.push_back(current_user);
    current_useres_email[email] = password;
    get_user_with_email_map[email] = current_user;
    current_useres_name.insert(userName);
}


bool user_is_there() {

    string email,pass; 

    cout <<"Enter Your Email:  ";
    cin >> email;

    cout <<"Enter Your Password:  ";
    cin >> pass;

    if (current_useres_email.count(email))return false;
    else if (current_useres_email[email]!=pass)return false;

}



bool username_is_there(string userName) const{
    return (current_useres_name.count(userName));
}
bool try_again()const{

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




};







