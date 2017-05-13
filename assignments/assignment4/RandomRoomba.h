#ifndef RANDOMROOMBA_H
#define RANDOMROOMBA_H

#include "./Floor.h"
using namespace std;

class RandomRoomba 
{
private:
	int battery; //how many moves it can make
	int moves; //moves between each clean
public:
	//The Roomba needs to be able to clean a floor, and
	//move left, right, up, down
	void set_battery(int battery_input);
	int get_battery();

	void set_moves(int moves_input);
	int get_moves();
	/*void set_roomba(RandomRoomba r)
	{
		this->battery = r.battery;
		this->total_moves = r.total_moves;
	}*/

	void clean_room();


	void moveLeft();


	void moveRight();


	void moveUp();


	void moveDown();


	void clean_floor(Floor r);
};

void RandomRoomba::set_battery(int battery_input)
{
	battery = battery_input;
}
int RandomRoomba::get_battery()
{
	return battery;
}

void RandomRoomba::set_moves(int moves_input)
{
	moves = moves_input;
}
int RandomRoomba::get_moves()
{
	return moves;
}
#endif