#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define ENTER 13
#define BKSP 8
#define SPACE 32
#define TAB 9

struct Nasabah{
    int nomor, saldo;
    char nama[50];
}nasabah;

//
void tambah_nasabah();
void setor_tarik();
void setor();
void tarik();
void cek_saldo();
void daftar_nasabah();
void hapus_nasabah();
void rank_nasabah();
void terkaya();
void terbokek();
// 
// tools
void gotoxy(short x, short y);
void startDisplay();
void logo();
//

void main(){
    int position = 12;
    while (1){
        startDisplay(1);
        gotoxy(80, 12);
        printf("\033[47m\033[30mTambah Nasabah");
        gotoxy(80, 14);
        printf("\033[47m\033[30mSetor dan Tarik");
        gotoxy(80, 16);
        printf("\033[47m\033[30mCek Saldo");
        gotoxy(80, 18);
        printf("\033[47m\033[30mDaftar Nasabah");
        gotoxy(80, 20);
        printf("\033[47m\033[30mHapus Nasabah");
        gotoxy(80, 22);
        printf("\033[47m\033[30mRank Nasabah");
        gotoxy(80, 24);
        printf("\033[47m\033[30mExit");
        gotoxy(75, position);
        printf("\033[47m\033[30m==>");
        int key = getch();
        if (key == 72){
            position -= 2;
        }
        else if (key == 80){
            position += 2;
        }
        else if (key == 13){
            position = position / 2 - 5;
            break;
        }
        if (position == 26){
            position = 12;
        }
        else if (position == 10){
            position = 24;
        }
    }
    switch (position){
    case 1: // tambah nasabah
        tambah_nasabah();
        break;
    case 2: // setor dan tarik
        setor_tarik();
        break;
    case 3: // cek saldo
        cek_saldo();
        break;
    case 4: // daftar nasabah
        daftar_nasabah();
        break;
    case 5: // hapus nasabah
        hapus_nasabah();
        break;
    case 6: // rank nasabah
        rank_nasabah();
        break;
    case 7: // keluar
        system("cls");
        exit(0);
        break;
    }
}

void tambah_nasabah(){
    int no_nasabah = 672022000;
    FILE *fp;
    startDisplay(1);
    char ID;
    fp = fopen("NextFile.dat", "a+");
    if ((fp = fopen("NextFile.dat", "a+")) != NULL){
        while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
            no_nasabah = nasabah.nomor;
        }
        gotoxy(80, 17);
        printf("\033[47m\033[30mmasukkan nama :");
        gotoxy(80, 18);
        scanf(" %[^\n]s", nasabah.nama);
        nasabah.nomor = no_nasabah + 1;
        nasabah.saldo = 0;
    }
    fp = fopen("NextFile.dat", "a");
    fprintf(fp, "%s %i %i\n", nasabah.nama, nasabah.nomor, nasabah.saldo);
    fclose(fp);
    startDisplay(1);
    gotoxy(80, 17);
    printf("\033[47m\033[30mNasabah berhasil ditambahkan\n");
    gotoxy(80, 18);
    system("pause");
    main();
}

void setor_tarik(){
    int position = 16;
    while (1){
        startDisplay(1);
        gotoxy(80, 16);
        printf("\033[47m\033[30mSetor");
        gotoxy(80, 18);
        printf("\033[47m\033[30mTarik");
        gotoxy(75, position);
        printf("\033[47m\033[30m==>");
        int key = getch();
        if (key == 72){
            position -= 2;
        }
        else if (key == 80){
            position += 2;
        }
        else if (key == 13){
            position = position / 2 - 7;
            break;
        }
        if (position == 20){
            position = 16;
        }
        else if (position == 14){
            position = 18;
        }
    }
    switch (position){
    case 1: // setor
        setor();
    case 2: // tarik
        tarik();
    }
}

