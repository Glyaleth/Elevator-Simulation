#pragma once
#include <queue>
#include "Passenger.h"
#include <vector>
using namespace std;

class Elevator {
public:
	vector <Passenger> elev_passengers; // vector of passengers in the elevator
	int current_floor;		// Current floor of elevator 
	int elevator_number;	// elevator ID
	bool idle;			//Elevator ID to keep track of which elevator is being acted on

	Elevator(); //Default Constructor
	Elevator(int ID); //creates elevator according to given I
	Elevator(int ID); //creates elevator according to given ID
	vector <Passenger> getElevPass();
	int getCurrentFloor();
	int getElevatorNumber();
	bool getIdle();
	void setCurrentFloor(int f);
	void setElevatorNumber(int n);
	void setIdle(bool i);

	bool still_exiting(); //checks if a passenger is still leaving elevator
	Passenger exit(); //takes out passenger and is used within unloading_passenger of Building.cpp to add to Exitor stack 
	void load(Passenger passe); //loads a passenger into the elevator 
};
