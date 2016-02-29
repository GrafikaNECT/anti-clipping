#include <iostream>
#include <string>
#include "../include/Printer.h"
#include "../include/SolidPolygon.h"
#include "../include/Kbhit.h"
#include "../include/Cube.h"

using namespace std;

#define ROTATESTEP 5

int main() {
	Printer::initializePrinter();
	
	
	Point3D centerpoint(400,400,400);
	Point3D eye(400,400,1000);

	float rotateDegX = 0;
	float rotateDegY = 0;
	float rotateDegZ = 0;

	std::vector<Texture> textures;
	textures.push_back(Texture::createSingleColorTexture(255,0,0,255));
	textures.push_back(Texture::createSingleColorTexture(0,255,0,255));
	textures.push_back(Texture::createSingleColorTexture(0,0,255,255));
	textures.push_back(Texture::createSingleColorTexture(255,255,0,255));
	textures.push_back(Texture::createSingleColorTexture(255,0,255,255));
	textures.push_back(Texture::createSingleColorTexture(0,255,255,255));

	Cube cube(centerpoint,200,textures);

			Model3D hasilRotasi = cube.rotationResult(rotateDegX,centerpoint,'x');
			hasilRotasi = hasilRotasi.rotationResult(rotateDegY,centerpoint,'y');
			hasilRotasi = hasilRotasi.rotationResult(rotateDegZ,centerpoint,'z');
			Printer::drawCanvas(0,0,0,255);
			std::vector<SolidPolygon3D> orderedSolidPolygon3D = hasilRotasi.orderSolidPolygon();
			Model3D orderedModel3D(orderedSolidPolygon3D);
			orderedModel3D.draw(eye);
			Printer::printToScreen();

	bool cont = true;
	Kbhit::initTermios();
	while (cont){
		if (Kbhit::kbhit()){
			switch(Kbhit::getch()){
				case 'q':
					cont=false;
				break;
				case 'w':
					rotateDegX-=ROTATESTEP;
				break;
				case 's':
					rotateDegX+=ROTATESTEP;
				break;
				case 'a':
					rotateDegY+=ROTATESTEP;
				break;
				case 'd':
					rotateDegY-=ROTATESTEP;
				break;
				case 'z':
					rotateDegZ+=ROTATESTEP;
				break;
				case 'c':
					rotateDegZ-=ROTATESTEP;
				break;
			}
			Model3D hasilRotasi = cube.rotationResult(rotateDegX,centerpoint,'x');
			hasilRotasi = hasilRotasi.rotationResult(rotateDegY,centerpoint,'y');
			hasilRotasi = hasilRotasi.rotationResult(rotateDegZ,centerpoint,'z');
			Printer::drawCanvas(0,0,0,255);
			std::vector<SolidPolygon3D> orderedSolidPolygon3D = hasilRotasi.orderSolidPolygon();
			Model3D orderedModel3D(orderedSolidPolygon3D);
			orderedModel3D.draw(eye);
			Printer::printToScreen();
		}
	}

	Kbhit::resetTermios();

	Printer::finishPrinter();

	return 0;
}
