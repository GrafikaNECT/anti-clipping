#include "polygon.h"
#include "point.h"
#include "line.h"

// Constructor


// Member management
void polygon::add(int x, int y) {
	point p(x,y);
	push_back(p);
}

// Operasi dasar
// Transformasi diri
void polygon::move(int dx, int dy) {
	int i;
	for (i=0;i<std::vector<point>::size();i++) {
		(*this)[i].move(dx,dy);
	}
}
void polygon::scale(float s) {
	int i;
	for (i=0;i<std::vector<point>::size();i++) {
		(*this)[i].scale(s);
	}
}
void polygon::scale(float s, int cx, int cy) {
	int i;
	for (i=0;i<std::vector<point>::size();i++) {
		(*this)[i].scale(s,cx,cy);
	}
}
void polygon::scale(float s, point& p) {
	scale(s,p.getX(),p.getY());
}
void polygon::rotate(float t) {
	int i;
	for (i=0;i<std::vector<point>::size();i++) {
		(*this)[i].rotate(t);
	}
}
void polygon::rotate(float t, int cx, int cy) {
	int i;
	for (i=0;i<std::vector<point>::size();i++) {
		(*this)[i].rotate(t,cx,cy);
	}
}
void polygon::rotate(float t, point& p) {
	rotate(t,p.getX(),p.getY());
}

// Hasil transformasi sbg objek baru
polygon polygon::Tmove(int dx, int dy) {
	polygon retval = *this;
	retval.move(dx,dy);
	return retval;
}
polygon polygon::Tscale(float s) {
	polygon retval = *this;
	retval.scale(s);
	return retval;
}
polygon polygon::Tscale(float s, int cx, int cy) {
	polygon retval = *this;
	retval.scale(s,cx,cy);
	return retval;
}
polygon polygon::Tscale(float s, point& p) {
	polygon retval = *this;
	retval.scale(s,p);
	return retval;
}
polygon polygon::Trotate(float t) {
	polygon retval = *this;
	retval.rotate(t);
	return retval;
}
polygon polygon::Trotate(float t, int cx, int cy) {
	polygon retval = *this;
	retval.rotate(t,cx,cy);
	return retval;
}
polygon polygon::Trotate(float t, point& p) {
	polygon retval = *this;
	retval.rotate(t,p);
	return retval;
}

// Menggambar
void polygon::draw() {
	int i;
	line l;
	for(i=0;i<std::vector<point>::size()-1;i++) {
		l.setP1(at(i));
		l.setP2(at(i+1));
		l.draw();
	}
	l.setP1(at(i));
	l.setP2(at(0));
	l.draw();
}


// Helper
















