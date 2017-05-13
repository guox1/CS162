/******************************************************
** Program: main.cpp
** Author: Jacky
** Date: 05/20/2015
** Description:
** Input:
** Output:
******************************************************/

#include <iostream>
#include <fstream>
#include "./Room.h"
#include "./RandomRoomba.h"
#include "./Roomba.h"
using namespace std;

void simulate_roomba();

string choose_roomba()
{
	string input;
	bool loop = true;
	while (loop == true)
	{
		cout << "Which Roomba (1 - Random, 2 - clockwise) ? " << endl;
		cin >> input;

		if (input == "1")
		{
			
			loop = false;
		}
		else if (input == "2")
		{

			loop = false;
		}

		else
		{
			cout << "Not a valid choice. Try Again. " << endl;
		}

	}
	return input;
}

string simulate_room(string User_File, vector<char> typeFloor, Floor &floor_layout)
{
	

	ifstream inputFile(User_File.c_str());
	string choice;//which roomba
    inputFile.get();
    inputFile.open("floorplan.txt");

	int counter = 0;
	int SizeRow = floor_layout.get_boardSizeRow(); //get max row size 

	RandomRoomba r;
	

	while (inputFile.good())
	{
	char ch;
	inputFile >> ch;
	typeFloor.push_back(ch);
	}
	for (int i = 0; i < typeFloor.size(); i++)
	{
		if (counter == (SizeRow/2) + 1)
		{
			cout << endl;
			counter = 0;
		}
		counter++;
		if (i+1 < typeFloor.size())
		{
			cout << typeFloor[i] << " ";
		}

	}
	
	cout << endl;
	choice = choose_roomba();
	//r.clean_room();

	inputFile.close();
	return choice;
}

/**********************************************************************
** Description: Read Item list to find # of rows and columns
** Parameters: filename: file to read
** Pre-conditions: None
** Post-conditions: return number of rows and columns
*********************************************************************/
void find_file_size(string User_File, Floor &floor_layout)
{
	ifstream inputFile(User_File.c_str());
	int boardSizeRow, boardSizeCol;
	string line;
	boardSizeRow = boardSizeCol = 0;
	inputFile.get();


	inputFile.open("floorplan.txt");
	if (inputFile)
	{

		//Counts Size of Column
		while (getline(inputFile, line))
		{
			boardSizeCol++;
		}

		cout << "Size of Columns : " << boardSizeCol << endl;

		//Counts Size of Row (Will be double due to spaces)
		getline(inputFile, line);
		boardSizeRow = line.size();
		cout << "Size of Rows : " << (boardSizeRow/2) + 1 << endl;
		
	}
	else
	{
		cout << "No File loaded." << endl;
		
	}

	floor_layout.set_boardSizeRow(boardSizeRow);
	floor_layout.set_boardSizeCol(boardSizeCol);
	
	//cout << floor_layout.get_boardSizeRow();
	//cout << floor_layout.get_boardSizeCol();
	//system("pause");



}

/**********************************************************************
** Description: Check if there is a file
** Parameters: filename: file to read
** Pre-conditions: None
** Post-conditions: True False
*********************************************************************/
void find_file(string file_name, bool &loaded)
{
	ifstream inputFile(file_name.c_str());
	inputFile.get();
	inputFile.open("floorplan.txt");
	if (inputFile)
	{
		cout << "File loaded." << endl;


		loaded = true;//used to check if file was a success
	}
	else
	{
		cout << "No File loaded!" << endl;
		loaded = false;
	}




}

int main(int argc, char *argv[])
{
	int User_Battery_Int, User_Moves_Int, User_Row_Int, User_Column_Int;
    string User_File, Input;
	bool looping;
    
    if (strcmp(argv[1] ,"-f")==0){
        User_File = atoi(argv[2]);
    }
    
    if (strcmp(argv[3], "-b") == 0){
        User_Battery_Int = atoi(argv[4]);
    }
    
    if (strcmp(argv[5], "-r") == 0){
        User_Row_Int = atoi(argv[6]);
    }
    
    if (strcmp(argv[7], "-c") == 0){
        User_Column_Int = atoi(argv[8]);
    }
    
    
    if (strcmp(argv[9], "-v") == 0){
        User_Moves_Int = atoi(argv[10]);
    }
    
    
	Floor floor_layout;
	vector<char> typeFloor;

	ifstream inputFile;
    cout << User_File << User_Battery_Int << endl;

	find_file(User_File, looping);

	if (looping == true)
	{
		find_file_size(User_File, floor_layout);
        simulate_room(User_File, typeFloor,floor_layout);

		Input = simulate_room(User_File, typeFloor, floor_layout);
		if (Input == "1") //random roomba
		{
			RandomRoomba Robot;
			Robot.set_battery(User_Battery_Int);
			Robot.set_moves(User_Moves_Int);
		}
		else //clockwise roomba
		{
			Roomba Robot;
		}

			//Roomba r2;
			//r.set_roomba(r2);
		
	}
	


	return 0;
}


