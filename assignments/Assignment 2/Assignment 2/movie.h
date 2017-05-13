#ifndef movie_h
#define movie_h

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h> // atoi
#include <stdio.h> // printf, fgets
#include <cstring> //strcmp string compare

using namespace std;

class movie {
public:
    movie();
    movie(int);//constructer
    ~movie();//destructer
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
    string *cast; //This is a dynamic array of strings
    string rating;
    int copies;
    int rented;
};
