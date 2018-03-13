#include "Building.h"

Building::Building(int e_num, int p_num)
{
	elevators = e_num;
	floors = p_num;
}

int Building::get_elevators() const
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
