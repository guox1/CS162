//
//  Paper.h
//  assignment3
//
//  Created by Jacky on 5/4/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#ifndef assignment3_Paper_h
#define assignment3_Paper_h

#include "Tool.h"

class Paper:public Tool{
public:
    Paper();//Default Constructor
    Paper(int);//Parameterized Constructor
    ~Paper();//Destructor
    
    int new_strength();
    bool fight(Tool);
    
private:
    int p;
    
};


#endif
