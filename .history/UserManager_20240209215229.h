#include "user.h"

class UserManager
{

vector <User>current_useres;
map<string,string>current_useres_email;
map<string,User>get_user_with_email_map;
set<string>current_useres_name;
User currentUser;
int last_id;


public:


UserManager(){
    last_id =0;
}

virtual void doLogin() {

    while (true)
    {
        string email , pass;
        cout <<"Enter user email and password: ";
        cin >> email >> pass;
        currentUser.setUserEmail(email);
        currentUser.setUserPasswprd(pass);

        if (!current_useres_email.count(currentUser.getUserEmail())){
            cout <<"\"email or are password is invalid.\"\n";
            if (!tryAgain())
                break;
        }

          if (current_useres_email[currentUser.getUserEmail()] != pass ){
            cout <<"\"email or are password is invalid.\"\n";
            if (!tryAgain())
                break;
        }

       const User &exist_user = get_user_with_email_map[currentUser.getUserEmail()];
       currentUser = exist_user;

        cout <<"\"Login successful\"\n";
        break;


    }
}


virtual void sign_up(){

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

        currentUser.signYourEntity();
        currentUser.readUser(user_email,user_name,++last_id);

        //submit it in map;
        handleData(currentUser.getUserEmail(),currentUser.getUserPassword()
        ,currentUser.getUserName());


        

    }
    

}

void handleData(const string &email,const string &password,const string &userName){
    current_useres.push_back(currentUser);
    current_useres_email[email] = password;
    get_user_with_email_map[email] = currentUser;
    current_useres_name.insert(userName);
    
}


bool userIsThere() {

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


const User &getCurrentUser(){
    return currentUser;
}




};







