#include "Elevator.h"
#include <iostream>
#include <vector>
using namespace std;

Elevator::Elevator()
{
	elevator_number = -1;
	current_floor = 0;
	vector <Passenger> elev_passengers;
	//elev_passengers.resize(10);
	idel = true;
}

Elevator::Elevator(int ID)
{
	//Constructor accepts elevator ID, 

	elevator_number = ID;
	current_floor = 0;
	vector <Passenger> elev_passengers;
	//elev_passengers.resize(10);
	idel = true;


}

int Elevator::getCurrentFloor()
{
	return current_floor;
}

bool Elevator::getEmergency_Button()
{
	return emergency_button;
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
		idel = false;
		return false; //if people in the elevator
	}
	else if (elev_passengers.empty() == true) {
		idel = true;
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

void Elevator::setEmergency_Button(bool e)
{
	emergency_button = false;
}

void Elevator::setElevatorNumber(int n)
{
	elevator_number = n;
}

void Elevator::setIdel(bool i)
{
	idel = i;
}

bool Elevator::still_exiting()
{
	if (elev_passengers.size() == 0) { //if no one is in the elevator, it's no longer exiting
		return false;
	}
	for (int i = 0; i < elev_passengers.size(); i++) {
		if (elev_passengers[i].getDestination() == current_floor) {
			return true;
		}
	}
	return false;
}

Passenger Elevator::exit()
{
	for (int i = 0; i < elev_passengers.size(); i++) {
		if (elev_passengers[i].getDestination() == current_floor) {
			Passenger pass = elev_passengers[i];
			elev_passengers.erase(elev_passengers.begin() + i);
			//cout << "EXITING: Passenger " << pass.getIDNum() << " on floor [" << current_floor << "]\n";
			return pass;
		}
	}
}

void Elevator::load(Passenger passe)
{
	passe.setOnElevator(true);
	elev_passengers.push_back(passe);
}


