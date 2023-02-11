#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

int menu_awal();
// bagian 1
int main_1();
int menu_1();
int calculate_1();
// end bagian 1
// bagian 2
int main_2();
int menu_2();
int calculate_2();
// end bagian 2
// bagian 3
int main_3();
int menu_3();
    // bagian 3.1
int main_3_1();
int menu_3_1();
int calculate_3_1();
    // end bagian 3.1
    // bagian 3.2
int main_3_2();
int menu_3_2();
int calculate_3_2();
    // end bagian 3.2
    // bagian 3.3
int main_3_3();
int menu_3_3();
int calculate_3_3();
    // end bagian 3.3
// end bagian 3
// bagian 4
int main_4();
// end bagian 4
// tools
int pause();
void gotoxy();

const float pi = 3.14159;

int main(){
    int pil,  num1, num2;
    pil = menu_awal();
    switch (pil){
    case 1:
        main_1();
        break;
    case 2:
        main_2();
        break;
    case 3:
        main_3();
        break;
    case 4:
        main_4();
        break;
    case 5:
        system("cls");
        printf("Pantes koreksinya susah......");
        Sleep(1500);
        system("cls");
        system("exit");
    }
}

int menu_awal(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0,0);
        printf("================================");
        gotoxy(0,1);
        printf("        Tugas Kalkulator");
        gotoxy(0,2);
        printf("================================");
        gotoxy(5,3);
        printf("1. PingPoroLanSudo");
        gotoxy(5, 4);
        printf("2. SinCosTan");
        gotoxy(5,5);
        printf("3. Hitung Keliling Dan Luas");
        gotoxy(5,6);
        printf("4. Hitung Akar Kuadrat");
        gotoxy(5,7);
        printf("5. Exit");
        gotoxy(0,8);
        printf("================================");
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
        if (pos_y == 8){
            pos_y = 3;
        }
        else if (pos_y == 2){
            pos_y = 7;
        }
    }
}

// bagian 1
int main_1(){
    int pil_1;
    pil_1 = menu_1();
    calculate_1(pil_1);
}

int menu_1(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0,0);
        printf("===================");
        gotoxy(0,1);
        printf("  PingPoroLanSudo");
        gotoxy(0,2);
        printf("===================");
        gotoxy(5,3);
        printf("1. Perkalian");
        gotoxy(5, 4);
        printf("2. Pembagian");
        gotoxy(5,5);
        printf("3. Penjumlahan");
        gotoxy(5,6);
        printf("4. Pengurangan");
        gotoxy(5,7);
        printf("5. Balek Menu");
        gotoxy(0,8);
        printf("===================");
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
        if (pos_y == 8){
            pos_y = 3;
        }
        else if (pos_y == 2){
            pos_y = 7;
        }
    }
}

int calculate_1(int pil_1){
    float num1, num2;
    char cond;
    if (pil_1 == 5){
        main();
    }
    else{
        system("cls");
        printf("masukkan angka pertama : ");
        scanf("%f", &num1);
        printf("masukkan angka kedua   : ");
        scanf("%f", &num2);
        if (pil_1 == 1){
            printf("hasil dari %.2f * %.2f adalah : %.2f\n", num1, num2, num1*num2);
        }
        else if (pil_1 == 2){
            printf("hasil dari %.2f / %.2f adalah : %.2f\n", num1, num2, num1/num2);
        }
        else if (pil_1 == 3){
            printf("hasil dari %.2f + %.2f adalah : %.2f\n", num1, num2, num1+num2);
        }
        else if (pil_1 == 4){
            printf("hasil dari %.2f - %.2f adalah : %.2f\n", num1, num2, num1-num2);
        }
        cond = pause();
        if (cond == 'y' || cond == 'Y'){
            calculate_1(pil_1);
        }
        else if (cond == 'n' || cond == 'N'){
            main_1();
        }
    }
}
// end bagian 1

// bagian 2
int main_2(){
    int pil_2;
    pil_2 = menu_2();
    calculate_2(pil_2);
}

int menu_2(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0, 0);
        printf("===================");
        gotoxy(0, 1);
        printf("     SinCosTan");
        gotoxy(0, 2);
        printf("===================");
        gotoxy(5,3);
        printf("1. Sinus");
        gotoxy(5, 4);
        printf("2. Cosinus");
        gotoxy(5, 5);
        printf("3. Tangen");
        gotoxy(5, 6);
        printf("4. Balek Menu");
        gotoxy(0, 7);
        printf("===================");
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

