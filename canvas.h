#include <math.h>
#include <iostream>
#include <fstream>
#include "point.h"

class Canvas{
public:
	int xSize;
	int ySize;
	std::ofstream myfile;
	std::string filename;

	Canvas(){}
	Canvas(int _xSize, int _ySize, std::string _filename = "default.ppm"){		
		xSize = _xSize;
		ySize = _ySize;
		filename = _filename;
	}

	void clear(){
		myfile.open(filename.c_str());

		myfile<< "P3"  << std::endl
			  << xSize << " " << ySize << std::endl 
			  << "255" << std::endl;

		for (int j = 0; j <  ySize; j++){
			for(int i = 0; i < xSize; i++){

				int r  = 255;
				int g  = 255;
				int b  = 255;

				myfile<< r << " " << g << " " << b << std::endl;
			}
		}
	}

	//Gera o coeficiente angular para dois pontos no canvas
	float getM(Point starter, Point final){
		return (float)(final.getY() - starter.getY())/(final.getX() - starter.getX() );
	}
	
	//Gera o Y inicial para traçar uma reta
	float getB(Point starter, float m){
		return (starter.getY() - m*starter.getX() ); 
	}


	bool belongsInLine(float m, float b, Point current){
		int virtualY = (m*current.getX() + b);
		return current.getY() == virtualY;
	}

	void drawLineBetweenPoints(Point starter, Point final){
		myfile.open(filename.c_str());

		myfile<< "P3"  << std::endl
			  << xSize << " " << ySize << std::endl 
			  << "255" << std::endl;


		int r  = 0;
		int g  = 0;
		int b  = 0;

		float _m = getM(starter, final);//coeficiente angular
		float _b = getB(starter, _m);    //Y inicial

		for (int j = 0; j <  ySize; j++){
			for(int i = 0; i < xSize; i++){
				Point current(i,j);

				if( belongsInLine(_m,_b, current) ){
					r  = 0;
					g  = 0;
					b  = 0;
				}else{
					r  = 255;
					g  = 255;
					b  = 255;
				}

				myfile<< r << " " << g << " " << b << std::endl;
			}
		}
		
	}

};
