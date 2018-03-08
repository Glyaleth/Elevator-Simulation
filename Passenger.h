#pragma once

class Passenger {
private: 
	int ArrivalTime, CurrentFloor, Destination, ExitTime, WaitTime, Direction, IDNum;

public: 
	Passenger(int arrive = 0, int current=-1, int destin=-1, int ID=0);
	int getArrivalTime(); //The time the passenger arrived
	int getCurrentFloor(); //The floor the passenger is on
	int getDestination(); //The floor the passenger wants to go
	int getExitTime(int ET); //sets and returns time the passenger gets off the elevator
	int getWaitTime(); //calculates, sets, and returns wait time based on currently assigned Arrive/Exit Time
	int getDirection(); //sets and returns Direction based on current/destination floor. 1=up, 0=down, -1=error-->current == destination floor 
	int getIDNum();

	void setArrivalTime(int AT);
	void setCurrentFloor(int CF);
	void setDestination(int Destin);
	void setIDNum(int ID);


};