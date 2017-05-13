#ifndef ROOM_H
#define ROOM_H
#include "floor.h"
#include "roomba.h"
#include <iostream>
using namespace std;
template <typename T>
class Room
{
private:
    Floor f;
    T *obj; 
public:

    void view_room();
    void clean_room();
    void set_roomba(Roomba *r);
    T get_T();
    Floor get_floor();
    void set_floor(Floor floor);
};


template <typename T>
void Room<T>::clean_room() {

    if(obj!=NULL)
    {
       obj->clean_floor(f);
    }

}

template <typename T>
void Room<T>::set_roomba(Roomba *r)
{
    this->obj = r;
}

template <typename T>
void Room<T>::view_room()
{
    f.print_floor();
}

template <typename T>
Floor Room<T>::get_floor()
{
    return f;
}

template <typename T>
void Room<T>::set_floor(Floor floor)
{
    f = floor;
}

template <typename T>
T Room<T>::get_T()
{
    return *obj;
}

#endif // ROOM_H
