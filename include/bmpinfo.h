#ifndef BMPINFO_H
#define BMPINFO_H

#include <stdint.h>

void write_uint32_le(unsigned char *buf,uint32_t value);

uint32_t read_uint32_le(const unsigned char * buf);
int bmp_info(const char *filename);
void print_bmp_file(const unsigned char *header);
void print_bmp_header(const unsigned char *header);
void write_uint16_le(unsigned char *buf,uint16_t value);
uint16_t read_uint16_le(const unsigned char * buf);
#endif