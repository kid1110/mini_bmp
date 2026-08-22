#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdint.h>

int create_bmp(const char *filename,int width,int height);

int create_bmpHeader(unsigned char *header);
int create_BIOHeader(unsigned char *header, int width, int height);
unsigned char * create_pixel_data(unsigned char *header,int width, int height);
#endif