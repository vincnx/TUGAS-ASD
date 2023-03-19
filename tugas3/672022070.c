#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAX 5

// BAGIAN UTAMA
int menu1();
// BAGIAN MENU1
int main1_1();
int menu1_1();
// STACK
int push();
int pop();
// BAGIAN MENU2
int main1_2();
int menu1_2();
// QUEUE
int enqueue();
int dequeue();
// TOOLS & STRUCT
void gotoxy();
int get_int();

struct queue{
    int list[MAX];
    int ptr;
}queue = {
    .ptr = 0
};
static const struct queue tmp = {
    .ptr = 0
};

struct stack{
    char list[MAX][100];
    int ptr;
}stack = {
    .ptr = 0
};
static const struct stack tmp2 = {
    .ptr = 0
};

int main(){
    int selection = menu1();
    switch (selection){
    case 1:
        main1_1();
        break;
    case 2:
        main1_2();
        break;
    case 3:
        system("cls");
        system("exit");
        break;
    }
}

// BAGIAN UTAMA
int menu1(){
    int pos = 3;
    while (1){
        system("cls");
        printf("=====================");
        gotoxy(0, 1);
        printf("TUGAS STACK AND QUEUE");
        gotoxy(0, 2);
        printf("=====================");
        gotoxy(5, 3);
        printf("1. STACK STRING");
        gotoxy(5, 4);
        printf("2. QUEUE INTEGER");
        gotoxy(5, 5);
        printf("3. EXIT");
        gotoxy(0, 6);
        printf("=====================");
        gotoxy(0, pos);
        printf("==>");
        int key = getch();
        if (key == 72){
            pos--;
        }
        else if (key == 80){
            pos++;
        }
        else if (key == 13){
            return pos - 2;
        }
        if (pos == 6){
            pos = 3;
        }
        else if (pos == 2){
            pos = 5;
        }
    }
}


// BAGIAN MENU 1
int main1_1(){
    char string[100];
    int selection1 = menu1_1();
    system("cls");
    switch (selection1){
    case 1:
        if (stack.ptr != MAX){
            printf("INPUT DATA : ");
            scanf(" %[^\n]s", &string);
            push(&stack, string);
        }
        else{
            printf("ERROR: STACK IS FULL!\n");
        }
        system("pause");
        main1_1();
        break;
    case 2:
        if (stack.ptr){
            pop(&stack, &string);
            printf("%s\n", string);
        }
        else{
            printf("ERROR: STACK IS EMPTY!\n");
        }
        system("pause");
        main1_1();
        break;
    case 3:
        if (stack.ptr){
            for (int i = stack.ptr - 1; i >= 0; i--){
                printf("DATA %i : %s\n", i, stack.list[i]);
            }
        }
        else{
            printf("NO DATA!\n");
        }
        system("pause");
        main1_1();
        break;
    case 4:
        stack = tmp2;
        printf("STACK HAS BEEN SUCCESSFULLY DELETED\n");
        system("pause");
        main1_1();
        break;
    case 5:
        main();
        break;
    }
}

int menu1_1(){
    int pos = 3;
    while (1){
        system("cls");
        printf("========================");
        gotoxy(0, 1);
        printf("      STACK STRING");
        gotoxy(0, 2);
        printf("========================");
        gotoxy(5, 3);
        printf("1. PUSH STACK");
        gotoxy(5, 4);
        printf("2. POP STACK");
        gotoxy(5, 5);
        printf("3. PRINT STACK");
        gotoxy(5, 6);
        printf("4. DELETE STACK");
        gotoxy(5, 7);
        printf("5. RETURN MAIN MENU");
        gotoxy(0, 8);
        printf("========================");
        gotoxy(0, pos);
        printf("==>");
        int key = getch();
        if (key == 72){
            pos--;
        }
        else if (key == 80){
            pos++;
        }
        else if (key == 13){
            return pos - 2;
        }
        if (pos == 8){
            pos = 3;
        }
        else if (pos == 2){
            pos = 7;
        }
    }
}


// STACK
int push(struct stack *target, char *string){
    strcpy(target->list[target->ptr], string);
    target->ptr++;
}

int pop(struct stack *target, char *string){
    strcpy(string, target->list[target->ptr - 1]);
    strcpy(target->list[target->ptr - 1], "\0");
    target->ptr--;
}


// BAGIAN MENU 2
int main1_2(){
    int result;
    int selection2 = menu1_2();
    system("cls");
    switch (selection2){
    case 1:
        if (queue.ptr != MAX){
            result = get_int("INPUT DATA : ");
            printf("\n");
            enqueue(&queue, result);
        }
        else{
            printf("ERROR: QUEUE IS FULL!\n");
        }
        system("pause");
        main1_2();
        break;
    case 2:
        if (queue.ptr){
            result = dequeue(&queue);
            printf("%d HAVE BEEN DEQUEUED\n", result);
        }
        else{
            printf("ERROR: QUEUE IS EMPTY!\n");
        }
        system("pause");
        main1_2();
        break;
    case 3:
        if (queue.ptr){
            for (int i = 0; i < queue.ptr; i++){
                printf("DATA %i : %i\n", i, queue.list[i]);
            }
        }
        else{
            printf("NO DATA!\n");
        }
        system("pause");
        main1_2();
        break;
    case 4:
        queue = tmp;
        printf("QUEUE HAS BEEN SUCCESSFULLY DELETED\n");
        system("pause");
        main1_2();
        break;
    case 5:
        main();
        break;
    }
}

int menu1_2(){
    int pos = 3;
    while (1){
        system("cls");
        printf("========================");
        gotoxy(0, 1);
        printf("     QUEUE INTEGER");
        gotoxy(0, 2);
        printf("========================");
        gotoxy(5, 3);
        printf("1. ENQUEUE INTEGER");
        gotoxy(5, 4);
        printf("2. DEQUEUE INTEGER");
        gotoxy(5, 5);
        printf("3. PRINT QUEUE");
        gotoxy(5, 6);
        printf("4. DELETE QUEUE");
        gotoxy(5, 7);
        printf("5. RETURN MAIN MENU");
        gotoxy(0, 8);
        printf("========================");
        gotoxy(0, pos);
        printf("==>");
        int key = getch();
        if (key == 72){
            pos--;
        }
        else if (key == 80){
            pos++;
        }
        else if (key == 13){
            return pos - 2;
        }
        if (pos == 8){
            pos = 3;
        }
        else if (pos == 2){
            pos = 7;
        }
    }
}


// QUEUE
int enqueue(struct queue *target, int result){
    target->list[target->ptr] = result;
    target->ptr++;
}

int dequeue(struct queue *target){
    int temp = target->list[0];
    for (int i = 0; i < target->ptr; i++){
        if (i == target->ptr - 1){
            target->list[i] = NULL;
        }
        else{
            target->list[i] = target->list[i + 1];
        }
    }
    target->ptr--;
    return temp;
}


// TOOLS
void gotoxy(int x, int y){
    COORD coor;
    coor.X = x;
    coor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}

int get_int(char *prompt){
    int num = 0, ch, count = 0;

    printf("%s", prompt);
    while (1){
        ch = getch();
        if (ch == 13 && count){
            break;
        }
        if (ch >= 48 && ch <= 57 && ch != 13){
            num = num * 10 + (ch - 48);
            printf("%c", ch);
            count++;
        }
        else if ((ch == 8 && num) || (num == 0 && count)){
            num /= 10;
            printf("\b \b");
            count--;
        }
    }
    return num;
}