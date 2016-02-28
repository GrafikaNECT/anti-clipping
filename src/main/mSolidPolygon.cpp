#include <iostream> 
#include <string>
#include "../include/Printer.h"
#include "../include/SolidPolygon.h"

using namespace std;

int main () {
	Printer::initializePrinter();
	Printer::drawCanvas(206,247,255,255);
	vector<SolidPolygon> islandVector;

	SolidPolygon smallIsland(Texture::createSingleColorTexture(200,4,5,255)); //TODO: GANTI WARNA
	smallIsland.push_back(50, 50);		
	smallIsland.push_back(100, 30);
	smallIsland.push_back(150, 70);
	smallIsland.push_back(50, 90);

	smallIsland.draw();
	Printer::printToScreen();

	SolidPolygon smallIsland2(Texture::createSingleColorTexture(4,200,5,255)); //TODO: GANTI WARNA
	smallIsland2.push_back(70, 70);		
	smallIsland2.push_back(80, 80);
	smallIsland2.push_back(20, 70);

	smallIsland2.draw();
	Printer::printToScreen();

	islandVector.push_back(smallIsland);
	islandVector.push_back(smallIsland2);

	return 0;
}