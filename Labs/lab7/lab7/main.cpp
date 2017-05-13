//
//  main.cpp
//  lab7
//
//  Created by Jacky on 5/20/15.
//  Copyright (c) 2015 lab7. All rights reserved.
//

#include "./vector.hpp"
#include <vector>
#include <iostream>
//We do not want to include either stmt. We wouldn't
//be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;
int main (){
    vector<int> v; //Our vector class
    std::vector<int> stdv; //Standard vector
    //Compare operation of our vector to std
    v.push_back(23);
    stdv.push_back(23);
    stdv.push_back(24);
    stdv.push_back(25);
    std::vector<int>::iterator i; //vector iterator
    i = stdv.begin();
    for(int x = 0; x < 3; x++){
        cout << "The contents of a vector element: " << *i << endl;
        i++;
    }
    return 0;
}