#ifndef LINE_H
#define LINE_H
#include "point.h"
/* Version:
- v1.0: Only as a struct of 2 points
- v2.0: Added transformations
- v2.1: Added transformations as a new object
- v2.2: Added setter
*/


class line {
	point p1, p2;
	
public:
	// Constructor
	line(int x1, int y1, int x2, int y2);
	line(point _p1, point _p2);
	line() {line(0,0,0,0);};
	
	// Getter
	point getP1();
	point getP2();
	int getX1();
	int getY1();
	int getX2();
	int getY2();
	
	// Setter
	void setP1(point _p1);
	void setP2(point _p2);
	
	// Operations
	// Transformation
	void move(int dx, int dy);
	void scale(float s);
	void scale(float s, int x, int y);
	void scale(float s, point p);
	void rotate(float t);
	void rotate(float t, int x, int y);
	void rotate(float t, point p);
	
	line Tmove(int dx, int dy);
	line Tscale(float s);
	line Tscale(float s, int x, int y);
	line Tscale(float s, point p);
	line Trotate(float t);
	line Trotate(float t, int x, int y);
	line Trotate(float t, point p);
	
	// Graphics
	void draw();
};


#endif // LINE_H
