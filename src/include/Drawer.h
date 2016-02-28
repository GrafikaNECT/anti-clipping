#ifndef DRAWER_H
#define DRAWER_H

#include "SolidPolygon.h"
	
class Drawer {
public:
	static void drawModel();

private:
	SolidPolygon transform();
	vector<SolidPolygon3D> orderSolidPolygon();

};

// Fungsi untuk orderSolidPolygon
vector<SolidPolygon3D> Model3D::orderSolidPolygon() {

}

#endif