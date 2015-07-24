/*
 * IntCell.h
 *
 *  Created on: Jul 20, 2015
 *      Author: º£»ª
 */

#ifndef SRC_INTCELL_H_
#define SRC_INTCELL_H_

class IntCell {
public:
	explicit IntCell(const int & initialValue = 0);
	const int read() const;
	void write(const int & x);
private:
	int storedValue;
};

#endif /* SRC_INTCELL_H_ */
