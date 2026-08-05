#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint32_t file_size;
    uint32_t pixel_offset;

} BMPFileHeader;


typedef struct
{
    uint32_t header_size;

    int32_t width;
    int32_t height;

    uint16_t planes;
    uint16_t bit_count;

    uint32_t compression;
    uint32_t image_size;

    int32_t x_pixels_per_meter;
    int32_t y_pixels_per_meter;

    uint32_t colors_used;
    uint32_t important_colors;

} BMPInfoHeader;


typedef struct
{
    BMPFileHeader file;
    BMPInfoHeader info;

} BMPHeader;

int create_bmp(const char *filename,int width,int height);

#endif