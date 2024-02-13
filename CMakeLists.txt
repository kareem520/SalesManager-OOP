cmake_minimum_required(VERSION 3.25)
project(ask)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ask
        Administrator.h
        Company.h
        Coupon.h
        Customer.h
        SalesManager.h
        main.cpp
        Person.h
        Transaction.h
        User.h
        UserManager.h PersonManager.h CompanyManager.h Product.h ProductManager.h Stock.h Help.h Order.h OrderItem.h OrderManager.h OrderItemManager.h SystemManager.h AdministratorManager.h StockManager.h ShopCart.h)
