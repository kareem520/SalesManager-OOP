#include "Administrator.h"
class AdministratorManager {

    vector<Administrator>all_administrators;

public:

    void createAdminstrator(const User &user){
        Administrator currentAdmin;
        currentAdmin.readAdmin(user);
        handleData(currentAdmin);
    }

    void handleData(Administrator &admin){
        all_administrators.push_back(admin);
    }


};


