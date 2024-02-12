#include "Order.h"


class OrderManager {

private:
    set<int>all_order_ids;
    map<int,Order>all_orders_by_id;
    map<int,Order>all_orders_by_number;
    OrderItemManager OITMG;
    Order currentOrder;
    int last_id;
public:

    OrderManager(){
        //all_this_order_items.clear();
        last_id = 17;
    }

    void createOrder(int number){
        currentOrder.readOrder(last_id++,number);
        handleData();
    }

    void handleData(){
        all_order_ids.insert(currentOrder.getId());
        all_orders_by_id[currentOrder.getId()] = currentOrder;
        all_orders_by_number[currentOrder.getNumber()] = currentOrder;
    }


    void print_current_order_items_in_this_order(){
        for (auto &ord:all_orders_by_number)
            cout << ord.second <<endl;
    }

    /*
    void UpadteOrder(const string &order_id,int status){
        if (!status){
            current_order_status_by_id[order_id]=Status::NEW;
        }
        else if (status == 1){
            current_order_status_by_id[order_id]=Status::HOLD;
        }
        else if (status == 2){
            current_order_status_by_id[order_id]=Status::PAID;
        }
        else if (status == 3){
            current_order_status_by_id[order_id]=Status::CANCELLED;
        }
    }

*/

};


