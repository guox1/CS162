//
//  Rock.cpp
//  assignment3
//
//  Created by Jacky on 5/6/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#include "Rock.h"

Rock::Rock(){
    strength = 1;
    type = 'r';
}
Rock::Rock(int x){
    strength = x;
    type = 'r';
}

Rock::~Rock(){}

/*void Tool::set_strength(int x){
    strength = 1;
}
*/
int Rock::new_strength(){
    return strength;
}

bool Rock::fight(Tool tool){
    int temp = 0;
    
    //Rock's strength is doubled (temporarily) when fighting scissors, but halved (temporarily) when fighting paper.
    if (tool.get_type() == 's'){
        temp = strength * 2;
    }
    else if (tool.get_type() == 'p'){
        temp = strength / 2;
    }
    
    //The strength field shouldn't change in the function, which returns true if the original class wins in strength and false otherwise.
    return temp > tool.get_strength();
}