#include<stdio.h>

int main(void){
    int i, j;
    for(i = 1;i < 10;i++){
        printf("%2d  ", i);
        for(j = 1;j < 10;j++){
            printf("%2d  ", i*j);
        }
        putchar('\n');
    }
}
