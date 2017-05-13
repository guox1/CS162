//
//  movie.cpp
//  CS162 Assignment2
//
//  Created by Jacky on 4/23/15.
//  Copyright (c) 2015. All rights reserved.
//

#include "movie.h"
#include "Netflix.h"
#include <iostream>
#include <cstdlib>
#include <string>


Netflix::Netflix(){
    movie = NULL;
    num_movie = 0;
}

Netflix::Netflix(int a){
    num_movie = a;
    movie = new class movie[a];
}

Netflix::~Netflix(){
    delete [] movie;
    movie = NULL;
}

void Netflix::set_movie(class movie* Newmovie){
    movie = Newmovie;
}

void Netflix::set_movie_at(class movie Newmovie, int i){
    movie[i] = Newmovie;
}

class movie* Netflix::get_movie(){
    return movie;
}

class movie Netflix::get_movie_at(int i){
    return movie[i];
}

int Netflix::get_num(){
    return num_movie;
}