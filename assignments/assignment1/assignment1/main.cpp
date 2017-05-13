/******************************************************
 ** Program: play_cf.cpp
 ** Author: Xilun Guo
 ** Date: 04/08/2015
 ** Description:
 ** Input: rows, cols, pieces, how many players
 ** Output: 2d array which can be change the content by user depend on which cols.
 ******************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>

using namespace std;
struct game {
    char **board;
    int r, c, p;
    char p1;
    char p2;
};
bool is_valid_int(string r);
string retry();
int check_input(string input);
void set_game_info(game *);
char** create_table(game *);
bool check_winner(game * p);
void play_game(game *);
void delete_table(game *);

/*********************************************************************
 ** Function: main function
 ** Description: run the whole program
 ** Parameters: int argc, const char * argv[]
 ** Pre-Conditions: c, r, p are int, p < r, p < c
 ** Post-Conditions:
 *********************************************************************/

int main(int argc, const char * argv[]) {
    struct game p;
    if(strcmp(argv[1],"-r")){
        cerr << "Wrong Command1" << endl;
        exit(1);
    }
    else if(strcmp(argv[3],"-c")){
        cerr << "Wrong Command2" << endl;
        exit(2);
    }
    else if(strcmp(argv[5],"-p")){
        cerr << "Wrong Command3" << endl;
        exit(3);
    }
    string temp;
    temp = argv[2];
    cout << temp;
    p.r = check_input(temp);
    
    temp = argv[4];
    cout << temp;
    p.c = check_input(temp);
    
    temp = argv[6];
    cout << temp;
    p.p = check_input(temp);
    while (p.p > p.r && p.p > p.c)
    {
        temp = retry();
        p.p = check_input(temp);
    }
    int x;
    do{
        set_game_info(&p);
        create_table(&p);
        play_game(&p);
        delete_table(&p);
        cout << "Do you want to play again (0-no, 1-yes)?  ";
        cin >> x;
    }while (x == 1);
    return 0;
}

/*********************************************************************
 ** Function: checking function
 ** Description: check int
 ** Parameters: string r
 ** Pre-Conditions: c, r, p are int, p < r, p < c
 ** Post-Conditions:
 *********************************************************************/

bool is_valid_int(string r){
    for (int i = 0; i < r.length(); i++)
    {
        if (r[i] < '0' || r[i] >'9' || r[0] == '0')
        {
            return false;
        }
    }
    return true;
}

string retry(){
    string x;
    cout << "Enter a valid intger: ";
    cin >> x;
    return x;
}

/*********************************************************************
 ** Function: checking function
 ** Description: check int
 ** Parameters: string input
 ** Pre-Conditions: c, r, p are int, p < r, p < c
 ** Post-Conditions:
 *********************************************************************/


int check_input(string input){
    bool check;
    int new_input;
    
    check = is_valid_int(input);
    while (check == false)
    {
        input = retry();
        check = is_valid_int(input);
    }
    new_input = atoi(input.c_str());
    
    return new_input;
}

