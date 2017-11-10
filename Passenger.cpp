/*
 * Passenger.h
 *
 *  Created on: Oct 16, 2017
 *      Author: beverlyackah
 */

#ifndef PASSENGER_CPP_
#define PASSENGER_CPP_
#include <string>
#include "Passenger.h"

Passenger::Passenger(){
	this->fName = "";
	this->lName = "";
	this->address = "";
	this->phone = "";
}

Passenger::Passenger(string fName, string lName, string address, string phone){
	this->fName = fName;
	this->lName = lName;
	this->address = address;
	this->phone = phone;
}

string Passenger::getFName(){
	return fName;
}
string Passenger::getLName(){
	return lName;
}
string Passenger::getAddress(){
	return address;
}
string Passenger::getPhone(){
	return phone;
}





#endif /* PASSENGER_CPP_ */
