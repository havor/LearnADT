/*
 * TestList.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: tanhh
 */

#include <iostream>
#include "List.h"

using namespace std;

int main(){
	List<int> intList;

	//List<int>::iterator itr = intList.begin();

	//print the initial state of intList
	cout << "Initial:" << endl;
	cout << "The size of intList is: " << intList.size() << endl;
	cout << "The number in intList is: " << endl;



	for(int i=0;i<20;++i){
		intList.push_back(i);
	}

	cout << "Push_back 20 number:" <<endl;
	cout << "The size of intList is: " << intList.size() << endl;

	for(List<int>::iterator itr = intList.begin(); itr != intList.end();){

		cout << (itr++).retrieve() << ",";
	}
	cout <<"\b."<<endl << endl;

	for (int i=0;i<20;++i){
		intList.push_front(i);

	}

	cout << "Push_front 20 number:"<< endl;
	cout << "The size of intList is: " << intList.size() << endl;

	for(List<int>::iterator itr = intList.begin(); itr != intList.end();){

		cout << (itr++).retrieve() << ",";
	}
	cout <<"\b."<<endl << endl;


	List<int>::iterator itr = intList.begin();
	cout << "The data in head is: " << itr.retrieve() << endl;

	itr = intList.end();
	cout << "The data in tail is: " << itr.retrieve() << endl;

	return 0;

}


