//
//  Header.h
//  Lab2 162
//
//  Created by Jacky on 15/4/15.
//  Copyright (c) 2015年 assignment2. All rights reserved.
//

#ifndef Lab2_162_Header_h
#define Lab2_162_Header_h

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Patient{
public:
    Patient();
    Patient(int gcharges, char* gname, int gdays);
    ~Patient();
    double get_charges();
    void set_charges(int Newcharges);
    int get_days();
    void set_days(int Newdays);
    char* get_name();
    void set_name(char* Newname);
    int get_daily_charges();
    
private:
    double total_charges;
    double daily_charges;
    char* name;
    int days;
};

class Surgery{
public:
    Surgery();
    ~Surgery();
    int at(int);
    string str_at(int);
    void update_Patient(int);
    
    
private:
    int* charges;
    string* type;
    int Newcharge;
};

class Pharmacy{
public:
    Pharmacy();
    ~Pharmacy();
    int at(int);
    string str_at(int);
    void update_Patient(int);
    
    
private:
    int* charges;
    string* type;
    int Newcharge;
};


#endif
