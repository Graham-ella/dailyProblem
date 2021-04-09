#include "Rectangle.h"
#include <iostream>
using std::cout;
using std::endl;
int main() {
	Rectangle p1(3, 5);
	p1.display();
	Rectangle p2;
	p2.display();
	int sum = Rectangle::getCount();
	cout << sum << endl;
	
	


}