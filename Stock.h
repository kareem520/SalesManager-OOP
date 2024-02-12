#include "ProductManager.h"
class Stock {

    set<string>all_ids;
    map<string,Product>all_currentProducts_by_id;
    set<string>all_available_ids;
    set<string>all_un_available_ids;
    ProductManager this_stock_PMG;

public:

    void readProduct(string product_id,int new_qty){

        bool known_id = true;
        known_id &= ask_for_id_product(product_id);

        if (known_id){
            editQuantity(new_qty,product_id);
        }
        else{
            this_stock_PMG.createProduct();
            all_currentProducts_by_id[product_id] = this_stock_PMG.getProduct_by_id();

            cout <<"product read in stock.(\"by Stock sent\")"<<endl;

            handleData(product_id);

            cout <<"product handle data is done  in stock.(\"by Stock sent\")"<<endl;

        }
    }

    void handleData(string product_id){

        Product &product = all_currentProducts_by_id[product_id];

        //called when add a new product in stock
        all_ids.insert(product_id);

        if (product.getQty() > 0)
            all_available_ids.insert(product_id);
        else
            all_un_available_ids.insert(product_id);

    }

    bool ask_for_id_product(string product_id){
        return all_ids.count(product_id);
    }

    void printProduct_by_id(string product_id){

        Product &product = getProduct_by_id(product_id);

        cout <<product<<endl;
        if (all_available_ids.count(product_id))
            cout <<"This Product is available in a stock"<<endl;
        else
            cout <<"This Product is un available in a stock"<<endl;

    }

    Product &getProduct_by_id(string product_id){
        //depends on that checked that there's this id

        return all_currentProducts_by_id[product_id];
    }

    void editQuantity(int new_qty,string product_id){
        Product &product = getProduct_by_id(product_id);

        //added quantity (not available now)
        if (!product.getQty()){
            if(all_un_available_ids.count(product.getId())){

                //delete product from non_available products
                all_un_available_ids.erase(product.getId());

                //put product into available products
                all_available_ids.insert(product.getId());

            }
            else {
                "There is a logic error!!!!!!!!!!!!!!!!!!";
            }
        }

        product.setQty(new_qty);

        // run out from stock.
        if (!new_qty){
            if(all_available_ids.count(product.getId())){

                //delete product from available products
                all_available_ids.erase(product.getId());

                //put product into non_available products
                all_un_available_ids.insert(product.getId());

            }
            else {
                "There is a logic error!!!!!!!!!!!!!!!!!!";
            }
        }
    }

    void editPrice(float price,string product_id){
        Product &product = getProduct_by_id(product_id);
        product.setPrice(price);
    }

    void takeFromProduct(string product_id,int wanted_qty){
        Product &product = getProduct_by_id(product_id);

        int new_qty = product.getQty()-wanted_qty;
        editQuantity(new_qty,product_id);
    }

    void RetrievalToProduct(string product_id,int wanted_qty){
        Product &product = getProduct_by_id(product_id);

        int new_qty = product.getQty()+wanted_qty;
        editQuantity(new_qty,product_id);
    }

    void getAvailableProducts(){
        for (auto &prod:all_available_ids)
            cout << all_currentProducts_by_id[prod]<<endl;
    }

    void getUnAvailableProducts(){
        for (auto &prod:all_un_available_ids)
            cout << all_currentProducts_by_id[prod]<<endl;
    }

    void print_AllCurrentProducts(){
        for (auto &prod:all_ids)
            cout << all_currentProducts_by_id[prod]<<endl;
    }
    //----------------------------------------product ops
    int getQTY(string product_id){
        Product &product = getProduct_by_id(product_id);
        return product.getQty();
    }
    string getUnit(string product_id){
        Product &product = getProduct_by_id(product_id);
        return product.getUnit();
    }
    string getName(string product_id){
        Product &product = getProduct_by_id(product_id);
        return product.getName();
    }
    double getPrice(string product_id){
        Product &product = getProduct_by_id(product_id);
        return product.getPrice();
    }
};

