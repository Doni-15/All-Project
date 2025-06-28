#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Ini struct isi nilai
struct kategori_penilaian{
    string nama;
    int kehadiran;
    int tugas;
    int proyek;
    int uts;
    int uas;
    float nilai_final;
    string kategori;
    string kelulusan;
};

// Fungsi
void gotoxy(int x, int y);
vector<string> buka_file(const string& nama_file);
vector<int> nilai_mahasiswa();
vector<kategori_penilaian> input_nilai();
bool urutan_nilai(const kategori_penilaian& a, const kategori_penilaian& b);

// Variabel global
vector<string> nama_file = buka_file("nama_mahasiswa.txt");
vector<kategori_penilaian> data_mahasiswa;
int y = 10, jlh = 0;

class Metode_Searching{
    public:
        // Fungsi buat tabel
        void tabel(int hitung, int m, bool peringkat){ //frans
            string n(183, '-');
            gotoxy(0, y + hitung); cout << n;

            if(peringkat == false){
                gotoxy(8, 6); cout << "Ditemukan : " << m << endl;
            }
            else{
                gotoxy(0, 6); cout << "URUTAN PERINGKAT  " << m  << " BESAR" << endl;
            }
            
            for(int i = 0; i < hitung; i++){
                for(int j = 0; j < 183; j++){
                    if(check(j)){
                        gotoxy(j, 10 + i); cout << "|";
                        gotoxy(j, y + hitung); cout << "+";
                    }
                }
                
            }
        }

        // fungsi menmepatan nilai
        void penempatan_nilai(int hitung, int i){ //rionaldo       
            int x = 70;
            gotoxy(x, y + hitung); cout << data_mahasiswa[i].kehadiran;
            gotoxy(x + 14, y + hitung); cout << data_mahasiswa[i].tugas;
            gotoxy(x + 27, y + hitung); cout << data_mahasiswa[i].proyek;
            gotoxy(x + 40, y + hitung); cout << data_mahasiswa[i].uts;
            gotoxy(x + 53, y + hitung); cout << data_mahasiswa[i].uas;
            gotoxy(x + 66, y + hitung); cout << data_mahasiswa[i].nilai_final;
            gotoxy(x + 80, y + hitung); cout << data_mahasiswa[i].kategori;
            gotoxy(x + 95, y + hitung); cout << data_mahasiswa[i].kelulusan;
        
            int lulus = 0;
            int tidak_lulus = 0;
        
            // Hitung jumlah lulus dan tidak lulus
            for (const auto& mhs : data_mahasiswa) {
                if (mhs.kelulusan == "LULUS") {
                    lulus++;
                } else {
                    tidak_lulus++;
                }
            }
        
            gotoxy(33, 6); cout << "Lulus : " << lulus << endl;
            gotoxy(53, 6); cout << "Tidak Lulus : " << tidak_lulus << endl;
        
        }

        // Fungsi ini untuk header tampilan
        void tampilan_header(){ //frans
            system("cls");
        
            string blok1(183, '=');
            string blok2(183, '-');
        
            // untuk kepala tampilan
            gotoxy(0, 0); cout << blok1 << endl;
            gotoxy(74, 1); cout << "PROGRAM PENGUMUMAN KELULUSAN MAHASISWA\n";
            gotoxy(0, 2); cout << blok1 << endl;
        
            header_tabel();
        
            // untuk kepala tabel
            gotoxy(0, 7); cout << blok2 << endl;
            gotoxy(0, 9); cout << blok2 << endl;
        }

        // Fungsi menjalankan program
        void running_program(){ //fatih
            tampilan_header();
            tabel(25, nama_file.size(), false);

            for(int i = 0; i < nama_file.size(); i++){
                if(i < 25){
                    gotoxy(3, y + i); cout << i + 1 << endl;
                    gotoxy(11, y + i); cout << nama_file[i] << endl;
                }
            }

            bool running = true;
            tampilkan_nama("a", jlh);
        
            string input, hasil;
            gotoxy(0, 4); cout << "Cari Nama Mahasiswa" << endl;        
            gotoxy(0, 5); cout << "\tCari : "; cin >> input;

            system("cls");
            tampilan_header();
            tampilkan_nama(input, jlh);
            
            gotoxy(0, 4); cout << "Cari Nama Mahasiswa\n\tCari : " << input + "\n\n\n";
        }

