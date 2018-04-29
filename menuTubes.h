#ifndef MENUTUBES_H_INCLUDED
#define MENUTUBES_H_INCLUDED
#include "libEvent.h"
#include "libSponsor.h"
#include "listRelasi.h"
void menuUtama(ListEvent Levent, ListChild Lsponsor, List_relasi Lrelasi);
void MenuSponsor(ListChild &Lsponsor);
void menuEvent(ListEvent &L);
void menuRelasi(ListEvent &Levent, ListChild &Lsponsor, List_relasi &Lrelasi);


#endif // MENUTUBES_H_INCLUDED
