#include "Building.h"

Building::Building()
{
	elevators = 0;
	floors = 0;
}

int Building::get_elevators() 
{
	return elevators;
}

int Building::get_floors()
{
	return floors;
}

void Building::set_elevators(int e)
{
	elevators = e; 
}

void Building::set_floors(int f)
{
	floors = f;
}
