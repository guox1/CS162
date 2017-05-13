//
//  Rock.h
//  assignment3
//
//  Created by Jacky on 5/4/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#ifndef assignment3_Rock_h
#define assignment3_Rock_h

#include "Tool.h"

class Rock:public Tool{
public:
    Rock();//Default Constructor
    Rock(int);//Parameterized Constructor
    ~Rock();//Destructor
    
    int new_strength();
    bool fight(Tool);
private:
    int r;

};

#endif
