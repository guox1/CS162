
#ifndef lab10_Date_h
#define lab10_Date_h

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

class movie{
public:
    movie();
    movie(int);
    ~movie();
    void set_all_information(string Newname, int Newstars, string* Newcast, string Newrating, int Newcopies);
    void set_cast_num(int);
    void set_rented(int);
    string get_name();
    int get_stars();
    int get_num_cast();
    string at(int);
    string* get_cast();
    string get_rating();
    int get_copies();
    int get_rented();
private:
    string name;
    int stars;
    int num_cast;
    string* cast;
    string rating;
    int copies;
    int rented;
};

#endif



