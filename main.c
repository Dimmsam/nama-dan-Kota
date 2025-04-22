#include "NSLL.h"

int main() {
    int n = 0;
    char inputNama[50], inputKota[50];
    int pilihan;

    do {
        printf("\n=== Menu Data Kota ===\n");
        printf("1. Tambah Kota Baru\n");
        printf("2. Entry nama ke kota\n");
        printf("3. Tampilkan semua kota dan nama\n");
        printf("4. Tampilkan nama-nama dalam satu kota\n");
        printf("5. Hapus data kota beserta nama\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                if (n >= 10) {
                    printf("Kota sudah mencapai batas maksimum!\n");
                    break;
                }
                printf("Masukkan nama kota baru: ");
                fgets(inputKota, sizeof(inputKota), stdin);
                inputKota[strcspn(inputKota, "\n")] = '\0';

                bool ada = false;
                for (int i = 0; i < n; i++) {
                    if (strcmp(namaKota[i].kt, inputKota) == 0) {
                        ada = true;
                        break;
                    }
                }

                if (ada) {
                    printf("Kota sudah terdaftar!\n");
                } else {
                    strcpy(namaKota[n].kt, inputKota);
                    namaKota[n].p = NULL;
                    n++;
                    printf("Kota berhasil ditambahkan!\n");
                }
                break;

            case 2:
                printf("Masukkan nama kota: ");
                fgets(inputKota, sizeof(inputKota), stdin);
                inputKota[strcspn(inputKota, "\n")] = '\0';

                printf("Masukkan nama orang: ");
                fgets(inputNama, sizeof(inputNama), stdin);
                inputNama[strcspn(inputNama, "\n")] = '\0';

                EntryNama(namaKota, n, inputKota, inputNama);
                break;

            case 3:
                TampilPerKota(namaKota, n);
                break;

            case 4:
                printf("Masukkan nama kota: ");
                fgets(inputKota, sizeof(inputKota), stdin);
                inputKota[strcspn(inputKota, "\n")] = '\0';

                TampilNamaKota(namaKota, n, inputKota);
                break;

            case 5:
                printf("Masukkan nama kota yang akan dihapus: ");
                fgets(inputKota, sizeof(inputKota), stdin);
                inputKota[strcspn(inputKota, "\n")] = '\0';

                DeleteKota(namaKota, &n, inputKota);
                break;

            case 0:
                printf("Keluar...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}