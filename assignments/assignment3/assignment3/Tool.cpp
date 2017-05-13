//
//  Tool.cpp
//  assignment3
//
//  Created by Jacky on 5/4/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#include "Tool.h"

Tool::Tool(){
    strength = 1;
}

Tool::Tool(int x){
    strength = x;
}

Tool::~Tool(){}

void Tool::set_strength(int x){
    strength = x;
}

int Tool::get_strength(){
    return strength;
}

char Tool::get_type(){
    return type;
}

bool Tool::fight(Tool tool){
    return true;
}

