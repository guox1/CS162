#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <string>
#include "RPSGame.h"

using namespace std;


/*********************************************************************
 ** Function: get strength function
 ** Description: get strength of rock, paper, scissors from user
 ** Parameters: char &choice_of_strengths, int &rock_strength, int &paper_strength, int &scissors_strength
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void strength(char &choice_of_strengths, int &rock_strength, int &paper_strength, int &scissors_strength){
    
    do{
        cout << "Welcome to Rock, Paper, Scissors! Do you want to choose different strengths for the tools? (y-yes, n-no) ";
        cin >> choice_of_strengths;
        if (choice_of_strengths != 'y' && choice_of_strengths != 'n')
            cout << "Invalid Input, 'y' or 'n' only! " << endl;
    }while(choice_of_strengths != 'y' && choice_of_strengths != 'n');
    
    if (choice_of_strengths == 'y'){
        cout << "Choose num of strength of Rock: ";
        float r = 0.0;
        cin >> r;
        rock_strength = r;
        while((r < 1)||((r - rock_strength) != 0)){
            cout << "Invalid Input, int num only! You can input again: ";
            cin.clear();cin.ignore(256, '\n');cin >> r; rock_strength = r;}
        cout << endl << "Choose num of strength of Paper: ";
        float p = 0.0;
        cin >> p;
        paper_strength = p;
        while((p < 1)||((p - paper_strength) != 0)){
            cout << "Invalid Input, int num only! You can input again: ";
            cin.clear();cin.ignore(256, '\n');cin >> p; paper_strength = p;}
        cout << endl << "Choose num of strength of scissors: ";
        float s = 0.0;
        cin >> s;
        scissors_strength = s;
        while((s < 1)||((s - scissors_strength) != 0)){
            cout << "Invalid Input, int num only! You can input again: ";
            cin.clear();cin.ignore(256, '\n');cin >> s; scissors_strength = s;}    }
}

/*********************************************************************
 ** Function: choice
 ** Description: get choice of rock, paper, scissors from user
 ** Parameters: char &choice_of_tools
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void choice(char &choice_of_tools){
    do{
        cout << "Choose your tool (r-rock, p-paper, s-scissor, e-exit): ";
        cin >> choice_of_tools;
        if (choice_of_tools != 'r' && choice_of_tools != 'p' && choice_of_tools != 's' && choice_of_tools != 'e'){
            cout << "Invalid Input! " << endl;
            cout << "Choose your tool (r-rock, p-paper, s-scissor, e-exit): ";
        }
    }while(choice_of_tools != 'r' && choice_of_tools != 'p' && choice_of_tools != 's' && choice_of_tools != 'e');
}

/*********************************************************************
 ** Function: set_human_tool
 ** Description: set the tool of human
 ** Parameters: int &rock_strength, int &paper_strength, int &scissors_strength, char &choice_of_strengths, char &choice_of_tools, Tool *&humantool
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void set_human_tool(int &rock_strength, int &paper_strength, int &scissors_strength, char &choice_of_strengths, char &choice_of_tools, Tool *&humantool){
    Rock *rock;
    Paper *paper;
    Scissors *scissors;
    if (choice_of_tools == 'r'){
        if (choice_of_strengths == 'y')
            rock = new Rock(rock_strength);
        else
            rock = new Rock();
        humantool = rock;
    }
    
    else if (choice_of_tools == 'p'){
        if (choice_of_strengths == 'y')
            paper = new Paper(paper_strength);
        else
            paper = new Paper();
        humantool = paper;
    }
    
    else if (choice_of_tools == 's'){
        if (choice_of_strengths == 'y')
            scissors = new Scissors(scissors_strength);
        else
            scissors = new Scissors();
        humantool = scissors;
    }
}

/*********************************************************************
 ** Function: set_computer_tool
 ** Description: set the tool of computer
 ** Parameters: int &rock_strength, int &paper_strength, int &scissors_strength, char &choice_of_strengths, char &choice_of_tools, Tool *&computertool, int &num
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void set_computer_tool(int &rock_strength, int &paper_strength, int &scissors_strength, char &choice_of_strengths, char &choice_of_tools, Tool *&computertool, int &num){
    Rock *rock;
    Paper *paper;
    Scissors *scissors;
    if (num == 0){
        if (choice_of_strengths == 'y')
            rock = new Rock(rock_strength);
        else
            rock = new Rock();
        computertool = rock;
        cout << "Computer chose Rock." << endl;
    }
    
    else if (num == 1){
        if (choice_of_strengths == 'y')
            paper = new Paper(paper_strength);
        else
            paper = new Paper();
        computertool = paper;
        cout << "Computer chose Paper." << endl;
    }
    
    else if (num == 2){
        if (choice_of_strengths == 'y')
            scissors = new Scissors(scissors_strength);
        else
            scissors = new Scissors();
        computertool = scissors;
        cout << "Computer chose Scissors." << endl;
    }

}


/*********************************************************************
 ** Function: free memory function
 ** Description: delete the humantool and computertool on the heap
 ** Parameters: Tool *humantool, Tool *computertool
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void free(Tool *humantool, Tool *computertool){
    delete humantool;
    humantool = NULL;
    delete computertool;
    computertool = NULL;
}

int main() {
    RPSGame RPSGame;
    char choice_of_strengths, choice_of_tools;
    Tool *humantool = 0;
    Tool *computertool = 0;
    int rock_strength = 0, paper_strength = 0, scissors_strength = 0, num = 0;
    strength(choice_of_strengths, rock_strength, paper_strength, scissors_strength);
    choice(choice_of_tools);
    while (choice_of_tools != 'e'){
        srand(time(NULL)); //set
        num = rand() % 3; // get a num among 0 - 2.
        set_human_tool(rock_strength, paper_strength, scissors_strength, choice_of_strengths, choice_of_tools, humantool);
        set_computer_tool(rock_strength, paper_strength, scissors_strength, choice_of_strengths, choice_of_tools, computertool, num);
        
        if(humantool->get_type() == computertool->get_type()){
            cout << "You have tied!" << endl;
            RPSGame.set_ties(RPSGame.get_ties());
        }
        else if(RPSGame.fight(humantool, computertool))
            cout << "Yon wins!!! " << endl;
        else
            cout << "Computer wins! :-( " << endl;
        RPSGame.print_info();
        choice(choice_of_tools);
        free(humantool, computertool);
    }
    return 0;
}
