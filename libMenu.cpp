#include "menuTubes.h"
void menuUtama(ListEvent Levent, ListChild Lsponsor, List_relasi Lrelasi){
    int pil;
    do{
        system("cls");
        cout<<"||========================================================||"<<endl;
        cout<<"||                     TUBES STD                          ||"<<endl;
        cout<<"||========================================================||"<<endl;
        cout<<"||     oleh : 1. Hariadi Adha Firmansyah (1301174252)     ||"<<endl;
        cout<<"||            2. Ivan Naufal (1301174318)                 ||"<<endl;
        cout<<"||========================================================||"<<endl;
        cout<<"  TUBES>>MENU UTAMA"<<endl<<endl;
        cout<<"  1. Event"<<endl;
        cout<<"  2. Sponsor"<<endl;
        cout<<"  3. Daftar kerjasama"<<endl;
        cout<<"  4. keluar"<<endl<<endl;
        cout<<"  Masukan pilihan [1/2/3/4] : "; cin>>pil;

        switch(pil){
            case 1 : menuEvent(Levent); break;
            case 2 : MenuSponsor(Lsponsor); break;
            case 3 : menuRelasi(Levent,Lsponsor,Lrelasi);break;
            case 4 : exit(0);break;

     //       case 3 :
        }
    }while(pil!=1||pil!=2);
}
void menuEvent(ListEvent &L){
    char menu;
    while(menu != '3'){
    do{
        system("cls");
        tengah1(120,"=====================================\n");
        tengah1(122,"DAFTAR EVENT\n");
        tengah1(120,"=====================================\n");
        cout<<endl;
        tengah1(25,"No. ");
        tengah1(30,"Nama Event ");
        tengah1(35,"Dana dibutuhkan ");
        tengah1(40,"Dana Kurang ");
        tengah1(45,"Dana Lebih ");

        cout<<endl;
        showEvent(L);
        cout<<endl;
        cout<<endl;
        tengah1(40,"1. Tambah Event \n");
        tengah1(38,"2. Hapus Event \n");
        tengah1(34,"3. Kembali \n");
        cout<<endl;
        tengah1(34,"Pilih Menu : ");
            cin>>menu;
            if(menu == '1'){
                system("CLS");
                tambahEvent(L);
            }else if(menu == '2'){
                system("CLS");
                string nmEvent;
                char pil;
                cout<<"Cari Nama Event : "; cin>>nmEvent;
                address_parent P = cariEvent(L,nmEvent);
                if(P == NULL){
                    cout<<"Tidak ada event bernama "<<nmEvent<<" "<<endl;
                    system("pause");
                    system("CLS");
                    menuEvent(L);
                }else{
                    cout<<info(P).nameEvent;
                    cout<<info(P).needBudget;
                    cout<<"\nApakah anda yakin menghapus data ini ? [y/t] "; cin>>pil;
                    if(pil == 'y'){
                        hapusEvent(L,nmEvent,P);
                        system("CLS");
                        menuEvent(L);
                    }else if(pil == 't'){
                        system("CLS");
                        menuEvent(L);
                    }
                }
            }/*else{
                tengah1(34,"input tidak valid, re input!\n");
            }*/
        }while((menu=='1')||(menu=='2')&&(menu=='3'));
    }
}

void MenuSponsor(ListChild &Lsponsor){
    int menu = 0;
    system("cls");
    tengah2(120,"=====================================\n");
    tengah2(122,"MENU SPONSOR\n");
    tengah2(120,"=====================================\n");
    cout<<endl;
    tengah2(25,"No. ");
    tengah2(35,"Nama Sponsor ");
    tengah2(45,"Budget ");
    tengah2(55,"Sisa Budget ");
    cout<<endl;
    show(Lsponsor);
    cout<<endl;
    cout<<endl;
    tengah2(40,"1. Tambah Sponsor \n");
    tengah2(38,"2. Hapus Sponsor \n");
    tengah2(33,"3. Kembali \n");
    cout<<endl;
    tengah2(34,"Pilih Menu : "); cin>>menu;

    if(menu == 1){
        system("CLS");
        insertData(Lsponsor);
    }else if(menu == 2){
        system("CLS");
        string nmSponsor;
        char pil;
        cout<<"Cari Nama Sponsor : "; cin>>nmSponsor;
        address_child P = cariSponsor(Lsponsor,nmSponsor);
        if(P == NULL){
            cout<<"Tidak Ditemukan";
            system("pause");
            system("CLS");
            MenuSponsor(Lsponsor);
        }else{
            cout<<info(P).namaSponsor;
            cout<<"\nApakah anda yakin menghapus data ini ? [y/t] "; cin>>pil;
            if(pil == 'y'){
                deleteData(Lsponsor,nmSponsor,P);
                system("CLS");
                MenuSponsor(Lsponsor);
            }else if(pil == 't'){
                system("CLS");
                MenuSponsor(Lsponsor);
            }
        }

    }else if(menu==3){

    }

}