void setor(){
    FILE *fp, *rp;
    int no_nasabah, jumlah;
    int cond = 0;
    startDisplay(1);
    if ((fp = fopen("NextFile.dat", "r+")) == NULL){
        gotoxy(80, 17);
        printf("\033[47m\033[30mBelum Ada Nasabah!");
    }
    else{
        rp = fopen("TempFile.dat", "w+");
        gotoxy(80, 16);
        printf("\033[47m\033[30mmasukkan nomor rekening:");
        gotoxy(80, 17);
        scanf("%i", &no_nasabah);
        fflush(stdin);
        startDisplay(1);
        while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
            if (no_nasabah == nasabah.nomor){
                cond = 1;
                I:
                gotoxy(80, 16);
                printf("\033[47m\033[30mRekening %s", nasabah.nama);
                gotoxy(80, 18);
                printf("\033[47m\033[30mmasukkan jumlah : ");
                scanf("%i", &jumlah);
                startDisplay(1);
                if (jumlah <= 0){
                    gotoxy(80, 17);
                    printf("\033[47m\033[30mjumlah terlalu kecil");
                    gotoxy(80, 18);
                    system("pause");
                    goto I;
                }
                else{
                    nasabah.saldo += jumlah;
                    fprintf(rp, "%s %i %i\n", nasabah.nama, nasabah.nomor, nasabah.saldo);
                    fflush(stdin);
                    gotoxy(80, 17);
                    printf("\033[47m\033[30mBerhasil Setor!");
                }
            }
            else{
                fprintf(rp, "%s %i %i\n", nasabah.nama, nasabah.nomor, nasabah.saldo);
                fflush(stdin);
            }
        }
        if (!cond){
            gotoxy(80, 17);
            printf("\033[47m\033[30mNOMOR REKENING TIDAK DIKENAL!");
        }
        fclose(rp);
        fclose(fp);
        remove("NextFile.dat");
        rename("TempFile.dat", "NextFile.dat");
    }
    gotoxy(80, 18);
    system("pause");
    main();
}

void tarik(){
    FILE *fp, *rp;
    int no_nasabah, jumlah;
    int cond = 0;
    startDisplay(1);
    if ((fp = fopen("NextFile.dat", "r+")) == NULL){
        gotoxy(80, 17);
        printf("\033[47m\033[30mBelum Ada Nasabah");
    }
    else{
        rp = fopen("TempFile.dat", "a");
        startDisplay(1);
        gotoxy(80, 16);
        printf("\033[47m\033[30mmasukkan nomor rekening:");
        gotoxy(80, 17);
        scanf("%i", &no_nasabah);
        fflush(stdin);
        startDisplay(1);
        while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
            if (no_nasabah == nasabah.nomor){
                cond = 1;
                I:
                gotoxy(80, 16);
                printf("\033[47m\033[30mRekening %s\n", nasabah.nama);
                gotoxy(80, 18);
                printf("\033[47m\033[30mmasukkan jumlah: ");
                scanf("%i", &jumlah);
                if (jumlah <= 0){
                    gotoxy(80, 17);
                    printf("\033[47m\033[30mjumlah terlalu kecil");
                    gotoxy(80, 18);
                    system("pause");
                    goto I;
                }
                else{
                    if (nasabah.saldo - jumlah <= 0){
                        gotoxy(80, 17);
                        printf("\033[47m\033[30mSaldo anda tidak cukup.\n");
                        goto I;
                    }
                    else{
                        startDisplay(1);
                        nasabah.saldo -= jumlah;
                        fprintf(rp, "%s %i %i\n", nasabah.nama, nasabah.nomor, nasabah.saldo);
                        fflush(stdin);
                        gotoxy(80, 17);
                        printf("\033[47m\033[30mPenarikan Berhasil!\n");
                    }
                }
            }
            else{
                fprintf(rp, "%s %i %i\n", nasabah.nama, nasabah.nomor, nasabah.saldo);
                fflush(stdin);
            }
        }
        if (!cond){
            gotoxy(80, 17);
            printf("\033[47m\033[30mNOMOR REKENING TIDAK DIKENAL!\n");
        }
        fclose(rp);
        fclose(fp);
        remove("NextFile.dat");
        rename("TempFile.dat", "NextFile.dat");
        gotoxy(80, 18);
        system("pause");
    }
    main();
}

