#include <stdio.h>
#include <windows.h>
#include <conio.h>

int menu();
int menu1();
int menu2();
int menu3();
void gotoxy();

int main(){
    int pilihan = menu();
    if (pilihan == 1){
        menu1();
        system("pause");
        main();
    }
    else if (pilihan == 2){
        menu2();
        system("pause");
        main();
    }
    else if (pilihan == 3){
        menu3();
        system("pause");
        main();
    }
    else{
        system("exit");
    }
}

int menu(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0,0);
        printf("===============");
        gotoxy(0,1);
        printf("Tugas Quiz ASD");
        gotoxy(0,2);
        printf("===============");
        gotoxy(5,3);
        printf("1. level 1");
        gotoxy(5,4);
        printf("2. level 2");
        gotoxy(5,5);
        printf("3. level 3");
        gotoxy(5,6);
        printf("4. exit");
        gotoxy(0, pos_y);
        printf("==>");
        int key = getch();
        if  (key == 72){
            pos_y--;
        }
        else if (key == 80){
            pos_y++;
        }
        else if (key == 13){
            return pos_y - 2;
        }
        if (pos_y == 7){
            pos_y = 3;
        }
        else if (pos_y == 2){
            pos_y = 6;
        }
    }
}

int menu1(){
    int ukuran;
    int j = 0;
    system("cls");
    printf("masukkan ukuran: ");
    scanf("%i", &ukuran);
    system("cls");
    for (int i = 1; i <= ukuran; i++){
        for (int k = 0; k < i; k++){
            j = i - 1 + k;
            if (j < 10){
                printf("%i  ",j);
            }
            else{
                printf("%i ",j);
            }
            j++;
        }
        printf("\n");
    }
}

int menu2(){
    int ukuran, j;
    int l = 1;
    system("cls");
    printf("masukkan ukuran: ");
    scanf("%i", &ukuran);
    system("cls");
    for (int i = 1; i <= ukuran; i++){
        for (int k = 0; k < i; k++){
            j = i * (k + 1);
            if (j < 10){
                printf("%i  ",j);
            }
            else{
                printf("%i ",j);
            }
        }
        printf("\n");
    }
}

int menu3(){
    int tinggi;
    int l = 1;
    system("cls");
    printf("masukkan setengah tinggi: ");
    scanf("%i", &tinggi);
    system("cls");
    for (int j = 1; j < tinggi; j++){
        for (int i = 1; i < tinggi - j; i++){
            printf(" ");
        }
        for (int i = tinggi - j; i < tinggi; i++){
            printf("%i", l);
            l++;
        }
        l= 1;
        int k = j-1;
        for (int i = 0; i< j - 1; i++){
            printf("%i",k);
            k--;
        }
        printf("\n");
    }
    for (int j = 1; j < tinggi - 1; j++){
        for (int i = 0; i < j; i++){
            printf(" ");
        }
        for (int i = 1; i < tinggi - j; i++){
            printf("%i", i);
        }
        for (int i = tinggi - j - 2; i >= 1; i--){
            printf("%i", i);
        }
        printf("\n");
    }


}

void gotoxy(int x, int y){
    COORD coor;
    coor.X = x;
    coor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}
