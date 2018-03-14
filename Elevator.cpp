#include "Elevator.h"
#include <vector>
using namespace std;

Elevator::Elevator()
{
	elevator_number = 0;
	current_floor = 0;
	vector <Passenger> elev_passengers;
	elev_passengers.resize(10);
	idel = true;
}

Elevator::Elevator(int ID)
{
	//Constructor acceptselevator ID, 

		elevator_number = ID;
		cout << "Creating elevator #" << elevator_number<<endl;
		current_floor = 0;
		vector <Passenger> elev_passengers;
		elev_passengers.resize(10);
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
	return idel;
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
	for (int i = 0; i < elev_passengers.size(); i++) {
		if (elev_passengers[i].getDestination() == current_floor) {
			return true;
		}
	}
	return false;
}

Passenger Elevator::exit()
{
	for (int i = 0; i < elev_passengers.size() - 1; i++) {
		if (elev_passengers[i].getDestination() == current_floor) {
			Passenger pass = elev_passengers[i];
			elev_passengers.erase(elev_passengers.begin() + i);
			return pass;
		}
	}
}

void Elevator::load(Passenger passe)
{
	elev_passengers.push_back(passe);
}
