#ifndef SMARTROOMBA1_H
#define SMARTROOMBA1_H
#include"roomba.h"
using namespace std;
class SmartRoomba1 : public Roomba
{
public:
    SmartRoomba1();
    ~SmartRoomba1();
    SmartRoomba1(int battery,int total_moves);
    void clean_floor(Floor f);
    bool need_charge();
};

#endif // SMARTROOMBA1_H
