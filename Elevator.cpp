#pragma once
#include <queue>
#include "Passenger.h"
#include <vector>
using namespace std;

//Elevator class object
class Elevator {
public:
//private:
	vector <Passenger> elev_passengers; // Vector of passengers entering the elevator.
	int current_floor;				// Current floor of elevator in relation to 
	bool emergency_button = false;	// Emergency button, should stop the entire running program if pressed. (Currently unused)
	int elevator_number;			// Consider use as elevator ID.
	bool idel;						//Elevator ID to keep track of which elevator is being acted on.


//public:
	//--------------Constructor--------------------
	Elevator(); //Default Constructor
	Elevator(int ID);


	//-------------Getters / Setters------------------------

	int getCurrentFloor();
	bool getEmergency_Button();
	int getElevatorNumber();
	vector <Passenger> getElevPass();
	bool getIdle();
	void setCurrentFloor(int f);
	void setEmergency_Button(bool e);
	void setElevatorNumber(int n);
	void setIdel(bool i);

	//-------------Functions------------------------

	bool still_exiting();
	Passenger exit();
	void load(Passenger passe);

};
