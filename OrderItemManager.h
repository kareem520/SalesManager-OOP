#include "OrderItem.h"
class OrderItemManager {

    OrderItem currentOrderItem;
    map<string,OrderItem>orderItem_by_product_id;

public:


    void createOrderItem(Product &product,int wanted_quantity){
        currentOrderItem.readOrderItem(product,wanted_quantity);
       // PMG.takeFromProduct(product,wanted_quantity);
    }

    void CancelOrderItem(Product &product,int wanted_quantity){
       // PMG.RetrievalToProduct(product,wanted_quantity);
    }




};


