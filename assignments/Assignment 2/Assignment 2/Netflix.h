#ifndef Netflix_h
#define Netflix_h

#include "movie.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h> // atoi
#include <stdio.h> // printf, fgets
#include <cstring> //strcmp string compare

using namespace std;

class Netflix {
public:
    Netflix();
    Netflix(int);
    ~Netflix();
    void set_movie(class movie*);
    void set_movie_at(class movie, int);
    class movie1* get_movie();
    class movie1 get_movie_at(int);
    int get_num();
private:
    movie1 *movie; //This is a dynamic array of movies
    int num_movies;
};

