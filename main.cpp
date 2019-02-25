#include <iostream>
#include "point.h"
#include "canvas.h"

int main(){
	Point starter(0,10);
	Point final(99,20);

	Canvas canvas(100,100);
	canvas.drawLineBetweenPoints(starter, final);

	return 0;
}