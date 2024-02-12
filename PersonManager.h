#include "Person.h"

class PersonManager{

    set<int>all_persons_id;
    map<int,Person>all_persons_by_id;

    Person currentPerson;

public:
    void createPerson(Customer &customer){
        currentPerson.readPerson(customer);
    }

    void handleData(){
        all_persons_id.insert(currentPerson.getUserId());
        all_persons_by_id[currentPerson.getUserId()] = currentPerson;
    }

    void printAllPersons(){
        for (auto &prs:all_persons_by_id)
            cout <<prs.second<<endl;
    }
};

