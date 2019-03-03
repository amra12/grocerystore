//
// Created by Amra Feta on 19.04.2016.
//
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>

#ifndef Log_h
#define Log_h

class log {
private:
    int ID; //to find the specific account
    static int ct; //counter to find and calculate id for each account
    const char *name;
    const char *username; // make it const because we cant change the username & password
    const char *pass;
public:
    log() : name(NULL), username(NULL), pass(NULL),
            ID(0) { }; //default const to be able to call the functions later in main
    void account(const char *Name, const char *User_Name, const char *Pass_Word);

    virtual bool type() { return 0; } //made it virtual because i want to have object of this class
    bool login(log *a[], const char *User_Name, const char *Pass_Word); //log*[] is for the poly. array so that we can make loop who goes through every account to check
};

class worker : public log {
public:
    worker(const char *x, const char *y, const char *z) {
        account(x, y, z);
    }

    bool type() //type is to check if the account is for owner or worker accessability
    {
        return false;
    }
};

class owner : public log {

public:
    owner(const char *x, const char *y, const char *z) {
        account(x, y, z);
    }

    bool type() {
        return true;
    }
};

#endif //Log_h

