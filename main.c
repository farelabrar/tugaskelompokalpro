#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct logistik {
    char nama_barang[50];
    char kondisi[20];
    int jumlah;
    char peminjam[50];
    char tanggal_peminjaman[20];
    char tanggal_pengembalian[20];
};

int pilihan, jumlah_barang = 0;
struct logistik data[50];

// fungsi untuk menambahkan data
void tambah_data() {
    system("cls");
    printf("Masukkan nama barang: ");
    scanf("%s", data[jumlah_barang].nama_barang);
    printf("Masukkan kondisi barang (baik/rusak): ");
    scanf("%s", data[jumlah_barang].kondisi);
    printf("Masukkan jumlah barang: ");
    scanf("%d", &data[jumlah_barang].jumlah);
    jumlah_barang++;
    printf("Data berhasil ditambahkan!\n");
}

// fungsi untuk mengedit data
void edit_data() {
    system("cls");
    int i, cari;
    char nama_barang[50];
        printf("Masukkan nama barang yang ingin diubah: ");
        scanf("%s", nama_barang);
        for (i = 0; i < jumlah_barang; i++) {
            if (strcmp(nama_barang, data[i].nama_barang) == 0) {
                cari = i;
                break;
                }
            }
            if (i == jumlah_barang) {
            printf("Barang tidak ditemukan!\n");
            } else {
            printf("Masukkan nama barang baru: ");
            scanf("%s", data[cari].nama_barang);
            printf("Masukkan kondisi barang baru (baik/rusak): ");
            scanf("%s", data[cari].kondisi);
            printf("Masukkan jumlah barang baru: ");
            scanf("%d", &data[cari].jumlah);
            printf("Data berhasil diubah!\n");
        }
}

// fungsi untuk mencari data
void cari_data() {
    system("cls");
    int i;
    char nama_barang[50];
        printf("Masukkan nama barang yang ingin dicari: ");
        scanf("%s", nama_barang);
        for (i = 0; i < jumlah_barang; i++) {
            if (strcmp(nama_barang, data[i].nama_barang) == 0) {
            printf("Nama barang: %s\n", data[i].nama_barang);
            printf("Kondisi barang: %s\n", data[i].kondisi);
            printf("Jumlah barang: %d\n",data[i].jumlah);
            break;
        }
}
            if (i == jumlah_barang) {
            printf("Barang tidak ditemukan!\n");
        }
}

// fungsi untuk mengurutkan data
void urut_data() {
    system("cls");
    int i, j;
    struct logistik temp;
    for (i = 0; i < jumlah_barang-1; i++) {
    for (j = i+1; j < jumlah_barang; j++) {
        if (strcmp(data[i].nama_barang, data[j].nama_barang) > 0) {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        }
    }
}
        printf("Data berhasil diurutkan!\n");
}

// fungsi untuk menampilkan kondisi barang
void kondisi_barang() {
    system("cls");
    int i;
    char kondisi[20];
        printf("Masukkan kondisi barang yang ingin ditampilkan (baik/rusak): ");
        scanf("%s", kondisi);
        for (i = 0; i < jumlah_barang; i++) {
            if (strcmp(kondisi, data[i].kondisi) == 0) {
            printf("Nama barang: %s\n", data[i].nama_barang);
            printf("Kondisi barang: %s\n", data[i].kondisi);
            printf("Jumlah barang: %d\n", data[i].jumlah);
            }
        }
}

// fungsi untuk meminjam barang
void pinjam_barang() {
    system("cls");
    int i, cari;
    char nama_barang[50];
        printf("Masukkan nama barang yang ingin dipinjam: ");
        scanf("%s", nama_barang);
        for (i = 0; i < jumlah_barang; i++) {
            if (strcmp(nama_barang, data[i].nama_barang) == 0) {
            cari = i;
            break;
            }
        }
            if (i == jumlah_barang) {
            printf("Barang tidak ditemukan!\n");
            } else {
            if (data[cari].jumlah <= 0) {
            printf("Barang tidak tersedia!\n");
            } else {
            printf("Masukkan nama peminjam: ");
            scanf("%s", data[cari].peminjam);
            printf("Masukkan tanggal peminjaman (dd/mm/yyyy): ");
            scanf("%s", data[cari].tanggal_peminjaman);
            data[cari].jumlah--;
            printf("Barang berhasil dipinjam!\n");
            }
        }
}

// fungsi untuk mengembalikan barang
void kembalikan_barang(){
    system("cls");
    int i, cari;
    char nama_barang[50];
        printf("Masukkan nama barang yang ingin dikembalikan: ");
        scanf("%s", nama_barang);
        for (i = 0; i < jumlah_barang; i++) {
            if (strcmp(nama_barang, data[i].nama_barang) == 0) {
            cari = i;
            break;
            }
        }
            if (i == jumlah_barang) {
            printf("Barang tidak ditemukan!\n");
            } else {
            if (strcmp(data[cari].peminjam, "") == 0) {
            printf("Barang belum pernah dipinjam!\n");
            } else {
            printf("Masukkan tanggal pengembalian (dd/mm/yyyy): ");
            scanf("%s", data[cari].tanggal_pengembalian);
            strcpy(data[cari].peminjam, "");
            data[cari].jumlah++;
            printf("Barang berhasil dikembalikan!\n");
            }
        }
}

int main() {
do {
    // system("cls");
    printf(" _____________________________________________________________\n");
    printf("|=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=|\n");
    printf("|========== FINAL PROJECT SISTEM DATA LOGISTIK ITTS ==========|\n");
    printf("|============= FARREL ABRAR/RIZKI FIR/ABYAN J ================|\n");
    printf("|================ CONTACT US : 081357586627 ==================|\n");
    printf("|=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=|\n");
    printf("|                                                             |\n");
    printf("|                        PILIH MENU:                          |\n");
    printf("|\t1. Tambah data                                        |\n");
    printf("|\t2. Edit data                                          |\n");
    printf("|\t3. Cari data                                          |\n");
    printf("|\t4. Urutkan data                                       |\n");
    printf("|\t5. Tampilkan kondisi barang                           |\n");
    printf("|\t6. Pinjam barang                                      |\n");
    printf("|\t7. Kembalikan barang                                  |\n");
    printf("|\t8. Keluar                                             |\n");
    printf("|_____________________________________________________________|\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);
        switch (pilihan) {
            system("cls");
            case 1:
                tambah_data();
                break;
            case 2:
                edit_data();
                break;
            case 3:
                cari_data();
                break;
            case 4:
                urut_data();
                break;
            case 5:
                kondisi_barang();
                break;
            case 6:
                pinjam_barang();
                break;
            case 7:
                kembalikan_barang();
                break;

            case 8:
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
            }
} while (pilihan != 8);

return 0;
}
