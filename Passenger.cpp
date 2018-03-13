#include <iostream>
#include <string>
#include <ctime>
#include "Passenger.h"
using namespace std;

Passenger::Passenger(int arrive, int ID, int numFloor)
{
	srand(time(NULL));
	ArrivalTime = arrive;
	CurrentFloor = rand() % numFloor + 1; //random number from 1-number of floors 
	Destination = rand() % numFloor + 1; //random number from 1-number of floors 
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

int Passenger::getDirection(int numFloor)
{
	srand(time(NULL));
	while (Destination == CurrentFloor) {
		//if they are already on the floor they want to go to, have them pick another floor
		Destination = rand() % numFloor + 1; //random number from 1-number of floors 
		cout << "Generating new destination... \n";
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


