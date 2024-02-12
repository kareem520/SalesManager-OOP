#include "StockManager.h"

class OrderItem {


    double sale_price; // product price + 14% taxes
    int quantity;
    string order_item_id;
    Product product_item;


public:

    void readOrderItem(const Product &product,int wanted_qty){
        setSalePrice(product.getPrice());
        setQty(wanted_qty);
    }

    void setSalePrice(double price){
        this->sale_price = addTaxes(price);
    }

    void setQty(int wanted_qty){
        this->quantity = wanted_qty;
    }

    double addTaxes(double price){
        return ((price*100)/14.0);
    }

    //override
    const double getPrice()const{
        return this->sale_price;
    }

    const int getQty()const{
        return this->quantity;
    }



};

