#include "bibliotekos.h"
#include "struktura.h"
void pildymas(vector <studentas>& a) //pildo studentų vektorių
{
    studentas b;
    int n = 0;
    int y = 0;
    int dydis = 0;
    string s, arrandom;
    while (true)
    {
        cout << "jei norite duomenis skaityti is failo, spauskite z, jei norite ranka pildyti studento duomenis, spauskite x, jei norite atsitiktinai generuoti studento duomenis, spauskite y: ";
        cin >> arrandom;
        if (arrandom == "x") //jei ivedamas simbolis x, pildomi duomenys ranka
        {
            cout << "iveskite varda ir pavarde: ";
            cin >> b.vardas >> b.pavarde;
            cout << endl;
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
            cout << "iveskite varda ir pavarde: ";
            cin >> b.vardas >> b.pavarde;
            cout << endl;
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
        else if (arrandom == "z")
        {
            string pav;
            while (true)
            {
                try
                {
                    cout << "iveskite failo pavadinima: ";
                    cin >> pav;
                    std::ifstream failas(pav);
                    if (!failas.is_open())
                    {
                        cout << "failas neegzistuoja, bandykite vel\n";
                        //throw std::runtime_error("failas neegzistuoja, bandykite vel\n");
                        continue;
                    }
                    string line;
                    while (std::getline(failas, line))
                    {
                        std::istringstream iss(line);
                        int num;
                        iss >> b.vardas >> b.pavarde >> b.metodas;
                        while (iss >> num) {
                            b.paz.push_back(num);
                        }
                        b.egz = b.paz.back();
                        b.paz.pop_back();
                        a.push_back(b);
                    }
                    break;
                }
                catch (...)
                {
                    cout << "netinkami failo duomenys\n";
                }
            }
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
bool palyginimas(studentas a, studentas b) {
    if (a.vardas == b.vardas) {
        return a.pavarde > b.pavarde;
    }
    return a.vardas > b.vardas;
}
void rusiavimasStudentu(std::vector<studentas>& A) 
{
    for (int i = 0; i < A.size() - 1; ++i) {
        for (int j = 0; j < A.size() - i - 1; ++j) {
            if (palyginimas(A[j], A[j + 1])) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}
void galutinisVid(studentas& A)
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
void galutinisMed(studentas& A)
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
        {
            galutinisVid(A[y]);
            cout << setw(10) << A[y].vardas << setw(15) << A[y].pavarde << setw(15) << fixed << setprecision(2) << A[y].vidurkis << " (vidurkis)" << endl;
        }
        else if (A[y].metodas == "m")
        {
            galutinisMed(A[y]);
            cout << setw(10) << A[y].vardas << setw(15) << A[y].pavarde << setw(15) << fixed << setprecision(2) << A[y].vidurkis << " (mediana)" << endl;
        }
    }

}
