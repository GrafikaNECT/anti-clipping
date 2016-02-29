#include "face.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "graphics.h"

int main() {
	point3 p1(640/2-100,480/2-100,0);
	point3 p2(640/2-100,480/2+100,0);
	point3 p3(640/2,480/2,0);
	
	face f(p1,p2,p3);
	
	int i;
	for (i=0;i<f.getSize();i++) {
		std::cout << "Vertex no " << i+1 << ": (" << f.getP(i).getX() << "," << f.getP(i).getY() << "," << f.getP(i).getZ() << ")\n"; 
	}
	for (i=0;i<f.getSize();i++) {
		std::cout << "Vertex no " << i+1 << ": (" << f.getP(i).getX() << "," << f.getP(i).getY() << "," << f.getP(i).getZ() << ")\n"; 
	}
	
	initializeGraphics();
	for (i=0;i<180;i++) {
		drawRectangle(0,0,640,480,0,0,0,255);
		f.rotate(3.1415/180,'z',640/2,480/2,0);
		f.draw();
		printToScreen();
		usleep(100000/6);
	}
	for (i=0;i<f.getSize();i++) {
		std::cout << "Vertex no " << i+1 << ": (" << f.getP(i).getX() << "," << f.getP(i).getY() << "," << f.getP(i).getZ() << ")\n"; 
	}
	return 0;
}
