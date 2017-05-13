/******************************************************
** Program: simulate_roomba.cpp
** Author: Jacky
** Date: 05/20/2015
** Description:
** Input:
** Output:
******************************************************/

#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctype.h>
#include "Room.h"
#include "RandomRoomba.h"
using namespace std;
int firstRow;
int firstColumn;
int pointoFView;
ifstream inputFile;
string file;

vector<char> typeFloor;

int batteryLife;

void choose_roomba(Room <Roomba> &r) {
	int choice;
	cout << "Which Roomba(1 - Random, 2 - ? , 3 - ? ) ? ";
	cin >> choice;


	if (choice == 1){
		RandomRoomba r1;
		r.set_roomba(r1);
	}
	else if (choice == 2){
		Roomba r2;
		r.set_roomba(r2);
	}
	else if (choice == 3){
		Roomba r2;
		r.set_roomba(r2);
	}

	else{

	}
}
void move(char **&nArray, int &r, int&c, int &pc, int &pr){
    Roomba Roomba;
    int num = 5;
    do{
        num = rand() % 4;
        if (num==0&&pc<c&&nArray[pr][pc+1]!='O')
            Roomba.moveRight();
        else if(num ==1&&pc>0&&nArray[pr][pc-1]!='O')
            Roomba.moveLeft();
        else if(num==2&&pr>0&&nArray[pr-1][pc]!='O')
            Roomba.moveUp();
        else if(num==3&&pr<r&&nArray[pr+1][pc]!='O')
            Roomba.moveDown();
        else
            num=5;
    }while(num==5);

}

void print(char **&nArray, int &r, int &c, int &pc, int &pr){
    move(*&nArray, r, c, pc, pr);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << nArray[i][j] << " ";
        }
        cout <<endl;
    }
}

void simulate_roomba(string floorplan, char **&nArray, int &r, int&c, int &pc, int &pr)
{
    Room <Roomba> R;
    Floor floor;
    ifstream inputFile(floorplan.c_str());
    int boardSizeRow, boardSizeCol;
    string line;
    int k=0;
    boardSizeRow = boardSizeCol = 0;
    inputFile.get();
    
   // ofstream inputFile;
    inputFile.open("floorplan.txt");
    if (inputFile)
    {
        
        //Counts Size of Column
        while (getline(cin, line))
        {
            boardSizeCol++;
        }
        
        cout << "Size of Columns : " << boardSizeCol << endl;
        
        //Counts Size of Row (Will be double due to spaces)
        getline(inputFile, line);
        boardSizeRow = line.size();
        cout << "Size of Rows : " << boardSizeRow / 2 << endl;
        
    }
    else
    {
        cout << "No File loaded. (Run the program again)" << endl;
        
    }

    c=boardSizeRow / 2;
 
    cout << "Beginning:" << endl;
    nArray = new char * [r];
    for (int i=0; i<r; i++) {
        nArray[i]=new char [c];
        for (int j=0; j<c; j++) {
            nArray[i][j]='f';
            cout << nArray[i][j];
            k+=2;
        }
    }
   // choose_roomba(R);
   // R.clean_room();
}

int main(int argc, char *argv[]) {
    char **nArray;
    string floorplan;
    int r=0, c=0,pr,pc;
    //read command line parameters
    if (strcmp(argv[1] ,"-f")==0){
        file = argv[2];
    }
    
    if (strcmp(argv[3], "-b") == 0){
        batteryLife = atoi(argv[4]);
    }
    
    if (strcmp(argv[5], "-r") == 0){
        firstRow = atoi(argv[6]);
    }
    
    if (strcmp(argv[7], "-c") == 0){
        firstColumn = atoi(argv[8]);
    }
    
    
    if (strcmp(argv[9], "-v") == 0){
        pointoFView = atoi(argv[10]);
    }
    ifstream inputFile;
    
    inputFile.open("floorplan.txt");
    
    //check file is present or not
    if (!inputFile){
        cout << "File not found" << endl;
    }
    simulate_roomba(floorplan, *&nArray, r, c, pc, pr);
    print(*&nArray, r, c, pc, pr);
    return 0;
}
