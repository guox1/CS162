#include "roomba.h"
#include <iostream>
using namespace std;

Roomba::Roomba()
{

}

Roomba::~Roomba()
{

}

void Roomba::clean_floor(Floor f)
{
    cout<<"Roomba::clean_floor"<<endl;
}
void Roomba::set_batterry(int btry)
{
    this->battery = btry;
}

void Roomba::set_total_moves(int stm)
{
    this->total_moves = stm;
}

void Roomba::move_left(Floor &f)
{
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'c');
    f.set_obj_col(f.get_obj_col()-1);
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'r');
    f.print_floor();
}
void Roomba::move_right(Floor &f)
{
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'c');
    f.set_obj_col(f.get_obj_col()+1);
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'r');
    f.print_floor();
}
void Roomba::move_up(Floor &f)
{
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'c');
    f.set_obj_row(f.get_obj_row()-1);
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'r');
    f.print_floor();
}
void Roomba::move_down(Floor &f)
{
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'c');
    f.set_obj_row(f.get_obj_row()+1);
    f.set_vector_char(f.get_obj_row(),f.get_obj_col(),'r');
    f.print_floor();
}

bool Roomba::all_clean(Floor f)
{
    for(int i =0;i < f.get_v().size();i++)
    {
        for(int j=0;j<f.get_v().size();j++)
        {
            if(f.get_vector_char(i,j)=='f')
                return false;
        }
    }
    return true;
}

