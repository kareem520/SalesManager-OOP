#include "PersonManager.h"



class SalesManager{
private:
    vector<Order>current_orders;//will clear after transaction
    map<int,Order>all_paid_orders;
    map<int,Order>all_hold_orders;
    map<int,Order>all_cancelled_orders;
    set<int>all_order_ids;//except cancelled orders
    Order *new_order;
    OrderItem* new_order_item;
    ShopCart ourShoupCart;
    StockManager STMG;

public:

    SalesManager(){
        new_order = nullptr;
        new_order_item = nullptr;
    }
/////////////////////////////////////////////////////order////

    void make_order(Order &ourOrder){
        cout <<"Creating a new order......."<<endl;
        //make a new orderItem to put in order
        OrderItem ourItem;
        make_order_item(ourItem);
        //now orderItem is added.

        //make an order and put this orderItem
        create_order_helper(ourOrder);
        //now order is created,

        add_orderItem_to_Order(ourItem,ourOrder);
        //now order item is added to order

        //put order in our shop cart.
        put_order_in_shopCart(ourOrder);

    }

    void create_order_helper(Order order){
        new_order = new Order;
        int random_id = Help::get_random_id();

        while(all_order_ids.count(random_id)){
            random_id = Help::get_random_id();
        }
        new_order->readOrder(random_id,ourShoupCart.get_counter_orders()+1);

        order = *new_order;
        new_order = nullptr;
    }

//--------------------------------------------------------------------------------------------------------------------


    /////////////////////////////////////////////////////manage order_item and add it to order////////////////////
    void make_order_item(OrderItem &Item){
        new_order_item = new OrderItem;

        string id;
        cout <<"Enter product id: ";
        cin >> id;
        while (!STMG.this_id_is_there(id)){
            cout <<"Enter product id: ";
            cin >> id;
        }

        cout <<"Enter quantity you want to add: ";
        add_wanted_quantity_to_order_item(*new_order_item,id);

        //get product from stock
        const Product *prodPtr = &STMG.Product_by_id(id);
        //add product to ->Order_item
        *new_order_item+=*prodPtr;

        Item = *new_order_item;
        new_order_item = nullptr;

        //add_orderItem_to_newOrder(*new_order_item,*new_order);


    }

    void add_wanted_quantity_to_order_item(OrderItem &Item,string product_id){

        int qty;
        cin >> qty;

        while (!STMG.is_available_quantity(qty,product_id)){
            cout <<"Available quantity in the stock: "<<
                STMG.get_available_quantity(product_id)<<endl;

            cout <<"Enter quantity you want to add: ";
            cin >> qty;
        }

        //add wanted quantity to my orderItem
        Item +=qty;

        //important****
        take_quantity_from_stock(*new_order_item);

    }

    void take_quantity_from_stock(OrderItem &Itme){

        /////////very important to decrease take the quantity from stock
        STMG.buy(Itme.getProductId(),Itme.getQty());

    }

    void add_orderItem_to_Order(OrderItem &Item,Order &order){

        // it called after putting product and quantity in orderItem
        order += Item;

    }
//----------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////ShopCart Operations//////////////////////////////////////////

    void places_an_Order(){
        if (ourShoupCart.get_counter_orders()>0){
            cout <<"You want to create a new order? ";
            string str;
            cin >> str;
            bool falg = true;
            falg &= Help::toLower(str);
            while (!falg){
                cout <<"Invalid Input" <<endl;
                cout <<"You want to create a new order? ";
                cin >> str;
                falg &= Help::toLower(str);
            }

            if (str=="yes"){
                Order ourOrder;
                make_order(ourOrder);
                put_order_in_shopCart(ourOrder);
            }
            else {
                //first client chooses order which he wants to add orderItem
                //ask him to enter order number or print for all his shop cart with orders details
                int number;
                cout <<"Enter number of the order which you want to add order in it: ";
                cin>>number;
                while (!check_shopCart(number)){
                    cout <<"Invalid number."<<endl;
                    cout <<"\tTry again->enter 1"
                           "\n\tprint your shop cart->enter 2";
                    int ch; cin >> ch;
                    while (!(ch==1 || ch==2)){
                        cout <<"Invalid input."<<endl;
                        cout <<"\tTry again->enter 1"
                               "\n\tprint your shop cart->enter 2";
                        cin >> ch;
                    }
                     if (ch==2){
                        cout <<ourShoupCart<<endl;
                    }
                    cout <<"Enter number of the order which you want to add order in it: ";
                    cin>>number;

                }

                //first get the order with this number.
                Order &order = getOrder_withidx(number);
                //delete order from shop cart to edite it in security way.
                putOut_order_from_shopCart(order);
                //make client enter the product which he wants.
                //add it to an orderItem.
                OrderItem orderItem;
                make_order_item(orderItem);
                add_orderItem_to_Order(orderItem,order);

                //now order is ready for replay to shop cart after modification.
                put_order_in_shopCart(order);

            }
        }
        else{
            Order ourOrder;
            make_order(ourOrder);
            put_order_in_shopCart(ourOrder);

        }
    }


    bool check_shopCart(int number){
        return (ourShoupCart.get_counter_orders()<=number);
    }
    void put_order_in_shopCart(const Order &order){
        ourShoupCart +=order;
    }
    void putOut_order_from_shopCart(Order &order){
        ourShoupCart-=order;
    }
    Order &getOrder_withidx(int idx){
        idx--;
        return ourShoupCart.getOrder_by_idx(idx);
    }



};

