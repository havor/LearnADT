/*
 * List.h
 *
 *  Created on: Jul 22, 2015
 *      Author: tanhh
 */

#ifndef LIST_H_
#define LIST_H_

/**
 * Example of List implementtion from Data Structures and Algorithm Analysis in CPP by Mark Allen Weise.
 *
 * 1. The List class itself, which contains links to both ends, the size of the list, and a host
 * of methods.
 *
 * 2. The Node class, which is likely to be a private nested class. A node contains the data
 * and pointers to the previous and next nodes, along with appropriate constructors.
 *
 * 3. The const_iterator class, which abstracts the notion of a position, and is a public nested
 * class. The const_iterator stores a pointer to “current” node, and provides implementation of
 * the basic iterator operations, all in the form of overloaded operators such as =, ==, !=, and ++.
 *
 * 4. The iterator class, which abstracts the notion of a position, and is a public nested class.
 * The iterator has the same functionality as const_iterator, except that operator*returns a
 * reference to the item being viewed, rather than a constant reference to the item. An important
 *  technical issue is that an iterator can be used in any routine that requires a const_iterator,
 *  but not vice versa. In other words, iterator IS-A const_iterator.
 *
 *
 * */
#include <algorithm>


template <typename Object>
class List{
private:
	struct Node{
		Object data;
		Node* previous;
		Node* next;

		Node(const Object & d = Object{},Node * p = nullptr, Node * n = nullptr)
		:data{d},
		 previous{p},
		 next{n}
		 {}

		 Node(Object && d, Node * p = nullptr,Node * n = nullptr)
		 :data{std::move(d)},
		  previous{p},
		  next{n}
		  {}



	};
public:
	class const_iterator{
	public:
		const_iterator():current{nullptr}{}
		const Object & operator * ()const{
			return retrieve();
		}

		const_iterator & operator ++ (){
			current = current -> next;
			return this;
		}

		const_iterator operator ++(int){
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator == (const const_iterator & rhs)const{
			return current == rhs.current;
		}

		bool operator != (const const_iterator & rhs)const{
			return !(*this==rhs);
		}

		Object& retrieve()const{
			return current->data;
			}

		const_iterator(Node* p):current{p}{}

	protected:
		Node* current;

		friend class List<Object>;

	};

	class iterator :public const_iterator{
	public:
		iterator(){}

		Object & operator * () {
			return const_iterator::retrieve();
		}

		const Object & operator * ()const{
			return const_iterator::retrieve();
		}

		iterator operator ++ (){
			this->current = this->current->next;
			return * this;
		}

		iterator operator ++ (int){
			iterator old = *this;
			++(*this);
			return old;
		}

	protected:
		iterator(Node *p):const_iterator{p}{}


		friend class List<Object>;

	};

public:
	List(){
		init();

	}

	List(const List & rhs){
		init();
		for(auto & x: rhs){
			push_back(x);
		}

	}

	List( List && rhs)
	:theSize {rhs.theSize},
	 head {rhs.head},
	 tail {rhs.tail}{
		rhs.theSize = 0;
		rhs.head = nullptr;
		rhs.tail = nullptr;

	}

	~List(){
		clear();
		delete head;
		delete tail;

	}

	List & operator =(const List & rhs){
		List copy = rhs;
		std::swap(*this,copy);
		return *this;


	}

	List & operator =(const List && rhs){
		std::swap(theSize,rhs.theSize);
		std::swap(head,rhs.head);
		std::swap(tail,rhs.tail);

		return *this;

		}

	iterator begin(){
		return {head->next};
	}

	const_iterator begin()const{
		return {head->next};
	}

	iterator end(){
		return {tail};
	}

	const_iterator end()const{
		return{tail};
	}

	int size()const{
		return theSize;

	}

	bool empty()const{
		return size()==0;

	}

	void clear(){
		while(!empty()){
			pop_front();
		}

	}

	Object & front(){
		return *begin();

	}

	const Object & front()const{
		return *begin();

	}

	Object & back(){
		return *--end();

	}

	const Object & back()const{
		return *--end();

	}

	void push_front(const Object & x){
		insert(begin(),x);

	}

	void push_front(Object && x){
		insert(begin(),std::move(x));

	}

	void push_back(const Object & x){
		insert(end(),x);

	}

	void push_back(Object && x){
		insert(end(),std::move(x));

	}

	void pop_front(){
		erase(begin());

	}

	void pop_back(){
		erase(end());

	}

	iterator insert(iterator itr, const Object & x){
		Node* p = itr.current;
		theSize++;
		return{p->previous = p->previous->next= new Node{x,p->previous,p}};

	}

	iterator insert(iterator itr, Object && x){
		Node* p = itr.current;
		theSize++;
		return{p->previous = p->previous->next = new Node{std::move(x),p->previous,p}};

	}

	iterator erase(iterator itr){
		Node * p= itr.current;
		iterator retVal {p->next};
		p->previous->next = p->next;
		p->next->previous = p->previous;
		delete p;
		theSize--;

		return retVal;


	}

	iterator erase(iterator from,iterator to){
		for(iterator itr=from; itr!=to;){
			itr = erase(itr);
		}

		return to;
	}



private:
	int theSize;
	Node* head;
	Node* tail;

	void init(){
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->previous = head;

	}
};



#endif /* LIST_H_ */
