#include "list_child.h"

void createList(List_child &L)
/* i.s: sembarang
   F.s: terbentuk list child kosong
//1301154118
//1301154230 */
{
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x)
/**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
//1301154118
//1301154230
{
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P)
/*I.S: P udah dialokasikan
  F.S: menempatkan element beralamat P pada awal list
//1301154118
//1301154230
*/
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P)
/*I.S: P udah dialokasikan
  F.S: menempatkan element beralamat P pada akhir list
//1301154118
//1301154230
*/
{
    if(first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}
void deleteFirst(List_child &L,address_child&P)
/*I.S: list sudah kosong
  F.S: menghapus element alamat pada element pertama list
//1301154118
//1301154230
*/
{
    if(first(L)!=NULL)
    {
        P = first(L);

        if(first(L) == L.last)
        {
            L.last = NULL;
            L.first = NULL;
        }
        else
        {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}
void deleteLast(List_child &L, address_child &P)
/*I.S: list sudah kosong
  F.S: menghapus element alamat pada element terakhir list
//1301154118
//1301154230
*/
{
    if(L.first!=NULL)
    {
        P = L.last;

        if(L.first == L.last)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}
void printInfo(List_child L)
/**
    * FS : menampilkan info seluruh elemen list L

//1301154118
//1301154230
  */
{
    address_child P = first(L);
    while(P !=NULL)
    {
        cout<<"ID UKM         :"<<info(P).id<<endl;
        cout<<"NAMA UKM       :"<<info(P).nama<<endl;
        cout<<"JENIS UKM      :"<<info(P).jenis<<endl;
        cout<<"TAHUN DIBENTUK :"<<info(P).tahun<<endl;
        cout<<"UMUR UKM       :"<<info(P).umur<<endl;
        cout<<"AKREDITASI UKM :"<<info(P).akreditasi<<endl<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x)
/**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
   //1301154118
//1301154230
 */
{
    address_child P = first(L);
    while(P != NULL)
    {
        if(info(P).id==x.id)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child Prec, address_child P)
/*I.S: P udah dialokasikan
  F.S: menempatkan element beralamat P sesudah element beralamat prec
//1301154118
//1301154230
*/
{
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteAfter(address_child Prec, address_child &P)
/*I.S: list sudah kosong
  F.S: menghapus element alamat pada element next(prec) list
//1301154118
//1301154230
*/

{
    P= Prec->next;

    Prec->next = P->next;
    Prec->next->prev = P->prev;

    P->next = NULL;
    P->prev = NULL;
}


void sorting1(List_child L)
/* F.S: Melakukan pengurutan  data pada umur
//1301154118
//1301154230
*/
{
    List_child lc;
    createList(lc);
    infotype_child infoc;

    address_child P = first (L);
    address_child Q;
    while(P !=NULL)
    {
        infoc.id=info(P).id;
        infoc.nama=info(P).nama;
        infoc.jenis=info(P).jenis;
        infoc.tahun=info(P).tahun;
        infoc.umur=info(P).umur;
        infoc.akreditasi=info (P).akreditasi;

        Q = alokasi(infoc);
        ascendingumur1(lc,Q);

        P = next(P);

    }
    ;
    printInfo(lc);


}
void ascending1(List_child &L, address_child P)
/*f.s: Mengurutkan berdasarkan id ukm
//1301154118
//1301154230
*/
{
    address_child Q=first(L);
    address_child prec=first(L);
    address_child r=findElm(L,info(P));
    if(r==NULL)
    {

        if ((first(L) == NULL) || (info(P).id <info(Q).id))
        {
            insertFirst(L,P);
        }
        else
        {
            Q = next(Q);

            while (Q !=NULL)
            {
                if (info(P).id> info(Q).id)
                {

                    prec =next(prec);
                }
                Q= next(Q);
            }
            if (next(prec) !=NULL)
            {
                insertAfter(prec,P);
            }
            else
            {
                insertLast(L,P);
            }


        }
    }
    else
    {
        cout<< "\n nim sudah digunakan" <<endl;
    }

}


void ascendingumur1(List_child &L, address_child P)
// f.s: Mengurutkan berdasarkan umur ukm
//1301154118
//1301154230
{
    address_child Q=first(L);
    address_child prec=first(L);

    if ((first(L) == NULL) || (info(P).umur <info(Q).umur))
    {
        insertFirst(L,P);
    }
    else
    {
        Q = next(Q);

        while (Q !=NULL)
        {
            if (info(P).umur> info(Q).umur)
            {

                prec =next(prec);
            }
            Q= next(Q);
        }
        if (next(prec) !=NULL)
        {
            insertAfter(prec,P);
        }
        else
        {
            insertLast(L,P);
        }
    }
}

void rataumur1 (List_child L)
/* melakukan rata rata berdasarkan umur
//1301154118
//1301154230
*/
{
    address_child P = first(L);
    int jumlah=0;
    double rata = 0;
    int i = 0;

    if (P != NULL)
    {
        while (P != NULL)
        {
            i++;
            jumlah = jumlah + info(P).umur;
            P = next(P);
        };

    }
    rata = jumlah/i;
    cout << rata << endl;
}





