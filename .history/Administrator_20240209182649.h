
#include "User.h"

enum role{
    stock_manager,_dataBase_manager,security_manager,sales_manager
};

class Administrator: public User{

private:
    role admin;
   

};

