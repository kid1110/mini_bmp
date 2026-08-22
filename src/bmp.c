#include "bmp.h"
#include <stdlib.h>
#include<string.h>
int create_bmp(const char *filename,int width,int height){
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }
    unsigned char header[54];
    memset(header, 0, sizeof(header));
    //Header magic
    create_bmpHeader(header);
    create_BIOHeader(header, width, height);
    unsigned char *pixel_data = create_pixel_data(header, width, height);
    fwrite(header, sizeof(header), 1, file);
    fwrite(pixel_data, sizeof(unsigned char), (header[28] * width + 31) / 32 * 4 * height, file);
    free(pixel_data);
    fclose(file);
    return 0;
}
int create_bmpHeader(unsigned char *header){
    //Windows 3.1x, 95, NT, ... etc
    header[0] = 'B';
    header[1] = 'M';
    header[10] = 54; // Offset to pixel data
    return 0;
}

int create_BIOHeader(unsigned char *header, int width, int height){
    header[14] = 40; // DIB header size
    //pixel width and height
    header[18] = width & 0xFF;
    header[19] = (width >> 8) & 0xFF;
    header[20] = (width >> 16) & 0xFF;
    header[21] = (width >> 24) & 0xFF;
    header[22] = height & 0xFF;
    header[23] = (height >> 8) & 0xFF;
    header[24] = (height >> 16) & 0xFF;
    header[25] = (height >> 24) & 0xFF;
    // default BI_RGB compression
    header[26] = 1; // Number of color planes
    header[28] = 24; // Bits per pixel
    return 0;
}


unsigned char * create_pixel_data(unsigned char *header,int width, int height){
    unsigned char bit_dep = header[28];
    //cal data size
    int row_size = ((bit_dep * width + 31) / 32) * 4;
    //use array to store pixel data
    unsigned char *pixel_data = (unsigned char *)malloc(row_size * height);
    memset(pixel_data, 0, row_size * height);
    // Initialize pixel data (example: set all pixels to red)
    for(int y = height -1; y >= 0; y--){
        for(int x = 0; x < width; x++){
            int pixel_index = y * row_size + x * 3;
            pixel_data[pixel_index] = 255;     // Blue
            pixel_data[pixel_index + 1] = 0; // Green
            pixel_data[pixel_index + 2] = 0; // Red
        }
    }
    return pixel_data;
}