    private:
        // Fungsi tampilkan nama sesuai input
        void tampilkan_nama(string huruf, int hitung){ //rio
            transform(huruf.begin(), huruf.end(), huruf.begin(), ::toupper);
            hitung = 0;
            int n, x = 70;
            for(int i = 0; i < nama_file.size(); i++){
                if(nama_file[i].substr(0, huruf.length()) == huruf){
                    string warna_merah = "";

                    for(char ch : huruf){
                        warna_merah += "\033[31m" + string(1, ch) + "\033[0m";
                    }
                
                    string sisanya = nama_file[i].substr(huruf.length());
                    penempatan_nilai(hitung, i);
                
                    gotoxy(3, y + hitung); cout << i + 1;
                    gotoxy(11, y + hitung); cout << warna_merah << sisanya;
                    n = i + 1;
                    hitung++;
                }
                if (hitung == 25) break;
            }

            int m = hitung;
            while((m < 25) && (n < nama_file.size())){
                gotoxy(3, y + m); cout << n + 1;
                gotoxy(11, y + m); cout << nama_file[n];
                penempatan_nilai(m, n);
            
                m++;
                n++;
            } 
            tabel(m, hitung, false);
        }

        // Fungsi check 
        bool check(int x){
            return ((x == 0) || (x == 8) || (x == 64) || (x == 78) || (x == 91) || (x == 104) || (x == 117) || (x == 130) || (x == 144) || (x == 157) || (x == 182));
        }

        // Fungsi untuk header tabel
        void header_tabel(){ //frans
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 183; j++){
                    if(i == 1){
                        if(check(j)){
                            gotoxy(j, 7 + i); cout << "|";
                        }
                        else{
                            gotoxy(3, 8); cout << "No.";
                            gotoxy(11, 8); cout << "Nama";
                            gotoxy(67, 8); cout << "Kehadiran";
                            gotoxy(80, 8); cout << "Tugas (10%)";
                            gotoxy(92, 8); cout << "Proyek (50%)";
                            gotoxy(107, 8); cout << "UTS (10%)";
                            gotoxy(120, 8); cout << "UAS (10%)";
                            gotoxy(132, 8); cout << "Nilai Akhir";
                            gotoxy(147, 8); cout << "Kategori";
                            gotoxy(165, 8); cout << "Kelulusan";
                        } 
                    }
                    else{
                        if(check(j)){
                            gotoxy(j, 7 + i); cout << "+";
                        }
                    }
                }
            }
        }

};

//fatih
class Metode_Sorting{
    private: 
        Metode_Searching metode1;
        int hitung = 25;

        // fungsi menampilkan ururtan
        void tampilkan_urutan_nilai(){            
            sort(data_mahasiswa.begin(), data_mahasiswa.end(), urutan_nilai);

            int x = 70;
            for (int i = 0; i < 25; i++){
                gotoxy(3, y + i); cout << i + 1;
                gotoxy(11, y + i); cout << data_mahasiswa[i].nama;
                gotoxy(x, y + i); cout << data_mahasiswa[i].kehadiran;
                gotoxy(x + 14, y + i); cout << data_mahasiswa[i].tugas;
                gotoxy(x + 27, y + i); cout << data_mahasiswa[i].proyek;
                gotoxy(x + 40, y + i); cout << data_mahasiswa[i].uts;
                gotoxy(x + 53, y + i); cout << data_mahasiswa[i].uas;
                gotoxy(x + 66, y + i); cout << data_mahasiswa[i].nilai_final;
                gotoxy(x + 80, y + i); cout << data_mahasiswa[i].kategori;
                gotoxy(x + 95, y + i); cout << data_mahasiswa[i].kelulusan;
            }
        }

    public:
        Metode_Sorting(){
            metode1.tampilan_header();
            tampilkan_urutan_nilai();
            metode1.tabel(hitung, hitung, true);
            gotoxy(150, 6); system("pause");
        }
};

