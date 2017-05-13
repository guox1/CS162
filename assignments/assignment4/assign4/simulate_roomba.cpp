#include <iostream>
#include <vector>
#include "room.hpp"
#include "roomba.h"
#include "randomroomba.h"
#include "cmdline.h"
#include "smartroomba1.h"
#include "smartroomba2.h"
using namespace std;

static string filename;
static int battery;
static int moves;
static int startingrow;
static int startingcol;


void choose_roomba(Room <Roomba> &r) {
    int choice;
    std::cout << "Which Roomba (1 – Random, 2 - SmartRoomba1, 3 - SmartRoomba2)? "<<std::endl;
    cin >> choice;
    if(choice == 1)
        r.set_roomba(new RandomRoomba(battery,moves));
    else if(choice ==2)
    {
        r.set_roomba(new SmartRoomba1(battery,moves));
    }
    else if(choice ==3)
    {
        r.set_roomba(new SmartRoomba2(battery,moves));
    }
}

void simulate_roomba() {
    Room <Roomba> r;
    choose_roomba(r);

    Floor f;
    f.setup_floor(filename,startingrow,startingcol);
    r.set_floor(f);
    r.clean_room(); 
}


int main(int argc,char* argv[])
{
    cmdline::parser a;
    a.add<string>("file",'f',"file name",true,"");
    a.add<int>("battery",'b',"battery",true,0,cmdline::range(0, 65535));

    a.add<int>("moves",'m',"moves before viewing",false,-1, cmdline::range(0, 65535));
    a.add<int>("row",'r',"starting row",false,-1, cmdline::range(0, 65535));
    a.add<int>("col",'c',"starting col",false, -1, cmdline::range(0, 65535));
    a.parse_check(argc, argv);

    filename = a.get<string>("file");
    battery =   a.get<int>("battery");
    moves =  a.get<int>("moves");
    startingrow =  a.get<int>("row");
    startingcol = a.get<int>("col");
    simulate_roomba();
    return 0;
}