int calculate_2(int pil_2){
    float derajat, rad;
    char cond;
    if (pil_2 == 4){
        main();
    }
    else{
        system("cls");
        printf("Masukkan sudut dalam derajat : ");
        scanf("%f", &derajat);
        rad = derajat * pi / 180.0;
        if (pil_2 == 1){
            printf("Hasil sinus adalah           : %.2f\n", sin(rad));
        }
        else if (pil_2 == 2){
            printf("Hasil cosinus adalah         : %.2f\n", cos(rad));
        }
        else if (pil_2 == 3){
            printf("Hasil tangen adalah          : %.2f\n", tan(rad));
        }
        cond = pause();
        if (cond == 'y' || cond == 'Y'){
            calculate_2(pil_2);
        }
        else if (cond == 'n' || cond == 'N'){
            main_2();
        }
    }
}
// bagian 2

// bagian 3
int main_3(){
    int pil_3;
    pil_3 = menu_3();
    switch (pil_3){
    case 1:
        main_3_1();
        break;
    case 2:
        main_3_2();
    case 3:
        main_3_3();
    case 4:
        main();
        break;
    default:
        break;
    }
}

int menu_3(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0, 0);
        printf("====================================");
        gotoxy(0, 1);
        printf("         KelilingLuasVolume");
        gotoxy(0, 2);
        printf("====================================");
        gotoxy(5,3);
        printf("1. Hitung Keliling Bangun Datar");
        gotoxy(5, 4);
        printf("2. Hitung Luas Bangun Datar");
        gotoxy(5, 5);
        printf("3. Hitung Volume Bangun Ruang");
        gotoxy(5, 6);
        printf("4. Balek Menu");
        gotoxy(0, 7);
        printf("====================================");
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

    // bagian 3.1
int main_3_1(){
    int pil_3_1;
    pil_3_1 = menu_3_1();
    calculate_3_1(pil_3_1);
}

int menu_3_1(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0, 0);
        printf("==============================");
        gotoxy(0, 1);
        printf("    Keliling Bangun Datar");
        gotoxy(0, 2);
        printf("==============================");
        gotoxy(5,3);
        printf("1. Keliling Persegi");
        gotoxy(5, 4);
        printf("2. Keliling Trapesium");
        gotoxy(5, 5);
        printf("3. Keliling Layang-layang");
        gotoxy(5, 6);
        printf("4. Keliling Lingkaran");
        gotoxy(5, 7);
        printf("5. Balek Menu");
        gotoxy(0, 8);
        printf("==============================");
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
        if (pos_y == 8){
            pos_y = 3;
        }
        else if (pos_y == 2){
            pos_y = 7;
        }
    }
}

int calculate_3_1(int pil_3_1){
    float pj_persegi, lb_persegi, atas_tpm, bawah_tpm, miring_tpm, atas_lyg, bawah_lyg, diameter_ling, jari_ling;
    char cond;
    system("cls");
    switch (pil_3_1){
    case 1:
        printf("Masukkan Panjang Persegi : ");
        scanf("%f", &pj_persegi);
        printf("Masukkan lebar Persegi   : ");
        scanf("%f", &lb_persegi);
        printf("Keliling Persegi Adalah  : %.2f\n", 2 * pj_persegi + 2 * lb_persegi);
        break;
    case 2:
        printf("Masukkan Sisi Atas Trapesium Sama Kaki   : ");
        scanf("%f", &atas_tpm);
        printf("Masukkan Sisi Bawah Trapesium Sama Kaki  : ");
        scanf("%f", &bawah_tpm);
        printf("Masukkan Sisi Miring Trapesium Sama Kaki : ");
        scanf("%f", &miring_tpm);
        printf("Keliling Trapesium Sama Kaki Adalah      : %.2f\n", 2 * miring_tpm + atas_tpm + bawah_tpm);        
        break;
    case 3:
        printf("Masukkan Panjang Sisi Atas Layang-layang : ");
        scanf("%f", &atas_lyg);
        printf("Masukkan Sisi Bawah Layang-layang        : ");
        scanf("%f", &bawah_lyg);
        printf("Keliling Layang-layang Adalah            : %.2f\n", 2 * atas_lyg + 2 * bawah_lyg);        
        break;
    case 4:
        printf("Masukkan Panjang Diameter Lingkaran  : ");
        scanf("%f", &diameter_ling);
        printf("Masukkan Panjang Jari-jari Lingkaran : ");
        scanf("%f", &jari_ling);
        printf("Keliling Lingkaran Berdasarkan Jari-jari Adalah : %.2f\n", 2 * pi * jari_ling);        
        printf("Keliling Lingkaran Berdasarkan Diameter Adalah  : %.2f\n", pi * diameter_ling);        
        break;
    case 5:
        main_3();
        break;
    }
    cond = pause();
    if (cond == 'y' || cond == 'Y'){
        calculate_3_1(pil_3_1);
    }
    else if (cond == 'n' || cond == 'N'){
        main_3_1();
    }
}
    // end bagian 3.1

    // bagian 3.2
