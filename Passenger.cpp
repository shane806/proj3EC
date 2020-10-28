//
// Created by Shane Humphrey on 10/13/20.
//

#include "Passenger.h"
// Name: Passenger(string, int, string, string)
// Desc - Overloaded Constructor for a passenger including name, age,
//        start location (where they board), final destination (where they get off)
// Preconditions - Data Available
// Postconditions - Creates a new Passenger
Passenger::Passenger(string fullName, int age, string start, string final)
{
  m_fullName = fullName;
  m_age = age;
  m_startLocation = start;
  m_finalDestination=final;
}
// Name: GetName
// Desc - Returns name
// Preconditions - Data Available
// Postconditions - Returns passenger name
string Passenger::GetName(){
  return m_fullName;
}
// Name: GetStartLocation
// Desc - Returns starting location
// Preconditions - Data Available
// Postconditions - Returns starting location
string Passenger::GetStartLocation(){
  return m_startLocation;
}
// Name: GetFinalDestination
// Desc - Returns final location
// Preconditions - Data Available
// Postconditions - Returns final destination
string Passenger::GetFinalDestination(){
  return m_finalDestination;
}
