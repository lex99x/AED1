#include <time.h>
#include <stdio.h>

int timing(int dias2000, int hora, int min, int seg){

    return dias2000 * 86400 + hora * 3600 + min * 60 + seg;

}

int emdiasdesde2000(int ano, int mes, int dia){

	int ano2000=2000, mes01=1, dia01=1;

    struct tm dt1 = (struct tm){.tm_year=ano-1900, .tm_mon=mes-1, .tm_mday=dia};
    time_t tempo1 = mktime(&dt1);

    struct tm dt2 = (struct tm){.tm_year=ano2000-1900, .tm_mon=mes01-1, .tm_mday=dia01};
    time_t tempo2 = mktime(&dt2);

    double seconds = difftime(tempo1, tempo2);

    seconds = (seconds<0?seconds*-1:seconds);

    return seconds/(24*60*60);

}

void printn(int ano, int mes, int dia, int hora, int min, int seg){

    printf("%d-", ano);
    mes < 10 ? printf("0%d-", mes) : printf("%d-", mes);
    dia < 10 ? printf("0%d ", dia) : printf("%d ", dia);
    hora < 10 ? printf("0%d:", hora) : printf("%d:", hora);
    min < 10 ? printf("0%d:", min) : printf("%d:", min);
    seg < 10 ? printf("0%d\n", seg) : printf("%d\n", seg);

}

int main(){

    int ano, mes, dia, hora, min, seg;
    int mAno, mMes, mDia, mHora, mMin, mSeg;
    int mAno2, mMes2, mDia2, mHora2, mMin2, mSeg2;
    int data, dataM, dataM2;
    short int empty = 0;

    for(int i = 1; empty != 1; i++){

        scanf("%d-%d-%d   %d:%d:%d", &ano, &mes, &dia, &hora, &min, &seg);

        mAno = ano; mMes = mes; mDia = dia; mHora = hora; mMin = min; mSeg = seg;
        mAno2 = ano; mMes2 = mes; mDia2 = dia; mHora2 = hora; mMin2 = min; mSeg2 = seg;

        if(ano != 0){

            while(ano != 0){

                scanf("%d-%d-%d   %d:%d:%d", &ano, &mes, &dia, &hora, &min, &seg);

                if(ano == 0){

                    printf("Ninhada:%d\n", i);
                    printn(mAno, mMes, mDia, mHora, mMin, mSeg);
                    printn(mAno2, mMes2, mDia2, mHora2, mMin2, mSeg2);

                }else{

                    data = timing(emdiasdesde2000(ano, mes, dia), hora, min, seg);
                    dataM = timing(emdiasdesde2000(mAno, mMes, mDia), mHora, mMin, mSeg);
                    dataM2 = timing(emdiasdesde2000(mAno2, mMes2, mDia2), mHora2, mMin2, mSeg2);

                    if(data < dataM){

                        mAno2 = mAno; mMes2 = mMes; mDia2 = mDia; mHora2 = mHora; mMin2 = mMin; mSeg2 = mSeg;
                        mAno = ano; mMes = mes; mDia = dia; mHora = hora; mMin = min; mSeg = seg;

                    }

                    if(data < dataM2 && data > dataM){

                        mAno2 = ano; mMes2 = mes; mDia2 = dia; mHora2 = hora; mMin2 = min; mSeg2 = seg;

                    }

                }

            }

        }else{

            empty = 1;

        }

    }

}