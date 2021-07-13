/*
 * Control.h
 *
 *  Created on: 8 May 2021
 *      Author: Aly
 */

#ifndef CONTROL_H_
#define CONTROL_H_


#include "Flight.h"
#include "flight_schedule.h"
template<class type>
class LaunchController
{
private:
	int launchHour1;
	int launchHour2;
	int launchMin1;
	int launchMin2;
public:
//	void LaunchController();
    void launchSchedule(FlightSchedule<type>*);
};
template<class type>
class LandController
{
private:
	int landHour1;
	int landHour2;
	int landhMin1;
	int landhMin2;
public:
//	LandController();
    void landingSchedule(FlightSchedule<type>*);
};

template<class type>
class FlightController: public LandController<type>, public LaunchController<type>
{
	
protected:
  FlightSchedule<type> flight_schedule;
public:
  FlightController();
  FlightSchedule<type> *flights;
  
};



#endif /* CONTROL_H_ */