int main_3_2(){
    int pil_3_2;
    pil_3_2 = menu_3_2();
    calculate_3_2(pil_3_2);
}

int menu_3_2(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0, 0);
        printf("==========================");
        gotoxy(0, 1);
        printf("    Luas Bangun Datar");
        gotoxy(0, 2);
        printf("==========================");
        gotoxy(5,3);
        printf("1. Luas Persegi");
        gotoxy(5, 4);
        printf("2. Luas Trapesium");
        gotoxy(5, 5);
        printf("3. Luas Layang-layang");
        gotoxy(5, 6);
        printf("4. Luas Lingkaran");
        gotoxy(5, 7);
        printf("5. Balek Menu");
        gotoxy(0, 8);
        printf("==========================");
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
        if (pos_y == 8){
            pos_y = 3;
        }
        else if (pos_y == 2){
            pos_y = 7;
        }
    }
}

int calculate_3_2(int pil_3_2){
    float pj_persegi, lb_persegi, atas_tpm, bawah_tpm, tinggi_tpm, dgp_lyg, dgl_lyg, diameter_ling, jari_ling;
    char cond;
    system("cls");
    switch (pil_3_2){
    case 1:
        printf("Masukkan Panjang Persegi : ");
        scanf("%f", &pj_persegi);
        printf("Masukkan lebar Persegi   : ");
        scanf("%f", &lb_persegi);
        printf("Luas Persegi Adalah      : %.2f\n", pj_persegi * lb_persegi);
        break;
    case 2:
        printf("Masukkan Sisi Atas Trapesium Sama Kaki  : ");
        scanf("%f", &atas_tpm);
        printf("Masukkan Sisi Bawah Trapesium Sama Kaki : ");
        scanf("%f", &bawah_tpm);
        printf("Masukkan Tinggi Trapesium Sama Kaki     : ");
        scanf("%f", &tinggi_tpm);
        printf("Luas Trapesium Sama Kaki Adalah         : %.2f\n", 0.5 * tinggi_tpm * (atas_tpm + bawah_tpm));        
        break;
    case 3:
        printf("Masukkan Diagonal Panjang Layang-layang : ");
        scanf("%f", &dgp_lyg);
        printf("Masukkan Diagonal Lebar Layang-layang   : ");
        scanf("%f", &dgl_lyg);
        printf("Luas Layang-layang Adalah               : %.2f\n", 0.5 * dgp_lyg * dgl_lyg);        
        break;
    case 4:
        printf("Masukkan Panjang Diameter Lingkaran  : ");
        scanf("%f", &diameter_ling);
        printf("Masukkan Panjang Jari-jari Lingkaran : ");
        scanf("%f", &jari_ling);
        printf("Luas Lingkaran Berdasarkan Jari-jari Adalah : %.2f\n", pi * pow(jari_ling, 2));        
        printf("Luas Lingkaran Berdasarkan Diameter Adalah  : %.2f\n", pi * pow(diameter_ling / 2, 2));        
        break;
    case 5:
        main_3();
        break;
    }
    cond = pause();
    if (cond == 'y' || cond == 'Y'){
        calculate_3_2(pil_3_2);
    }
    else if (cond == 'n' || cond == 'N'){
        main_3_2();
    }
}
    // end bagian 3.2

    // bagian 3.3
int main_3_3(){
    int pil_3_3;
    pil_3_3 = menu_3_3();
    calculate_3_3(pil_3_3);
}

int menu_3_3(){
    int pos_y = 3;
    while(1){
        system("cls");
        gotoxy(0, 0);
        printf("=====================");
        gotoxy(0, 1);
        printf(" Volume Bangun Ruang");
        gotoxy(0, 2);
        printf("=====================");
        gotoxy(5,3);
        printf("1. Volume Kubus");
        gotoxy(5, 4);
        printf("2. Volume Prisma");
        gotoxy(5, 5);
        printf("3. Volume Limas");
        gotoxy(5, 6);
        printf("4. Volume Bola");
        gotoxy(5, 7);
        printf("5. Balek Menu");
        gotoxy(0, 8);
        printf("=====================");
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
        if (pos_y == 8){
            pos_y = 3;
        }
        else if (pos_y == 2){
            pos_y = 7;
        }
    }
}

