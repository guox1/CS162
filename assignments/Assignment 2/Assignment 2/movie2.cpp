#include "movie.h"

using namespace std;
/**********************************************************************
** Description: Construct string from Item
** Parameters: dx_<field>: width of field to print
** Pre-conditions: None
** Post-conditions: Item is not mutated
*********************************************************************/

string Item::to_string() const
{
	stringstream accum;

	accum << "Movie: " << name << "|"
		<< " Cast: " << cast << "|"
		<< " Stars: " << stars << "|"
		<< " Rating: " << rating << "|"
		<< "Quantity: " << qty << "|";
		//<< setw(dx_subtotal) << price * qty;

	string str;
	getline(accum, str);

	return str;
}

/**********************************************************************
** Description: Construct tab-delimited string from Item
** Parameters: None
** Pre-conditions: None
** Post-conditions: Item is not mutated
*********************************************************************/
string Item::to_tabbed_string() const
{
	stringstream accum;

	accum << "Movie: " << name << "|" 
		<< " Cast: " << cast << "|"
		<< " Stars: " << stars << "|" 
		<< " Rating: " << rating << "|"
		<< "Quantity: " << qty << "|";

	string str;
	getline(accum, str);

	return str;
}

/**********************************************************************
** Description: Setter for name
** Parameters: name: the new name
** Pre-conditions: None
** Post-conditions: Item.name is mutated
*********************************************************************/
void Item::set_name(string name)
{
	this->name = name;
}

/**********************************************************************
** Description: Setter for unit
** Parameters: stars: the new unit
** Pre-conditions: None
** Post-conditions: Item.cast is mutated
*********************************************************************/
void Item::set_cast(string cast)
{
	this->cast = cast;
}

/**********************************************************************
** Description: Setter for stars
** Parameters: stars: the new stars
** Pre-conditions: None
** Post-conditions: Item.stars is mutated
*********************************************************************/
void Item::set_stars(int stars)
{
	this->stars = stars;
}

/**********************************************************************
** Description: Setter for rating
** Parameters: qty: the new quantity
** Pre-conditions: None
** Post-conditions: Item.rating is mutated
*********************************************************************/
void Item::set_rating(int rating)
{
	this->rating = rating;
}

/**********************************************************************
** Description: Setter for qty
** Parameters: qty: the new quantity
** Pre-conditions: None
** Post-conditions: Item.qty is mutated
*********************************************************************/
void Item::set_qty(int qty)
{
	this->qty = qty;
}


/**********************************************************************
** Description: Parametized constructor for Item
** Parameters: <var_name> -> Item.<var_name>
** Pre-conditions: None
** Post-conditions: A new Item is returned
*********************************************************************/
Item::Item(string name, string cast, int stars, int rating, int qty)
{
	this->name = name;
	this->cast = cast;
	this->stars = stars;
	this->rating = rating;
	this->qty = qty;
}

/**********************************************************************
** Description: Constructor for Item from tab-delimited string
** Parameters: arg_string: tab-delimited string
** Pre-conditions: None
** Post-conditions: A new Item is returned
*********************************************************************/
Item::Item(std::string arg_string)
{
	stringstream ss;
	ss << arg_string;

	string tmp;

	getline(ss, tmp, '\t');
	name = tmp;

	getline(ss, tmp, '\t');
	cast = tmp;

	getline(ss, tmp, '\t');
	stars = std::atof(tmp.c_str());

	getline(ss, tmp, '\t');
	rating = std::atof(tmp.c_str());

	getline(ss, tmp, '\t');
	qty = atof(tmp.c_str());
}
