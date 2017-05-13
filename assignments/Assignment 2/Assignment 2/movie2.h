#ifndef ITEMS_H
#define ITEMS_H

#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h> // atoi 
#include <stdio.h> // printf, fgets 
#include <iostream> //cout cin
#include <cstring> //strcmp string compare
using namespace std;

class Item
{
private:
	string name;
	string cast;
	int stars;
	int rating;
	int qty;

public:
	/* standard accessors */
	string get_name() const { return name; }
	string get_cast() const { return cast; }
	int get_stars() const { return stars; }
	int get_rating() const { return rating; }
	int get_qty() const { return qty; }
	//double get_subtotal() const { return qty * price; }

	string to_string() const;

	string to_tabbed_string() const;
	
	/* standard mutators */
	void set_name(string name);
	void set_cast(string cast);
	void set_stars(int stars);
	void set_rating(int rating);
	void set_qty(int qty);

	/* constructors */
	Item(string name, string cast,int stars, int rating, int qty);
	Item(string arg_string);
};

#endif