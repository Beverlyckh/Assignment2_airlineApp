/*
 * Passenger.h
 *
 *  Created on: Oct 18, 2017
 *      Author: beverlyackah
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
#include <sstream>
using namespace std;

class Passenger {
private:
	string fName, lName;
	string address;
	string phone;

public:
	string getFName();
	string getLName();
	string getAddress();
	string getPhone();
	Passenger();
	Passenger(string fName, string lName, string address, string phone);
	bool operator <(const Passenger &other){
		if(lName < other.lName){
			return true;
		}
		return false;
	}
	friend ostream& operator << (ostream& os, Passenger& passenger){
		os<<"Name: "<<passenger.fName<<" "<<passenger.lName<<" , Address: "<<passenger.address<<" ,Phone: "<<passenger.phone;
		return os;

	}
	bool operator == (const Passenger &other){
		if(fName == other.fName && lName == other.lName){
			return true;
		}
		return false;
	}

};





#endif /* PASSENGER_H_ */
