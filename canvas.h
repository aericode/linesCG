#include <math.h>
#include <iostream>
#include <fstream>

class Canvas{
public:
	int xSize;
	int ySize;
	std::ofstream myfile;	

	Canvas(){}
	Canvas(int _xSize, int _ySize){		
		xSize = _xSize;
		ySize = _ySize;
	}

	void clear(){
		myfile.open ("helloworld.ppm");

		myfile<< "P3"  << std::endl
			  << xSize << " " << ySize << std::endl 
			  << "255" << std::endl;

		for (int j = 0; j <  xSize; j++){
			for(int i = 0; i < ySize; i++){

				int r  = 255;
				int g  = 255;
				int b  = 255;

				myfile<< r << " " << g << " " << b << std::endl;
			}
		}
	}

	void drawLine(){
		myfile.open ("helloworld.ppm");

		myfile<< "P3"  << std::endl
			  << xSize << " " << ySize << std::endl 
			  << "255" << std::endl;


		int r  = 0;
		int g  = 0;
		int b  = 0;

		for (int j = 0; j <  xSize; j++){
			for(int i = 0; i < ySize; i++){

				if(i==j){
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

	//Gera o coeficiente angular para dois pontos no canvas
	float getM(int x1, int y1, int x2, int y2){
		return (float)(y2-y1)/(float)(x2-x1);
	}
	
	//Gera o Y inicial para traçar uma reta
	float getB(int x1, int y1, float m){
		return (y1 - m*x1); 
	}


	bool belongsInLine(float m, float b, int currentX, int currentY){
		int virtualY = float(m*currentX + b);
		return currentY == virtualY;
	}

	void drawLineBetweenPoints(int x1, int y1, int x2, int y2){
		myfile.open ("helloworld.ppm");

		myfile<< "P3"  << std::endl
			  << xSize << " " << ySize << std::endl 
			  << "255" << std::endl;


		int r  = 0;
		int g  = 0;
		int b  = 0;

		float _m = getM(x1,y1,x2,y2);//coeficiente angular
		float _b = getB(x1,y1,_m);    //Y inicial

		for (int j = 0; j <  ySize; j++){
			for(int i = 0; i < xSize; i++){

				if( belongsInLine(_m,_b,i,j) ){
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
