/*
 * IntCell.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: º£»ª
 */

#include "IntCell.h"

IntCell::IntCell(const int & initialValue):storedValue{initialValue}{}

const int IntCell::read()const{
	return storedValue;
}

void IntCell::write(const int & x){
	storedValue = x;

}
