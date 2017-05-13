//
//  RPSGame.cpp
//  assignment3
//
//  Created by Jacky on 5/4/15.
//  Copyright (c) 2015 assignment3. All rights reserved.
//

#include "RPSGame.h"
#include <iostream>
using namespace std;

/*********************************************************************
 ** Function: default constructor
 ** Description: default human_wins, computer_wins, and ties to 0.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

RPSGame::RPSGame(){
    human_wins = 0;
    computer_wins = 0;
    ties = 0;
}

RPSGame::RPSGame(int h, int c, int t){
    human_wins = h;
    computer_wins = c;
    ties = t;
}

RPSGame::~RPSGame(){}

Tool *RPSGame::human_tool(){
    return humantool;
}

Tool *RPSGame::computer_tool(){
    return computertool;
}

int RPSGame::get_human_wins(){
    return human_wins;
}

int RPSGame::get_computer_wins(){
    return computer_wins;
}

int RPSGame::get_ties(){
    return ties + 1;
}

void RPSGame::set_human_tool(Tool *tool){
    humantool = tool;
}

void RPSGame::set_computer_tool(Tool *tool){
    computertool = tool;
}

void RPSGame::set_human_wins(int HW){
    human_wins = HW;
}

void RPSGame::set_computer_wins(int CW){
    computer_wins = CW;
}

void RPSGame::set_ties(int T){
    ties = T;
}

/*********************************************************************
 ** Function: fighting
 ** Description: human wins return true and human_wins + 1, otherwise return false and computer_wins + 1
 ** Parameters: Tool *human, Tool *computer
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

bool RPSGame::fight(Tool *human, Tool *computer){
    //human wins return true, otherwise return false.
    if (human->fight(*computer)){
        human_wins = human_wins + 1;
        return true;
    }
    else{
        computer_wins = computer_wins + 1;
        return false;
    }
}

void RPSGame::print_info(){
    cout << "Human wins: " << human_wins << endl;
    cout << "Computer wins: " << computer_wins << endl;
    cout << "Ties: " << ties << endl;
}








