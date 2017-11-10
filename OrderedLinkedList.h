/*
 * OrderLinkedList.h
 *
 *  Created on: Oct 21, 2017
 *      Author: beverlyackah
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include "LinkedList.h"
#include "Passenger.h"

template <class T>
class OrderedLinkedList : public LinkedList<T>{

public:
	void deleteLastPassenger(string fname,string lname);
	void insertSortedPassenger(T& passenger);
	Passenger* getPassenger(string fname, string lname);
	void listPassengers();
	OrderedLinkedList();
	~OrderedLinkedList();
};

template <class T>
void OrderedLinkedList<T> :: deleteLastPassenger(string fname,string lname){


	if(this->head == NULL){
		return ;
	}
	else if(this->head->data.getFName() == fname && this->head->data.getLName() == lname){
		this->head = this->head->next;
		return ;
	}
	else {
		node<T>* ptr1 = this->head;
		node<T>* ptr2 = NULL;
		while(ptr1!= NULL){
			if(ptr1->data.getFName() == fname && ptr1->data.getLName() == lname){

				if(ptr2 != NULL){
					ptr2->next = ptr1->next;
					ptr1 = ptr2;
				}

			}
			else{
				ptr2 = ptr1;
				ptr1 = ptr1->next;
			}
		}

	}
}

template <class T>
void OrderedLinkedList<T>::insertSortedPassenger(T& passenger){

	node<T>* newpassenger = new node<T>() ;
	newpassenger->data = passenger;
	newpassenger->next = NULL;

	if(this->head == NULL){

		this->head = newpassenger;
		return;
	}
	else{

		node<T>* p = NULL;
		node<T>* q = this->head;
		while(q!=NULL && q->data < passenger){

			p = q;
			q = q->next;
		}
		if(q!=NULL){
			cout<<" "<<endl;
			if(p!=NULL){
				p->next = newpassenger;
				newpassenger->next = q;
				q=p;
			}
			else{
				newpassenger->next = this->head;
				this->head = newpassenger;
			}

		}
		else{

			if(p->data<passenger){
				p->next = newpassenger;
			}
		}
	}
	delete newpassenger;
}

template <class T>
Passenger* OrderedLinkedList<T>:: getPassenger(string fname, string lname){
	if(this->head == NULL){
		return NULL;
	}
	node<T>* ptr = this->head;
	while(ptr!=NULL){
		if(ptr->data.getFName() == fname && ptr->data.getLName() == lname){
			return &(ptr->data);
		}
		ptr = ptr->next;
	}
	return NULL;

}

template <class T>
void OrderedLinkedList<T>::listPassengers(){
	if(this->head == NULL){
		return ;
	}
	node<T>* ptr = this->head;
	while(ptr!=NULL){
		cout<<ptr->data<<endl;
		ptr = ptr->next;
	}
}


template <class T>
OrderedLinkedList<T> :: OrderedLinkedList(){

}

template <class T>
OrderedLinkedList<T> :: ~OrderedLinkedList(){

}




#endif /* ORDEREDLINKEDLIST_H_ */
