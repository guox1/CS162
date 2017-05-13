#include “./mult_div.h”
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;
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
