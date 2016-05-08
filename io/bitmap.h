//
// bitmap.h
//
// header file for MS bitmap format
//
// Yuck -- Eugene

#ifndef BITMAP_H
#define BITMAP_H

// global I/O routines
extern unsigned char *readBMP(const char *fname, int& width, int& height);
extern bool writeBMP(const char *iname, int width, int height, const unsigned char *data); 

#endif

