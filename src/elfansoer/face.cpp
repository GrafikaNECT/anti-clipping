#include "face.h"
#include "polygon.h"

// Constructor
face::face(point3 _p1, point3 _p2, point3 _p3) {
	vertexes.push_back(_p1);
	vertexes.push_back(_p2);
	vertexes.push_back(_p3);
}

face::face() {
	//point3 p(0,0,0);
	//vertexes.push_back(p);
}

// Getter
point3 face::getP(int i){
	return vertexes[i];
}
int face::getSize() {
	return vertexes.size();
}

// Setter
void face::setP(int i, point3 _p) {
	vertexes[i] = _p;
}

// Member management
void face::add(point3 _p) {
	vertexes.push_back(_p);
}

	// Operations
// Move: dx, dy dz as a translation distance
void face::move(int dx, int dy, int dz) {
	int i;
	for (i=0;i<vertexes.size();i++) {
		vertexes[i].move(dx,dy,dz);
	}
}
// Scale: s as a scalar, 1 being normal size
void face::scale(float s) {
	int i;
	for (i=0;i<vertexes.size();i++) {
		vertexes[i].scale(s);
	}
}
void face::scale(float s, int cx, int cy, int cz) {
	int i;
	for (i=0;i<vertexes.size();i++) {
		vertexes[i].scale(s,cx,cy,cz);
	}
}
void face::scale(float s, point3& cp) {
	int i;
	for (i=0;i<vertexes.size();i++) {
		vertexes[i].scale(s,cp);
	}
}
// Rotate, t as angle, dir as axis
void face::rotate(float t, char dir) {
	int i;
	for (i=0;i<vertexes.size();i++) {
		vertexes[i].rotate(t,dir);
	}
}
void face::rotate(float t, char dir, int cx, int cy, int cz) {
	int i;
	for (i=0;i<vertexes.size();i++) {
		vertexes[i].rotate(t,dir,cx,cy,cz);
	}
}
void face::rotate(float t, char dir, point3& cp) {
	int i;
	for (i=0;i<vertexes.size();i++) {
		vertexes[i].rotate(t,dir,cp);
	}
}

void face::draw() {
	polygon p(0);
	point temp;
	int i;
	for (i=0;i<vertexes.size();i++) {
		temp.setX(vertexes[i].getX());
		temp.setY(vertexes[i].getY());
		p.add(temp);
	}
	p.draw();
}
