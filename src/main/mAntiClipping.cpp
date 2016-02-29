#include <iostream>
#include <string>
#include "../include/Printer.h"
#include "../include/SolidPolygon.h"
#include "../include/Kbhit.h"
#include "../include/Cube.h"

using namespace std;

#define ROTATESTEP 5

Model3D createDemoModel(){
	vector<SolidPolygon3D> retval;

	Point3D centerpoint1(400,400,400);
	Point3D centerpoint2(400,800,800);
	Point3D centerpoint3(400,800,400);
	Point3D centerpoint4(800,400,800);
	Point3D centerpoint5(800,800,800);
	Point3D centerpoint6(400,400,800);
	Point3D centerpoint7(800,400,400);
	Point3D centerpoint8(800,800,400);

	std::vector<Texture> textures;
	textures.push_back(Texture::createSingleColorTexture(255,0,0,255));
	textures.push_back(Texture::createSingleColorTexture(0,255,0,255));
	textures.push_back(Texture::createSingleColorTexture(0,0,255,255));
	textures.push_back(Texture::createSingleColorTexture(255,255,0,255));
	textures.push_back(Texture::createSingleColorTexture(255,0,255,255));
	textures.push_back(Texture::createSingleColorTexture(0,255,255,255));

	Cube cube1(centerpoint1,200,textures);
	Cube cube2(centerpoint2,200,textures);
	Cube cube3(centerpoint3,200,textures);
	Cube cube4(centerpoint4,200,textures);
	Cube cube5(centerpoint5,200,textures);
	Cube cube6(centerpoint6,200,textures);
	Cube cube7(centerpoint7,200,textures);
	Cube cube8(centerpoint8,200,textures);

	for (int i=0;i<cube1.size();i++)
		retval.push_back(cube1[i]);
	for (int i=0;i<cube2.size();i++)
		retval.push_back(cube2[i]);
	for (int i=0;i<cube3.size();i++)
		retval.push_back(cube3[i]);
	for (int i=0;i<cube4.size();i++)
		retval.push_back(cube4[i]);
	for (int i=0;i<cube5.size();i++)
		retval.push_back(cube5[i]);
	for (int i=0;i<cube6.size();i++)
		retval.push_back(cube6[i]);
	for (int i=0;i<cube7.size();i++)
		retval.push_back(cube7[i]);
	for (int i=0;i<cube8.size();i++)
		retval.push_back(cube8[i]);

	return Model3D(retval);
}

int main() {
	Printer::initializePrinter();
	
	
	Point3D centerpoint(600,600,600);
	Point3D eye(400,400,1000);

	float rotateDegX = 0;
	float rotateDegY = 0;
	float rotateDegZ = 0;

	Model3D model = createDemoModel();

			Model3D hasilRotasi = model.rotationResult(rotateDegX,centerpoint,'x');
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
			Model3D hasilRotasi = model.rotationResult(rotateDegX,centerpoint,'x');
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
