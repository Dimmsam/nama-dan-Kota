#ifndef NSLL_H
#define NSLL_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char infotype[50];
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
} ElmtList;

typedef struct {
    infotype kt;
    address p;
} Kota;

Kota namaKota[10];

typedef address List;

/**Modul Utama**/
bool isEmpty(List L);
void Create_Node(address *p, infotype data);
void DeAlokasi(address *p);
void PrintList(List L);

/**Modul Pencarian**/
address Search(List L, infotype X);
bool FSearch(List L, address P);
address SearchPrec(List L, infotype X);

/**Modul Penyisipan**/
void InsertFirst(List *L, address P);
void InsertAfter(List *L, address P, address Prec);
void InsertLast(List *L, address P);
void InsVFirst(List *L, infotype X);
void InsVLast(List *L, infotype X);

/**Modul Penghapusan**/
void DelFirst(List *L, address *P);
void DelP(List *L, infotype X);
void DelLast(List *L, address *P);
void DelAfter(List *L, address *Pdel, address Prec);
void DelVFirst(List *L, infotype *X);
void DelVLast(List *L, infotype *X);

/**Modul Pendukung**/
void EntryNama(Kota namaKota[], int n, char *namaKotaTarget, char *nama);
void TampilPerKota(Kota namaKota[], int n);
void TampilNamaKota(Kota namaKota[], int n, char *namaKotaTarget);
void DeleteKota(Kota namaKota[], int *n, char *namaKotaTarget);

#endif