#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main()
{
    List_child lc;
    createList(lc);
    List_parent lp;
    createList(lp);
    infotype_parent infop;
    infotype_child infoc;
    int pilihan;
    int umur;
    string nama, jurusan,kelas,tempat,tanggal_lahir, nama_ukm, tgl;
    int nim;
    //1301154118
//1301154230

    do
    {
        system("cls");
        cout<<"Menu : "<<endl;
        cout<<"1. Input Mahasiswa"<<endl;
        cout<<"2. Input UKM"<<endl;
        cout<<"3. Tambah UKM Mahasiswa"<<endl;
        cout<<"4. Cari Mahasiswa"<<endl;
        cout<<"5. cari ukm "<<endl;
        cout<<"6.  delete mahasiswa"<<endl;
        cout<<"7. lihat data keseluruhan"<<endl;
        cout<<"8. sorting mahasiswa"<<endl;
        cout<<"9. sorting ukm"<<endl;
        cout<<"10. reporting"<<endl;
        cout<<"11. reporting1"<<endl;
        cout<<"12. Keluar"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        if(pilihan==1)
            //1301154118
            //1301154230
        {
            cout<<"Input Mahasiwa"<<endl;
            cout<<"nim                 :";
            cin>> infop.nim;
            cout<<"nama                :";
            cin>> infop.nama;
            cout<<"jurusan             :";
            cin>>infop.jurusan;
            cout<<"kelas               :";
            cin>>infop.kelas;
            cout<<"tempat              :";
            cin>>infop.tempat;
            cout<<"tanggal lahir       :";
            cin>>infop.tanggal_lahir;
            cout<<"umur mahasiswa     :";
            cin>>infop.umur;

            address_parent p = alokasi(infop);
            ascending(lp,p);
            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==2)
        {
            cout<<"Input UKM"<<endl;
            cout<<"ID Ukm :";
            cin>>infoc.id;
            cout<<"Nama Ukm :";
            cin>>infoc.nama;
            cout<<"jenis ukm:";
            cin>>infoc.jenis;
            cout<<"tahun berdiri Ukm :";
            cin>>infoc.tahun;
            cout<<"umur Ukm :";
            cin>>infoc.umur;
            cout<<"akreditasi Ukm :";
            cin>>infoc.akreditasi;

            address_child c = alokasi(infoc);
            ascending1(lc,c);
            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==3)
        {
            cout<<"Tambah UKM Mahasiswa"<<endl;
            cout<<"id ukm :";
            cin>> infoc.id;
            cout<<"nim mahasiswa :";
            cin>> infop.nim;
            address_parent p= findElm(lp, infop);
            address_child c=findElm(lc,infoc);
            if((p!=NULL) && (c!=NULL))
            {
                address_relasi r = alokasi(c);
                insertFirst(p->child,r);
            }
            else
            {
                cout<<"tidak ditemukan"<<endl;
            }

            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==4)
        {
            cout<<"cari mhs :"<<endl;
            cout<<"nim mahasiswa :";
            cin>> infop.nim;

            address_parent p= findElm(lp, infop);
            if(p!=NULL )
            {
                cout<<"nama mahasiswa   :"<<info(p).nama<< endl;
                cout<<"nim mahasiswa    :"<<info(p).nim<<endl;
                cout<<"kelas            :"<<info(p).kelas<<endl;
                cout<<"jurusan          :"<<info(p).jurusan<<endl;
                cout<<"tempat           :"<<info(p).tempat<<endl;
                cout<<"tanggal lahir    :"<<info(p).tanggal_lahir<<endl;
                cout<<"umur             :"<<info(p).umur<<endl;

            }
            else
            {
                cout<<"data error"<<endl;
            }

            getch();
            //1301154118
//1301154230
        }

        else if(pilihan==5)
        {
            cout<<"cari ukm :"<<endl;
            cout<<"ID ukm :";
            cin>> infoc.id;

            address_child c= findElm(lc, infoc);
            if(c!=NULL )
            {
                cout<<"Nama ukm     :"<<info(c).nama <<endl;
                cout<<"jenis ukm    :"<<info(c).jenis <<endl;
                cout<<"tahun berdiri:"<<info(c).tahun <<endl;
                cout<<"umur         :"<<info(c).umur <<endl;
                cout<<"akreditas    :"<<info(c).akreditasi <<endl;

            }
            else
            {
                cout<<"data error"<<endl;
            }

            getch();
            //1301154118
//1301154230
        }

        else if(pilihan==6)
        {
            cout<<"delete data"<<endl;
            {
                createList(lp);
                createList(lc);
            }

            cout<<"data kosong"<<endl;

            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==7)
        {
            cout<<" lihat data keseluruhan"<<endl;
            {
                printInfo(lp);
                printInfo(lc);
            }


            getch();
            //1301154118
//1301154230
        }

        else if(pilihan==8)
        {
            cout<<"sorting mahasiswa"<<endl;
            sorting(lp);
            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==9)
        {
            cout<<"sorting ukm"<<endl;
            sorting1(lc);
            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==10)
        {
            cout<<"rata rata umur"<<endl;
            rataumur(lp);

            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==11)
        {
            cout<<"rata rata umur"<<endl;
            rataumur1(lc);

            getch();
            //1301154118
//1301154230
        }
        else if(pilihan==12)
        {
            cout<<"Terima Kasih";
            getch();
        }
        else
        {
            cout<<"Menu tidak tersedia"<<endl;
            getch();
            //1301154118
//1301154230
        }
    }
    while(pilihan!=12);
}
