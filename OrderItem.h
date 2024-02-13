#include "StockManager.h"




class OrderItem {


    int quantity;
    Product product_item;
    ProductManager PMG;


public:

    void readOrderItem(const Product &product,int wanted_qty){
        setQty(wanted_qty);
    }


    void setQty(int wanted_qty){
        this->quantity = wanted_qty;
    }
    void setProduct(const Product &product_item){
        this->product_item = product_item;
    }


    const int getQty()const{
        return this->quantity;
    }

    string getProductId()const{
        return product_item.getId();
    }

    double getProductPrice()const {
        return product_item.getPrice();
    }

    OrderItem &operator+=(int adder) {
        this->setQty(adder+ this->getQty());
        return *this;
    }

    OrderItem &operator+=(const Product &product) {
        this->setProduct(product);
        return *this;
    }

};

