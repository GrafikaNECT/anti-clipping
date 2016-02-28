#include <algorithm>
#include <iostream> 
#include <string>
#include "../include/SolidPolygon3D.h"

using namespace std;

vector<SolidPolygon3D> orderSolidPolygon(vector<SolidPolygon3D> val) {
	cout << "Sorting " << endl;
	for(int i=0; i<3; i++) {
		cout << "First: " << val.at(i).at(0).getZ() << endl;
	}
	std::sort( val.begin(), val.end() );
	cout << "Sorted " << endl;
	for(int i=0; i<3; i++) {
		cout << "First: " << val.at(i).at(0).getZ() << endl;
	}
	return val;
}

int main () {
	vector<SolidPolygon3D> listOfSolidPolygon3D;
	SolidPolygon3D poly1(Texture::createSingleColorTexture(200,4,5,255)); //TODO: GANTI WARNA
	poly1.push_back(50, 50, 10);		
	poly1.push_back(100, 30, 10);
	poly1.push_back(150, 70, 10);
	poly1.push_back(50, 90, 10);

	SolidPolygon3D poly2(Texture::createSingleColorTexture(200,4,5,255)); //TODO: GANTI WARNA
	poly2.push_back(50, 50, 5);		
	poly2.push_back(100, 30, 5);
	poly2.push_back(150, 70, 5);
	poly2.push_back(50, 90, 5);

	SolidPolygon3D poly3(Texture::createSingleColorTexture(200,4,5,255)); //TODO: GANTI WARNA
	poly3.push_back(50, 50, 15);		
	poly3.push_back(100, 30, 15);
	poly3.push_back(150, 70, 15);
	poly3.push_back(50, 90, 15);

	listOfSolidPolygon3D.push_back(poly1);
	listOfSolidPolygon3D.push_back(poly2);
	listOfSolidPolygon3D.push_back(poly3);

	vector<SolidPolygon3D> retval = orderSolidPolygon(listOfSolidPolygon3D);


	for(int i=0; i<3; i++) {
		cout << "First: " << listOfSolidPolygon3D.at(i).at(0).getZ() << endl;
	}

	cout << "Odered" << endl;

cout << "RETVAL SIZE: " << retval.size() << endl;
	for(int i=0; i<3; i++) {
		cout << "First: " << retval.at(i).at(0).getZ() << endl;
	}

	return 0;
}