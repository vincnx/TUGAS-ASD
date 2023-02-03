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
    }
    else if (pilihan == 2){
        menu2();
    }
    else if (pilihan == 3){
        menu3();
    }
    else{
        system("exit");
        return 0;
    }
    system("pause");
    main();
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
        gotoxy(0,7);
        printf("===============");
        gotoxy(0, pos_y);
        printf("==>");
        int key = getch();
        if (key == 72){
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
    int ukuran, val;
    system("cls");
    printf("masukkan ukuran: ");
    scanf("%i", &ukuran);
    system("cls");
    for (int row = 0; row <= ukuran; row++){
        for (int col = 0; col <= row; col++){
            val = row + col;
            if (val < 10){
                printf("%i  ",val);
            }
            else{
                printf("%i ",val);
            }
        }
        printf("\n");
    }
}

int menu2(){
    int ukuran, val;
    system("cls");
    printf("masukkan ukuran: ");
    scanf("%i", &ukuran);
    system("cls");
    for (int row = 1; row <= ukuran; row++){
        for (int col = 1; col <= row; col++){
            val = row * col;
            if (val < 10){
                printf("%i  ", val);
            }
            else{
                printf("%i ", val);
            }
        }
        printf("\n");
    }
}

int menu3(){
    int ukuran;
    system("cls");
    printf("masukkan bilangan: ");
    scanf("%i", &ukuran);
    system("cls");
    for (int row = 1; row <= ukuran; row++){
        for (int col = 0; col < ukuran - row; col++){
            printf(" ");
        }
        for (int col = 1; col <= row; col++){
            printf("%i", col);
        }
        for (int col = 1; col < row; col++){
            printf("%i",row - col);
        }
        printf("\n");
    }
    for (int row = 1; row < ukuran; row++){
        for (int col = 1; col <= row; col++){
            printf(" ");
        }
        for (int col = 1; col <= ukuran - row; col++){
            printf("%i", col);
        }
        for (int col = 1; col < ukuran - row; col++){
            printf("%i", ukuran - row - col);
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