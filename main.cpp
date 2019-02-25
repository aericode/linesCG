#include <iostream>
#include "point.h"
#include "canvas.h"

void basicPoint(Point& insert){
	int x;
	int y;
	std::cout<< "insert point's X" <<std::endl;
	std::cin >> x;
	std::cout<< "insert point's Y" <<std::endl;
	std::cin >> y;

	insert.setX(x);
	insert.setY(y);

}

int main(){
	Point starter(0,10);
	Point final(99,20);

	basicPoint(starter);
	basicPoint(final);

	Canvas canvas(100,100);
	canvas.drawLineBetweenPoints(starter, final);

	return 0;
}