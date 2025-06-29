#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(){
    int pilih_kategori, pilih_makanan, pilih_minuman, pilih_atk, harga, n;
    float hasil;
    string jenis_makanan;
    
    //ini untuk kategori
    kategori: 
    system("cls");
    printf("Kategori Produk\n");
    printf("[1] Makanan\n");
    printf("[2] Minuman \n");
    printf("[3] Alat Tulis Kantor \n\n");
    printf("Silahkan masukkan pilihan : "); scanf("%d", &pilih_kategori);

    if(pilih_kategori == 1) goto makanan;
    else if(pilih_kategori == 2) goto minuman;
    else if(pilih_kategori == 3) goto atk;
    else{
        printf("Silahkan masukkan angka yang tepat\n");
        system("pause");
        goto kategori;
    }
    
    //produk kategori makanan
    makanan: 
    system("cls");
    cout << "Kategori Makanan\n";
    cout << "_____________________________________________\n";
    cout << "| No | Nama Produk    |   Harga    | Diskon |\n";
    cout << "|____|________________|____________|________|\n";
    cout << "|  1 | Chicken Nugget | Rp  40.000 |   15%  |\n";
    cout << "|  2 | Sari Roti      | Rp  20.000 |   10%  |\n";
    cout << "|  3 | Chitato        | Rp  12.000 |   50%  |\n";
    cout << "|  4 | Roma Kelapa    | Rp  15.000 |   30%  |\n";
    cout << "|  5 | Selai Olai     | Rp   8.000 |   25%  |\n";
    cout << "|  6 | Onigiri        | Rp  20.000 |    5%  |\n";
    cout << "|  7 | Kinder Joy     | Rp  25.000 |    0%  |\n";
    cout << "|  8 | Roti Selamat   | Rp  18.000 |   40%  |\n";
    cout << "|  9 | Orong-orong    | Rp  30.000 |    0%  |\n";
    cout << "| 10 | Quaker Oat     | Rp 200.000 |   35%  |\n";
    cout << "|____|________________|____________|________|\n";

    printf("\nSilahkan masukkan nomor produk : "); scanf("%d", &pilih_makanan);
    switch (pilih_makanan){
        case 1:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.85 * 40000 * n;
            harga = floor(0.85 * 40000 * n);
            jenis_makanan += "| Chicken Nugget                 |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 2:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.9 * 20000 * n;
            harga = floor(0.9 * 20000 * n);
            jenis_makanan += "| Sari Roti                      |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 3:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.5 * 12000 * n;
            harga = floor(0.5 * 12000 * n);
            jenis_makanan += "| Chitato                        |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 4:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.7 * 15000 * n;
            harga = floor(0.7 * 15000 * n);
            jenis_makanan += "| Roma Kelapa                    |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 5:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.75 * 8000 * n;
            harga = floor(0.75 * 8000 * n);
            jenis_makanan += "| Selai Olai                     |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 6:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.95 * 20000 * n;
            harga = floor(0.95 * 20000 * n);
            jenis_makanan += "| Onigiri                        |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 7:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1 * 25000 * n;
            harga = floor(1 * 25000 * n);
            jenis_makanan += "| Kinder Joy                     |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 8:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.6 * 18000 * n;
            harga = floor(0.6 * 18000 * n);
            jenis_makanan += "| Roti Selamat                   |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 9:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1 * 30000 * n;
            harga = floor(1 * 30000 * n);
            jenis_makanan += "| Orong-orong                    |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 10:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.65 * 200000 * n;
            harga = floor(0.65 * 200000 * n);
            jenis_makanan += "| Quaker Oat                     |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        default :
            printf("Pilihan Tidak Valid");
    }
        goto hasil_akhir;
        
    //produk kategori minuman
    minuman:
    system("cls");
    cout << "Kategori Makanan\n";
    cout << "_____________________________________________\n";
    cout << "| No | Nama Produk         |   Harga    | Diskon |\n";
    cout << "|____|_____________________|____________|________|\n";
    cout << "|  1 | Susu Bayi (800g)    | Rp 310.000 |   16%  |\n";
    cout << "|  2 | Diabetasol (570g)   | Rp 140.000 |   15%  |\n";
    cout << "|  3 | Jus Jeruk (1 L)     | Rp  32.000 |   41%  |\n";
    cout << "|  4 | Sirup (400 ml)      | Rp  30.000 |   40%  |\n";
    cout << "|  5 | Air Mineral (600 ml)| Rp   5.000 |    0%  |\n";
    cout << "|  6 | Air Mineral (1.5 L) | Rp   8.000 |    0%  |\n";
    cout << "|  7 | Air Mineral (19 L)  | Rp  25.000 |    0%  |\n";
    cout << "|  8 | Hilo (12 x 15g)     | Rp 104.000 |   14%  |\n";
    cout << "|  9 | Susu UHT            | Rp  30.000 |    0%  |\n";
    cout << "| 10 | Kopi (400g)         | Rp  40.000 |    0%  |\n";
    cout << "|____|_____________________|____________|________|\n";
    
    printf("\nSilahkan masukkan nomor produk : "); scanf("%d", &pilih_minuman);
    switch (pilih_minuman){
        case 1:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.84 * 310000 * n;
            harga = floor(0.84 * 310000 * n);
            jenis_makanan += "| Susu Bayi                      |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 2:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.85 * 140000 * n;
            harga = floor(0.85 * 140000 * n);
            jenis_makanan += "| Diabetasol                     |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 3:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.59 * 32000 * n;
            harga = floor(0.59 * 32000 * n);
            jenis_makanan += "| Jus Jeruk                      |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 4:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.6 * 30000 * n;
            harga = floor(0.6 * 30000 * n);
            jenis_makanan += "| Sirup                          |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 5:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1 * 5000 * n;
            harga = floor(1 * 5000 * n);
            jenis_makanan += "| Air Mineral (600 ml)           |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 6:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1 * 8000 * n;
            harga = floor(1 * 8000 * n);
            jenis_makanan += "| Air Mineral (1.5L)             |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 7:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1 * 25000 * n;
            harga = floor(1 * 25000 * n);
            jenis_makanan += "| Air Mineral (19L)              |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 8:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 0.86 * 104000 * n;
            harga = floor(0.86 * 104000 * n);
            jenis_makanan += "| Hilo                           |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 9:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1 * 30000 * n;
            harga = floor(1 * 30000 * n);
            jenis_makanan += "| Susu UHT                       |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 10:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1 * 60000 * n;
            harga = floor(1 * 60000 * n);
            jenis_makanan += "| Kopi                           |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        default :
            printf("Pilihan Tidak Valid");
    }
    goto hasil_akhir;
        
    //produk kategori alat tulis kantor
    atk:
    system("cls");
    cout << "Kategori Alat Tulis Kantor\n";
    cout << "____________________________________________________\n";
    cout << "| No | Nama Produk                    |   Harga    |\n";
    cout << "|____|________________________________|____________|\n";
    cout << "|  1 | Pensil 2B                      | Rp  2.000  |\n";
    cout << "|  2 | Pulpen (Biru)                  | Rp  3.000  |\n";
    cout << "|  3 | Buku Catatan (A5, 100 halaman) | Rp 15.000  |\n";
    cout << "|  4 | Penghapus                      | Rp  1.500  |\n";
    cout << "|  5 | Rautan Pensil                  | Rp  2.500  |\n";
    cout << "|  6 | Stapler                        | Rp 25.000  |\n";
    cout << "|  7 | Kertas HVS A4 (500 lembar)     | Rp 50.000  |\n";
    cout << "|  8 | Pita Stapler                   | Rp  5.000  |\n";
    cout << "|  9 | Spidol Permanen                | Rp  4.000  |\n";
    cout << "| 10 | Binder Clip ( ukuran 25mm)     | Rp  3.000  |\n";
    cout << "|____|________________________________|____________|\n";
    
    printf("\nSilahkan masukkan nomor produk : "); scanf("%d", &pilih_atk);
    switch (pilih_atk){
        case 1:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 2000 * n;
            harga = floor(2000 * n);
            jenis_makanan += "| Pensil 2B                      |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 2:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 3000 * n;
            harga = floor(3000 * n);
            jenis_makanan += "| Pulpen                         |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 3:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 15000 * n;
            harga = floor(15000 * n);
            jenis_makanan += "| Buku Catatan                   |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 4:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 1500 * n;
            harga = floor(1500 * n);
            jenis_makanan += "| Penghapus                      |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 5:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 2500 * n;
            harga = floor(2500 * n);
            jenis_makanan += "| Rautan Pensil                  |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 6:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 25000 * n;
            harga = floor(25000 * n);
            jenis_makanan += "| Stapler                        |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 7:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 50000 * n;
            harga = floor(50000 * n);
            jenis_makanan += "| Kertas HVS A4                  |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 8:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 5000 * n;
            harga = floor(5000 * n);
            jenis_makanan += "| Pita Stapler                   |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 9:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 4000 * n;
            harga = floor(4000 * n);
            jenis_makanan += "| Spidol Permanen                |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        case 10:
            printf("Ingin beli berapa : ");
            scanf("%i",&n);
            hasil = hasil + 3000 * n;
            harga = floor(3000 * n);
            jenis_makanan += "| Binder Clip                    |    " + to_string(n) + "    |    " + to_string(harga) + "\n";
            break;
        default :
            printf("Pilihan Tidak Valid");
    }
    goto hasil_akhir;

    hasil_akhir:
    char beli_lagi;

    cout << fixed << setprecision(0);
    cout << "Apakah ingin membeli produk lain>? [Y/N]"; cin >> beli_lagi;
    if(beli_lagi == 'Y' || beli_lagi == 'y') goto kategori;
    else{
        if(hasil >= 500000){
            hasil = 0.9 * hasil;
        }
    }

    system("cls");
    printf("Anda membeli : \n");
    cout << "_______________________________________________________________\n";
    cout << "| Nama                           |  Jumlah |       Harga      |\n";
    cout << "|________________________________|_________|__________________|\n";
    cout << jenis_makanan;
    cout << "|________________________________|_________|__________________|\n";
    cout << "Total belanja anda = Rp " << hasil;
}