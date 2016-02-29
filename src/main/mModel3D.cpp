#include "../include/Model3D.h"
#include "../include/Printer.h"
#include <unistd.h>
#include <iostream>

int main(){
	//test konstruksi
	vector<SolidPolygon3D> listOfSolidPolygon3D;
	SolidPolygon3D poly1(Texture::createSingleColorTexture(200,4,5,255)); //TODO: GANTI WARNA
	poly1.push_back(50, 50, 10);		
	poly1.push_back(100, 30, 10);
	poly1.push_back(150, 70, 10);
	poly1.push_back(50, 90, 10);

	SolidPolygon3D poly2(Texture::createSingleColorTexture(4,200,10,255)); //TODO: GANTI WARNA
	poly2.push_back(50, 50, 5);		
	poly2.push_back(100, 30, 5);
	poly2.push_back(150, 70, 5);
	poly2.push_back(50, 90, 5);

	SolidPolygon3D poly3(Texture::createSingleColorTexture(200,4,200,255)); //TODO: GANTI WARNA
	poly3.push_back(50, 50, 15);		
	poly3.push_back(100, 30, 15);
	poly3.push_back(150, 70, 15);
	poly3.push_back(50, 90, 15);

	listOfSolidPolygon3D.push_back(poly1);
	listOfSolidPolygon3D.push_back(poly2);
	listOfSolidPolygon3D.push_back(poly3);

	Model3D model3D(listOfSolidPolygon3D);


	Printer::initializePrinter();
	Point3D eye(8,8,20);
	//test gambar	
	Printer::drawCanvas(0,0,0,255);
	model3D.orderSolidPolygon();
	model3D.draw(eye);
	Printer::printToScreen();
	sleep(2);

	//test rotasi
	for (char axis = 'x';axis<='z';axis++){
		for (int i=0;i<360;i++){
			std::cout<<"test rotasi axis " << axis << " sudut " << i << std::endl;
			Model3D hasilRotasi = model3D.rotationResult(i,axis);
			Printer::drawCanvas(0,0,0,255);
			hasilRotasi.orderSolidPolygon();
			hasilRotasi.draw(eye);
			Printer::printToScreen();
			usleep(1);
		}
	}

	Printer::finishPrinter();
}
