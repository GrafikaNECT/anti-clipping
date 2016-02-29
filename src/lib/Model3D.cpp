#include "../include/Model3D.h"
#include <algorithm>

void Model3D::rotate(float deltaDegree, char axis) {

}

void Model3D::rotate(float deltaDegree, Point3D poros, char axis) {

}


Model3D Model3D::rotationResult(float deltaDegree, char axis){
	Model3D retval=*this;
	for (int i=0;i<std::vector<SolidPolygon3D>::size();i++){
		const SolidPolygon3D& s = at(i);
		retval[i]=s.rotationResult(deltaDegree, axis);
	}
	return retval;
}

Model3D Model3D::rotationResult(float deltaDegree, Point3D poros, char axis){
	Model3D retval=*this;
	for (int i=0;i<std::vector<SolidPolygon3D>::size();i++){
		const SolidPolygon3D& s = at(i);
		retval[i]=s.rotationResult(deltaDegree, poros, axis);
	}
	return retval;
}

std::vector<SolidPolygon3D> Model3D::orderSolidPolygon() {
	std::vector<SolidPolygon3D> retval = *this;
	std::sort( retval.begin(), retval.end() );
	return retval;
}

std::vector<SolidPolygon> Model3D::projectionResult(Point3D eye) {
	std::vector<SolidPolygon> model2D;
	for (std::vector<SolidPolygon3D>::iterator it = this->begin(); it!=this->end(); it++) {
		model2D.push_back(it->projectionResult(eye));		
	}
	return model2D;
}

void Model3D::draw(Point3D eye){
	//Painter algorithm
	orderSolidPolygon();
	std::vector<SolidPolygon> model2D = projectionResult(eye);
	for (std::vector<SolidPolygon>::iterator it = model2D.begin(); it!=model2D.end(); it++) {
		it->draw();		
	}
}
