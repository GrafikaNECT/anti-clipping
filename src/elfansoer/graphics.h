#ifndef GRAPHICS_H
#define GRAPHICS_H

// Getter
int getXRes();
int getYRes();

// Machine Operations
int initializeGraphics();
int finalizeGraphics();
void printToScreen();

// Basic Programs
void setColor(unsigned char R, unsigned char G, unsigned char B, unsigned char A);

void drawPix(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A);

void drawRectangle(int x1, int y1, int x2, int y2, unsigned char R, unsigned char G, unsigned char B, unsigned char A);

void drawCanvas(unsigned char R, unsigned char G, unsigned char B, unsigned char A);

#endif // GRAPHICS_H
