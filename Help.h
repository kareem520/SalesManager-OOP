#include <iostream>
#include <map>
#include <vector>
#include <set>
#include "chrono"
#include "random"
using namespace std;

class Help {

public:

    static int toInt(const char* num){
        int number = 0;
        int idx=0;
        while(num[idx]!=' '){
            number *=10 + (num[idx++]-'0');
        }

        return number;
    }

    static double toDouble(const char* num){
        double number =0,fr =0;
        int idx=0;
        //before fraction
        while(num[idx]!='.'){
            number *=10 + (num[idx++]-'0');
        }
        idx++;
        while(num[idx]!=' '){
            fr *=10 + (num[idx++]-'0');
        }
        return (number+fr);
    }

    static string toString(const char* ch){
        int idx=0;
        string ret ="";
        while (ch[idx]!='#')
            ret.push_back(ch[idx++]);
        return ret;
    }


   static void welcome(){
        cout <<"|------------------Welcome with you at our Supermarket"
               "------------------|"<<endl;
    }

   static bool toLower(string &str){

        for (int i=0; i < str.size(); ++i){
            if (str[i]>='A' &&str[i]<='Z')
                str[i]+=32;

            if (!(str[i]>='a'&str[i]<='z')) {
                cout <<"Wrong input. (try again)"<<endl;
                return false;
            }
        }

       if (str=="yes" || str == "no")return true;
       else return false;
    }

    static string getDateNow(){
        chrono::system_clock::time_point now = std::chrono::system_clock::now();

        // Convert the time point to a time_t object
        time_t now_c = std::chrono::system_clock::to_time_t(now);

        // Convert the time_t object to a local time struct
        tm* local_time = std::localtime(&now_c);


        string str = std::asctime(local_time);
        // Print the current local time
      //  std::cout << "Current local time is: " << str;
        return str;
    }
    static int get_random_id(){
        random_device rd; // Obtain a random seed from the OS entropy device
        mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

        uniform_int_distribution<int> dist(1, 100000000);

        int randomNumber = dist(gen);

        return randomNumber;

    }
};


