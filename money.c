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
    int F = -1; //Yes(1),No(0)判定用の変数定義
    int cnt;    //カウント用変数定義
    int judge_amount_of_people = 0; //入力する人数判定用変数定義
    M_class dummy = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    MEMBERS member1, member2, member3, member4, member5, member6,   //最大10人分までのMEMBERS構造体定義
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
                &member5, &member6, &member7, &member8, &member9, &member10};   //MEMBERS構造体へのポインタ
    

    do{
        printf("給料金種別計算機\n");
        printf("入力する人数を指定してください(最大10人):");
        scanf("%d", &judge_amount_of_people);

        if(judge_amount_of_people == 0){    //入力する人数が0人の場合のエラー処理
            fprintf(stderr, "入力する人数が0人なのでシステムを終了します\n");
            exit(1);
        }else if(judge_amount_of_people < 0){    //入力する人数が0人未満の場合のエラー処理
            fprintf(stderr, "入力できる人数に負の値は設定できません\n");
            exit(1);
        }else if(10 < judge_amount_of_people){    //入力する人数が10人を超えた場合のエラー処理
            fprintf(stderr, "入力できる人数の最大は10人です\n");
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
            printf("別データを入力しますか？\nYes(1),No(0)");
            scanf("%d", &F);
        }while(F!=1&&F!=0);
    }while(F==1);
    return 0;
}

void Input_data(MEMBERS *data, int len){      //データの入力を行う関数
    for(int cnt = 0;cnt < len;cnt++){
        printf("%d人目名前入力【半角100文字(全角50文字)以内、空白入力禁止:", cnt + 1);
        scanf("%s", data[cnt].name);
        printf("%d人目の名前入力完了:%s\n", cnt + 1, data[cnt].name);
        printf("%sさんの給料入力【0以上100,000,000以下】:", data[cnt].name);
        scanf("%d", &(data[cnt].salary_total));
        printf("%d人目の給料入力完了:%d\n", cnt + 1, data[cnt].salary_total);
    }
}
void Calc_data(MEMBERS data, int money){        //データの計算を行う関数
    printf("%5d円は、        %10d枚\n", money, (data.salary_total / money));
}
void Export_txtdata(MEMBERS *data, int amount_of_people){   //データをテキストに出力する関数

}
void Export_dispdata(MEMBERS *data, int amount_of_people){  //データを画面に出力する関数
    printf("給料金種内訳明細書\n");
    printf("-------------------------\n");
    for(int i = 0;i < amount_of_people;i++){
        printf("%2d人目：%sさんの給料%d円の金種内訳\n", i + 1, data->name, data->salary_total);
        for(int j = 0;j < amount_of_people;j++){
            Calc_data(data[j], MONEY[j]);
        }
    }
    
}
