#include<stdio.h>
#include "bmp.h"
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

    return 0;
}