//
//  Scissors.cpp
//  assignment3
//
//  Created by Jacky on 5/6/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#include "Scissors.h"

Scissors::Scissors(){
    strength = 1;
    type = 's';
}

Scissors::Scissors(int x){
    strength = x;
    type = 's';
}

Scissors::~Scissors(){}

/*void Tool::set_strength(int x){
    strength = 1;
}
*/
int Scissors::new_strength(){
    return strength;
}

bool Scissors::fight(Tool tool){
    int temp = 0;
    
    //Scissors's strength is doubled (temporarily) when fighting Paper, but halved (temporarily) when fighting Rock.
    
    if (tool.get_type() == 'p'){
        temp = strength * 2;
    }
    
    else if (tool.get_type() == 'r'){
        temp = strength / 2;
    }
    //The strength field shouldn't change in the function, which returns true if the original class wins in strength and false otherwise.
    return temp > tool.get_strength();
}