//============================================================================
// Name        : Assignment2.cpp
// Author      : Beverly ACKAH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"
using namespace std;

void getPassenger(string fname, string lname);
void deleteLastPassenger(int flightNum,string fName,string lName);

//Passenger p;
OrderedLinkedList<Passenger> flight100;
OrderedLinkedList<Passenger> flight200;
OrderedLinkedList<Passenger> flight300;
OrderedLinkedList<Passenger> flight400;

int main() {

	char operation;
	do{
		cout << "***DELTA AIRLINES***"<<endl; 	//do while loop
		cout << "Please chose an operation"<<endl;
		cout << "(A)ADD | (S)SEARCH | (D)DELETE | (L)LIST | (Q)QUIT"<<endl;
		cin>>operation;

		switch(operation){
		case 'A': case 'a':{ //To add, we only build our linked list with Passenger object.
			int flightNum;
			string fName, lName;
			string address, phone;
			cout <<"Enter flight number:"<<endl;
			cin >> flightNum;
			cout <<"Enter first name:"<<endl;
			cin >> fName;
			cout <<"Enter last name:"<<endl;
			cin >> lName;
			cout <<"Enter address:"<<endl;
			cin.ignore();
			getline(cin, address);
			cout << "Enter phone:" <<endl;

			cin >> phone;
			cin.ignore();

			Passenger passenger(fName, lName, address, phone);

			if(flightNum == 100){

				flight100.insertSortedPassenger(passenger);

			} else if(flightNum == 200){
				flight200.insertSortedPassenger(passenger);

			} else if(flightNum == 300){
				flight300.insertSortedPassenger(passenger);

			} else if (flightNum == 400){
				flight400.insertSortedPassenger(passenger);

			} else {
				cout << "The flight number you entered does not exist!" <<endl;
			}
			break;

		}

		case 'S': case 's':{
			int flightNum;
			string fName, lName;
			string address,phone;

			cout <<"Enter last name"<<endl;
			cin >> lName;
			cout <<"Enter first name:"<<endl;
			cin >> fName;
			getPassenger(fName,lName);


			break;
		}

		case 'D': case 'd':{
			int flightNum;
			string fName, lName;
			cout <<"Enter flight number:"<<endl;
			cin >> flightNum;
			cout <<"Enter last name"<<endl;
			cin >> lName;
			cout <<"Enter first name:"<<endl;
			cin >> fName;
			deleteLastPassenger(flightNum,fName,lName);

			break;
		}

		case 'L': case 'l':{
			int flightNum;
			cout << "Enter flight number:"<<endl;
			cin >> flightNum;

			if (flightNum == 100){
				flight100.listPassengers();
				//list the content of the linked list flight100
			} else if(flightNum == 200){
				flight200.listPassengers();
			} else if(flightNum == 300){
				flight300.listPassengers();
			}  else if(flightNum == 400){
				flight400.listPassengers();
			} else cout <<"We couldn't find the flight. Sorry";
			break;
		}

		case 'Q':

		case 'q':{


		}
		break;
		}
	} while (operation != 'Q');

	return 0;
}

void getPassenger(string fname, string lname){
	int flightNumber =0;
	Passenger p;
	if(flight100.getPassenger(fname,lname) != NULL){
		p = *(flight100.getPassenger(fname,lname));
		flightNumber = 100;
	}
	else if(flight200.getPassenger(fname,lname) != NULL){
		p = *(flight200.getPassenger(fname,lname));
		flightNumber = 200;
	}
	else if(flight300.getPassenger(fname,lname) != NULL){
		p = *(flight300.getPassenger(fname,lname));
		flightNumber = 300;
	}
	else if(flight400.getPassenger(fname,lname) != NULL){
		p = *(flight400.getPassenger(fname,lname));
		flightNumber = 400;
	}

	if(p.getLName()!=""){
		cout<<"FLIGHT NUMBER : "<<flightNumber<<endl;
		cout<<"FIRST NAME : "<<p.getFName()<<endl;
		cout<<"LAST NAME : "<<p.getLName()<<endl;
		cout<<"ADDRESS: "<<p.getAddress()<<endl;
		cout<<"PHONE : "<< p.getPhone() <<endl;

	}
	else{
		cout<<"Passenger not found"<<endl;
	}

}


void deleteLastPassenger(int flightNum, string fname, string lname){
	if(flightNum == 100){
		flight100.deleteLastPassenger(fname,lname);
		cout<<"Passenger deleted"<<endl;
	}
	else if(flightNum == 200){
		flight200.deleteLastPassenger(fname,lname);
		cout<<"Passenger deleted"<<endl;
	}
	else if(flightNum == 300){
		flight300.deleteLastPassenger(fname,lname);
		cout<<"Passenger deleted"<<endl;
	}
	else if(flightNum == 400){
		flight400.deleteLastPassenger(fname,lname);
		cout<<"Passenger deleted"<<endl;

	}
}
