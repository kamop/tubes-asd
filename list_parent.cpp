#include "list_parent.h"

void createList(List_parent &L)

// 1301154118
//1301154230
{
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x)

//1301154118
//1301154230
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P)
//1301154118
//1301154230
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List_parent &L, address_parent P)
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
        address_parent q = L.first;
        while(q->next != NULL)
        {
            q=q->next;
        }
        q->next = P;
    }
}

void printInfo(List_parent L)
//1301154118
//1301154230
{
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL)
    {
        do
        {
            cout<<"NAMA MAHASISWA :"<<info(P).nama<<endl;
            cout<<"NIM MAHASISWA  :"<<info(P).nim<<endl;
            cout<<"KELAS          :"<<info(P).kelas<<endl;
            cout<<"JURUSAN        :"<<info(P).jurusan<<endl;
            cout<<"TEMPAT         :"<<info(P).tempat<<endl;
            cout<<"TANGGAL LAHIR  :"<<info(P).tanggal_lahir<<endl;
            cout<<"UMUR           : "<<info(P).umur<<endl;
            printInfo(child(P));
            P = next(P);
        }
        while((P)!=first(L));
    }
}

void deleteFirst(List_parent &L, address_parent &P)
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
void deleteLast(List_parent &L, address_parent &P)
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
            address_parent q=P;
            while(q->next->next != NULL)
            {
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}
void insertAfter(List_parent &L, address_parent Prec, address_parent P)
/*  IS : List_parent L mungkin kosong
    FS : elemen yang ditunjuk P menjadi elemen prec pada List_parent L
    next dari last elemen menunjuk ke after elemen
//1301154118
//1301154230 */
{
    P->next = Prec->next;
    Prec->next = P;
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
/* I.S : list tidak kosong
   F.S : alamat dari next(prec) , menghapus next(prec) dari list
1301154118
1301154230 */
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}
address_parent findElm(List_parent L, infotype_parent x)
//1301154118
//1301154230
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    if (P != NULL)
    {
        do
        {
            if(info(P).nim == x.nim)
            {
                return P;
            }
            P = next(P);
        }
        while(P != first(L));
    }

    return NULL;
}

void sorting(List_parent L)
// f.s: mengurutkan data mahasiswa berdasarkan umur
//1301154118
//1301154230
{
    List_parent lp;
    createList(lp);
    infotype_parent infop;

    address_parent P = first (L);
    address_parent Q;
    do
    {
        infop.nama=info(P).nama;
        infop.nim=info(P).nim;
        infop.jurusan=info(P).jurusan;
        infop.kelas=info(P).kelas;
        infop.tempat=info(P).tempat;
        infop.tanggal_lahir=info (P).tanggal_lahir;
        infop.umur=info(P).umur;

        Q = alokasi(infop);

        address_relasi r = first(child(P));
        insertFirst(child(Q),r);

        ascendingumur(lp,Q);

        P = next(P);

    }
    while(P !=first(L));
    printInfo(lp);


}
void ascending(List_parent &L, address_parent P)
// f.s: membuat urutan dari NIM yang ada di menu sorting
//1301154118
//1301154230
{
    address_parent Q=first(L);
    address_parent prec=first(L);
    address_parent r=findElm(L,info(P));
    if(r==NULL)
    {

        if ((first(L) == NULL) || (info(P).nim <info(Q).nim))
        {
            insertFirst(L,P);
        }
        else
        {
            Q = next(Q);
            while ((info(P).nim > info(Q).nim) && (Q !=first(L)))

            {
                Q= next(Q);
                prec =next(prec);
            }
            insertAfter(L,prec,P);
        }
    }
    else
    {
        cout<< "\n nim sudah digunakan" <<endl;
    }

}

void ascendingumur(List_parent &L, address_parent P)
// f.s: Mengurutkan berdasarkan umur mahasiswa
//1301154118
//1301154230
{
    address_parent Q=first(L);
    address_parent prec=first(L);

    if ((first(L) == NULL) || (info(P).umur <=info(Q).umur))
    {
        insertFirst(L,P);
    }
    else
    {
        Q = next(Q);
        while ((info(P).umur >= info(Q).umur) && (Q !=first(L)))
        {
            Q= next(Q);
            prec =next(prec);
        }
        insertAfter(L,prec,P);
    }
}

void rataumur (List_parent L)
//f.s:mencari rata-rata umur sesuai data yg sudah inputkan
//1301154118
//1301154230
{
    address_parent P = first(L);
    int jumlah=0;
    double rata = 0;
    int i = 0;

    if (P != NULL)
    {
        do
        {
            i++;
            jumlah = jumlah + info(P).umur;
            P = next(P);
        }
        while (P != first(L));
    }
    rata = jumlah/i;
    cout << rata << endl;
}