int main(){
    srand(time(0));
    data_mahasiswa = input_nilai();
    Metode_Searching metode_searching;

    bool running = true;
    while(running){
        metode_searching.tampilan_header();
        metode_searching.running_program();

        char pilihan;
        gotoxy(90, 6); cout << "Menampilkan Peringkat 25 besar? [Y/N] "; cin >> pilihan;
        gotoxy(150, 6); system("pause");

        if((pilihan == 'y') || (pilihan == 'Y')){
            Metode_Sorting metode_sorting;
            running = true;
        }
        else{
            running = false;
        }
    }

    system("cls");
    string n(183, '=');
    cout << n << endl;
    gotoxy(85, 1); printf("Terima Kasih\n");
    gotoxy(83, 2); printf("Telah Menggunakan\n");
    gotoxy(85, 3); printf("Program Kami\n");
    gotoxy(83, 4); printf("Sampai Jumpa Lagi\n");
    cout << n << endl;
}

// fungsi check nilai terbesar
bool urutan_nilai(const kategori_penilaian& a, const kategori_penilaian& b){
    return a.nilai_final > b.nilai_final;
}

// Fungsi menampilkan nilai
vector<kategori_penilaian> input_nilai(){
    vector<int> hasil = nilai_mahasiswa();

    vector<kategori_penilaian> data;  
    vector<int> nilai_kehadiran = nilai_mahasiswa(); 
    vector<int> nilai_tugas = nilai_mahasiswa();
    vector<int> nilai_proyek = nilai_mahasiswa();
    vector<int> nilai_uts = nilai_mahasiswa();
    vector<int> nilai_uas = nilai_mahasiswa();

    int lulus = 0, tidak_lulus = 0, x = 70;
    for(int i = 0; i < hasil.size(); i++){
        kategori_penilaian mahasiswa;
        mahasiswa.nama = nama_file[i]; // untuk nama
        mahasiswa.kehadiran = nilai_kehadiran[i]; // 10%
        mahasiswa.tugas = nilai_tugas[i]; // 10%
        mahasiswa.proyek = nilai_proyek[i]; // 50%
        mahasiswa.uts = nilai_uts[i]; // 15%
        mahasiswa.uas = nilai_uas[i]; // 15%
        mahasiswa.nilai_final = (mahasiswa.kehadiran * 0.1) + (mahasiswa.tugas * 0.1) + (mahasiswa.proyek * 0.5) + (mahasiswa.uts * 0.15) + (mahasiswa.uas * 0.15); 
       
        if (mahasiswa.nilai_final >= 90) mahasiswa.kategori = "A+";
        else if (mahasiswa.nilai_final >= 85) mahasiswa.kategori = "A";
        else if (mahasiswa.nilai_final >= 80) mahasiswa.kategori = "A-";
        else if (mahasiswa.nilai_final >= 75) mahasiswa.kategori = "B+";
        else if (mahasiswa.nilai_final >= 70) mahasiswa.kategori = "B";
        else if (mahasiswa.nilai_final >= 65) mahasiswa.kategori = "B-";
        else if (mahasiswa.nilai_final >= 60) mahasiswa.kategori = "C+";
        else if (mahasiswa.nilai_final >= 55) mahasiswa.kategori = "C";
        else if (mahasiswa.nilai_final >= 50) mahasiswa.kategori = "C-";
        else if (mahasiswa.nilai_final >= 40) mahasiswa.kategori = "D";
        else mahasiswa.kategori = "E";

        if(mahasiswa.nilai_final >= 55){
            mahasiswa.kelulusan = "LULUS";
        }
        else{
            mahasiswa.kelulusan = "TIDAK LULUS";
        }
        
        data.push_back(mahasiswa);
    }
    return data;
}

// Fungsi membuat nilai
vector<int> nilai_mahasiswa(){
    vector<int> hasil;

    const int total = nama_file.size();
    int nilai;

    while(hasil.size() < total){
        int r = rand() % 1000;
        if ((r > 100) && (r < 500))
            nilai = 100;
        else 
            nilai = rand() % 100;
            
        hasil.push_back(nilai);
    }
    return hasil;
}

// Fungsi ini untuk membuka file nama mahasiswa
vector<string> buka_file(const string& nama_file){
    ifstream file(nama_file);
    string baris;
    bool nama;
    
    vector<string> nama_mahasiswa;
    if (file.is_open()) {
        while (getline(file, baris)){
            nama_mahasiswa.push_back(baris);
        }
        file.close();
    } 
    else{
        cout << "Gagal membuka file!. File mungkin beda path dengan kode";
    }
    return nama_mahasiswa;
}

// fungsi goto x,y
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}