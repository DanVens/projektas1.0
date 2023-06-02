#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "bibliotekos.h"
#include "struktura.h"
#include <deque>

struct studentas //struktūra, nusakanti studento duomenis
{
    string vardas, pavarde;
    deque<int> paz;
    int egz;
    double vidurkis;
    double mediana;
};

void pildymas(deque<studentas>& a);
void rusiavimas(deque<int>& arr, int low, int high);
void merge(deque<studentas>& A, int low, int mid, int high);
bool palyginimas(const studentas& a, const studentas& b);
void rusiavimasStudentu(deque<studentas>& A, int low, int high);
void galutinisVid(studentas& A);
void galutinisMed(studentas& A);
void Spausdinimas(deque<studentas>& A);
void FailuGeneravimas(int& pazsk);
void perrasymas(int pazsk);

#endif  // FUNKCIJOS_H
