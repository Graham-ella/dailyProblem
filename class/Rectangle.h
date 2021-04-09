#pragma once
class Rectangle
{
	private:
		double width;
		double height;
		static int count;
	public:
		//Rectangle();
		Rectangle(double width = 1.0, double height = 1.0);
		~Rectangle();
		double getWidth();
		double getHeight();
		void setWidth(double width);
		void setHeight(double height);
		void display();
		double getArea();
		double getPerimeter();
		static int getCount();
};

