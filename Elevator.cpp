#include <iostream>
#include "Elevator.h"
#include <vector>
using namespace std;

Elevator::Elevator()
{
	elevator_number = 0;
	current_floor = 0;
	vector <Passenger> elev_passengers;
	elev_passengers.resize(10);//did we delete this resize function on the .cpp?
	idel = true;
}

Elevator::Elevator(int ID)
{
	//Constructor acceptselevator ID, 

	elevator_number = ID;
	current_floor = 1;
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

bool Elevator::getIdel()
{
	if (elev_passengers.empty() == false)
		return false; //if people in the elevator
	else if (elev_passengers.empty()==true)
		return true; //if empty, it is idle
}

void Elevator::setCurrentFloor(int f)
{
	current_floor = f;

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
			cout << pass.getIDNum() << " EXITED on floor " << current_floor << endl;
			return pass;
		}
	}
}

void Elevator::load(Passenger passe)
{
	elev_passengers.push_back(passe);
}
