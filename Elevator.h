#include <queue>
#include <vector>
#include "Building.h"
#include "Passenger.h"



#pragma once
class Elevator
{
public:

	//-------------------Variables------------------
	enum direction { down, up, idle };	// Direction.Up represents 0, Direction.down represents 1. direction.idle represents 2.
	direction dir;
	std::vector<Passenger> elev_passengers;		// Queue of passengers entering the elevator.
	int current_floor;				// Current floor of elevator in relation to 
	bool emergency_button = false;
	int elevator_number;			// Consider use as elevator ID.



	//--------------Constructors--------------------
	Elevator(int e_num);
	Elevator(int ID, int _cur_floor) {  //Constructor accepts 2 values, elevator ID, and starting floor to assign to our current floor for initialization
		
		elevator_number = ID;
		current_floor = _cur_floor;
		dir = direction.idle;
		elev_passengers.resize(10);

	}


	//-------------Functions------------------------
	void setCurrentFloor(int floor_num) { // Setter for our current floor
		current_floor = floor_num;
	}
	int getCurrentFloor() {
		return current_floor;
	}

	bool still_exiting() {
		for (int i = 0; i < elev_passengers.size(); i++) {
			if (elev_passengers[i].getDestion() == current_floor)
				return true;
		}
		return false;
	}


	Passenger exit() {
		dir = direction.idle();
		for (int i = 0; i < x.size()); i++){
			if (x[i].getDestination() == current_floor) {
				Passenger help = x[i];
				x.pop(i);
				return help;
			}
		}
	}
	void load(Passenger passe) {
		elev_passengers.push_back(passe);
		dir = direction.idle;
	}

	
			
	

};
