#ifndef RANDOMROOMBA_H
#define RANDOMROOMBA_H
#include "roomba.h"
using namespace std;
class RandomRoomba : public Roomba
{
public:
    RandomRoomba();
    ~RandomRoomba();
    RandomRoomba(int battery,int total_moves);
    void clean_floor(Floor f);
    bool can_move(Floor f,int c);
};

#endif // RANDOMROOMBA_H
