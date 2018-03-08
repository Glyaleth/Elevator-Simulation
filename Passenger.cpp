#include <iostream>
#include <string>
#include "Passenger.h"
using namespace std;

Passenger::Passenger(int arrive, int current, int destin, int ID)
{
	ArrivalTime = arrive;
	CurrentFloor = current;
	Destination = destin;
	getDirection();
	IDNum = ID;
}

int Passenger::getArrivalTime()
{
	return ArrivalTime;
}

int Passenger::getCurrentFloor()
{
	return CurrentFloor;
}

int Passenger::getDestination()
{
	return Destination;
}

int Passenger::getExitTime(int ET)
{
	ExitTime = ET;
	return ExitTime;
}

int Passenger::getWaitTime()
{
	WaitTime = ExitTime - ArrivalTime;
	return WaitTime;
}

int Passenger::getDirection()
{
	while (Destination == CurrentFloor) {
		//if they are already on the floor they want to go to, have them pick another floor
		cout << "Your destination cannot be your current floor, try again\n";
		cin >> Destination;
		//or generate another random number
	}
	if (Destination > CurrentFloor)
		return 1; //if they are going up
	else if (Destination < CurrentFloor)
		return 0; //if they are going down
}

int Passenger::getIDNum()
{
	return IDNum;
}

void Passenger::setArrivalTime(int AT)
{
	ArrivalTime = AT;
}

void Passenger::setCurrentFloor(int CF)
{
	CurrentFloor = CF;
}

void Passenger::setDestination(int Destin)
{
	Destination = Destin;
}

void Passenger::setIDNum(int ID)
{
	IDNum = ID;
}




