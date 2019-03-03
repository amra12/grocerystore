//
// Created by HP on 02.05.2016.
//
#include "Products.hpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <iostream>
#include "Log.hpp"
#include <fstream>

using namespace std;

int Products::ct = 0;


bool Products::Save_To_File() {

    ofstream File;

    File.open("Products.dat", ios::binary | ios::app);

    File.write(reinterpret_cast<char *>(this), sizeof(Products));

    File.close();
    return true;
}


void Products::Read_From_File() {
    ifstream File;
    File.open("Products.dat", ios::binary);
    if (!File) {
        cout << "No File excist.." << endl;
    }
    while (File.read(reinterpret_cast<char *> (this), sizeof(Products))) {
        this->show_product();
    }
    File.close();
}

void Products::create_product() {

    cout << "\nEnter the name of the product :";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter the price : ";
    cin >> price;
    cout << "\nEnter the quantity : ";
    cin >> quantity;
    cout << "Does this product have discount? (Y/N)";
    char a;
    cin >> a;
    a = toupper(a);
    if (a == 'Y') {
        cout << "\nEnter the discount : ";
        cin >> this->discount;
    }
    cout << "\n";
Products b;
    int i=b.Get_Last_ID();
    this->ID=++i;

    Save_To_File();


}

void Products::show_product() const {

    cout << "\nProduct Number : " << ID;
    cout << "\nProduct name : " << name;
    cout << "\nPrice : " << price;
    if (discount) {
        cout << "\n Discount : " << discount;
    }
    else {
        cout << "\nDiscount : No discount";
    }
    cout << "\n Quantity of Product" << quantity;
}

long int Products::getprice() const {
    return this->price;
}

double Products::get_discount() { return this->discount; }

int Products::get_id() { return this->ID; }

void Products::modify() {
    cout << "\nProduct Name : " << name;
    cout << "\nModify Product Price  : ";
    cin >> price;
    cout << "\nModify Discount : ";
    cout << "Does this product have discount? (Y/N)";
    char a;
    cin >> a;
    a = toupper(a);
    if (a == 'Y') {
        cout << "\nEnter the discount : ";
        cin >> this->discount;
    }

}

void Products::modify_File(
        int id) { //we find the specific product from file then we call modify function for that product
    bool error = false;
    fstream File;
    File.open("Products.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "No File excist..";
        return;
    }
    while (File.read(reinterpret_cast<char *>(this), sizeof(Products)) && error == false) {

        if (get_id() == id) {
            show_product();
            cout << "\n\n\tEnter The New info Product" << endl;
            modify();
            int pos = (-1) * static_cast<int>(sizeof(Products));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (this), sizeof(Products));
            cout << "\n\n\tproduct changed";
            error = true;
        }
    }
    File.close();
    if (error == false) {
        cout << "\n\n\tThis product couldn't be found";
    }

}

void Products::display_pro(int id) {

    ifstream File;
    File.open("Products.dat", ios::binary);
    if (!File) {
        cout << "No File excist..";
        return;
    }
    while (File.read(reinterpret_cast<char *>(this), sizeof(Products))) {

        if (get_id() == id) {
            show_product();
        }
    }
    File.close();
}

bool Products::delete_pro(int id) {
    ifstream File;
    ofstream Fileout;
    File.open("Products.dat", ios::binary);
    if (!File) {
        cout << "No File excist..";
        return false;
    }
    Fileout.open("tmp.dat", ios::binary);
    while (File.read(reinterpret_cast<char *>(this), sizeof(Products))) {

        if (get_id() != id) {
            Fileout.write(reinterpret_cast<char *>(this), sizeof(Products));
        }
    }
    File.close();
    Fileout.close();

    remove("Products.dat");
    rename("tmp.dat", "Products.dat");
    return true;
}

void Products::display_all() {

    ifstream File;
    File.open("Products.dat", ios::binary);
    if (!File) {
        cout << "No File excist..";
        return;
    }
    while (File.read(reinterpret_cast<char *>(this), sizeof(Products))) {
        show_product();
    }
    File.close();
}

bool Products::buy_product() {
    display_all();
    int id;
    cout << "\n\n\nPlease choose one of them to buy:" << endl;
    cin >> id;
    if (quantity == 1) {
        delete_pro(id); //Not good
        return true;
    }
    else {
        --this->quantity;
        delete_pro(id);//Not good it doesnt buy my product it deletes it
        Save_To_File();
        return true;
    }
}

bool Products::Check_Product(char *Name) {
    ifstream File;
    File.open("Products.dat", ios::binary);
    while (File.read(reinterpret_cast<char *>(this), sizeof(Products))) {
        if (strcmp(this->name, Name) == 0) {
            File.close();
            return true;
        }
    }
    File.close();
    return false;

}

int Products::Get_Last_ID() {
    ifstream File;
    File.open("Products.dat",ios::binary);
    while(File.read(reinterpret_cast<char *>(this), sizeof(Products))){

    }
    File.close();
    return ID;
}

