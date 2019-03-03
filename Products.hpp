//
// Created by Amra Feta on 19.04.2016.
//

#ifndef HOMEWORK_PRODUCTS_H
#define HOMEWORK_PRODUCTS_H
#endif //HOMEWORK_PRODUCTS_H

class Products

{
    char name[50];
    int ID;
    double price;
    int quantity;//how many products i have
     const int tax=(3/10);
    double discount;


public:
    Products():discount(0),ID(0){}
    int Get_Last_ID();
    static int ct;
    static int profit;
    void create_product();
    void show_product() const;
    //void get_product();
    void modify();
    long int getprice()const;
    double get_discount();
    int get_id();
    bool delete_pro(int id);//delete them by Id
    void display_pro(int id);//delete them by Id
    bool Save_To_File();
    void Read_From_File();
    void modify_File(int id);
    void display_all();
    bool buy_product();
    bool Check_Product(char *Name);


};
