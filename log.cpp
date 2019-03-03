//
// Created by Amra Feta on 19.04.2016.
//
#include "Log.hpp"
#include <iostream>
#include <cstring>

int log::ct=0;

void log::account(const char *Name,const char *User_Name,const char *Pass_Word){
    Name=name;
    username=User_Name;
    pass=Pass_Word;
    ID=++ct;
}

bool log::login(log **a, const char *User_Name, const char *Pass_Word)
{
    for (int j=0; j<2; ++j) {
        if (strcmp(a[j]->username,User_Name)==0 && strcmp(a[j]->pass,Pass_Word)==0) {
            return true;
        }
    }
    return false;
}