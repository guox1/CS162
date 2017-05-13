#ifndef ROOMBA_H
#define ROOMBA_H
#include "floor.h"
class Roomba
{
private:
    int battery;      
    int total_moves;  
public:
    Roomba();
    ~Roomba();
    virtual void clean_floor(Floor f);
    void set_batterry(int btry);
    void set_total_moves(int stm);
    int get_battery(){return this->battery;}
    int get_total_moves(){return this->total_moves;}
public:

    void move_left(Floor &f);
    void move_right(Floor &f);
    void move_up(Floor &f);
    void move_down(Floor &f);
    bool all_clean(Floor f);
};

#endif // ROOMBA_H
