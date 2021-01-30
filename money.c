#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int MONEY[] = {10000, 5000, 1000, 500, 100, 50, 10, 5, 1};

typedef struct m_class{
    int A10000;
    int B5000;
    int C1000;
    int D500;
    int E100;
    int F50;
    int G10;
    int H5;
    int I1;
}M_class;

typedef struct members{
    char name[101];
    int salary_total;
}MEMBERS;

void Input_data(MEMBERS *data, int len);
void Calc_data(MEMBERS data, int money);
void Export_txtdata(MEMBERS *data, int amount_of_people);
void Export_dispdata(MEMBERS *data, int amount_of_people);

int main(void){
    int F = -1; //Yes(1),No(0)����p�̕ϐ���`
    int cnt;    //�J�E���g�p�ϐ���`
    int judge_amount_of_people = 0; //���͂���l������p�ϐ���`
    M_class dummy = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    MEMBERS member1, member2, member3, member4, member5, member6,   //�ő�10�l���܂ł�MEMBERS�\���̒�`
                             member7, member8, member9, member10;
    strcpy(member1.name, " ");
    member1.salary_total = 0;

    member2 = member3;
    member2 = member4;
    member2 = member5;
    member2 = member6;
    member2 = member7;
    member2 = member8;
    member2 = member9;
    member2 = member10;

    MEMBERS *data[10] = {&member1, &member2, &member3, &member4, 
                &member5, &member6, &member7, &member8, &member9, &member10};   //MEMBERS�\���̂ւ̃|�C���^
    

    do{
        printf("��������ʌv�Z�@\n");
        printf("���͂���l�����w�肵�Ă�������(�ő�10�l):");
        scanf("%d", &judge_amount_of_people);

        if(judge_amount_of_people == 0){    //���͂���l����0�l�̏ꍇ�̃G���[����
            fprintf(stderr, "���͂���l����0�l�Ȃ̂ŃV�X�e�����I�����܂�\n");
            exit(1);
        }else if(judge_amount_of_people < 0){    //���͂���l����0�l�����̏ꍇ�̃G���[����
            fprintf(stderr, "���͂ł���l���ɕ��̒l�͐ݒ�ł��܂���\n");
            exit(1);
        }else if(10 < judge_amount_of_people){    //���͂���l����10�l�𒴂����ꍇ�̃G���[����
            fprintf(stderr, "���͂ł���l���̍ő��10�l�ł�\n");
            exit(1);
        }

        int amount_of_people[judge_amount_of_people];
        for(cnt = 0;cnt < judge_amount_of_people;cnt++){
            int content = cnt + 1;
            amount_of_people[cnt] = content;
        }

        Input_data(*data, judge_amount_of_people);
        Export_dispdata(*data, judge_amount_of_people);
        
        do{
            printf("�ʃf�[�^����͂��܂����H\nYes(1),No(0)");
            scanf("%d", &F);
        }while(F!=1&&F!=0);
    }while(F==1);
    return 0;
}

void Input_data(MEMBERS *data, int len){      //�f�[�^�̓��͂��s���֐�
    for(int cnt = 0;cnt < len;cnt++){
        printf("%d�l�ږ��O���́y���p100����(�S�p50����)�ȓ��A�󔒓��͋֎~:", cnt + 1);
        scanf("%s", data[cnt].name);
        printf("%d�l�ڂ̖��O���͊���:%s\n", cnt + 1, data[cnt].name);
        printf("%s����̋������́y0�ȏ�100,000,000�ȉ��z:", data[cnt].name);
        scanf("%d", &(data[cnt].salary_total));
        printf("%d�l�ڂ̋������͊���:%d\n", cnt + 1, data[cnt].salary_total);
    }
}
void Calc_data(MEMBERS data, int money){        //�f�[�^�̌v�Z���s���֐�
    printf("%5d�~�́A        %10d��\n", money, (data.salary_total / money));
}
void Export_txtdata(MEMBERS *data, int amount_of_people){   //�f�[�^���e�L�X�g�ɏo�͂���֐�

}
void Export_dispdata(MEMBERS *data, int amount_of_people){  //�f�[�^����ʂɏo�͂���֐�
    printf("����������󖾍׏�\n");
    printf("-------------------------\n");
    for(int i = 0;i < amount_of_people;i++){
        printf("%2d�l�ځF%s����̋���%d�~�̋������\n", i + 1, data->name, data->salary_total);
        for(int j = 0;j < amount_of_people;j++){
            Calc_data(data[j], MONEY[j]);
        }
    }
    
}
