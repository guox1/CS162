#include "movie.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

void read_from_file(string filename, vector<Item> &list);
void write_to_file(string filename, const vector<Item> &list);
void print_list(const vector<Item> &list);
void wait_for_user();
void add_item(vector<Item> &list);
void remove_item(vector<Item> &list);

/*********************************************************************
** Function:is_valid_int
** Description:checks if str input is between 1-9
** Parameters:
** Pre-Conditions:string
** Post-Conditions: True/false
*********************************************************************/
bool is_valid_int(string input)//checks if between 0 and 9
{

	for (int i = 0; i < input.length(); i++)
		if (input[i] < '1' || input[i] > '9')
		{
			return false;
		}


	return true;
}

/*********************************************************************
** Function:retry
** Description:Gets a new string from user
** Parameters:
** Pre-Conditions:
** Post-Conditions: string
*********************************************************************/
string retry()
{
	string input;
	cout << "Please enter a valid integer: (1-9 only)";
	cin >> input;

	return input;
}
/*********************************************************************
** Function:check_input
** Description:checks input and converts to int
** Parameters:
** Pre-Conditions:string
** Post-Conditions: int
*********************************************************************/
int check_int(string input)
{
	bool checkrow;
	int new_input;

	checkrow = is_valid_int(input);

	while (checkrow == false)//checks if valid int
	{
		//cout << "Enter a valid Input. " << endl;
		//cout << "checked row: " << checkrow << endl;
		input = retry();
		checkrow = is_valid_int(input);
	}

	new_input = atoi(input.c_str());//converts string to int
	cout << endl;

	return new_input;//returns the string as int
}
int main()
{
	vector<Item> items;
	string input;
	int counter;
	bool looping = true;
	read_from_file("movie.txt", items);//reads from current file

	while (looping) 
	{
		cout << endl
			<< "Input List" << endl
			<< "==========" << endl
			<< endl
			<< "(v)iew the list" << endl
			<< "(a)dd an item to the list" << endl
			<< "(r)emove an item from the list" << endl
			<< "(q)uit" << endl
			<< endl
			<< "What would you like to do? (v, a, r, q): ";

		getline(cin, input);

		switch (input.c_str()[0]) 
		{
		case 'v':
			cout << endl;
			print_list(items);
			wait_for_user();
			break;
		case 'a':
			cout << "How many movies titles are you putting in?";
			getline(cin, input);
			counter = check_int(input);
			while (counter > 0)
			{
				add_item(items);
				wait_for_user();
				counter--;
			}

			break;
		case 'r':
			remove_item(items);
			wait_for_user();
			break;
		case 'q':
			looping = false;

		}
		cout << string(50, '\n');
	}

	write_to_file("movie.txt", items);
	return 0;
}

/**********************************************************************
** Description: Read tab-delimited Item list from file into vector
** Parameters: filename: file to read
**             list: vector to load data into
** Pre-conditions: None
** Post-conditions: list is mutated.
*********************************************************************/
void read_from_file(string filename, vector<Item> &list)
{
	ifstream file(filename.c_str());

	if (file) {
		string line;
		while (getline(file, line)) {
			list.push_back(Item(line));
		}

		file.close();
		cout << "File loaded." << endl;
	}
	else {
		cout << "No File loaded." << endl;
	}
}

/**********************************************************************
** Description: Write Item list to file.
** Parameters: filename: file to write
**             list: Item vector to read from
** Pre-conditions: None.
** Post-conditions: list is not mutated.
*********************************************************************/
void write_to_file(string filename, const vector<Item> &list)
{
	ofstream file(filename.c_str());

	if (file) {
		for (auto i = list.begin(); i != list.end(); ++i) {
			file << i->to_tabbed_string() << endl;
		}

		file.close();
		cout << "File saved." << endl;
	}
	else {
		cout << "Nothing happens." << endl;
	}
}

/**********************************************************************
** Description: Print Item vector to screen
** Parameters: list: Item vector to print
** Pre-conditions: None
** Post-conditions: list is not mutated
*********************************************************************/
void print_list(const vector<Item> &list)
{
	/*cout << "Name: " << endl;
	cout << "Cast: " << endl;
	cout << "Rating: "  << endl;
	cout << "Stars: " << endl;
	cout << "Copies: " << endl;*/

	size_t count = 1;
	double total = 0;

	for (auto item = list.begin(); item != list.end(); ++item) {
		cout << setw(4) << right << count++ << ") ";
		cout << item->to_string() << endl;
		//total += item->get_subtotal();
	}

}

/**********************************************************************
** Description: Pause to let user see output
** Parameters: None
** Pre-conditions: None
** Post-conditions: None
*********************************************************************/
void wait_for_user()
{
	cout << "(press ENTER to continue)";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**********************************************************************
** Description: Construct Item from user input and add to vector
** Parameters: list: Item vector
** Pre-conditions: None
** Post-conditions: list is mutated
*********************************************************************/
void add_item(vector<Item> &list)
{
	int counter;
	string input, name, cast;
	int stars, rating, qty;

	//////////////////////str
	cout << "movie name: ";
	getline(cin, name);
	//////////////////////str
	cout << "# of Cast(Int): ";
	getline(cin, input);
	counter = check_int(input);

	while (counter > 0)
	{
		cout << "Cast Member #"<< counter << "'s name" <<" : ";
		getline(cin, input);
		cast.append(input);
		cast.append(" ");
		counter--;
		cout << endl;
	}
	//////////////////////int

	cout << "# of Stars (Int): ";
	getline(cin, input);
	stars = check_int(input);

	cout << "Rating (Int): ";
	getline(cin, input);
	rating = check_int(input);

	cout << "# of copies (Int): ";
	getline(cin, input);
	qty = check_int(input);


	list.push_back(Item(name, cast, stars, rating, qty));
	cout << "Item added to list. ";
}

/**********************************************************************
** Description: Remove Item from vector
** Parameters: list: Item vector
** Pre-conditions: None
** Post-conditions: A valid subscript is erased, or nothing happens
*********************************************************************/
void remove_item(vector<Item> &list)
{
	string input;

	cout << endl;
	print_list(list);
	cout << endl
		<< "Which item do you want to remove?"
		<< " (enter a number, 0 to cancel) ";
	getline(cin, input);

	size_t pos = atoi(input.c_str());

	/*
	* if the list.size() == numeric_limits<size_t>::max(),
	* can't delete last item, but can still abort with 0
	*/
	if (pos <= list.size() && pos > 0) {
		/* compensate for 0-indexing */
		pos -= 1;
		list.erase(list.begin() + pos);
		cout << "Item removed. ";
	}
	else {
		cout << "Nothing happens." << endl;
	}
}