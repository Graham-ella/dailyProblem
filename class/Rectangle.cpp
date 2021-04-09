#include "Rectangle.h"
#include <iostream>
using std::cout;
using std::endl;

int Rectangle::count = 0;

/*
Rectangle::Rectangle() {
	cout << "无参数创建\n" << endl;
	count++;
}
*/

Rectangle::Rectangle(double width, double height) {
	this->width = width;
	this->height = height;
	cout << "含参数创建\n" << endl;
	count++;
}
Rectangle::~Rectangle() {
	cout << "释放\n" << endl;
	count--;
}
double Rectangle::getWidth() {
	return width;
}
double Rectangle::getHeight() {
	return height;
}
double Rectangle::getArea() {
	return width * height;
}
double Rectangle::getPerimeter() {
	return 2 * (width + height);
}
void Rectangle::display() {
	cout << "width = " << width << "height = " << height << endl;
	cout << "Area  = " << this->getArea() << endl;
	cout << "Perimeter = " << this->getPerimeter() << endl;
}
void Rectangle::setHeight(double height) {
	this->height = height;
}
void Rectangle::setWidth(double width) {
	this->width = width;
}
int Rectangle::getCount() {
	return count;
}