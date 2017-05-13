#include “./mult_div.h”
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

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

