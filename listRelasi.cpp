#include "listRelasi.h"
#include "menuTubes.h"

void createListRelasi(List_relasi &L){
    first(L) = NULL;
}
void insertFirst(List_relasi &L, address_relasi P){
    if(first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLast(List_relasi &L, address_relasi P){
    if(first(L) == NULL){
        insertFirst(L,P);
    }else{
        address_relasi Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}
void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P){
    if(first(L) == NULL){
        insertFirst(L,P);
    }else{
        if(first(L) == Prec){
            insertFirst(L,P);
        }else if(next(Prec) == NULL){
            insertLast(L,P);
        }else{
            next(P) = next(Prec);
            prev(next(Prec)) = P;
            prev(P) = Prec;
            next(Prec) = P;
        }
    }
}
void deleteFirst(List_relasi &L, address_relasi &P){
    if(first(L) == NULL){
        cout<<"[kosong]";
    }else{
        P = first(L);
        prev(next(P)) = NULL;
        first(L) = next(P);
        next(P) = NULL;

    }
}
void deleteLast(List_relasi &L, address_relasi &P){
    if(first(L) == NULL){
        cout<<"[kosong]";
    }else{
        P = first(L);
        while(P != NULL){
            P = next(P);
        }
        next(prev(P)) = NULL;
        prev(P) = NULL;
    }
}
void deleteAfter(List_relasi &L,address_relasi Prec, address_relasi &P){
    if(first(L) == NULL){
        cout<<"Kosong";
    }else{
        if(first(L) == P){
            deleteFirst(L,P);
        }else if(next(P) == NULL){
            deleteLast(L,P);
        }else{
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}
address_relasi alokasi(address_parent P, address_child C, infotypeR x){

    address_relasi Q = new elmRelasi;
    child(Q) = C;
    parent(Q) = P;
    info(Q) = x;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}
void dealokasi(address_relasi &P){
    delete P;
}
address_relasi findElm(List_relasi L, address_parent P, address_child C){
    address_relasi Q = first(L);
    while(Q != NULL){
        if(parent(Q) == P && child(Q) == C){
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}
void printInfo(List_relasi L){
    address_relasi Q = first(L);
    long budget = info(parent(Q)).needBudget - info(Q).gradeBudget;
    while(Q != NULL){
        cout<<info(parent(Q)).nameEvent<<"\n";
        cout<<info(child(Q)).namaSponsor<<"\n";
        cout<<info(Q).grade<<"\n";
        cout<<budget<<"\n";
    }
}
