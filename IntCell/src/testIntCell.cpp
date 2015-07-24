#include <iostream>
#include "IntCell.h";
using namespace std;

int main(){
	IntCell m;
	m.write(15);
	cout << "The value stored in m is :" << m.read() << endl;

	return 0;
}

