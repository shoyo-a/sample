#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(void){
    FILE *f_pt;
    char choice = 0;
    char buff[256];
    char *ptr_1, *ptr_2, *ptr_3, *ptr_4, *ptr_5;
    char* ptr[5] = {ptr_1, ptr_2, ptr_3, ptr_4, ptr_5};
    char *theme[5] = {"1. �}�C���X�g�[��", "2. �l�̖ڕW", "3. �����̓��B�ڕW�Ɨ\\����", "4. �ۑ�Ƒ΍�", "5. �����̋C�Â�"};
    for(int i = 0;i < 5;i++){
        if(i == 2){
            printf("%s\n���B�ڕW�F", theme[i]);
            scanf("%s", buff);
            ptr[i] = malloc(sizeof(buff));
            strcpy(ptr[i], buff);
            strcpy(buff, "");

            printf("�\\�����F");
            scanf("%s", buff);
            ptr[strlen(ptr[i])] = malloc(sizeof(buff));
            strcpy(ptr[strlen(ptr[i])], buff);
            strcpy(buff, "");            
        }else{
            printf("%s\n�F", theme[i]);
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
        fprintf(stderr, "�t�@�C���̃I�[�v���Ɏ��s���܂���\n");
        return -1;
    }
    printf("==========================================================\n");
    printf("TO:AAA����\n");
    printf("CC:BBB����ACCC����\n");
    printf("FM:ABCDEFGHIJKLMN���ƕ� DDD\n");
    printf("\n");
    printf("�����l�ł��BABCDEFGHIJKLMN���ƕ���DDD�ł��B\n");
    printf("�{���̍�Ɠ���ɂ��ĉ��L�ɋL�ڂ����Ă��������܂��B\n");
    printf("\n");
    for(int i = 0;i < 5;i++){
        printf("%s\n", theme[i]);
        printf("�E%s\n", ptr[i]);
    }
    printf("\n");
    printf("�ȏゲ�m�F��낵�����肢���܂��B\n");
    printf("----------------------------------------------------------\n");
    printf("abcdeg������� ABCDEFGHIJKLMN���ƕ�\n");
    printf("DDD EEE(�f�B�[�f�B�[�f�B �C�[�C�[�C�[)\n");
    printf("Phone:080-XXXX-XXXX\n");
    printf("E-mail:abcdefghi@zzz.com\n");
    printf("----------------------------------------------------------\n");
    printf("==========================================================\n");

    
    fputs("TO:AAA����\n", f_pt);
    fputs("CC:BBB����ACCC����\n", f_pt);
    fputs("FM:ABCDEFGHIJKLMN���ƕ� DDD\n", f_pt);
    fputs("\n", f_pt);
    fputs("�����l�ł��BABCDEFGHIJKLMN���ƕ���DDD�ł��B\n", f_pt);
    fputs("�{���̍�Ɠ���ɂ��ĉ��L�ɋL�ڂ����Ă��������܂��B\n", f_pt);
    fputs("\n", f_pt);
    for(int i = 0;i < 5;i++){
        fputs(theme[i], f_pt);
        fputs("\n�E", f_pt);
        fputs(ptr[i], f_pt);
        fputs("\n", f_pt);
    }
    fputs("\n", f_pt);
    fputs("�ȏゲ�m�F��낵�����肢���܂��B\n", f_pt);
    fputs("-------------------------------------------------------------\n", f_pt);
    fputs("abcdeg������� ABCDEFGHIJKLMN���ƕ�\n", f_pt);
    fputs("DDD EEE(�f�B�[�f�B�[�f�B �C�[�C�[�C�[)\n", f_pt);
    fputs("Phone:080-XXXX-XXXX\n", f_pt);
    fputs("E-mail:abcdefghi@zzz.com\n", f_pt);
    fputs("-------------------------------------------------------------\n", f_pt);

    printf("\n���[���̍쐬���������܂���");
    fclose(f_pt);
    
    return 0;
}