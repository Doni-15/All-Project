#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

void tampilan();
void bentuk_dasar(int cakram);
void bentuk_dasar_2();
bool perulangan();
void gotoxy(int x, int y);
string warna(int i);
vector<string> pembentukan_cakram(int cakram);
void penempatan_cakram_awal(int cakram);
void penempatan_cakram(int cakram);
void rekursif_menara_hanoi(int cakram, int tiang_a, int tiang_b, int tiang_c);
void pindahkan_cakram(int tiang_a, int tiang_b);

bool running = true;
vector<vector<int>>tiang(3);
int cakram_global = 0;

int main(){
    int cakram;  
    while(running == true){
        system("cls");
        tampilan();
        
        printf("Masukkan jumlah cakram: "); scanf("%d", &cakram);
        if(cakram >= 21){
            printf("Overload. Tidak dapat memuat lebih dari 20 cakram\n");
            system("pause");
            running = true;
        }
        else if(cakram <= 0){
            printf("Cakram minimal berjumlah satu. Silahkan masukkan angka valid\n");
            system("pause");
            running = true;
        }
        else{
            system("cls");
            tampilan();
            
            bentuk_dasar(cakram);
            bentuk_dasar_2();

            int y = cakram + 15 ;
            penempatan_cakram_awal(cakram);
            gotoxy(1, y); system("pause");
            
            cakram_global = cakram;
            for(int i = 0; i < 3;  i++){
                tiang[i].clear();
            }
            
            penempatan_cakram(cakram);
            rekursif_menara_hanoi(cakram, 0, 1, 2);

            perulangan();
        }
    }
    
}

// Fungsi untuk mengambar ulang cakram
void gambar_ulang(){
    system("cls");

    tampilan();
    bentuk_dasar(cakram_global);
    bentuk_dasar_2();

    int y_awal = (cakram_global + 11) - cakram_global;
    vector<string> hasil = pembentukan_cakram(cakram_global);

    int x;
    for(int t = 0; t < 3; ++t){
        if(t == 0) x = 30 - cakram_global;
        else if(t == 1) x = 90 - cakram_global;
        else x = 150 - cakram_global;

        int y = y_awal + (cakram_global - tiang[t].size());
        for (int i = tiang[t].size() - 1; i >= 0; --i){
            gotoxy(x, y);
            cout << hasil[tiang[t][i] - 1];
            y++;
        }
    }
    int y = cakram_global + 15 ;
    gotoxy(1, y); system("pause");
}

// Fungsi memindahkan cakram
void pindahkan_cakram(int awal, int akhir){
    if(!tiang[awal].empty()){
        int cakram = tiang[awal].back();
        tiang[awal].pop_back();
        tiang[akhir].push_back(cakram);
        gambar_ulang();
    }
} 

// Fungsi rekursif menara hanoi
void rekursif_menara_hanoi(int cakram, int tiang_a, int tiang_b, int tiang_c){
    if(cakram == 1){
        pindahkan_cakram(tiang_a, tiang_c);
    }
    else{
        rekursif_menara_hanoi(cakram - 1, tiang_a, tiang_c, tiang_b);
        pindahkan_cakram(tiang_a, tiang_c);
        rekursif_menara_hanoi(cakram - 1, tiang_b, tiang_a, tiang_c);
    }

}

// Fungsi menempatkan cakram
void penempatan_cakram_awal(int cakram){
    vector<string> hasil = pembentukan_cakram(cakram);

    int x = 30 - cakram, y = (cakram + 11) - cakram, i = 0;
    while(i < cakram){
        gotoxy(x, y); cout << hasil[i];
        y++;
        i++;
    }
}

// Fungsi menempatkan cakram pemindahan
void penempatan_cakram(int cakram){
    vector<string> hasil = pembentukan_cakram(cakram);

    int x = 30 - cakram, y = (cakram + 11) - cakram, i = 0;
    while(i < cakram){
        gotoxy(x, y); cout << hasil[i];
        y++;
        i++;
    }

    for(int i = cakram; i >= 1; --i){
        tiang[0].push_back(i);
    }
}

// Fungsi buat cakram
vector<string> pembentukan_cakram(int cakram){ 
    vector<string> bentuk_cakram(cakram);
    for(int i = 0; i < cakram; i++){
        string nomor_blok = "", spasi1 = "";
        int banyak_blok = 3 + 2 * i;
        int spasi_blok = (3 + 2 * (cakram - 1) - banyak_blok) / 2;

        int lebar_spasi = (cakram + 2) - i;

        
        for (int j = spasi_blok; j > 0; j--) {
            spasi1 += " ";
        }

        string blok(banyak_blok, '#');
        string spasi(lebar_spasi, ' ');

        nomor_blok = spasi + "<----- C" + to_string(i + 1) ;
        string n = warna(i + 1) + spasi1 + blok + "\033[0m";
        bentuk_cakram[i] = n + nomor_blok;
    }
    return bentuk_cakram;
}

// Header tampilan 
void tampilan(){
    string n = "", m = "";
    for (int i = 1; i <= 183; i++){
        n += "=";
        if(i > 98)
            m += " ";
    }
    string tampilan =  n + "\n" + m + "TOWER OF HANOI" + "\n" + n;
    cout << tampilan << "\n\n\n\n";
}

// Fungsi bentuk dasar
void bentuk_dasar(int cakram){
    string tiang = "";
    int n = cakram + 5;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 150; j++){
            if(((j == 30) || (j == 90) || (j == 150)) && (i < n))
                tiang += "|";
            else
                tiang += " ";
        }
        tiang += "\n";

    }
    cout << tiang;
    
}

// Fungsi tampilan bawah
void bentuk_dasar_2(){
    string tiang2 = "";
    for(int i = 0; i < 3; i++){
        for(int j= 0; j < 183; j++){
            if((i == 0) || (i == 2)){
                tiang2 += "-";
            }
            else if(i == 1){
                if ((j == 0)||(j == 4)||(j == 47)||(j == 52)||(j == 99)||(j == 104)||(j == 144)||(j == 149)) tiang2 += "|";
                else if(j == 24) tiang2 += "T I A N G  A";
                else if(j == 73) tiang2 += "T I A N G  B";
                else if(j == 122) tiang2 += "T I A N G  C";
                else if(j < 150) tiang2 += " ";
            }
            else{
                tiang2 += " ";
            }
        }
        tiang2 += "\n";
    }
    cout << tiang2;
}

// Fungsi mengulangi program
bool perulangan(){
    char ulang;

    cout << "Apakah anda ingin mengulang? (y/n): "; cin >> ulang;
    if(ulang == 'y' || ulang == 'Y')
        running = true;
    else
        running = false;

    return running;
}

// fungsi goto x,y
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Fungsi untuk wanah cakram
string warna(int i){
    int kode = 31 + (i % 7);
    return "\033[" + to_string(kode) + "m";
}