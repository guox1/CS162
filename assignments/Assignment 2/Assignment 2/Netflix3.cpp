#include"Header.h"
#include "Netflix.h"

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