int calculate_3_3(int pil_3_3){
    float sisi_kbs; // var kubus
    float sisi_prs, alas_sgt_prs, tinggi_sgt_prs, jari_prs, diam_prs, tinggi_prs; // var prisma
    float sisi_lim, alas_sgt_lim, tinggi_sgt_lim, jari_lim, diam_lim, tinggi_lim; // val limas
    float jari_bol, diam_bol; // val bol
    char cond;
    system("cls");
    switch (pil_3_3){
    case 1:
        printf("Masukkan Panjang Sisi Kubus : ");
        scanf("%f", &sisi_kbs);
        printf("Volume Kubus Adalah         : %.2f\n", pow(sisi_kbs, 3));
        break;
    case 2:
        printf("Masukkan Sisi Persegi        : ");
        scanf("%f", &sisi_prs);
        printf("Masukkan Lebar Alas Segitiga : ");
        scanf("%f", &alas_sgt_prs);
        printf("Masukkan Tinggi Segitiga     : ");
        scanf("%f", &tinggi_sgt_prs);
        printf("Masukkan Jari-Jari Lingkaran : ");
        scanf("%f", &jari_prs);
        printf("Masukkan Diameter Lingkaran  : ");
        scanf("%f", &diam_prs);
        printf("Masukkan Tinggi Prisma       : ");
        scanf("%f", &tinggi_prs);
        printf("Volume Prisma Persegi Adalah                 : %.2f\n", pow(sisi_prs, 2) * tinggi_prs);        
        printf("Volume Prisma Segitiga Adalah                : %.2f\n", 0.5 * alas_sgt_prs * tinggi_sgt_prs * tinggi_prs);        
        printf("Volume Silinder Berdasarkan Jari-jari Adalah : %.2f\n", pi * pow(jari_prs, 2) * tinggi_prs);        
        printf("Volume Silinder Berdasarkan Diameter Adalah  : %.2f\n", pi * pow(diam_prs / 2, 2) * tinggi_prs);        
        break;
    case 3:
        printf("Masukkan Sisi Persegi        : ");
        scanf("%f", &sisi_lim);
        printf("Masukkan Lebar Alas Segitiga : ");
        scanf("%f", &alas_sgt_lim);
        printf("Masukkan Tinggi Segitiga     : ");
        scanf("%f", &tinggi_sgt_lim);
        printf("Masukkan Jari-jari Lingkaran : ");
        scanf("%f", &jari_lim);
        printf("Masukkan Diameter Lingkaran  : ");
        scanf("%f", &diam_lim);
        printf("Masukkan Tinggi Limas        : ");
        scanf("%f", &tinggi_lim);
        printf("Volume Limas Persegi Adalah                        : %.2f\n", 1.0 / 3.0 * pow(sisi_lim, 2) * tinggi_lim);        
        printf("Volume Limas Segitiga Adalah                       : %.2f\n", 1.0 / 3.0 * 0.5 * alas_sgt_lim * tinggi_sgt_lim * tinggi_lim);        
        printf("Volume Limas Silinder Berdasarkan Jari-jari Adalah : %.2f\n", 1.0 / 3.0 * pi * pow(jari_lim, 2) * tinggi_lim);        
        printf("Volume Limas Silinder Berdasarkan Diameter Adalah  : %.2f\n", 1.0 / 3.0 * pi * pow(diam_lim / 2, 2) * tinggi_lim);        
        break;
    case 4:
        printf("Masukkan Jari-jari Lingkaran : ");
        scanf("%f", &jari_bol);
        printf("Masukkan Diameter Lingkaran  : ");
        scanf("%f", &diam_bol);
        printf("Volume Bola Berdasarkan Jari-jari Adalah : %.2f\n", 4.0 / 3.0 * pi * pow(jari_bol, 3));        
        printf("Volume Bola Berdasarkan Diameter Adalah  : %.2f\n", 4.0 / 3.0 * pi * pow((diam_bol / 2), 3));        
        break;
    case 5:
        main_3();
        break;
    }
    cond = pause();
    if (cond == 'y' || cond == 'Y'){
        calculate_3_3(pil_3_3);
    }
    else if (cond == 'n' || cond == 'N'){
        main_3_3();
    }
}
    // end bagian 3.3
// end bagian 3

// bagian 4
int main_4(){
    float num;
    char cond;
    system("cls");
    printf("Masukkan Bilangan Yang Akan Diakarkan : ");
    scanf("%f", &num);
    printf("Hasil dari akar %.2f adalah %.2f\n", num, sqrt(num));
    cond = pause();
    if (cond == 'y' || cond == 'Y'){
        main_4();
    }
    else if (cond == 'n' || cond == 'N'){
        main();
    }
}
// end bagian 4
// tools
void gotoxy(int x, int y){
    COORD coor;
    coor.X = x;
    coor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}

int pause(){
    char cond;
    system("pause");
    while(1){
        printf("apakah ingin hitung ulang ? (y/n) ");
        scanf(" %c", &cond);
        if (cond == 'y' || cond == 'Y' || cond == 'n' || cond == 'N'){
            return cond;
        }
        else{
            system("cls");
            printf("invalid input!\n");
        }
    }
}