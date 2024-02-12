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

    void this_id_is_there(string product_id){

        if (stock1.ask_for_id_product(product_id)){
            cout <<"id is there"<<endl;
        }
        else {
            cout <<"\"No product with this id.\""<<endl;
        }
    }

    void print_available_products(){
        stock1.getAvailableProducts();
    }

    //-----------------------------------------------------------------system ops
    void buy(){
        string id;
        int wanted_qty;

        cout << "Enter product id: ";
        while(cin >> id) {
            if (stock1.ask_for_id_product(id))
                break;
            cout << "Enter product id: ";
        }

        cout <<"Enter wanted quantity: ";
        while(cin >> wanted_qty){
            if (stock1.getQTY(id)<=wanted_qty) {
                stock1.takeFromProduct(id, wanted_qty);
                break;
            }
            else{
                cout <<"Not available quantity."<<endl;
                cout <<"our quantity in a stock: "<<stock1.getQTY(id)<<endl;
            }
            cout <<"Enter wanted quantity: ";

        }
        cout <<"added";
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


};


