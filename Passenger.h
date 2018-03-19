#pragma once
class Passenger {
private:
	int ArrivalTime, CurrentFloor, Destination, ExitTime, WaitTime, Direction, IDNum;
	bool OnElevator;

public:
	Passenger(int arrive = -1, int ID = -1, int numFloor = -1);
	int getArrivalTime(); //The time the passenger arrived
	int getCurrentFloor(); //The floor the passenger is on
	int getDestination(); //The floor the passenger wants to go
	int getExitTime(); //sets and returns time the passenger gets off the elevator
	int getWaitTime(); //calculates, sets, and returns wait time based on currently assigned Arrive/Exit Time
	int getIDNum();
	int getDirection();
	bool getOnElevator();

	void setOnElevator(bool a);
	void setArrivalTime(int AT);
	void setExitTime(int ET);
	void setCurrentFloor(int CF);
	void setDestination(int Destin);
	void setDirection(int D);
	void setIDNum(int ID);


};
