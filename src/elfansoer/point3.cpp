#include "point3.h"
#include <math.h>

// Constructor
point3::point3(int _x, int _y, int _z) {
	x = _x;
	y = _y;
	z = _z;
}

// Getter
int point3::getX() {
	return x;
}
int point3::getY() {
	return y;
}
int point3::getZ() {
	return z;
}

// Setter
void point3::setX(int _x) {
	x = _x;
}
void point3::setY(int _y) {
	y = _y;
}
void point3::setZ(int _z) {
	z = _z;
}

// Operations
void point3::move(int dx, int dy, int dz) {
	x = x + dx;
	y = y + dy;
	z = z + dz;
}
void point3::scale(float s) {
	x = (int)x*s;
	y = (int)y*s;
	z = (int)z*s;
}
void point3::scale(float s, int cx, int cy, int cz) {
	move(-cx,-cy,-cz);
	scale(s);
	move(cx,cy,cz);
}
void point3::scale(float s, point3& cp) {
	scale(s,cp.getX(),cp.getY(),cp.getZ());
}
void point3::rotate(float t, char dir) {
	int x1, y1, z1;
	if (dir=='x'||dir=='X') {
		// Rotation along x axis
		x1 = x;
		y1 = round(cos(t)*y - sin(t)*z);
		z1 = round(sin(t)*y + cos(t)*z);
	} else if (dir=='y'||dir=='Y') {
		// Rotation along y axis
		z1 = round(cos(t)*z - sin(t)*x);
		x1 = round(sin(t)*z + cos(t)*x);
		y1 = y;
	} else if (dir=='z'||dir=='Z') {
		// Rotation along z axis
		x1 = round(cos(t)*x - sin(t)*y);
		y1 = round(sin(t)*x + cos(t)*y);
		z1 = z;
	}
	x = x1;
	y = y1;
	z = z1;
}
void point3::rotate(float t, char dir, int cx, int cy, int cz) {
	move(-cx,-cy,-cz);
	rotate(t,dir);
	move(cx,cy,cz);
}

void point3::rotate(float t, char dir, point3& cp) {
	rotate(t,dir,cp.getX(),cp.getY(),cp.getZ());
}

// Transformation as a new object
point3 point3::Tmove(int dx, int dy, int dz) {
	point3 retval = *this;
	retval.move(dx,dy,dz);
	return retval;
}
point3 point3::Tscale(float s) {
	point3 retval = *this;
	retval.scale(s);
	return retval;
}
point3 point3::Tscale(float s, int cx, int cy, int cz) {
	point3 retval = *this;
	retval.scale(s,cx,cy,cz);
	return retval;
}
point3 point3::Tscale(float s, point3& cp) {
	point3 retval = *this;
	retval.scale(s,cp);
	return retval;
}
point3 point3::Trotate(float t, char dir) {
	point3 retval = *this;
	retval.rotate(t,dir);
	return retval;
}
point3 point3::Trotate(float t, char dir, int cx, int cy, int cz) {
	point3 retval = *this;
	retval.rotate(t,dir,cx,cy,cz);
	return retval;
}
point3 point3::Trotate(float t, char dir, point3& cp) {
	point3 retval = *this;
	retval.rotate(t,dir,cp);
	return retval;
}
