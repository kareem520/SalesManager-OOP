#include "PersonManager.h"



class CustomerManager
{
private:

    set<int>all_customers_id;
    map<int,Customer>all_customers_by_id;
    Customer currentCustomer;
    PersonManager PMG;
    CompanyManager CMPMG;

    // vector<Transaction>allMyTransactions;

public:


  void createCustomer(const User &user){
      currentCustomer.readCustomer(user.getUser());
      handleData();
      IsA();

  }

  void IsA(){
      if (currentCustomer.getCustomerRole() == EntityCustomer::person){
            PMG.createPerson(currentCustomer);
      }
      else{//company
          CMPMG.createCompany(currentCustomer);
      }
  }

    void handleData(){
        all_customers_id.insert(currentCustomer.getUserId());
        all_customers_by_id[currentCustomer.getUserId()] = currentCustomer;
    }


    //System oop
    Customer &getCustomer_by_id(int id){
        return all_customers_by_id[id];
   }
   void edit_order_customer(){

  }



    void places_an_order(){

  }

};

