#ifndef POINT3_H
#define POINT3_H
/* Version:
- v1.0: Copied from point.h, added z coordinates
- v1.1: Change rotate to theta and azimuth
- v1.2: Revised rotation to axial rotation, with parameter 'dir'
- v1.3: Added transformation as new object

*/

class point3 {
	int x, y, z;
public:
	// Constructor
	point3(int _x, int _y, int _z);
	point3() {point3(0,0,0);};
	
	// Getter
	int getX();
	int getY();
	int getZ();
	
	// Setter
	void setX(int _x);
	void setY(int _y);
	void setZ(int _y);
	
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
	
	// Transformation as new object
	// Move: dx, dy dz as a translation distance
	point3 Tmove(int dx, int dy, int dz);
	// Scale: s as a scalar, 1 being normal size
	point3 Tscale(float s);
	point3 Tscale(float s, int cx, int cy, int cz);
	point3 Tscale(float s, point3& cp);
	// Rotate, t as angle, dir as axis
	point3 Trotate(float t, char dir);
	point3 Trotate(float t, char dir, int cx, int cy, int cz);
	point3 Trotate(float t, char dir, point3& cp);
	
};

#endif // POINT3_H
