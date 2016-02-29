#ifndef FACE_H
#define FACE_H
#include "point3.h"
#include <vector>
/* Version:
- 1.0: Using vector, try for member management.
- 1.1: Added transformation
- 2.0: Added draw, includes polygon.h

*/

class face {
std::vector<point3> vertexes;
public:
	// Constructor
	face(point3 _p1, point3 _p2, point3 _p3);
	face();
	
	// Getter
	point3 getP(int i);
	int getSize();
	
	// Setter
	void setP(int i, point3 _p);
	
	// Member management
	void add(point3 _p);
	
	// Operations
	// Move: dx, dy dz as a translation distance
	void move(int dx, int dy, int dz);
	// Scale: s as a scalar, 1 being normal size
	void scale(float s);
	void scale(float s, int cx, int cy, int cz);
	void scale(float s, point3& cp);
	// Rotate, t as angle, dir as axis
	void rotate(float t, char dir);
	void rotate(float t, char dir, int cx, int cy, int cz);
	void rotate(float t, char dir, point3& cp);
	
	// Graphics related
	void draw();
};

#endif // FACE_H