void menuRelasi(ListEvent &Levent, ListChild &Lsponsor, List_relasi &Lrelasi){
    int pilih;
    char pilGrade; string nmevent,nmSponsor;
        system("cls");
        cout<<"1. Dukung Event\n";
        cout<<"2. Lihat Event Yang Didukung\n";
        cout<<"pilih : "; cin>>pilih;
    if(pilih == 1){
        int pilGrade;
        system("cls");
        address_relasi R;
        address_child C;
        relasi infoR;
        sponsor so;
        event ev;
        address_parent Pr = first(Levent);
        cin.ignore();
        if(Pr != NULL){
            cout<<"Nama Event\n";
            do{
                cout<<info(Pr).nameEvent<<endl;
                Pr = next(Pr);
            }while(Pr != first(Levent));
                        cout<<"Masukan Nama Event Yang Akan Didukung : "; getline(cin,nmevent);
            address_parent P = cariEvent(Levent,nmevent);
            if(P == NULL){
                system("pause");
            }

            if(P != NULL){

                system("cls");
                cout<<"Nama Event : "<<info(P).nameEvent<<endl;
                cout<<"Dana Yang Dibutuhkan : "<<info(P).needBudget<<endl;
                cout<<"Grade Dukungan : \n";
                cout<<"1.Super-Uranium = 100%\n";
                cout<<"2.Uranium = 65%\n";
                cout<<"3.Platinum = 50%\n";
                cout<<"4.Gold = 25%\n";
                cout<<"5.Silver = 15%\n";
                cout<<"6.Bronze = 10%\n";
                cout<<"7.Reguler = 5%\n";
                cout<<"8.Lainnya\n";
                cout<<"Pilih Grade Dukungan : "; cin>>pilGrade;
                cout<<"Masukan nama sponsor anda : "; cin>>nmSponsor;
                C = cariSponsor(Lsponsor,nmSponsor);
            if(C == NULL){
                cout<<"Sponsor tidak ditemukan !!";
                system("pause");
            }

                if(pilGrade == 1&&C!=NULL){
                    infoR.grade = "Super-Uranium";
                    infoR.gradeBudget = ((info(P).needBudget*100)/100);

                    if(info(C).budget>=info(R).gradeBudget){
                        long budgetSponsor = info(C).budget;
                        if(info(C).counter == 0){
                            info(C).sisaBudget = budgetSponsor - infoR.gradeBudget;
                            info(C).counter = info(C).counter+1;
                        }else if(info(C).counter >= 1){
                            info(C).sisaBudget = info(C).sisaBudget - infoR.gradeBudget;
                            info(C).counter = info(C).counter+1;
                        }

                        long danaEvent = info(P).needBudget;
                        info(P).minusBudget = danaEvent - infoR.gradeBudget;

                        R = alokasi(P,C,infoR);
                        insertFirst(Lrelasi,R);

                        cout<<"Selamat anda berhasil donasi sebesar "<<info(R).gradeBudget<<"\n";
                        cout<<info(C).counter;
                        system("pause");
                    }else{
                         cout<<"Maaf Budget Anda tidak cukup!!";
                         system("pause");
                    }




                }else if(pilGrade == 2&&C!=NULL){
                    infoR.grade = "Uranium";
                    infoR.gradeBudget = ((info(P).needBudget*65)/100);

                    if(info(C).budget>=0){
                        long budgetSponsor = info(C).budget;
                        info(C).sisaBudget = budgetSponsor - infoR.gradeBudget;

                        long danaEvent = info(P).needBudget;
                        info(P).minusBudget = danaEvent - infoR.gradeBudget;

                        R = alokasi(P,C,infoR);
                        insertFirst(Lrelasi,R);

                        cout<<"Selamat anda berhasil donasi sebesar "<<info(R).gradeBudget<<"\n";
                        system("pause");
                    }else{
                         cout<<"Maaf Budget Anda tidak cukup!!";
                         system("pause");
                    }




                }
            }
        }else{
            cout<<"Silahkan tambah event terlebih dahulu\n";
            system("pause");
        }


 }else if(pilih == 2){
        system("cls");
        //cout<<"Masukan Nama Sponsor : "; cin>>nmSponsor;
        address_relasi R = first(Lrelasi);
        if(R==NULL){
            cout<<"NULL";
        }else{
            cout<<info(parent(R)).nameEvent;
        }
        /*while(R != NULL){
            if(info(child(R)).namaSponsor == nmSponsor){
                cout<<info(parent(R)).nameEvent<<"\n";
                cout<<info(parent(R)).needBudget<<"\n";
                cout<<info(parent(R)).minusBudget<<"\n";
                cout<<info(child(R)).namaSponsor<<"\n";
                cout<<info(child(R)).budget<<"\n";
                cout<<info(child(R)).sisaBudget<<"\n";


                cout<<"\n\n";
            }
            R = next(R);
        }

            system("pause");
    }*/
    system("pause");
    }
}



