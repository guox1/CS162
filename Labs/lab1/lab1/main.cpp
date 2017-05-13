//
//  main.cpp
//  lab1
//
//  Created by Jacky on 4/1/15.
//  Copyright (c) 2015 lab1. All rights reserved.
//
//#include “./mult_div.h”
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

struct mult_div_values {
    int mult;
    float div;
};
bool is_valid_diminsions(int argc, const char * argv[], string m, string n);
mult_div_values** create_table(int m, int n);
void set_mult_values(mult_div_values **table, int m, int n);
void set_div_values(mult_div_values **table, int m, int n);
void delete_table(mult_div_values **table, int m);

int main(int argc, const char * argv[]) {
    int x, rows, cols;
    string m ,n;
    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    do{
        is_valid_diminsions(argc, argv, m, n);
        mult_div_values** table = create_table(rows, cols);
        create_table(rows, cols);
        set_mult_values(table, rows, cols);
        set_div_values(table, rows, cols);
        //delete_table(table, rows);
        cout << "Would you like to see a different size matrix (0-no, 1-yes)? " << endl;
        cin >> x;
    }while(x == 1);
    return 0;
}

bool is_valid_diminsions(int argc, const char * argv[], string m, string n){//不确定是否可以将char * 改为string
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    for(int i = 0; i < m.length(); i++)
        if(m[i] < '0' || m[i] > '9')
            return false;
    for(int i = 0; i < n.length(); i++)
        if(n[i] < '0' || n[i] > '9')
            return false;
    return true;
        
}

mult_div_values** create_table(int m, int n){
    
    mult_div_values** table = new mult_div_values *[m];
    
    for (int x = 1; x <= m; x++)
    {
        table[x] = new mult_div_values [n];
  
    }
    return table;
}

void set_mult_values(mult_div_values **table, int m, int n){
    for (int x = 1; x <= m; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            
            table[x][y].mult = x * y;
            cout << table[x][y].mult << " ";
        }
        cout << endl;
    }
    
}

void set_div_values(mult_div_values **table, int m, int n){
    int i = 0, j = 0;
    for (float x = 0; x < m; x++)
    {
        i = i + 1;
        for (float y = 0; y < n; y++)
        {
            j = j + 1;
            table[i][j].div = (x+1) / (y+1);
            cout << table[i][j].div << " ";
        }
        cout << endl;
    }
}

void delete_table(mult_div_values **table, int m){
    for(int i = 0; i < m-1; i++)
    {
        delete [] table[i];
    }
    
    //delete [] table;
}








