#ifndef ZERORESERVATION_H_INCLUDED
#define ZERORESERVATION_H_INCLUDED
/*=======================================
=            ZeroReservation            =
=======================================*/
/**

	TODO:
	- import library
	- Procedure & Function
	- MultiLinked List

 */

/**
 *
 * library
 *
 */
 #include <iostream>
 #include <string.h>
 #include <windows.h>
 #include <conio.h>

#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define last(l) l.last
#define first(l) l.first
 using namespace std;

 /*----------  Pointer Declaration  ----------*/
 typedef struct elmPlane *addressPlane;
 typedef struct elmSchedules *addressSchedules;
 typedef struct elmPassenger *addressPassenger;
typedef struct elmListRelasi *addressRelasi;
/*----------  Data Type Declaration  ----------*/
 struct dataPlane {
 	string planeID;
 	string type;
 	string route;
 	long int price;
 	int capacity;
 };

 struct dataSchedules
 {
 	string schID;
 	string date;
 };

 struct dataPassenger{
 	string passengerID;
 	string name;
 	string username;
 	string password;
 	int age;
 	string gender;
 	string address;
 };


/*----------  Double Linked List Declaration ----------*/
struct schedules
{
	addressSchedules first;
	addressSchedules last;
};

struct plane
{
	addressPlane first;
	addressPlane last;
};

struct listRelasi{
    addressRelasi first;
    addressRelasi last;
};

/*----------  Single Linked List Declaration  ----------*/
struct passenger
{
	addressPassenger first;
};


/*----------  Element of Multi Linked List  ----------*/

struct elmSchedules
{
	dataSchedules info;
	addressSchedules next;
	addressSchedules prev;
	listRelasi child;
};

struct elmPlane
{
	dataPlane info;
//	passenger passengerList;
	addressPlane next;
	addressPlane prev;
};

struct elmPassenger
{
	dataPassenger info;
	addressPassenger next;
	addressPlane plane;
};

struct elmListRelasi {
    addressRelasi next;
    addressRelasi prev;
    addressPlane info ;
};





/*----------  Function & Procedure  ----------*/

/*===================================
=            Create List            =
===================================*/
void createListPlane(plane &l);
void createListSchedules(schedules &l);
void createListPassenger(passenger &l);
void createListRelasi(listRelasi &l);


/*=====  End of Create List  ======*/

/*==================================
=            Alocattion            =
==================================*/
addressSchedules alokasiSch(dataSchedules x);
addressPlane alokasiPlane(dataPlane x);
addressPassenger alokasiPassenger(dataPassenger x);
addressRelasi alokasiRelasi(addressPlane p);
/*=====  End of Alocattion  ======*/


/*==============================
=            Insert            =
==============================*/
/*----------  Option Insert  ----------*/
void insertOption(char &pilih);
/*----------  Schedules  ----------*/
void insertSchedulesMain(schedules &l);
void insertFirstSch(schedules &l , addressSchedules p);
void insertLastSch(schedules &l , addressSchedules p);

/*----------  Plane  ----------*/
void insertPlaneMain(plane &l);
void insertFirstPlane(plane &l , addressPlane p);
void insertLastPlane(plane &l , addressPlane p);

/*----------  Passenger  ----------*/
void insertPassengerMain(passenger &l);
void insertFirstPas(passenger &l, addressPassenger p);
void insertLastPas(passenger &l , addressPassenger p);
/*----------  Relasi  ----------*/
void insertFirst(listRelasi &l, addressRelasi p);
void insertLast(listRelasi &l, addressRelasi p);

/*=====  End of Insert  ======*/
/*----------  add  ----------*/
void addJadwaltoPlane(schedules &sch , plane &pln);
void addDataPassenger(passenger l , dataPassenger &x);
void addDataPlane(plane l , dataPlane &x);
void addDataSchedules(schedules l , dataSchedules &x);
void addPassengertoPlane(plane &pln , addressPassenger &pas);
/*=====  End of add  ======*/



/*==============================
=            Delete            =
==============================*/
/*----------  schedules  ----------*/
void deleteFirstSch(schedules &l);
void deleteLastSch(schedules &l);
void deleteSchbyID(schedules &l);
/*----------  plane  ----------*/
void deleteFirstPlane(plane &l);
void deleteLastPlane(plane &l);
void deletePlanebyID(plane &l);
/*----------  passenger  ----------*/
void deleteFirstPas(passenger &l);
void deleteLastPas(passenger &l);
void deletePasbyID(passenger &l);

/*=====  End of Delete  ======*/


/*============================
=            Edit            =
============================*/
void editSchedules(schedules &l);
void editPlane(plane &l);
void editPassenger(passenger &l);
/*=====  End of Edit  ======*/


/*========================================
=            Find & Searching            =
========================================*/
addressPlane findElmPlane(plane l , string planeID);
addressSchedules findElmSchedules(schedules l, string schID);
addressPassenger findElmPassenger(passenger l , string passengerID);
addressRelasi findElmRelasi(listRelasi l , string planeID);


/*=====  End of Find & Searching  ======*/

/*=============================
=            Print            =
=============================*/

void printInfoSchedules(schedules l);
void printInfoPlane(plane l);
void printInfoPassenger(passenger l);
void printAll(schedules l);
void printSemua(schedules l);
void printSch_Pln(schedules l);
void printPesanan(passenger l , addressPassenger p);
void printInfoRelasi(listRelasi l);
/*=====  End of Print  ======*/


/*----------  menu  ----------*/
void menuPassanger(schedules &sch , plane &pln , passenger &pas);
void menuAdmin(schedules &sch , plane &pln , passenger &pas);
void mainMenu(schedules &sch, plane &pln , passenger &pas);
void menuTambah(schedules &sch, plane &pln , passenger &pas);
void menuHapus(schedules &sch , plane &pln , passenger &pas);
void menuEdit(schedules &sch , plane &pln , passenger &pas);
void pesanPenerbangan(schedules &sch , plane &pln , passenger &pas);

/*----------  Exception Handler  ----------*/
bool is_number(const std::string& s);

/*----------  check no element  ----------*/
bool checkPlaneID(plane l , string ID);
bool checkSchedulesID(schedules l , string ID);
bool checkPassengerID(passenger l , string ID);

/*================================
=            #connect            =
================================*/

void connect(addressPlane p , addressPassenger q);
void disconnect(addressPassenger p);

/*=====  End of #connect  ======*/


#endif // ZERORESERVATION_H_INCLUDED
