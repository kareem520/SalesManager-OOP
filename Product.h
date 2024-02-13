#include "Help.h"
enum class ProductType {
    Kilogram,
    Gram,
    Quantity
};



class Product {

private:
    string id;
    string name;
    double price;
    int qty_in_stock;
    ProductType type;





public:


    void readProduct() {
        string take;

        cout << "Enter name of the product: ";
        cin >> take;
        this->name = take;

        cout << "Enter id of this product: ";
        cin >> take;
        this->id = id;

        cout << "Enter the unit of this product(k or g or q): ";
        while (cin >> take) {
            int ch = take[0];
            if (ch == 'q') {
                this->type = ProductType::Quantity;
                break;
            }
            else if (ch == 'g') {
                this->type = ProductType::Gram;
                break;
            }
            else if (ch == 'k') {
                this->type = ProductType::Kilogram;
                break;
            }
            else {
                cout << "invalid type\n";
                cout << "Enter the unit of this product(k or g or q): ";
                continue;
            }
        }

        cout << "Please Enter the quantity of " << this->name
             << " which available in the stock: ";
        int q;
        cin >> q;
        this->qty_in_stock = q;

        cout << "Please Enter the last price of  " << this->name
             << ": ";
        double p;
        cin >> p;
        this->price = p;
    }

    //setters
    void setId(string &id){
        this->id = id;
    }
    void setName(string &name){
        this->name = name;
    }
    void setPrice(float price){
        this->price = price;
    }
    void setQty(int qty_in_stock){
        this->qty_in_stock = qty_in_stock;
    }

    //getters
     string getId()const{
        return this->id;
    }
     string getName()const{
        return this->name;
    }
    double getPrice()const{
        return this->price;
    }
     int getQty()const{
        return this->qty_in_stock;
    }
     ProductType getProductUnit()const{
        return this->type;
    }
     string getUnit()const{
        if (this->type == ProductType::Kilogram)
            return "Kilogram";
        else if (this->type == ProductType::Gram)
            return "Gram";
        else if (this->type == ProductType::Quantity)
            return "one";
    }


};

ostream&operator<<(ostream &oss,const Product& product ){
    oss<<"Product info:"
       <<"\n\t"<<"name: "<<product.getName()
       <<"\n\t"<<"id: "<<product.getId()
       <<"\n\t"<<"available quantity: "<<product.getQty()
       <<"\n\t"<<"price: "<<product.getPrice() <<" per " << product.getUnit();


    return oss;
}


