#include "list_relasi.h"

void createList(List_relasi &L)
/**
    * FS : first(L) diset Nil
    */
{
    first(L) = NULL;
}

address_relasi alokasi(address_child C)
/**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
{
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P)
/**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
{
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List_relasi &L, address_relasi P)
/*  IS : List_parent L mungkin kosong
    FS : elemen yang ditunjuk P menjadi elemen terakhir pada List_parent L
        next dari last elemen menunjuk ke first elemen
1301154118
1301154230 */
{
    if(L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        address_relasi q = L.first;
        while(q->next != NULL)
        {
            q=q->next;
        }
        q->next = P;
    }
}

void deleteFirst(List_relasi &L, address_relasi &P)
/* I.S : list tidak kosong
   F.S : alamat dari alamat element pertama list sebelum elemen pertama list dihapus
1301154118
1301154230 */
{
    if(L.first == NULL)
    {
        // isi pesan dalam kutip
        //cout << "List Telah Kosong. Tidak ada elemen yang dapat dihapus"<<endl;
    }
    else
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;

    }
}
void deleteLast(List_relasi &L, address_relasi &P)
/* I.S : list tidak kosong
   F.S : alamat dari alamat element terakhir list sebelum elemen terakhir list dihapus
1301154118
1301154230 */

{
    if(L.first == NULL)
    {
        // isi pesan dalam kutip
        //cout << "List Telah Kosong. Tidak ada elemen yang dapat dihapus"<<endl;
    }
    else
    {
        P=L.first;
        if(P->next == NULL)
        {
            L.first = NULL;

        }
        else
        {
            address_relasi q=P;
            while(q->next->next != NULL)
            {
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}

void printInfo(List_relasi L)
 /**
    * FS : menampilkan info seluruh elemen list L
    */
{
    address_relasi P = first(L);
    if (P == NULL)
    {
        cout << "Tidak punya UKM" << endl << endl;
    }
    else
    {
        while(P !=NULL)
        {
            cout<<"UKM : "<<info(info(P)).id<<endl<< endl;
            P = next(P);
        }
    }

}


address_relasi findElm(List_relasi L, address_child C)
/**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
{
    address_relasi P = first(L);
    while(P != NULL)
    {
        if(info(P)== C)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P)
/*  IS : List_parent L mungkin kosong
    FS : elemen yang ditunjuk P menjadi elemen prec pada List_parent L
    next dari last elemen menunjuk ke after elemen
//1301154118
//1301154230 */
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteAfter(address_relasi Prec, address_relasi &P)
/* I.S : list tidak kosong
   F.S : alamat dari next(prec) , menghapus next(prec) dari list
1301154118
1301154230 */
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;

}
