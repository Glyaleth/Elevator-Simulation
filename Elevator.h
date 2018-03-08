#include <queue>
//#include "passengers.cpp"/"passengers.h"
//#include "building.cpp/.h"


#pragma once
class Elevator
{
public:
	//Up=0, Down=1. If up, the elevator goes up. If down, the elevator does down. 
	enum direction { up, down };
	//This queue would need to be ordered, and acts as our range of floors in the building. Each floor may or may not be populated with a passenger, 
	std::queue<Floor> elev;
	int current_floor;
	size_t total_capacity = elev.size();
	//Easter egg emergency button. Only to be used if elevator breaks down.
	bool emergency_button = false;
	int elevator_number;
	bool not_moving;


	
	
	
	Elevator();
	~Elevator();

};

