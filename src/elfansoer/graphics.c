#include "graphics.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

// Variabel Global
    int fbfd = 0; // FrameBufferFrameDevice, integer for statuses.
    struct fb_var_screeninfo vinfo; // Variable data
    struct fb_fix_screeninfo finfo; // Fixed data
    long int screensize = 0;  // Screen size in bytes
    char *fbp = 0; // Frame Buffer Pointer (Address Cursor)
    long int location = 0; // Real Cursor
    char * workspace = NULL;

// Getter
int getXRes() {
    return vinfo.xres;
}
int getYRes() {
    return vinfo.yres;
}

// Operasi-operasi mesin
int initializeGraphics() {
    //1. Open the framebuffer file
    fbfd = open("/dev/fb0",O_RDWR);
    if (fbfd == -1) {
        perror("Error: Cannot open framebuffer device");
        return 1;
    }
    printf("The framebuffer was opened successfully.\n");

    //2. Read fixed screen-information
    if (ioctl(fbfd,FBIOGET_FSCREENINFO,&finfo) == -1) {
        perror("Error: Cannot load fixed information");
        return 2;
    }

    //3. Read variable screen-information
    if (ioctl(fbfd,FBIOGET_VSCREENINFO,&vinfo) == -1) {
        perror("Error: Cannot load variable information");
        return 3;
    }

    //4. Print screen-info
    printf("Screen size: %dX%d, with %dbpp\n",vinfo.xres,vinfo.yres,vinfo.bits_per_pixel);

    //5. Read screen size
    screensize = finfo.smem_len;

    //6. Map the device framebuffer to memory
    fbp = (char*) mmap(0, screensize, PROT_READ|PROT_WRITE, MAP_SHARED, fbfd, 0);
    if (fbp == (void*) -1) {
        perror("Error: Cannot map the framebuffer device into memory");
        return 4;
    }
    printf("The framebuffer device was mapped to memory successfully.\n");
    printf("%d",vinfo.xres*vinfo.yoffset);

    //7. Create a workspace
    workspace = (char*)malloc(screensize);

    return 0;
}

int finalizeGraphics() {
    if (workspace) free(workspace); // What is this?
    if (fbp) munmap(fbp,screensize); // Something to do with unmapping
    if (fbfd) close(fbfd); // Close file
}
void printToScreen() {
	memcpy(fbp,workspace,screensize);
}	

// Operasi-operasi dasar
void setColor(unsigned char R, unsigned char G, unsigned char B, unsigned char A) {
    if (vinfo.bits_per_pixel == 32) {
        // 32 bit: 8-bit of Blue, 8-bit of Green, 8-bit of Red, 8-bit of Alpha
        // *fbp: pixel at (0,0)
        // location: (X,Y) offset from fbp
        // + i : (bit offset from location. char is a 8-bit type)
        *(workspace + location) = B;
        *(workspace + location + 1) = G;
        *(workspace + location + 2) = R;
        *(workspace + location + 3) = A;

    } else  {
        // Assume it is 16bpp = short int.
        // r, g, b is 5-bit long
        // t = rrrrr0gggggbbbbb
        int b = B/8;
        int g = G/8;
        int r = R/8;
        unsigned short int t = r<<11 | g << 5 | b;
        *((unsigned short int*)(workspace + location)) = t;
    }
}

void drawPix(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A){
	// Check if it is within screen boundary
	if (x>=0 && y>=0 && x<getXRes() && y<getYRes()){
	    // (xoffset,yoffset) is the (0,0) pixel
        // location is an array of Y (size: line_length);
        // Y is an array of X (size: bit-per-pixel);
        // X is an array of 4x8-bit char;
		location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
		           (y+vinfo.yoffset) * finfo.line_length;
		setColor(R,G,B,A);
	}
}

void drawRectangle(int x1, int y1, int x2, int y2, unsigned char R, unsigned char G, unsigned char B, unsigned char A) {
    int i,j;
    // Check if it is within boundary
    if (x1<0) x1 = 0;
    if (y1<0) y1 = 0;
    for (i=0; i<=y2-y1 && y1+i<getYRes(); i++) {
        for (j=0; j<=x2-x1 && x1+j<getXRes();j++) {
            location = (vinfo.yoffset+y1+i) * finfo.line_length
                     + (vinfo.xoffset+x1+j) * (vinfo.bits_per_pixel/8);
            setColor(R,G,B,A);
        }
    }
}

void drawCanvas(unsigned char R, unsigned char G, unsigned char B, unsigned char A) {
    drawRectangle(0,0,vinfo.xres,vinfo.yres,R,G,B,A);
}