void rank_nasabah(){
    int position = 16;
    while (1){
        startDisplay(1);
        gotoxy(80, 16);
        printf("\033[47m\033[30mTerkaya");
        gotoxy(80, 18);
        printf("\033[47m\033[30mTerbokek");
        gotoxy(75, position);
        printf("\033[47m\033[30m==>");
        int key = getch();
        if (key == 72){
            position -= 2;
        }
        else if (key == 80){
            position += 2;
        }
        else if (key == 13){
            position = position / 2 - 7;
            break;
        }
        if (position == 20){
            position = 16;
        }
        else if (position == 14){
            position = 18;
        }
    }
    switch (position){
    case 1: // terkaya
        terkaya();
    case 2: // terbokek
        terbokek();
    }
}

void terkaya(){
    FILE *fp;
    int max = 0;
    int limit = 0;
    int cond = 1;
    int num = 1;
    startDisplay(1);
    if ((fp = fopen("NextFile.dat", "r+")) == NULL){
        gotoxy(48, 17);
        printf("\033[47m\033[30mBelum Ada Nasabah");
        gotoxy(48, 18);
        system("pause");
        main();
    }
    else{
        startDisplay(0);
        while (cond){
            cond = 0;
            while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
                if (limit){
                    if (nasabah.saldo > max && nasabah.saldo < limit){
                    max = nasabah.saldo;
                    cond = 1;
                    }
                }
                else{
                    if (nasabah.saldo > max){
                        max = nasabah.saldo;
                        cond = 1;
                    }
                }
            }
            fseek(fp, 0, SEEK_SET);
            while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
                if (nasabah.saldo == max){
                    gotoxy(48, 7 + num);
                    printf("\033[47m\033[30m%i. %s Saldo : Rp.%i.00", num, nasabah.nama, nasabah.saldo);
                    num++;
                }
            }
            fseek(fp, 0, SEEK_SET);
            limit = max;
            max = 0;
        }
    }
    gotoxy(45, 8 + num);
    system("pause");
    main();
}

void terbokek(){
    FILE *fp;
    int limit = -1;
    int max = 0;
    int cond = 1;
    int num = 1;
    startDisplay(1);
    if ((fp = fopen("NextFile.dat", "r+")) == NULL){
        gotoxy(48, 17);
        printf("\033[47m\033[30mBelum Ada Nasabah");
        gotoxy(48, 18);
        system("pause");
        main();
    }
    else{
        startDisplay(0);
        while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
            if (nasabah.saldo > max){
                max = nasabah.saldo;
            }
        }
        fseek(fp, 0, SEEK_SET);
        while (cond){
            int lowest = max;
            cond = 0;
            while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
                if (nasabah.saldo < lowest && nasabah.saldo > limit){
                    lowest = nasabah.saldo;
                    cond = 1;
                }
            }
            limit = lowest;
            fseek(fp, 0, SEEK_SET);
            while (fscanf(fp, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
                if (nasabah.saldo == lowest){
                    gotoxy(48, 7 + num);
                    printf("\033[47m\033[30m%i. %s Saldo : Rp.%i.00\n", num, nasabah.nama, nasabah.saldo);
                    num++;
                }
            }
            fseek(fp, 0, SEEK_SET);
        }
    gotoxy(45, 8 + num);
    system("pause");
    main();
    }
}

void cek_saldo(){
    int target;
    int found = 0;
    FILE *sfile;
    sfile = fopen("NextFile.dat", "r");
    startDisplay(1);
    gotoxy(80,16);
    printf("\033[47m\033[30mMasukkan nomor rekening : ");
    gotoxy(80,17);
    scanf("%i", &target);
    startDisplay(1);
    while (!feof(sfile) && found == 0){
        fscanf(sfile, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo);
        if (target == nasabah.nomor){
            found = 1;
        }
    }
    if (found){
        gotoxy(80, 15);
        printf("\033[47m\033[30mNama Nasabah\t\t:%s", nasabah.nama);
        gotoxy(80, 16);
        printf("\033[47m\033[30mNomor Nasabah\t\t:%i", nasabah.nomor);
        gotoxy(80, 17);
        printf("\033[47m\033[30mSaldo\t\t\t:%i", nasabah.saldo);
    }
    else{
        gotoxy(80, 17);
        printf("\033[47m\033[30mNasabah Tidak Ada");
    }
    fclose(sfile);
    gotoxy(80, 19);
    system("pause");
    main();
}