/*********************************************************************
 ** Function: set info function
 ** Description: set the play which colors
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void set_game_info(game * p){
    cout << "Player one, do you want red or yellow (r or y)?  ";
    cin >> p->p1;
    while(p->p1 != 'r' && p->p1 != 'y'){
        cout << "Only r or y you can pick! (r or y)? ";
        cin >> p->p1;
    }
    if(p->p1 == 'r')
        p->p2 = 'y';
    else
        p->p2 = 'r';

}

/*********************************************************************
 ** Function: create table function
 ** Description: create a 2d array
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

char** create_table(game * p){
    p->board = new char*[p->r];
    for (int i = 0; i < p->r; i++)
        p->board[i] = new char[p->c];
    for (int i = 0; i < p->r; i++){
        for (int j = 0; j < p->c; j++)
            p->board[i][j] = 32;
    }
    return p->board;
}

/*********************************************************************
 ** Function: play function
 ** Description: player1 choose cols to put
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void play_game0(game * p){
    int x0 = p->r-1;
    string temp;
    cout <<"Player 1, what column do you want to put your piece? ";
    cin >> temp;
    int c0 = check_input(temp);
    for (int i = p->r-1; i > 0; i--){
        if (p->board[0][c0-1] != 32){
            cout << "This column that has filled all rows already! Slect another one: ";
            cin >> temp;
            c0 = check_input(temp);
        }
        if((p->board [i][c0-1] == 'r')||(p->board [i][c0-1] == 'y')){
            x0--;
        }

    }
    p->board [x0][c0-1] = p->p1;
    for ( int i = 0; i <p->r; i++){
        for ( int j = 0; j <p->c; j++)
        {
            cout << p->board[i][j]<<" | ";
        }
        cout << endl;
        for(int y = 0; y < p->c; y++)
            cout << "----";
        cout << endl;
    }
}

/*********************************************************************
 ** Function: play function
 ** Description: player2 choose cols to put
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void play_game1(game * p){
    int x1 = p->r-1;
    string temp;
    cout <<"Player 2, what column do you want to put your piece? ";
    cin >> temp;
    int c1 = check_input(temp);
    for (int i = p->r-1; i > 0; i--){
        if (p->board[0][c1-1] != 32){
            cout << "This column that has filled all rows already! Slect another one: ";
            cin >> temp;
            c1 = check_input(temp);
        }
        if((p->board [i][c1-1] == 'r')||(p->board [i][c1-1] == 'y')){
            x1--;
        }
    }
    p->board [x1][c1-1] =p->p2;
    for ( int i = 0; i <p->r; i++){
        for ( int j = 0; j <p->c; j++)
        {
            cout << p->board[i][j]<<" | ";
        }
        cout << endl;
        for(int y = 0; y < p->c; y++)
            cout << "----";
        cout << endl;
    }
}

/*********************************************************************
 ** Function: play function
 ** Description: computer choose cols to put
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void play_game_npc(game * p){
    int c1, x = p->r-1;
    srand(time(NULL));
    c1 = rand() % p->c;
    for (int i = p->r-1; i > 0; i--){
        if((p->board [i][c1-1] == 'r')||(p->board [i][c1-1] == 'y')){
            x--;
        }
    }
    p->board [x][c1-1] =p->p2;
    for ( int i = 0; i <p->r; i++){
        for ( int j = 0; j <p->c; j++)
        {
            cout << p->board[i][j]<<" | ";
        }
        cout << endl;
        for(int y = 0; y < p->c; y++)
            cout << "----";
        cout << endl;
    }
}

/*********************************************************************
 ** Function: check winner function
 ** Description: check who's the winner |
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

bool check_winner_vertical(game * p){
    int z0 = 0, z1 = 0;
    for(int i = p->r-1; i > 0; i--){
        for(int j = 0; j < p->c; j++)
        {
            if(p->board[i][j]=='r')
            {
                if(p->board[i-1][j] == 'r')
                    z0++;
                else
                    z0 = 0;
            }
            if(p->board[i][j] == 'y')
            {
                if(p->board[i-1][j] == 'y')
                    z1++;
                else
                    z1 = 0;
            }
        if(z0 == (p->p-1) || z1 == (p->p-1))
            return true;
        }
    }
    return false;
}

/*********************************************************************
 ** Function: check winner function
 ** Description: check who's the winner by -
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/


bool check_winner_horizontal(game * p){
    int z0 = 0, z1 = 0;
    for(int i = p->r-1; i >= 0; i--){
        for(int j = 0; j < p->c; j++)
        {
            if(p->board[i][j]=='r')
            {
                if(p->board[i][j+1] == 'r')
                    z0++;
                else
                    z0 = 0;
            }
            if(p->board[i][j] == 'y')
            {
                if(p->board[i][j+1] == 'y')
                    z1++;
                else
                    z1 = 0;
            }
            if(z0 == (p->p-1) || z1 == (p->p-1))
                return true;
        }
    }
    return false;

}

/*********************************************************************
 ** Function: check winner function
 ** Description: check who's the winner by /
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/


bool check_winner_ld(game * p){
    int z0 = 0, x = 0, y = 0;
    for(int i = p->r-1; i > 0; i--){
        for(int j = 0; j < p->c-1; j++)
        {
            x=i;
            y=j;
            while(p->board[x][y] == 'r'&&x!=0){
                x = x-1;
                y = y+1;
                z0++;
            }
            if(z0 == p->p)
                return true;
            else if(p->board[x][y] != 'r')
                z0=0;
            x=i;
            y=j;
            while (p->board[x][y] == 'y'&&x!=0){
                x = x-1;
                y = y+1;
                z0++;
            }
            if(z0 == p->p)
                return true;
            else if(p->board[x][y] != 'y')
                z0=0;

        }
    }
    return false;
    
}

/*********************************************************************
 ** Function: check winner function
 ** Description: check who's the winner by \
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

bool check_winner_rd(game * p){
    int z0 = 0, x = 0, y = 0;
    for(int i = p->r-1; i > 0; i--){
        for(int j = p->c-1; j > 0; j--)
        {
            x=i;
            y=j;
            while(p->board[x][y] == 'r'&&x!=0){
                x = x-1;
                y = y-1;
                z0++;
            }
            if(z0 == p->p)
                return true;
            else if(p->board[x][y] != 'r')
                z0=0;
            x=i;
            y=j;
            while (p->board[x][y] == 'y'&&x!=0){
                x = x-1;
                y = y-1;
                z0++;
            }
            if(z0 == p->p)
                return true;
            else if(p->board[x][y] != 'y')
                z0=0;
            
        }
    }
    return false;
    
}

/*********************************************************************
 ** Function: combine check winner function
 ** Description: check who's the winner
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/


bool check_winner(game * p){
    bool winv = check_winner_vertical(p);
    if(winv == true){
        cout << "Vertical " << endl;
        return true;
    }
    bool winh = check_winner_horizontal(p);
    if(winh == true){
        cout << "Horizontal " << endl;
        return true;
    }
    bool windl = check_winner_ld(p);
    if(windl == true){
        cout << "Left Diagornal " << endl;
        return true;
    }
    bool windr = check_winner_rd(p);
    if(windr == true){
        cout << "Right Diagornal " << endl;
        return true;
    }
    return false;
}

/*********************************************************************
 ** Function: combine play game function
 ** Description: play the game depend on how many player
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void play_game(game * p){
    bool win = false;
    int h = 0, f = 1;
    cout << "You want to play with computer? Enter 0, you want to play with others? Enter 1 ";
    cin >> h;
    if (h == 1){
        do{
            for(int i = 0; i < p->c-1; i++){
                if(p->board[0][i] != 32)
                    f = f + 1;
            }
            if(f < p->c)
                f = 1;
            else {
                cout << "No Winner in this game!" << endl;
                break;
                
            }
            play_game0(p);
            win = check_winner(p);
            if(win == true){
                cout << "Player 1 wins!! " << endl;
                break;
            }
            play_game1(p);
            win = check_winner(p);
            if(win == true){
                cout << "Player 2 wins!! " << endl;
                break;
            }
        }while (win == false);
    }
    if(h == 0){
        do{
            play_game0(p);
            win = check_winner(p);
            if(win == true){
                cout << "Player 1 wins!! " << endl;
                break;
            }
            play_game_npc(p);
            win = check_winner(p);
            if(win == true){
                cout << "Player 2 wins!! " << endl;
                break;
            }
        }while (win == false);
    }
}

/*********************************************************************
 ** Function: delete function
 ** Description: delete the 2d array on the heap
 ** Parameters: game * p
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void delete_table(game * p){
    for(int i = 0; i < p->r-1; i++)
        delete [] p->board[i];
    delete [] p->board;
    p->board = NULL;
}

