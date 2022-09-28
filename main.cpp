#include<iostream>
#include<conio.h>
#include<windows.h>
#define Max 5

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;

int TOP;

struct paket
{
    int code;
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[Max];

/***************/

void initStack(){
    TOP = 1;
}

int isEmpty(){
    if(TOP==1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(TOP==Max+1)
        return 1;
    else
        return 0;
}

void bersihlayar()
{
    for(int a=0; a<80; a++)
    {
        for(int b=0; b<=24; b++)
        {
            gotoxy(a,b); cout << " ";
        }
    }
}

void tambahdata(int x)
{
    if(isFull()==1){
        gotoxy(20,15); cout << "Stack sudah penuh \n";
        gotoxy(40,20);
        cout << "Press Any Key...";
        getch();
    }
    else{
        gotoxy(20,15); cout << "Inputkan Jenis Barang    :";
        cin >> kirim[x].jenis_brg;
        gotoxy(20,16); cout << "Inputkan Berat           :";
        cin >> kirim[x].berat;
        gotoxy(20,17); cout << "Inputkan Kota Tujuan     :";
        cin >> kirim[x].kota;
        TOP++;
    }
}

void tampildata(int x)
{
    if(isEmpty()==1){
        gotoxy(20,15); cout << "Stack masih kosong \n";
        gotoxy(40,20);
        cout << "Press Any Key...";
        getch();
    }
    else{
        gotoxy(40,10); cout << "Daftar Kiriman Paket" << "\n";
        for(int a=1; a<x; a++)
        {
            gotoxy(40,19-a);
            cout << a << ". ";
            cout << kirim[a].jenis_brg << " ";
            cout << kirim[a].berat << "Kg ";
            cout << kirim[a].kota << "\n";
        }
        cout << TOP;
        gotoxy(40,20);
        cout << "Press Any Key...";
        getch();
        //        harus Ijin --> #include<conio.h>/
    }

}

void hapusdata(int x)
{
    if(isEmpty()==1){
        gotoxy(20,15); cout << "Stack masih kosong\n";
        gotoxy(40,20);
        cout << "Press Any Key...";
        getch();
    }
    else{
        gotoxy(40,12); cout << "Data Terakhir yang anda Hapus Adalah :" << "\n";
        gotoxy(40,13); cout << kirim[x].jenis_brg << " ";
        cout << kirim[x].berat << "Kg ";
        cout << kirim[x].kota << "\n\n";
        TOP--;

        gotoxy(40,15); cout << "Press Any Key...";
        getch();
    }
}

int main()
{
    int pilih;
    initStack();
    do
    {
        bersihlayar();
        gotoxy(1,1); cout << "MENU UTAMA";
        gotoxy(1,2); cout << "1. Tambah Data";
        gotoxy(1,3); cout << "2. Hapus Data Terakhir" << "\n";
        gotoxy(1,4); cout << "3. Tampil Data" << "\n";
        gotoxy(1,5); cout << "9. Keluar" << "\n";

        gotoxy(1,7); cout << "Pilihan Anda [1-9] : ";
        cin >> pilih;
        switch(pilih)
        {
            case 1:
                tambahdata(TOP);
                break;
            case 2:
                hapusdata(TOP-1);
                break;
            case 3:
                tampildata(TOP);
                break;
            case 9:
                gotoxy(25,10);
                cout << "Terima kasih sudah mampir ke program kami \n";
                break;
            default:
                gotoxy(25,10);
                cout << "Inputan tidak valid \n";

                gotoxy(40,15); cout << "Press Any Key...";
                getch();
        }
    }
    while(pilih!=9);
    return 0;
}
