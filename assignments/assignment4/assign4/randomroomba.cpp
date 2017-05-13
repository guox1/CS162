#include "randomroomba.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
RandomRoomba::RandomRoomba()
{

}

RandomRoomba::~RandomRoomba()
{

}
RandomRoomba::RandomRoomba(int battery,int total_moves)
{
    this->set_batterry(battery);
    this->set_total_moves(total_moves);
}

void RandomRoomba::clean_floor(Floor f)
{
    std::cout<<"begin clean floor!"<<std::endl;
    srand((unsigned)time(NULL));
    while(get_total_moves()<get_battery())
    {
        int c = 1+rand()%4;// ramdom 1 - 4

        if(!can_move(f,c))
        {
            continue;
        }
        switch (c) {
        case 1:
            cout<<"move left! total moves:" << get_total_moves()+1<<endl;
            move_left(f);
            break;
        case 2:
            cout<<"move right! total moves:" << get_total_moves()+1<<endl;
            move_right(f);
            break;
        case 3:
            cout<<"move up! total moves:"<< get_total_moves()+1<<endl;
            move_up(f);
            break;
        case 4:
            cout<<"move down! total moves:"<< get_total_moves()+1<<endl;
            move_down(f);
            break;
        default:
            break;
        }
        set_total_moves(get_total_moves()+1);
        if(all_clean(f))
        {
            cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
            return;
        }
    }
    cout<<"battery need charge!"<<endl;
}

bool RandomRoomba::can_move(Floor f,int c)
{

    bool b;
    switch (c) {
    case 1:
        b = f.is_obj_out(f.get_obj_row(),f.get_obj_col()-1);
        if(!b)
            return false;
        if(f.get_vector_char(f.get_obj_row(),f.get_obj_col()+1)=='f')
            return true;
        break;
    case 2:
        b = f.is_obj_out(f.get_obj_row(),f.get_obj_col()+1);
        if(!b)
            return false;
        if(f.get_vector_char(f.get_obj_row(),f.get_obj_col()-1)=='f')
            return true;
        break;
    case 3:
        b = f.is_obj_out(f.get_obj_row()-1,f.get_obj_col());
        if(!b)
            return false;
        if(f.get_vector_char(f.get_obj_row()-1,f.get_obj_col())=='f')
            return true;
        break;
    case 4:
        b =f.is_obj_out(f.get_obj_row()+1,f.get_obj_col());
        if(!b)
            return false;
        if(f.get_vector_char(f.get_obj_row()+1,f.get_obj_col())=='f')
            return true;
        break;
    default:
        break;
    }
    return true;
}
