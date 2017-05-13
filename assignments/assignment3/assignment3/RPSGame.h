//
//  RPSGame.h
//  assignment3
//
//  Created by Jacky on 5/4/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#ifndef assignment3_RPSGame_h
#define assignment3_RPSGame_h

#include "Tool.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

class RPSGame{
public:
    RPSGame(); //Default Constructor
    RPSGame(int, int, int);
    ~RPSGame(); //Destructor 感觉不需要 因为没有用到heap
    
    Tool *computer_tool();
    Tool *human_tool();
    
    //getter
    int get_human_wins();
    int get_computer_wins();
    int get_ties();
    
    //setter
    void set_human_tool(Tool* tool);
    void set_computer_tool(Tool* tool);
    void set_human_wins(int);
    void set_computer_wins(int);
    void set_ties(int);
    
    //Human 赢 return true!
    bool fight(Tool*, Tool*);
    
    void print_info();

    
protected:
    Tool *humantool;
    Tool *computertool;
    int human_wins;
    int computer_wins;
    int ties;
};

#endif
