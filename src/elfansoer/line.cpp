#include "line.h"
#include "graphics.h"

// Constructor
line::line(int _x1, int _y1, int _x2, int _y2) {
	p1.setX(_x1);
	p1.setY(_y1);
	p2.setX(_x2);
	p2.setY(_y2);
}
line::line(point _p1, point _p2) {
	p1 = _p1;
	p2 = _p2;
}

// Getter
point line::getP1() {return p1;}
point line::getP2() {return p2;}
int line::getX1() {return p1.getX();}
int line::getY1() {return p1.getY();}
int line::getX2() {return p2.getX();}
int line::getY2() {return p2.getY();}

// Setter
void line::setP1(point _p1) {
	p1 = _p1;
}
void line::setP2(point _p2) {
	p2 = _p2;
}

// Operations
void line::move(int dx, int dy) {
	p1.move(dx,dy);
	p2.move(dx,dy);
}
void line::scale(float s) {
	p1.scale(s);
	p2.scale(s);
}
void line::scale(float s, int x, int y) {
	p1.scale(s,x,y);
	p2.scale(s,x,y);
}
void line::scale(float s, point p) {
	p1.scale(s,p);
	p2.scale(s,p);
}
void line::rotate(float t) {
	p1.rotate(t);
	p2.rotate(t);
}
void line::rotate(float t, int x, int y) {
	p1.rotate(t,x,y);
	p2.rotate(t,x,y);
}
void line::rotate(float t, point p) {
	p1.rotate(t,p);
	p2.rotate(t,p);
}

line line::Tmove(int dx, int dy) {
	line retval = *this;
	retval.move(dx,dy);
	return retval;
}
line line::Tscale(float s) {
	line retval = *this;
	retval.scale(s);
	return retval;
}
line line::Tscale(float s, int x, int y) {
	line retval = *this;
	retval.scale(s,x,y);
	return retval;
}
line line::Tscale(float s, point p) {
	line retval = *this;
	retval.scale(s,p);
	return retval;
}
line line::Trotate(float t) {
	line retval = *this;
	retval.rotate(t);
	return retval;
}
line line::Trotate(float t, int x, int y) {
	line retval = *this;
	retval.rotate(t,x,y);
	return retval;
}
line line::Trotate(float t, point p) {
	line retval = *this;
	retval.rotate(t,p);
	return retval;
}
	
// Graphics
void line::draw() {
	int x1 = p1.getX();
	int y1 = p1.getY();
	int x2 = p2.getX();
	int y2 = p2.getY();
	int i,j;
	int dy = y2-y1;
	int dx = x2-x1;
	short int cx, cy, cs;
	
	if (x1==x2) {	// Vertikal
		if (y1<=y2) {
			for (i=y1;i<=y2;i++) drawPix(x1,i,255,255,255,255);
		} else {
			for (i=y2;i<=y1;i++) drawPix(x1,i,255,255,255,255);
		}
	} else if (y1==y2) {	// Horizontal
		if (x1<=x2) {
			for (i=x1;i<=x2;i++) drawPix(i,y1,255,255,255,255);
		} else {
			for (i=x2;i<=x1;i++) drawPix(i,y1,255,255,255,255);
		}
	} else {
		// Check for quadrant position of p2
		if (dy>0) {
			if (dx>0) {	// Kuadran I
				cx = 1; cy = 1; cs = 1;
			} else {	// Kuadran II
				cx = -1; cy = 1; cs = -1;
			}
		} else {
			if (dx<0) {	// Kuadran III
				cx = -1; cy = -1; cs = 1;
			} else {	// Kuadran IV
				cx = 1; cy = -1; cs = -1;
			}
		}
		i = 0;
		j = 0;
		while (cx*i<=cx*dx) {
			drawPix(x1+i,y1+j,255,255,255,255);
			while (i*dy*cs>j*dx*cs) {
				j = j+cy;
				drawPix(x1+i,y1+j,255,255,255,255);
			}
			i = i+cx;
		}
	}
}
