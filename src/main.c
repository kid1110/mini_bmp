#include<stdio.h>
#include "bmp.h"
#include "bmpinfo.h"
int main(){
    int ret = create_bmp(
        "red.bmp",
        100,
        100
    );


    if (ret != 0)
    {
        printf("create bmp failed\n");
        return 1;
    }
    printf("create bmp success\n");
    bmp_info("red.bmp");
    return 0;
}