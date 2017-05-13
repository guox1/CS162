#ifndef SMARTROOMBA2_H
#define SMARTROOMBA2_H
#include"roomba.h"

class SmartRoomba2 : public Roomba
{
public:
    SmartRoomba2();
    ~SmartRoomba2();
    SmartRoomba2(int ,int);
    void clean_floor(Floor f);
    bool need_charge();
    void from_left_top(Floor f);
    void from_left_bottom(Floor f);
    void from_right_top(Floor f);
    void from_right_bottom(Floor f);

};

#endif // SMARTROOMBA2_H
