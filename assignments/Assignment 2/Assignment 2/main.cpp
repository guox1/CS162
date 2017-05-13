//
//  main.cpp
//  Assignment 2
//
//  Created by Jacky on 4/21/15.
//  Copyright (c) 2015 Assignment 2. All rights reserved.
//
#include "movie1.h"
#include "Netflix1.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
int main() {
    int user_input;
    cout << "Do you want to enter a movie to the database or find a movie to rent? (1 – enter, 2 – find, or 0 - exit) ";
    cin >> user_input;
    do{
        if(user_input == 1){
            cout << "How many movies do you want to enter to the database? ";
        }
        if(user_input == 2){
            
        }
        else
            exit();
        cout << "Do you want to enter a movie to the database or find a movie to rent? (1 – enter, 2 – find, or 0 - exit) ";
        cin >> user_input;
    }while(user_input == 0);
    return 0;
}
