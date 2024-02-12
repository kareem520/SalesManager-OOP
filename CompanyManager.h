#include "Company.h"

class CompanyManager {

    set<int>all_companies_id;
    map<int,Company>all_companies_by_id;
    Company currentCompany;

public:

    void createCompany(Customer &customer){
        currentCompany.readCompany(customer);

    }

    void handleData(){
        all_companies_id.insert(currentCompany.getUserId());
        all_companies_by_id[currentCompany.getUserId()] = currentCompany;
    }

    void printAllPersons(){
        for (auto &comp:all_companies_by_id)
            cout <<comp.second<<endl;
    }
};


