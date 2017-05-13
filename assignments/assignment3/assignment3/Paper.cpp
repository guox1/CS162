//
//  Paper.cpp
//  assignment3
//
//  Created by Jacky on 5/6/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#include "Paper.h"

Paper::Paper(){
    strength = 1;
    type = 'p';
}

Paper::Paper(int x){
    strength = x;
    type = 'p';
}

Paper::~Paper(){}

/*void Tool::set_strength(int x){
    strength = 1;
}
*/
int Paper::new_strength(){
    return strength;
}

bool Paper::fight(Tool tool){
    int temp = 0;
    
    //Paper's strength is doubled (temporarily) when fighting Rock, but halved (temporarily) when fighting Scissors.
    if (tool.get_type() == 'r'){
        temp = strength * 2;
    }
    else if (tool.get_type() == 's'){
        temp = strength / 2;
    }
    
   //The strength field shouldn't change in the function, which returns true if the original class wins in strength and false otherwise.
    return temp > tool.get_strength();
}