#include "OrderItemManager.h"

enum class Status{
    HOLD,
    PAID,
    CANCELLED
};

class Order {

private:

    static int id;
    int number;
    string date;
    Status order_status;
    double total_price;
    vector<OrderItem>order_items;

public:

    Order(){
        total_price =0;
    }


    void readOrder(int id, int number){
        setDate();
        setId(id);
        setNumber(number);
        setStatus(Status::HOLD);
    }

    void setId(int id){
        this->id = id;
    }
    void setNumber(int number){
        this->number = number;
    }
    void setStatus(Status status){
        this->order_status = status;
    }
    void setDate(){
        this->date = Help::getDateNow();
    }

    int getId()const{
        return id;
    }

    int getNumber()const{
        return number;
    }

    double getTotalPrice()const{
        return total_price;
    }
    string getOrderDate()const{
        return date;
    }
    Status getOrderStatus()const{
        return order_status;
    }
    void printStatus()const{
        switch (order_status) {
            case Status::HOLD:
                cout <<"Hold Order"<<endl;
                break;
            case Status::PAID:
                cout <<"Paid Order"<<endl;
                break;
            case Status::CANCELLED:
                cout <<"Paid Order"<<endl;
                break;

        }
    }





};

int Order::id = 0;

ostream&operator<<(ostream &oss,const Order& order ){
    oss<<"Order info:"
       <<"\n\t"<<"id: "<<order.getId()
       <<"\n\t"<<"Number: "<<order.getNumber()
       <<"\n\t"<<"Time: "<<order.getOrderDate()
       <<"\n\t"<<"total price: "<<order.getTotalPrice()
       <<"\n\t";
    order.printStatus();

    return oss;
}
