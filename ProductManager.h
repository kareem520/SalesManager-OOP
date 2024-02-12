#include "Product.h"


class ProductManager {

    Product current_product;

public:

    void createProduct(){
        current_product.readProduct();
        cout <<"product read in stock.(\"by product manager sent\")"<<endl;

    }



    void printProduct_by_id(Product &product){

        cout <<product<<endl;
        if (product.getQty()>0)
            cout <<"This Product is available in a stock"<<endl;
        else
            cout <<"This Product is un available in a stock"<<endl;

    }




    Product &getProduct_by_id(){
        return current_product;
    }

    //admin ops
    //add extra quantity, add new product , delete product from stock
    //read available products(admin or Customer), read non_available products





};


