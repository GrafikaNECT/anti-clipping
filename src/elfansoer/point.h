#ifndef POINT_H
#define POINT_H
/* Version:
- v1.0: Only as a vector of 2 variables
- v2.0: Added transformations

*/

class point {
	int x, y;
public:
	// Constructor
	point(int _x, int _y);
	point() {point(0,0);};
	
	// Getter
	int getX();
	int getY();
	
	// Setter
	void setX(int _x);
	void setY(int _y);
	
	// Operations
	void move(int dx, int dy);
	void scale(float s);
	void scale(float s, int cx, int cy);
	void scale(float s, point& cp);
	void rotate(float t);
	void rotate(float t, int cx, int cy);
	void rotate(float t, point& cp);
};

#endif // POINT_H
