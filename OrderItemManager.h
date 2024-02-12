#include "OrderItem.h"
class OrderItemManager {

    OrderItem currentOrderItem;
    map<string,Product>oroduct_by_order_item_id;
    map<string,OrderItem>order_item_by_this_id;
    ProductManager PMG;

public:


    void createOrderItem(Product &product,int wanted_quantity){
        currentOrderItem.readOrderItem(product,wanted_quantity);
       // PMG.takeFromProduct(product,wanted_quantity);
    }

    void CancelOrderItem(Product &product,int wanted_quantity){
       // PMG.RetrievalToProduct(product,wanted_quantity);
    }




};


