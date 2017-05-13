#include "smartroomba1.h"
#include <iostream>

using namespace std;
SmartRoomba1::SmartRoomba1()
{

}

SmartRoomba1::~SmartRoomba1()
{

}

SmartRoomba1::SmartRoomba1(int battery, int total_moves)
{
    this->set_batterry(battery);
    this->set_total_moves(total_moves);
}


void SmartRoomba1::clean_floor(Floor f)
{
    while(f.get_obj_col()>0){
        cout<<"move left! total moves:" << get_total_moves()+1<<endl;
        move_left(f);
        set_total_moves(get_total_moves()+1);
        if(need_charge())
        {
            cout<<"Roomba need charge!"<<endl;
            return;
        }
    }
    while(f.get_obj_row()>0){
        cout<<"move left! total moves:" << get_total_moves()+1<<endl;
        move_up(f);
        set_total_moves(get_total_moves()+1);
        if(need_charge())
        {
            cout<<"Roomba need charge!"<<endl;
            return;
        }
    }

    int index = 0;
    while(index<f.get_v().size())
    {
        if(all_clean(f))
        {
            cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
            return;
        }
        while(f.get_obj_col()<f.get_v()[index].size()-1)
        {
            cout<<"move right! total moves:" << get_total_moves()+1<<endl;
            move_right(f);
            set_total_moves(get_total_moves()+1);
            if(all_clean(f)){
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }
            if(f.get_obj_row()==f.get_v().size()-1&&
                    f.get_obj_col()==f.get_v()[index].size()-1)
            {
                cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }

            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
                return;
            }

        }
        if(f.get_obj_row()<f.get_v().size()-1)
        {
            cout<<"move down! total moves:" << get_total_moves()+1<<endl;
            move_down(f);
            set_total_moves(get_total_moves()+1);
            index++;
            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
            }
        }
        while(f.get_obj_col()>0)
        {
            cout<<"move left! total moves:" << get_total_moves()+1<<endl;
            move_left(f);
            set_total_moves(get_total_moves()+1);
            if(all_clean(f)){
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }
            if(f.get_obj_row()==f.get_v().size()-1&&
                    f.get_obj_col()==0)
            {
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }

            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
                return;
            }
        }
        if(f.get_obj_row()<f.get_v().size()-1)
        {
            cout<<"move down! total moves:" << get_total_moves()+1<<endl;
            move_down(f);
            set_total_moves(get_total_moves()+1);
            index++;
            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
                return;
            }
        }
    }
}

bool SmartRoomba1::need_charge()
{
    if(get_total_moves()>=get_battery())
        return true;
    return false;
}

