/*
 * testVector.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: tanhh
 */
#include<iostream>
#include "Vector.h"
using namespace std;

int main(){
	Vector <int> intVector;
	cout << "Initial:" << endl;
	cout << "The capacity of intVector is:"<<intVector.capacity() << endl;
	cout << "The size of intVector is:" << intVector.size() << endl;
	cout << "The number in intVector is:" << endl;

	Vector <int>::const_iterator itr = intVector.begin();

	while(itr!= intVector.end()){
		cout<<*itr++<<",";

	}
	cout <<'\b' << "." << endl;


	for (int i=0; i<100;i++){
		intVector.push_back(i);
	}

	cout << "Put 100 number into intVector:" << endl;
	cout << "The capacity of intVector is:"<<intVector.capacity() << endl;
	cout << "The size of intVector is:" << intVector.size() << endl;
	cout << "The number in intVector is:" << endl;

	itr = intVector.begin();

	while(itr!= intVector.end()){
		cout<<*itr++<<",";

	}
	cout <<'\b' << "." << endl;

	for (int i=0; i<50;i++){
		intVector.pop_back();
	}

	cout << "pop_back 50 times to the intVector:" << endl;
	cout << "The capacity of intVector is:"<<intVector.capacity() << endl;
	cout << "The size of intVector is:" << intVector.size() << endl;
	cout << "The number in intVector is:" << endl;

	itr = intVector.begin();

	while(itr!= intVector.end()){
		cout<<*itr++<<",";

	}
	cout <<'\b' << "." << endl;



	return 0;
}




