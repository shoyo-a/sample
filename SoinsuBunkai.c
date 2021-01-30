#include<stdio.h>

int main(){
    int data = 0;

    printf("input a data ...");
    scanf("%d", &data);

    printf("%d = 1 ", data);
    for(int i = 2;i <= data;){
        if(data % i == 0){
            printf(" * %d", i);
            data /= i;
        }else{
            i++;
        }
    }
}