#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(void){
    FILE *f_pt;
    char choice = 0;
    char buff[256];
    char *ptr_1, *ptr_2, *ptr_3, *ptr_4, *ptr_5;
    char* ptr[5] = {ptr_1, ptr_2, ptr_3, ptr_4, ptr_5};
    char *theme[5] = {"1. マイルストーン", "2. 個人の目標", "3. 今日の到達目標と予\実差", "4. 課題と対策", "5. 今日の気づき"};
    for(int i = 0;i < 5;i++){
        if(i == 2){
            printf("%s\n到達目標：", theme[i]);
            scanf("%s", buff);
            ptr[i] = malloc(sizeof(buff));
            strcpy(ptr[i], buff);
            strcpy(buff, "");

            printf("予\実差：");
            scanf("%s", buff);
            ptr[strlen(ptr[i])] = malloc(sizeof(buff));
            strcpy(ptr[strlen(ptr[i])], buff);
            strcpy(buff, "");            
        }else{
            printf("%s\n：", theme[i]);
            scanf("%s", buff);
            ptr[i] = malloc(sizeof(buff));
            strcpy(ptr[i], buff);
            strcpy(buff, "");
        }
    }
    for(int i = 0;i < 5;i++){
        printf("%s\n", ptr[i]);
    }
    
    f_pt = fopen("outlook.txt", "a");
    if(f_pt == NULL){
        fprintf(stderr, "ファイルのオープンに失敗しました\n");
        return -1;
    }
    printf("==========================================================\n");
    printf("TO:AAAさん\n");
    printf("CC:BBBさん、CCCさん\n");
    printf("FM:ABCDEFGHIJKLMN事業部 DDD\n");
    printf("\n");
    printf("お疲れ様です。ABCDEFGHIJKLMN事業部のDDDです。\n");
    printf("本日の作業日報について下記に記載させていただきます。\n");
    printf("\n");
    for(int i = 0;i < 5;i++){
        printf("%s\n", theme[i]);
        printf("・%s\n", ptr[i]);
    }
    printf("\n");
    printf("以上ご確認よろしくお願いします。\n");
    printf("----------------------------------------------------------\n");
    printf("abcdeg株式会社 ABCDEFGHIJKLMN事業部\n");
    printf("DDD EEE(ディーディーディ イーイーイー)\n");
    printf("Phone:080-XXXX-XXXX\n");
    printf("E-mail:abcdefghi@zzz.com\n");
    printf("----------------------------------------------------------\n");
    printf("==========================================================\n");

    
    fputs("TO:AAAさん\n", f_pt);
    fputs("CC:BBBさん、CCCさん\n", f_pt);
    fputs("FM:ABCDEFGHIJKLMN事業部 DDD\n", f_pt);
    fputs("\n", f_pt);
    fputs("お疲れ様です。ABCDEFGHIJKLMN事業部のDDDです。\n", f_pt);
    fputs("本日の作業日報について下記に記載させていただきます。\n", f_pt);
    fputs("\n", f_pt);
    for(int i = 0;i < 5;i++){
        fputs(theme[i], f_pt);
        fputs("\n・", f_pt);
        fputs(ptr[i], f_pt);
        fputs("\n", f_pt);
    }
    fputs("\n", f_pt);
    fputs("以上ご確認よろしくお願いします。\n", f_pt);
    fputs("-------------------------------------------------------------\n", f_pt);
    fputs("abcdeg株式会社 ABCDEFGHIJKLMN事業部\n", f_pt);
    fputs("DDD EEE(ディーディーディ イーイーイー)\n", f_pt);
    fputs("Phone:080-XXXX-XXXX\n", f_pt);
    fputs("E-mail:abcdefghi@zzz.com\n", f_pt);
    fputs("-------------------------------------------------------------\n", f_pt);

    printf("\nメールの作成が完了しました");
    fclose(f_pt);
    
    return 0;
}