#include <iostream>
#include <string>
#include <ctime>
#include "Passenger.h"
using namespace std;



Passenger::Passenger(int arrive, int ID, int numFloor)
{
	ArrivalTime = arrive;
	OnElevator = false;
	CurrentFloor = 0 + (rand() % numFloor); //random number from 0 to n floors

	Destination = 0 + (rand() % numFloor); //random number from 0 to n floors 

	if (numFloor != -1) {
		while (Destination == CurrentFloor) { //pick another floor
			Destination = 0 + (rand() % numFloor); //random number from 0 to n floors 
		}
	}
	
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

int Passenger::getExitTime()
{
	return ExitTime;
}

int Passenger::getWaitTime()
{
	WaitTime = ExitTime - ArrivalTime;
	return WaitTime;
}

int Passenger::getIDNum()
{
	return IDNum;
}

int Passenger::getDirection()
{
	if (CurrentFloor < Destination) { //if going up
		Direction = 1;
		return 1;
	}
	else if (CurrentFloor > Destination) { //if going down
		Direction = 0;
		return 0;
	}
}

bool Passenger::getOnElevator()
{
	return OnElevator;
}



void Passenger::setOnElevator(bool a)
{
	OnElevator = a;
}

void Passenger::setArrivalTime(int AT)
{
	ArrivalTime = AT;
}

void Passenger::setExitTime(int ET)
{
	ExitTime = ET;
}

void Passenger::setCurrentFloor(int CF)
{
	CurrentFloor = CF;
}

void Passenger::setDestination(int Destin)
{
	Destination = Destin;
}

void Passenger::setDirection(int D)
{
	Direction = D;
}

void Passenger::setIDNum(int ID)
{
	IDNum = ID;
}
