#include "../include/SolidPolygon3D.h"
#include "../include/Line.h"
#include "../include/Printer.h" 

#include <algorithm>

void SolidPolygon3D::push_back(int x, int y, int z){
	Point3D p(x,y,z);
	push_back(p);
}

SolidPolygon3D SolidPolygon3D::hasilGeser(Point3D delta){
	return hasilGeser(delta.getX(), delta.getY(), delta.getZ());
}

SolidPolygon3D SolidPolygon3D::hasilGeser(int deltax, int deltay, int deltaz){
	SolidPolygon3D retval = *this;
	for (int i=0;i<std::vector<Point3D>::size();i++){
		retval[i].scale(deltax,deltay,deltaz);
	}
	return retval;
}
SolidPolygon3D SolidPolygon3D::hasilPerbesar(float scale){
	SolidPolygon3D retval = *this;
	for (int i=0;i<std::vector<Point3D>::size();i++){
		Point3D& p = retval[i];
		p.setX(p.getX()*scale);
		p.setY(p.getY()*scale);
		p.setZ(p.getZ()*scale);
	}
	return retval;
}

SolidPolygon3D SolidPolygon3D::hasilSkala(float scaleX, float scaleY, float scaleZ){
	SolidPolygon3D retval = *this;
	for (int i=0;i<std::vector<Point3D>::size();i++){
		Point3D& p = retval[i];
		p.setX(p.getX()*scaleX);
		p.setY(p.getY()*scaleY);
		p.setZ(p.getZ()*scaleZ);
	}
	return retval;
}

SolidPolygon3D SolidPolygon3D::hasilRotasi(float deltaDegree){
	SolidPolygon3D retval(std::vector<Point3D>::size(),texture);
	for (int i=0;i<std::vector<Point3D>::size();i++){
		const Point3D& p = at(i);
		retval[i]=p.hasilRotasi(deltaDegree);
	}
	return retval;	
}

// TODO: ROTASI
SolidPolygon3D SolidPolygon3D::hasilRotasi(float deltaDegree, Point3D poros){
	SolidPolygon3D tmp1 = hasilGeser(poros.hasilMirror00());
	SolidPolygon3D tmp2 = tmp1.hasilRotasi(deltaDegree);
	return tmp2.hasilGeser(poros);
}