#include "OrderItemManager.h"

enum class Status{
    NEW,
    HOLD,
    PAID,
    CANCELLED
};


//SalesManager is the manager of Order .
class Order {

private:

    int id;
    int number;
    string date;
    Status order_status;
    double total_price;

    vector<OrderItem>order_items;
    map<string,int>idx_by_id;
    set<string>all_orderItem_ids;

public:

    Order(){
        total_price =0;
    }


    void readOrder(int id, int number){
        setDate();
        setId(id);
        setNumber(number);
        setStatus(Status::NEW);
    }

    void setId(int id){
        this->id = id;
    }
    void setNumber(int number){
        this->number = number;
    }

    bool is_order_item_there(string product_id){
        if (all_orderItem_ids.count(product_id))
            return true;
        return false;
    }
    void setStatus(Status status){
        this->order_status = status;
    }
    void setDate(){
        this->date = Help::getDateNow();
    }
    void setItem(const OrderItem order_item){
        //it called only from += operator
        idx_by_id[order_item.getProductId()]= order_items.size();
        all_orderItem_ids.insert(order_item.getProductId());
        this->order_items.push_back(order_item);
    }

    void addPrice(const OrderItem order_item){
        this->total_price +=order_item.getProductPrice()*order_item.getQty();
    }
    int get_orderItem_idx_byId(string product_id){
        return idx_by_id[product_id];
    }
    void edit_order_item(){

    }

    int getId()const{
        return id;
    }

    int getNumber()const{
        return number;
    }

    double getOrderTotalPrice()const{
        return total_price;
    }
    string getOrderDate()const{
        return date;
    }
    Status getOrderStatus()const{
        return order_status;
    }
    string printOrderStatus()const{
        switch (order_status) {
            case Status::NEW:
                return "New Order";
                break;
            case Status::HOLD:
                return "Hold Order";
                break;
            case Status::PAID:
                return "Paid Order";
                break;
            case Status::CANCELLED:
                return "Cancelled Order";
                break;

        }
    }



    Order operator+=(const OrderItem& item) {

        // check first if this product is in the order as orderItem or no.
        // if: yes -> get orderItem with idx and add quantity to it.
        // if no: setNew item in order.
        //then add price of the orderItem to the order .

        if (is_order_item_there(item.getProductId())){
            int idx = this->get_orderItem_idx_byId(item.getProductId());
            order_items[idx]+=item.getQty();
        }
        else{
            this->setItem(item);
        }

        addPrice(item);

        return *this;
    }




};


ostream&operator<<(ostream &oss,const Order& order ){
    oss<<"Order info:"
       <<"\n\t"<<"id: "<<order.getId()
       <<"\n\t"<<"Number: "<<order.getNumber()
       <<"\n\t"<<"Time: "<<order.getOrderDate()
       <<"\n\t"<<"total price: "<<order.getOrderTotalPrice()
       <<"\n\t"<< order.printOrderStatus();

    return oss;
}
