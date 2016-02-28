#include <iostream> 
#include <string>
#include "../include/Point.h"
#include "../include/Point3D.h"

using namespace std;

int main () {
	Point3D p;
	//Point buat kubus
	Point3D frontA,frontB,frontC,frontD;
	Point3D backA,backB,backC,backD;

	p.setXYZ(8,8,20);
	frontA.setXYZ(5,5,10);
	frontB.setXYZ(5,11,10);
	frontC.setXYZ(11,5,10);
	frontD.setXYZ(11,11,10);
	backA.setXYZ(5,5,0);
	backB.setXYZ(5,11,0);
	backC.setXYZ(11,5,0);
	backD.setXYZ(11,11,0);


	cout << frontA.projectionResult(p).getX() << "," << frontA.projectionResult(p).getY() << endl; 
	cout << frontB.projectionResult(p).getX() << "," << frontB.projectionResult(p).getY() << endl;
	cout << frontC.projectionResult(p).getX() << "," << frontC.projectionResult(p).getY() << endl;
	cout << frontD.projectionResult(p).getX() << "," << frontD.projectionResult(p).getY() << endl;

	cout << backA.projectionResult(p).getX() << "," << backA.projectionResult(p).getY() << endl; 
	cout << backB.projectionResult(p).getX() << "," << backB.projectionResult(p).getY() << endl;
	cout << backC.projectionResult(p).getX() << "," << backC.projectionResult(p).getY() << endl;
	cout << backD.projectionResult(p).getX() << "," << backD.projectionResult(p).getY() << endl;

	return 0;
}