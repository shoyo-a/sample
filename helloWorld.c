#include<stdio.h>
#include<string.h>

int main(){
    char moji[] = {"HelloWorld"};
    printf("%s\n", moji);
    printf("%d\n", strlen(moji));
    printf("%c\n", moji[strlen(moji) - 1]);
}