#include "bmp.h"

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
    header[0] = 'B';
    header[1] = 'M';

    header[10] = 54; // Offset to pixel data
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

    header[26] = 1; // Number of color planes
    header[28] = 24; // Bits per pixel

    fwrite(header, sizeof(header), 1, file);
    
    fclose(file);
    return 0;
}