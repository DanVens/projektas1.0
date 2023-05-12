#include "Header.h"
struct studentas //struktūra, nusakanti studento duomenis
{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double vidurkis;
    string metodas;
};
void pildymas(vector <studentas> &a) //pildo studentų vektorių
{
    studentas b;
    int n = 0;
    int y = 0;
    int dydis = 0;
    string s, arrandom;
    cout << "iveskite varda ir pavarde: ";
    cin >> b.vardas >> b.pavarde;
    cout << endl;
    while (true)
    {
        cout << "jei norite ranka pildyti studento duomenis, spauskite x, jei norite atsitiktinai generuoti studento duomenis, spauskite y: ";
        cin >> arrandom;
        if (arrandom == "x") //jei ivedamas simbolis x, pildomi duomenys ranka
        {
            cout << "iveskite pazymius po viena nuo 1 iki 10 ir po kiekvieno spauskite enter (iveskite x, kai busite ivede visus pazymius): " << endl;
            while (true)
            {
                cout << "\npazymys " << b.paz.size() + 1 << ": ";
                try
                {
                    cin >> s;
                    int i = stoi(s);
                    if (i > 0 && i < 11)
                    {
                        b.paz.push_back(i);

                    }
                    else cout << "pazymys nera tarp 1 ir 10, bandykite dar karta\n";
                }
                catch (...)
                {
                    if (s == "x" && b.paz.size() != 0)
                        break;
                    else if (s == "x")
                        cout << "turi buti ivestas bent vienas pazymys, bandykite vel\n";
                    else cout << "netinkami duomenys, bandykite vel\n";
                }   //vedami pažymiai, jei netinkami duomenys, vėl prašoma pažymio
                cin.clear();
            }
            while (true)
            {
                try
                {
                    cout << "iveskite egzamino rezultata: ";
                    cin >> s;
                    int i = stoi(s);
                    if (i > 0 && i < 11)
                    {
                        b.egz = i;
                        break;
                    }
                    else cout << "pazymys nera tarp 1 ir 10, bandykite dar karta\n";
                }
                catch (...)
                {
                    cout << "netinkami duomenys, bandykite vel\n";
                }   //vedamas egzamino rezultatas, jei netinkami duomenys, vėl prašoma pažymio
            }
            a.push_back(b);
            cin.clear();
            break;
        }
        else if (arrandom == "y")
        {
            try
            {
                cout << "iveskite, kiek pazymiu norite generuoti: ";
                cin >> dydis;
            }
            catch (...)
            {
                cout << "netinkami duomenys, bandykite vel\n";
            }
            cin.clear();
            srand(time(NULL));
            int rand_sk;
            for (int i = 0; i < dydis; i++) //generuojami ir pildomi skaičiai
            {
                rand_sk = rand();
                while (rand_sk > (RAND_MAX - (RAND_MAX % 10)) && rand_sk != 0); //generuojamas skaičius, kol gaunamas toks, kuris neišeina iš nustatytų ribų
                if (rand_sk % 10 == 0)
                    rand_sk = 10;
                else rand_sk = rand_sk % 10;
                b.paz.push_back(rand_sk);
            }
            while (rand_sk > (RAND_MAX - (RAND_MAX % 10)));
            if (rand_sk % 10 == 0)
                rand_sk = 10;
            else rand_sk = rand_sk % 10;
            b.egz = rand_sk;
            a.push_back(b);
            cin.clear();
            break;
        }
        cout << "netinkami duomenys, bandykite vel\n";
    }
}
void rusiavimas(studentas A)  //rūšiuojami studento pažymiai
{
    int i, j;
    for (i = 0; i < A.paz.size() - 1; i++)
        for (j = 0; j < A.paz.size() - i - 1; j++)
            if (A.paz[j] > A.paz[j + 1])
                swap(A.paz[j], A.paz[j + 1]);
}
void galutinisVid(studentas &A)
{
    double galutinis, vid, sum = 0;
    for (int i = 0; i < A.paz.size(); i++)
    {
        sum = sum + A.paz[i];
    }
    vid = sum / A.paz.size();
    galutinis = 0.4 * vid + 0.6 * A.egz;
    A.vidurkis = galutinis;
}
void galutinisMed(studentas &A)
{
    double galutinis, med = 0;
    int vidurinis = A.paz.size() / 2;
    if (A.paz.size() % 2 == 0)
        med = (A.paz[vidurinis - 1] + A.paz[vidurinis]) / 2.0;
    else med = A.paz[vidurinis];
    galutinis = 0.4 * med + 0.6 * A.egz;
    A.vidurkis = galutinis;
}
void Spausdinimas(vector<studentas> A)
{
    cout << setw(10) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis" << endl;
    cout << "---------------------------------------------------\n";
    for (int y = 0; y < A.size(); y++)
    {
        if (A[y].metodas == "v")
            cout << setw(10) << A[y].vardas << setw(15) << A[y].pavarde << setw(15) << fixed << setprecision(2) << A[y].vidurkis << " (vidurkis)" << endl;
        else if (A[y].metodas == "m")
            cout << setw(10) << A[y].vardas << setw(15) << A[y].pavarde << setw(15) << fixed << setprecision(2) << A[y].vidurkis << " (mediana)" << endl;
    }
    
}
int main()
{
    vector<studentas> S;
    int dydis = 1;
    int n = 1;
    string taip, mv;
    for (int i = 0; i < n; i++)
    {
        pildymas(S);
        rusiavimas(S[i]);
        while (true)
        {
            cout << "jei norite galutinio rezultato, suskaiciuoto pagal vidurki, iveskite v ir enter, jei norite pagal mediana, iveskite m ir enter: ";
            cin >> mv;
            S[i].metodas = mv;
            if (mv == "v")
            {
                galutinisVid(S[i]);
                Spausdinimas(S);
                break;
            }
            else if (mv == "m")
            {
                galutinisMed(S[i]);
                Spausdinimas(S);
                break;
            }
            cout << "netinkami duomenys, bandykite vel\n";
        }
        cout << "jeigu norite ivesti dar viena studenta, iveskite y ir spauskite enter, jei ne, iveskite bet koki kita simboli ir spauskite enter: ";
        cin >> taip;
        if (taip == "y")
            n++;
    }
}
