//
//  Scissors.h
//  assignment3
//
//  Created by Jacky on 5/4/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#ifndef assignment3_Scissors_h
#define assignment3_Scissors_h

#include "Tool.h"

class Scissors:public Tool{
public:
    Scissors();//Default Constructor
    Scissors(int);//Parameterized Constructor
    ~Scissors();//Destructor
    
    int new_strength();
    bool fight(Tool);
    
private:
    int s;
    
};


#endif