void hapus_nasabah(){
    int target;
    int found = 0;
    FILE *sfile, *tfile;
    sfile = fopen("NextFile.dat", "r");
    tfile = fopen("TempFile.dat", "w+");
    startDisplay(1);
    gotoxy(80, 16);
    printf("\033[47m\033[30mMasukkan Nomor Rekening: ");
    gotoxy(80, 17);
    scanf("%i", &target);
    startDisplay(1);
    while (fscanf(sfile, "%s %i %i\n", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
        if (target == nasabah.nomor){
            found = 1;
        }
        else{
            fprintf(tfile, "%s %i %i\n", nasabah.nama, nasabah.nomor, nasabah.saldo);
        }
    }
    if (!found){
        gotoxy(80, 17);
        printf("\033[47m\033[30mNasabah Tidak Ada");
    }
    else{
        gotoxy(80, 17);
        printf("\033[47m\033[30mNasabah Telah Berhasil Dihapus");
    }
    fclose(sfile);
    fclose(tfile);
    remove("NextFile.dat");
    rename("TempFile.dat", "NextFile.dat");
    gotoxy(80, 18);
    system("pause");
    main();
}

void daftar_nasabah(){
    FILE *f;
    int i, q;
    startDisplay(0);
    if ((f = fopen("NextFile.dat", "r")) == NULL){
        gotoxy(10, 3);
        printf("\033[47m\033[30mBelum Ada Nasabah\n");
    }
    else{
        gotoxy(0, 7);
        for (i = 0; i < 120; i++){
            printf("\033[47m\033[30m-");
        }
        gotoxy(5, 8);
        printf("\033[47m\033[30mNama Nasabah");
        gotoxy(53, 8);
        printf("\033[47m\033[30mNomor Rekening");
        gotoxy(103, 8);
        printf("\033[47m\033[30mJumlah Saldo");
        q = 10;
        while (fscanf(f, "%s %i %i", nasabah.nama, &nasabah.nomor, &nasabah.saldo) != EOF){
            gotoxy(5, q);
            printf("\033[47m\033[30m%s", nasabah.nama);
            gotoxy(56, q);
            printf("\033[47m\033[30m%i", nasabah.nomor);
            gotoxy(103, q);
            printf("\033[47m\033[30m%i", nasabah.saldo);
            q++;
        }
        printf("\n");
        for (i = 0; i < 120; i++){
            printf("\033[47m\033[30m-");
        }
        printf("\n");
    }
    fclose(f);
    gotoxy(45, q + 3);
    system("pause");
    main();
}

void startDisplay(int with_logo){
    printf("\033[0m");
    system("cls");
    // Menampilkan layar berwarna biru
    printf("\033[44m");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 120; j++){
            printf(" ");
        }
        printf("\n");
    }

    // Menampilkan layar berwarna putih
    printf("\033[47m");
    for (int i = 0; i < 25; i++){
        for (int j = 0; j < 120; j++){
            printf(" ");
        }
        printf("\n");
    }
    gotoxy(56, 2);
    printf("\033[44m\033[1m\033[33m\033[4m\033[5mBANK547\033[0m");
    gotoxy(47, 3);
    printf("\033[44m\033[3m\033[37mJl. Osamaliki No.12, Medan\033[0m");
    if (with_logo){
        logo();
    }
    printf("\033[0m");
}

void logo(){
    printf("\033[41m");
    // horisontal
    for (int i = 0; i < 21; i++){
        for (int j = 0; j < 2; j++){
            gotoxy(20 + i, 16 + j);
            printf(" ");
        }
    }
    // vertikal
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 13; j++){
            gotoxy(28 + i, 12 + j);
            printf(" ");
        }
    }
    printf("\033[0m");
}

void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
