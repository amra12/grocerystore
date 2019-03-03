#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Log.hpp"
#include "Products.hpp"

using namespace std;

bool Save_To_File();

void Owner();

void Customer();

void Worker();

int main() {

    log *accounts[10];
    accounts[0] = new worker("Mr.Thomanson", "Thom", "123");
    accounts[1] = new owner("Mr Brandson", "Bran", "456");


    int i;
    log call;
    //call the functions in worker and owner header
    char ch;


    Products a;
    do {
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. CUSTOMER";
        cout << "\n\n\t02. ADMINISTRATOR";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;
        switch (ch) {
            case '1': {
                Customer();
                break;
            }

            case '2': {
                char user[50];
                char pass[50];
                cout << "Please enter your username:";
                cin.ignore();
                cin.getline(user, 50);
                cout << endl;
                cout << "Please enter your pass:";
                cin.getline(pass, 50);
                if (call.login(accounts, user, pass)) {
                    Owner();
                }
                else {
                    system("cls");
                    cout << "Wrong user name or pass...\nPress any key..." << endl;
                    break;
                }
            }
            case '3': {

                break;
            }
            default :
                cout << "\a";
        }
        cin.ignore();//eveytime for the cleanning the buffer and prepare it for next entry from the user
        cin.get();
        system("cls");
    }
    while (ch != '3');

for(int i;i<2;++i)
{
    delete accounts[i];
}
    return 0;
}

bool login(char *a) {
    // if()
}

void Owner() {
    char ch;
    Products a;
    do {
        cout << "\n\n\t01. Create a product";
        cout << "\n\n\t02. Show all Products";
        cout << "\n\n\t03. Modify product";
        cout << "\n\n\t04. Delete product";
        cout << "\n\n\t05. Display a specific product";
        cout << "\n\n\t06.Back to  main menu";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;
        switch (ch) {
            case '1': {
                a.create_product();
                break;
            }

            case '2': {
                a.display_all();
                break;
            }

            case '3': {
                cout << "Please enter the id of the product : ";
                int id;
                cin >> id;
                a.modify_File(id);
                break;
            }
            case '4': {
                int id;
                cout << "Which one of them you want to delete\n Enter the number:";
                a.display_all();
                cin >> id;
                if (a.delete_pro(id)) {
                    cout << "Your product has been deleted\n Press any key..." << endl;
                }
                break;
            }
            case '5': {
                int id;
                cin >> id;
                a.display_pro(id);
                break;
            }
            case '6': {
                cout << "Press any key..." << endl;
                break;
            }
            default :
                cout << "Wrong Entry\nPress any key...." << endl;
        }
        cin.ignore();//eveytimefor the clcleeaanning the buffer and prepare it for next entry from the user
        cin.get();
        system("cls");
    } while (ch != '6');
}



void Customer() {
    char ch;
    Products a;

    do{
        cout<<"\n\n\t01.Show all Products ";
        cout<<"\n\n\t02.Display a specific product:";
        cout<<"\n\n\t03.Buy this product :";
        cout << "\n\n\t04.Back to  main menu";
        cout << "\n\n\tPlease Select Your Option (1-4) ";
        cin>> ch;
        switch (ch){

            case '1': {
                a.display_all();
                break;
            }
            case '2': {
                cout<<"Enter the id of the product you want to see:";
                    int id;
                    cin >> id;
                    a.display_pro(id);
                    break;
                }
            case '3':{
                a.buy_product();
                cout << "\n\n\tProduct bought";

                break;
            }
            case '4': {
                cout << "Press any key..." << endl;
                break;
            }
            default :
                cout << "Wrong Entry\nPress any key...." << endl;
        }
        cin.ignore();//eveytimefor the clcleeaanning the buffer and prepare it for next entry from the user
        cin.get();
        system("cls");
    } while (ch != '4');


}

 void Worker() {
    char ch;
     Products a;
    do {
        cout << "\n\n\t01. Create a product";
        cout << "\n\n\t02. Show all Products";
        cout << "\n\n\t03. Display a specific product";
        cout << "\n\n\t04.Back to  main menu";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;
        switch (ch) {
            case '1': {
                a.create_product();
                break;
            }

            case '2': {
                a.display_all();
                break;
            }

            case '3': {
                int id;
                cin >> id;
                a.display_pro(id);
                break;
            }
            case '4': {
                cout << "Press any key..." << endl;
                break;
            }
            default :
                cout << "Wrong Entry\nPress any key...." << endl;
        }
        cin.ignore();//eveytimefor the clcleeaanning the buffer and prepare it for next entry from the user
        cin.get();
        system("cls");
    } while (ch != '4');

}

