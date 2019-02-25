#ifndef POINT
#define POINT

class Point
{
private:
    int x;
    int y;
public:
	Point(int _x, int _y){
		x = _x;
		y = _y;
	}

	int getX(){return x;}
	int getY(){return y;}

	void setX(int _x){x = _x;}
	void setY(int _y){y = _y;}
};

#endif