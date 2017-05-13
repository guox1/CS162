#include "smartroomba2.h"
#include <iostream>
using namespace std;
SmartRoomba2::SmartRoomba2()
{

}

SmartRoomba2::~SmartRoomba2()
{

}


SmartRoomba2::SmartRoomba2(int battery, int total_moves)
{
    this->set_batterry(battery);
    this->set_total_moves(total_moves);
}


bool SmartRoomba2::need_charge()
{
    if(get_total_moves()>=get_battery())
        return true;
    return false;
}

void SmartRoomba2::clean_floor(Floor f)
{
    int v_row = f.get_v().size();
    int v_col = f.get_v()[0].size();
    if(f.get_obj_row()<(v_row/2)&&f.get_obj_col()<(v_col/2))
    {
        from_left_top(f);
    }
    if(f.get_obj_row()<(v_row/2)&&f.get_obj_col()>=(v_col/2))
    {
        from_right_top(f);
    }
    if(f.get_obj_row()>=(v_row/2)&&f.get_obj_col()<(v_col/2))
    {
        from_left_bottom(f);
    }
    if(f.get_obj_row()>=(v_row/2)&&f.get_obj_col()>=(v_col/2))
    {
        from_right_bottom(f);
    }
}

void SmartRoomba2::from_left_top(Floor f)
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
                return;
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
void SmartRoomba2::from_left_bottom(Floor f)
{
    int v_row = f.get_v().size();
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
    while(f.get_obj_row()<v_row-1){
        cout<<"move down! total moves:" << get_total_moves()+1<<endl;
        move_down(f);
        set_total_moves(get_total_moves()+1);
        if(need_charge())
        {
            cout<<"Roomba need charge!"<<endl;
            return;
        }
    }

    int index = f.get_v().size()-1;
    while(index>0)
    {
        if(all_clean(f))
            return;
        while(f.get_obj_col()<f.get_v()[index].size()-1)
        {
            cout<<"move right! total moves:" << get_total_moves()+1<<endl;
            move_right(f);
            set_total_moves(get_total_moves()+1);
            if(all_clean(f)){
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }
            if(f.get_obj_row()==0&&
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
        if(f.get_obj_row()>0)
        {
            cout<<"move up! total moves:" << get_total_moves()+1<<endl;
            move_up(f);
            set_total_moves(get_total_moves()+1);
            index--;
            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
                return;
            }
        }
        while(f.get_obj_col()>0)//<f.get_v()[index].size()-1)
        {
            cout<<"move left! total moves:" << get_total_moves()+1<<endl;
            move_left(f);
            set_total_moves(get_total_moves()+1);
            if(all_clean(f)){
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }
            if(f.get_obj_row()==0&&
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
        if(f.get_obj_row()>0)
        {
            cout<<"move up! total moves:" << get_total_moves()+1<<endl;
            move_up(f);
            set_total_moves(get_total_moves()+1);
            index--;
            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
                return;
            }
        }
    }

}
void SmartRoomba2::from_right_top(Floor f)
{
    int v_col = f.get_v()[0].size();
    while(f.get_obj_col()<v_col-1){
        cout<<"move left! total moves:" << get_total_moves()+1<<endl;
        move_right(f);
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
            return;
        while(f.get_obj_col()>0)//<f.get_v()[index].size()-1)
        {
            cout<<"move left! total moves:" << get_total_moves()+1<<endl;
            move_left(f);
            set_total_moves(get_total_moves()+1);
            if(all_clean(f)){
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }
            if(f.get_obj_row()==f.get_v().size()-1&&
                    f.get_obj_col()==0)//f.get_v()[index].size()-1)
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
        while(f.get_obj_col()<f.get_v()[index].size()-1)//>0)
        {
            cout<<"move right! total moves:" << get_total_moves()+1<<endl;
            move_right(f);
            set_total_moves(get_total_moves()+1);
            if(all_clean(f)){
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }
            if(f.get_obj_row()==f.get_v().size()-1&&
                    f.get_obj_col()==f.get_v()[index].size())
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
void SmartRoomba2::from_right_bottom(Floor f)
{
    int v_row = f.get_v().size();
    int v_col = f.get_v()[0].size();
    while(f.get_obj_col()<v_col-1){
        cout<<"move left! total moves:" << get_total_moves()+1<<endl;
        move_right(f);
        set_total_moves(get_total_moves()+1);
        if(need_charge())
        {
            cout<<"Roomba need charge!"<<endl;
            return;
        }
    }
    while(f.get_obj_row()<v_row-1){
        cout<<"move left! total moves:" << get_total_moves()+1<<endl;
        move_down(f);
        set_total_moves(get_total_moves()+1);
        if(need_charge())
        {
            cout<<"Roomba need charge!"<<endl;
            return;
        }
    }

    int index = f.get_v().size()-1;
    while(index>0)
    {
        if(all_clean(f))
            return;
        while(f.get_obj_col()>0)//f.get_v()[index].size()-1)
        {
            cout<<"move left! total moves:" << get_total_moves()+1<<endl;
            move_left(f);
            set_total_moves(get_total_moves()+1);
            if(all_clean(f)){
                 cout<<"Entire floor visited and cleaned in "<<get_total_moves()<<" moves!!!"<<endl;
                return;
            }
            if(f.get_obj_row()==0&&
                    f.get_obj_col()==0)//f.get_v()[index].size()-1)
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
        if(f.get_obj_row()>0)
        {
            cout<<"move up! total moves:" << get_total_moves()+1<<endl;
            move_up(f);
            set_total_moves(get_total_moves()+1);
            index--;
            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
                return;
            }
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
            if(f.get_obj_row()==0&&
                    f.get_obj_col()==f.get_v()[0].size()-1)
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
        if(f.get_obj_row()>0)
        {
            cout<<"move up! total moves:" << get_total_moves()+1<<endl;
            move_up(f);
            set_total_moves(get_total_moves()+1);
            index--;
            if(need_charge())
            {
                cout<<"Roomba need charge!"<<endl;
                return;
            }
        }
    }
}
