#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "./Floor.h"
#include "./RandomRoomba.h"

using namespace std;

template <typename T>

class Room 
{
private:
	Floor f;
	T *obj; //obj could be a Roomba, Person, etc.
public:
	//The functionality of a room is to view it, put
	//objects in it, take objects out of it, etc.
		void clean_room() {
			if (obj != NULL)
				obj->clean_floor(f);
		}


		/*void set_roomba(Roomba rob)
		{
			obj = &rob;
		}*/
};
#endif