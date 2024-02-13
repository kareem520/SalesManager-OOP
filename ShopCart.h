#include "Order.h"
class ShopCart {

    double total_price;
    vector <Order>orders;
    map<int,set<string>>ids_product_by_ids_order;
public:

    ShopCart(){
        total_price = 0.00;
    }

    const void add_order_in_shop(const Order &order){
        orders.push_back(order);
    }

    Order &getOrder_by_idx(int idx){
        return orders[idx];
    }

    int get_counter_orders(){
        return (int)orders.size();
    }



    ShopCart& operator+=(const Order& order) {
        orders.push_back(order);
        total_price +=order.getOrderTotalPrice();
        return *this;
    }

    ShopCart& operator-=(const Order& order){

        //take an order from this shop cart
        // i will send from sales manager order which i want to take

        total_price -=order.getOrderTotalPrice();
        return *this;
    }
    friend ostream&operator<<(ostream &oss,const ShopCart shopCart );

};

ostream&operator<<(ostream &oss,const ShopCart shopCart ){
    int count = 1;
    oss << "Shop_cart info:";
    for (auto &shp:shopCart.orders) {
        oss << "\n\t" << "order number " << count++
            << "\n\t" << "order price: " << shp.getOrderTotalPrice();
    }
    oss<<"\n\t"<<"shop_cart total_price: " << shopCart.total_price;

    return oss;
}

