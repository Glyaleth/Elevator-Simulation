#include <queue>
#include "Building.h"
#include "Passenger.h"



#pragma once
class Elevator
{
public:

	//-------------------Variables------------------
	enum direction { up, down, idle };	// Direction.Up represents 0, Direction.down represents 1. direction.idle represents 2.
	std::queue<Passenger> elev;		// Queue of passengers entering the elevator.
	int current_floor;				// Current floor of elevator in relation to 
	bool emergency_button = false;
	int elevator_number;			// Consider use as elevator ID.



									//--------------Constructors--------------------
	Elevator(int e_num);
	Elevator(int ID, int _cur_floor) {  //Constructor accepts 2 values, elevator ID, and starting floor to assign to our current floor for initialization
		elevator_number = ID;
		current_floor = _cur_floor;
	}
	~Elevator();


	//-------------Functions------------------------
	void setCurrentFloor(int floor_num) { // Setter for our current floor
		current_floor = floor_num;
	}

	void prioritizePassengers() {  //Will be used to prioritize passengers in our queue, elev.\
								   								    Should swap users in place determined by their destination, and distance from destination

	}

	void moveElevator() {		  //Will move up or down depending on the first passenger in the queue, elev. 

	}

};
