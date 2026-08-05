#include <stdio.h>
#include "bmpinfo.h"

void write_uint32_le(unsigned char *buf,uint32_t value){
    buf[0] = value & 0xFF;
    buf[1] = (value >> 8) & 0xFF;
    buf[2] = (value >> 16) & 0xFF;
    buf[3] = (value >> 24) & 0xFF;

}


uint32_t read_uint32_le(const unsigned char * buf){
    return (uint32_t)buf[0] | (uint32_t)buf[1] << 8 | (uint32_t)buf[2] << 16 | (uint32_t)buf[3] << 24;

}

void write_uint16_le(unsigned char *buf,uint16_t value){
    buf[0] = value & 0xFF;
    buf[1] = (value >> 8) & 0xFF;
}

uint16_t read_uint16_le(const unsigned char * buf){
    return (uint16_t)buf[0] | (uint16_t)buf[1] << 8;
}


int bmp_info(const char *filename){
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    unsigned char header[54];
    int fread_ret = fread(header, sizeof(header),1, file);
    if (fread_ret != 1) {
        perror("fread");
        fclose(file);
        return 1;
    }
    print_bmp_file(header);
    print_bmp_header(header);
    fclose(file);
    return 0;
}

void print_bmp_file(const unsigned char *header) {
    
    printf("BMP FILE HEADER\n");
    printf("============================\n");
    if(header[0] == 'B' && header[1] == 'M') {
        printf("Signature   : BM\n");
    } else {
        printf("Magic Number: Invalid\n");
        return;
    }
    printf("File Size   : %u\n", read_uint32_le(&header[2]));
    printf("Pixel Offset: %u\n", read_uint32_le(&header[10]));
    printf("Width       : %u\n", read_uint32_le(&header[18]));
    printf("Height      : %u\n", read_uint32_le(&header[22]));
    printf("\n");
}


/** 
 * 
 * 
 * Header Size     : 40
Width           : 100
Height          : 100
Planes          : 1
Bit Count       : 24
Compression     : 0
Image Size      : 0
XPelsPerMeter   : 0
YPelsPerMeter   : 0
Colors Used     : 0
Important Colors: 0
*/
void print_bmp_header(const unsigned char *header) {
    printf("BMP INFO HEADER\n");
    printf("============================\n");
    printf("HEADER SIZE: %u\n", read_uint32_le(&header[14]));
    printf("WIDTH      : %u\n", read_uint32_le(&header[18]));
    printf("HEIGHT     : %u\n", read_uint32_le(&header[22]));
    printf("PLANES     : %u\n", read_uint16_le(&header[26]));
    printf("BITSCOUNT : %u\n", read_uint16_le(&header[28]));
    printf("COMPRESSION: %u\n", read_uint32_le(&header[30]));
    printf("IMAGESIZE  : %u\n", read_uint32_le(&header[34]));
    printf("XPelsPerMeter: %u\n", read_uint32_le(&header[38]));
    printf("YPelsPerMeter: %u\n", read_uint32_le(&header[42]));
    printf("COLORSUSED : %u\n", read_uint32_le(&header[46]));
    printf("IMPORTANTCOLORS: %u\n", read_uint32_le(&header[50]));
}