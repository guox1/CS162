
#include"Header.h"

movie::movie(){
    name = " ";
    stars = 0;
    num_cast = 0;
    cast = NULL;
    rating = " ";
    copies = 0;
    rented = 0;
}

movie::movie(int numcast){
    num_cast = numcast;
    cast = new string[num_cast];
    rented = 0;
}

movie::~movie(){
    delete [] cast;
    cast = NULL;
}

void movie::set_all_information(string Newname, int Newstars, string* Newcast, string Newrating, int Newcopies){
    name = Newname;
    stars = Newstars;
    cast = Newcast;
    rating = Newrating;
    copies = Newcopies;
}

void movie::set_cast_num(int a){
    num_cast = a;
    cast = new string[a];
    
}

void movie::set_rented(int a){
    rented = a;
}

int movie::get_rented(){
    return rented;
}

string* movie::get_cast(){
    return cast;
}

string movie::get_name(){
    return name;
}

int movie::get_stars(){
    return stars;
}

int movie::get_num_cast(){
    return num_cast;
}

string movie::at(int i){
    return cast[i-1];
}

string movie::get_rating(){
    return rating;
}

int movie::get_copies(){
    return copies;
}