
#include <iostream>


using namespace std;

#ifndef FLIGHT_schedule_H_
#define FLIGHT_schedule_H_

#include "Flight.h"

template<class type>
class FlightSchedule
{
	type x;
public:
	FlightSchedule();
    Flight Flights[3];
    type method(type);
};
#endif
