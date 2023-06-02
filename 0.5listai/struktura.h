#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "bibliotekos.h"
#include "struktura.h"
struct studentas
{
    string vardas, pavarde;
    list<int> paz;
    int egz;
    double vidurkis;
    double mediana;
};

void pildymas(list<studentas>& a);
void rusiavimas(list<int>& lst, list<int>::iterator low, list<int>::iterator high);
void merge(list<studentas>& A, int low, int mid, int high);
bool palyginimas(const studentas& a, const studentas& b);
void rusiavimasStudentu(list<studentas>& A, int low, int high);
void galutinisVid(studentas& A);
void galutinisMed(studentas& A);
void Spausdinimas(const list<studentas> & A);
void FailuGeneravimas(int& pazsk);
void perrasymas(int pazsk);

#endif  // FUNKCIJOS_H
