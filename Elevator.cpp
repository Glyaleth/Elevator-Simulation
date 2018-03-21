#include "Elevator.h"
#include <iostream>
#include <vector>
using namespace std;

Elevator::Elevator()
{
	elevator_number = -1; 
	current_floor = 0;//all elevators start in ground floor
	vector <Passenger> elev_passengers; 
	idle = true;
}

Elevator::Elevator(int ID)
{
	elevator_number = ID;
	current_floor = 0;
	vector <Passenger> elev_passengers;
	idle = true;
}

int Elevator::getCurrentFloor()
{
	return current_floor;
}

int Elevator::getElevatorNumber()
{
	return elevator_number;
}

vector<Passenger> Elevator::getElevPass()
{
	return elev_passengers;
}

bool Elevator::getIdle()
{
	if (elev_passengers.empty() == false) {
		idle = false;
		return false; //if people in the elevator
	}
	else if (elev_passengers.empty() == true) {
		idle = true;
		return true; //if empty, it is idle
	}
}

void Elevator::setCurrentFloor(int f)
{
	int IDNum = this->elevator_number;
	if (f == -1) { //if floor didn't change, because no new requests 
		cout << "Elevator " << IDNum << " went nowhere\n";
	}

	else { //move elevator and load passengers
		cout << "Elevator " << IDNum << " went from floor [" << current_floor;
		current_floor = f;
		cout << "] to [" << current_floor << "]\n";
	}

}

void Elevator::setElevatorNumber(int n)
{
	elevator_number = n;
}

void Elevator::setIdle (bool i)
{
	idle = i;
}

bool Elevator::still_exiting()
{
	if (elev_passengers.size() == 0) { //if no one is in the elevator, it's no longer exiting
		return false;
	}
	for (int i = 0; i < elev_passengers.size(); i++) {
		if (elev_passengers[i].getDestination() == current_floor) { //if a passenger in the vector is going out of elevator's current floor -> still exiting 
			return true;
		}
	}
	return false;
}

Passenger Elevator::exit()
{
	for (int i = 0; i < elev_passengers.size(); i++) {
		if (elev_passengers[i].getDestination() == current_floor) { //looks at all passengers in the elevator
			Passenger pass = elev_passengers[i]; //creates copy to output statement and work with unloading_passengers in Building.cpp
			elev_passengers.erase(elev_passengers.begin() + i);
			cout << "EXITING: Passenger " << pass.getIDNum() << " on floor [" << current_floor << "]\n";
			return pass;
		}
	}
}

void Elevator::load(Passenger passe) //
{
	passe.setOnElevator(true); //taken from Passenger class
	elev_passengers.push_back(passe); //adds to vector of elevator
}