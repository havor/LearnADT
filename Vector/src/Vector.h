/*
 * Vector.h
 *
 *  Created on: Jul 21, 2015
 *      Author: tanhh
 *
 */


/**
 * This example is from Data Structures and Algorithm Analysis in C++ by Mark Allen Weise
 *
 * 1. The Vector will maintain the primitive array (via a pointer variable to the block of
 * allocated memory), the array capacity, and the current number of items stored in the
 * Vector.
 *
 * 2. The Vector will implement the Big-Five to provide deep-copy semantics for the copy
 * constructor and operator=, and will provide a destructor to reclaim the primitive array.
 * It will also implement C++11 move semantics.
 *
 * 3. The Vector will provide a resize routine that will change (generally to a larger number)
 * the size of the Vector and a reserve routine that will change (generally to a larger
 * number) the capacity of the Vector. The capacity is changed by obtaining a new block
 * of memory for the primitive array, copying the old block into the new block, and
 * reclaiming the old block.
 * 4. The Vector will provide an implementation of operator[] (as mentioned in
 * Section 1.7.2, operator[] is typically implemented with both an accessor and mutator
 * version).
 * 5. The Vector will provide basic routines, such as size, empty, clear (which are typically
 * one-liners), back, pop_back, and push_back. The push_back routine will call reserve if the
 * size and capacity are same.
 * 6. The Vector will provide support for the nested types iterator and const_iterator, and
 * associated begin and end methods.

 */

#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_

#include <algorithm>


template <typename Object>
class Vector{
public:
	explicit Vector(int initSize = 0):
	theSize{initSize},
	theCapacity{initSize + SPARE_CAPACITY}
	{objects = new Object[theCapacity];}

	Vector(const Vector& rhs):
			theSize{rhs.theSize},
			theCapacity{rhs.theCapacity},
			objects{nullptr}{
				objects = new Object[theCapacity];
				for(int k=0;k<theSize;++k){
					objects[k] = rhs.objects[k];
				}
			}
	Vector(const Vector&& rhs):
		theSize{rhs.theSize},
		theCapacity{rhs.theCapacity},
		objects{rhs.objects}{
				rhs.objects = nullptr;
				rhs.theCapacity = 0;
				rhs.theSize = 0;
			}

	Vector& operator = (const Vector& rhs){
		Vector copy = rhs;
		std::swap(*this,copy);
		return *this;
	}

	Vector& operator = (Vector&& rhs){
		std::swap(theSize,rhs.theSize);
		std::swap(theCapacity,rhs.theCapacity);
		std::swap(objects,rhs.objects);
		return *this;
	}

	Object& operator [](int index){
		return objects[index];
	}

	const Object& operator [](int index)const{
		return objects[index];
	}

	bool empty()const{
		return size()==0;
	}

	int size()const{
		return theSize;

	}

	int capacity()const{
		return theCapacity;
	}

	void push_back(const Object& x){
		if (theSize == theCapacity)	reserve(2*theCapacity + 1);
		objects[theSize++]=x;
	}

	void push_back(Object&& x){
		if (theSize == theCapacity) reserve(2*theCapacity + 1);
		objects[theSize++]=std::move(x);
	}

	void pop_back(){
		--theSize;
	}

	const Object& back()const{
		return objects[theSize-1];
	}

	typedef Object* iterator;
	typedef const Object* const_iterator;

	iterator begin(){
		return &objects[0];
	}

	const_iterator begin()const{
		return &objects[0];
	}

	iterator end(){
		return &objects[size()];
	}

	const_iterator end()const{
		return &objects[size()];
	}

	~Vector(){
		delete [] objects;
	}

	void resize(int newSize){
		if (newSize > theCapacity) reserve(newSize * 2);
		theSize = newSize;
	}

	void reserve(int newCapacity){
		if (newCapacity < theSize)
			return;

		Object *newArray = new Object[newCapacity];
		for(int k =0;k<theSize;++k){
			newArray[k]=std::move(objects[k]);
		}
		theCapacity = newCapacity;
		std::swap(objects,newArray);
		delete[] newArray;

	}


	static const int SPARE_CAPACITY = 16;

private:
	int theSize;
	int theCapacity;
	Object* objects;
};



#endif /* SRC_VECTOR_H_ */
