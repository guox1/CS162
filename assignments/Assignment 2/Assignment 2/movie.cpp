//
//  movie.cpp
//  CS162 Assignment2
//
//  Created by Jacky on 4/23/15.
//  Copyright (c) 2015. All rights reserved.
//

#include "movie.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

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

string movie::at(int i){
    return cast[i-1];
}

int check_input(string input)
{
    int check = 1;
    for (int i = 0; i < input.length(); i++)
    {
        if(input[i] < '0' || input[i] > '9')
            check = 0;
    }
    return check;
}

/*********************************************************************
 ** Function: enter_a_movie
 ** Description: to ask the user how many movie they want to enter
 ** Parameters: no
 ** Pre-Conditions: main
 ** Post-Conditions:
 *********************************************************************/
int enter_movie()
{
    int movie_num, check;
    string input1;
    do
    {
        cout << "How many movies do you want to enter to the database?: ";
        cin >> input1;
        check = check_input(input1);
    cin >> movie_num;
    }while(check == 0);
    return movie_num;
}

/*********************************************************************
 ** Function: get_movie_name
 ** Description: to get the movie's name
 ** Parameters: no
 ** Pre-Conditions: get_movie_info
 ** Post-Conditions: get_movie_info
 *********************************************************************/
string movie::get_name()
{
    string name;
    cin.ignore();
    cout << "Enter the name of your movie: ";
    getline(cin, name);
    
    return name;
}

/*********************************************************************
 ** Function: get_movie_stars
 ** Description: to get movie's stars
 ** Parameters: no
 ** Pre-Conditions: get_movie_info
 ** Post-Conditions: get_movie_info
 *********************************************************************/
int movie::get_stars()
{
    int stars, check;
    string input2;
    do
    {
        cout << "How many stars? ";
        cin >> input2;
        check = check_input(input2);
    }while (check == 0);
    
    stringstream ss(input2);
    ss >> stars; // converting the string into int
    
    return stars;
}

/*********************************************************************
 ** Function: get_number_of_cast
 ** Description: ask the user how many cast does the movie has
 ** Parameters: no
 ** Pre-Conditions: get_movie_info
 ** Post-Conditions: get_movie_info
 *********************************************************************/
int movie::get_num_cast()
{
    int num_cast;
    string input3;
    int check;
    do
    {
        cout << "How many cast member? ";
        cin >> input3;
        check = check_input(input3);
    }while(check == 0);
    
    stringstream ss(input3);
    ss >> num_cast; // converting the string into int
    

    return num_cast;
}

/*********************************************************************
 ** Function: get_cast_member
 ** Description: input each cast member
 ** Parameters: int numcast
 ** Pre-Conditions: get_movie_info
 ** Post-Conditions: get_movie_info
 *********************************************************************/
string *movie::get_cast(int num_cast)
{
    string *cast;
    cast = new string[num_cast];
    cin.ignore();
    for (int i = 1; i <= num_cast; i++)
    {
        cout << "Enter cast member " << i << " : ";
        getline(cin, cast[i-1]);
    }
    return cast;
}

/*********************************************************************
 ** Function: get_movie_rating
 ** Description: input movie's rating
 ** Parameters: no
 ** Pre-Conditions: get_movie_info
 ** Post-Conditions: get_movie_info
 *********************************************************************/
string movie::get_rating()
{
    string rating;
    cout << "Enter the movie rating: ";
    cin >> rating;
    
    return rating;
}

/*********************************************************************
 ** Function: get_movie_copies
 ** Description: input how many copies the movie has
 ** Parameters: no
 ** Pre-Conditions: get_movie_info
 ** Post-Conditions: get_movie_info
 *********************************************************************/
int movie::get_copies()
{
    int copies, check;
    string input4;
    do
    {
        cout << "How many copies of this movie: ";
        cin >> copies;
        check = check_input(input4);
    }while(check == 0);
    stringstream ss(input4);
    ss >> copies;
    
    return copies;
}

/*********************************************************************
 ** Function: get_movie_info
 ** Description: to get the movie's information user entered
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void get_all_information(movie* m, int num, string Newname, int Newstars, string* Newcast, string Newrating, int Newcopies)
{
    /*int stars, num_cast, copies, rented;
    string name, rating;
    string cast;
    ifstream moive("newmovie.dat");*/
    int num_movie = enter_movie();
    for(int i=0; i< num_movie; i++){
    //    while (movie >> num >> name >> stars >>num_cast >>cast >> rating >> copies >>rented) {
      //      num = num+1;
        //}
        ofstream output;
        output.open("movie.dat", ios::app);
        output << num <<"|"<<m->get_name()<<"|"<<m->get_stars()<<"|"<<m->get_num_cast()<<"|";
     
        for(int i=0;i < m->get_num_cast();i++){
            output<<m->get_cast()[i]<<"|";
        }
        output<<m->get_rating()<<"|"<<m->get_copies()<<"|"<<m->get_rented();
        output.close();

       
        cout << "Added to the database!" << endl;
    }
}

void searchname()
{
    ifstream moive("newmovie.dat");
    int stars, num_cast, copies, rented, num;
    string name, rating, newname;
    string ccoutast;
    
    cout <<" name? "<<endl;
    cin>>newname;

    while (movie >> num >> name >> stars >>num_cast >>cast >> rating >> copies >>rented) {
        if (newname == name) {
            cout << " movie found"<<endl;
            cout << "Number: "<<num<<endl;
            cout <<" Title:"<<name <<endl;
            cout <<"Stars:"<<stars <<endl;
            cout <<"Cast Members: "
            }
        }
    }
}

