/*
 * Flight.cpp
 *
 *  Created on: 8 May 2021
 *      Author: Aly
 */
#include<iostream>
using namespace std;
#include "Flight.h"

Flight::Flight()
{
	cout<<"Enter the name of the flight:";
	cin>>flightName;
	cout<<endl;
	cout<<"Enter the departure time of the plane:";
	cin>>launchHour;
	cin>>launchMin;
	cout<<endl;
	cout<<"Enter the duration of flight in minutes:";
    cin>>duration;
	cout<<endl;
	state="Idle";
	calculateLanding();
}



int Flight::getlaunchHour()
{
   return launchHour;
}
int Flight::getlaunchMin()
{
  return launchMin;
}
int Flight::getlandHour()
{
   return landHour;
}
int Flight::getlandMin()
{
  return landMin;
}
void Flight::setState(string s)
{
  state=s;
}
string Flight::getState()
{
	return state;
}
string Flight:: getName()
{
	return flightName;
}
void Flight::calculateLanding()
{

  landHour=(duration/60)+launchHour;
  landMin=(duration%60)+launchMin;
  if(landMin>=60)
  {
	  landHour+=1;
	  landMin=landMin%60;
  }
}
