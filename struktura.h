#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "bibliotekos.h"
#include "struktura.h"
struct studentas //struktūra, nusakanti studento duomenis
{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double vidurkis;
    string metodas = "";
};

void pildymas(vector<studentas>& a);
void rusiavimas(studentas A);
bool palyginimas(studentas a, studentas b);
void rusiavimasStudentu(vector<studentas>& A);
void galutinisVid(studentas& A);
void galutinisMed(studentas& A);
void Spausdinimas(vector<studentas> A);

#endif  // FUNKCIJOS_H
