#ifndef SolidPolygon3D_h
#define SolidPolygon3D_h

#include <vector>
#include "Point3D.h"
#include "Texture.h"

class SolidPolygon3D: public std::vector<Point3D>{
public:
	SolidPolygon3D(Texture t = Texture::createSingleColorTexture(0,0,0,0)):std::vector<Point3D>(){texture=t;};
	SolidPolygon3D(std::vector<Point3D>::size_type s,Texture t = Texture::createSingleColorTexture(0,0,0,0)):std::vector<Point3D>(s){texture=t;};
	SolidPolygon3D(std::vector<Point3D>& vec, Texture t = Texture::createSingleColorTexture(0,0,0,0)):std::vector<Point3D>(vec),texture(t){};

	SolidPolygon3D hasilGeser(Point3D delta);
	SolidPolygon3D hasilGeser(int deltax, int deltay, int deltaz);
	SolidPolygon3D hasilPerbesar(float scale);

	SolidPolygon3D hasilSkala(float scaleX, float scaleY, float scaleZ);
	SolidPolygon3D hasilRotasi(float deltaDegree);
	SolidPolygon3D hasilRotasi(float deltaDegree, Point3D poros);

	void push_back(int x, int y, int y); 
	void push_back(const Point3D& p){std::vector<Point3D>::push_back(p);};
private:
	Texture texture;
	
};

#endif
