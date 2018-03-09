//
//  main.cpp
//  elevator


#include "main.h"
#include <iostream>
using namespace std;



class manager
{
protected:
    int entry_passengers;
    int exit_passengers;
public:
    void get_entry_pass();
    int current_pass_in_ele();
    void passenger_entry(int i);
    void passenger_exit(int n);
    
};


