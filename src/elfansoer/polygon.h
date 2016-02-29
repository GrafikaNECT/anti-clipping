#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "point.h"
/* Version:
- v1.0: Only as a collection of points with transformations and line-draw
*/

class polygon: public std::vector<point> {
public:
	// Constructor
	polygon():std::vector<point>(){};
	polygon(std::vector<point>::size_type s):std::vector<point>(s){};
	
	// Member Management
	void add(int x, int y);
	void add(const point& p) {std::vector<point>::push_back(p);};
	
	// Operasi dasar
	void move(int dx, int dy);
	void scale(float s);
	void scale(float s, int cx, int cy);
	void scale(float s, point& p);
	void rotate(float t);
	void rotate(float t, int cx, int cy);
	void rotate(float t, point& p);
	
	polygon Tmove(int dx, int dy);
	polygon Tscale(float s);
	polygon Tscale(float s, int cx, int cy);
	polygon Tscale(float s, point& p);
	polygon Trotate(float t);
	polygon Trotate(float t, int cx, int cy);
	polygon Trotate(float t, point& p);
	
	
	void draw();
	
private:
};

#endif // POLYGON_H
