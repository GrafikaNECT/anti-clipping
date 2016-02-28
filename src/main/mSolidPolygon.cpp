#include <iostream> 
#include <string>
#include "../include/Printer.h"
#include "../include/SolidPolygon.h"

using namespace std;

int main () {
	Printer::initializePrinter();
	Printer::drawCanvas(206,247,255,255);

	SolidPolygon smallIsland(Texture::createSingleColorTexture(200,4,5,255)); //TODO: GANTI WARNA
	smallIsland.push_back(50, 50);		
	smallIsland.push_back(100, 30);
	smallIsland.push_back(150, 70);
	smallIsland.push_back(50, 90);

	smallIsland.draw();
	Printer::printToScreen();

	return 0;
}