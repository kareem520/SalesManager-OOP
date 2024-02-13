#include "Stock.h"
class StockManager {

    Stock stock1;

public:


    //----------------------------------------------------------admin ops
    void put_product_in_stock(){

        string id;
        cout <<"Enter Product Id: ";
        cin >> id;

        int new_qty;
        cout <<"Enter Quantity you want to add: ";
        cin >> new_qty;

        stock1.readProduct(id,new_qty);
        cout <<"putting the product in stock is done.(\"by Stock Manager sent\")"<<endl;
    }

    void edit_quantity_for_product_in_stock(int new_qty,string product_id){
        if (!stock1.ask_for_id_product(product_id)){
            cout <<"there's is no product with this id to edit!."<<endl;
        }
        else{
            stock1.editQuantity(new_qty,product_id);
        }

    }
    void print_un_available_products(){
        stock1.getUnAvailableProducts();
    }
    //------------------------------------------------------admin and system oos

    bool this_id_is_there(string product_id) {
        return stock1.ask_for_id_product(product_id);
    }

    void print_available_products(){
        stock1.getAvailableProducts();
    }

    //-----------------------------------------------------------------system ops
    void buy(string id , int wanted_qty) {
        stock1.takeFromProduct(id, wanted_qty);
    }

    void retrival(){
        string id;
        int wanted_qty;

        cout << "Enter product id: ";
        while(cin >> id) {
            if (stock1.ask_for_id_product(id))
                break;
            cout << "Enter product id: ";
        }
        cin>>wanted_qty;
        stock1.RetrievalToProduct(id,wanted_qty);

    }

    bool is_available_quantity(int wanted_qty, string id){
        return (stock1.getQTY(id)<=wanted_qty);
    }
    int get_available_quantity(string id){
        return (stock1.getQTY(id));
    }
    const Product &Product_by_id(string id){
        return stock1.getProduct_by_id(id);
    }


};


