#include "../include/Cube.h"
#include "../include/Printer.h"
#include <unistd.h>
#include <iostream>

#include <vector>

int main(){
	Point3D centerpoint(400,400,400);

	std::vector<Texture> textures;
	textures.push_back(Texture::createSingleColorTexture(255,0,0,255));
	textures.push_back(Texture::createSingleColorTexture(0,255,0,255));
	textures.push_back(Texture::createSingleColorTexture(0,0,255,255));
	textures.push_back(Texture::createSingleColorTexture(255,255,0,255));
	textures.push_back(Texture::createSingleColorTexture(255,0,255,255));
	textures.push_back(Texture::createSingleColorTexture(0,255,255,255));

	Cube cube(centerpoint,200,textures);



	//gambar
	Point3D eye (400,400,1000);

	Printer::initializePrinter();

	for (char axis = 'x';axis <='z';axis++){
		for (int i=0;i<360;i++){
			Model3D hasilRotasi = cube.rotationResult(i,centerpoint,axis);

			Printer::drawCanvas(0,0,0,255);
			std::vector<SolidPolygon3D> orderedSolidPolygon3D = hasilRotasi.orderSolidPolygon();
			Model3D orderedModel3D(orderedSolidPolygon3D);
			orderedModel3D.draw(eye);
			Printer::printToScreen();
			usleep(1);
		}
	}

	Printer::finishPrinter();

	return 0;
}
