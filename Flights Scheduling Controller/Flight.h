/*
 * Flight.h
 *
 *  Created on: 8 May 2021
 *      Author: Aly
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <iostream>

using namespace std;

class Flight
{
  private:
       string flightName;
       int launchHour;
       int launchMin;
       int landHour;
       int landMin;
       int duration;/*duration is passed in minutes*/
       string state;
  public:
       Flight();
       int getlaunchHour();
       int getlaunchMin();
       int getlandHour();
       int getlandMin();
       void setState(string);
       string getState();
       string getName();
       void calculateLanding();

};




#endif /* FLIGHT_H_ */
