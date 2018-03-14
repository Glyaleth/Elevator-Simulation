#pragma once


#include <queue>
#include "Building.h"
#include "Passenger.h"
#include <vector>

using namespace std;

class Elevator{

public: 
	vector <Passenger> elev_passengers; // vector of passengers entering the elevator.
	int current_floor;				// Current floor of elevator in relation to 
	bool emergency_button = false;
	int elevator_number;			// Consider use as elevator ID.
	bool idel;


	//--------------Constructor--------------------
	Elevator(); //Default Constructor
	Elevator(int ID);

	
	//-------------Getters / Setters------------------------

	int getCurrentFloor();
	bool getEmergency_Button();
	int getElevatorNumber();
	vector <Passenger> getElevPass();
	bool getIdel();
	void setCurrentFloor(int f);
	void setEmergency_Button(bool e);
	void setElevatorNumber(int n);
	void setIdel(bool i);

	//-------------Functions------------------------

	bool still_exiting();
	Passenger exit();
	void load(Passenger passe);





};
