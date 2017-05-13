//
//  Tool.h
//  assignment3
//
//  Created by Jacky on 5/4/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#ifndef assignment3_Tool_h
#define assignment3_Tool_h

class Tool{
public:
    Tool();//Default Constructor
    Tool(int);
    ~Tool();//Destructor
    
    virtual void set_strength(int);
    int get_strength();
    char get_type();
    
    virtual bool fight(Tool);
protected:
    int strength;
    char type;
};

#endif
