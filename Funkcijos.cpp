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
void FailuGeneravimas(int & pazsk)
{
    int rand_sk, i = 0;
    studentas a;
    vector <studentas> visi;
    cout << "kiek pazymiu noretumete generuoti kiekvienam studentui failuose? ";
    while (true)
    {
        try
        {
            cin >> pazsk;
            break;
        }
        catch (...)
        {
            cout << "netinkami duomenys, bandykite vel\n";
        }
    }
    auto start1000 = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::high_resolution_clock::now();
    ofstream failas1000("Studentai1000.txt");
    failas1000.clear();
    std::stringstream ss;
    ss << i + 1;
    failas1000 << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Metodas" << setw(25) << "Pazymiai\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    for (i = 0; i < 1000; i++)
    {
        int rand_sk = dist(gen);

        if (rand_sk == 0)
        {
            failas1000 << setw(25) << "Vardas" + ss.str() << setw(25) << "Pavarde" + ss.str() << setw(25) << "v";
        }
        else
        {
            failas1000 << setw(25) << "Vardas" + ss.str() << setw(25) << " Pavarde" + ss.str() << setw(25) << "m";
        }

        for (int y = 0; y < pazsk; y++)
        {
            rand_sk = dist(gen);
            failas1000 << rand_sk << " ";
        }

        rand_sk = dist(gen);
        failas1000 << " " << rand_sk << endl;
    }
    failas1000.close();
    auto stop1000 = std::chrono::high_resolution_clock::now();
    auto duration1000 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1000 - start1000);
    cout << "failo 'failas1000.txt'generavimas uztruko " << duration1000.count() / 1000.0 << "s" << endl;
    cout << "------------------------------------------------------------------------\n";
    auto start10000 = std::chrono::high_resolution_clock::now();
    ofstream failas10000("Studentai10000.txt");
    failas10000.clear();
    ss << i + 1;
    failas10000 << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Metodas" << setw(25) << "Pazymiai\n";
    for (i = 0; i < 10000; i++)
    {
        int rand_sk = dist(gen);

        if (rand_sk == 0)
        {
            failas10000 << setw(25) << "Vardas" + ss.str() << setw(25) << "Pavarde" + ss.str() << setw(25) << "v";
        }
        else
        {
            failas10000 << setw(25) << "Vardas" + ss.str() << setw(25) << " Pavarde" + ss.str() << setw(25) << "m";
        }

        for (int y = 0; y < pazsk; y++)
        {
            rand_sk = dist(gen);
            failas10000 << rand_sk << " ";
        }

        rand_sk = dist(gen);
        failas10000 << " " << rand_sk << endl;
    }
    failas10000.close();
    auto stop10000 = std::chrono::high_resolution_clock::now();
    auto duration10000 = std::chrono::duration_cast<std::chrono::milliseconds>(stop10000 - start10000);
    cout << "failo 'failas10000.txt'generavimas uztruko " << duration10000.count() / 1000.0 << "s" << endl;
    cout << "------------------------------------------------------------------------\n";
    auto start100000 = std::chrono::high_resolution_clock::now();
    ofstream failas100000("Studentai100000.txt");
    failas100000.clear();
    ss << i + 1;
    failas100000 << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Metodas" << setw(25) << "Pazymiai\n";

    for (i = 0; i < 100000; i++)
    {
        int rand_sk = dist(gen);

        if (rand_sk == 0)
        {
            failas100000 << setw(25) << "Vardas" + ss.str() << setw(25) << "Pavarde" + ss.str() << setw(25) << "v";
        }
        else
        {
            failas100000 << setw(25) << "Vardas" + ss.str() << setw(25) << " Pavarde" + ss.str() << setw(25) << "m";
        }

        for (int y = 0; y < pazsk; y++)
        {
            rand_sk = dist(gen);
            failas100000 << rand_sk << " ";
        }

        rand_sk = dist(gen);
        failas1000 << " " << rand_sk << endl;
    }
    failas100000.close();
    auto stop100000 = std::chrono::high_resolution_clock::now();
    auto duration100000 = std::chrono::duration_cast<std::chrono::milliseconds>(stop100000 - start100000);
    cout << "failo 'failas100000.txt'generavimas uztruko " << duration100000.count() / 1000.0 << "s" << endl;
    cout << "------------------------------------------------------------------------\n";
    /*auto start1000000 = std::chrono::high_resolution_clock::now();
    ofstream failas1000000("Studentai1000000.txt");
    failas1000000.clear();
    ss << i + 1;
    failas1000000 << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Metodas" << setw(25) << "Pazymiai\n";

    for (i = 0; i < 1000000; i++)
    {
        int rand_sk = dist(gen);

        if (rand_sk == 0)
        {
            failas1000000 << setw(25) << "Vardas" + ss.str() << setw(25) << "Pavarde" + ss.str() << setw(25) << "v";
        }
        else
        {
            failas1000000 << setw(25) << "Vardas" + ss.str() << setw(25) << " Pavarde" + ss.str() << setw(25) << "m";
        }

        for (int y = 0; y < pazsk; y++)
        {
            rand_sk = dist(gen);
            failas1000000 << rand_sk << " ";
        }

        rand_sk = dist(gen);
        failas1000000 << " " << rand_sk << endl;
    }
    failas1000000.close();
    auto stop1000000 = std::chrono::high_resolution_clock::now();
    auto duration10000000 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1000000 - start1000000);
    cout << "failo 'failas10000000.txt'generavimas uztruko " << duration10000000.count() / 1000.0 << "s" << endl;
    cout << "------------------------------------------------------------------------\n";
    auto start10000000 = std::chrono::high_resolution_clock::now();
    ofstream failas10000000("Studentai1000000.txt");
    failas10000000.clear();
    ss << i + 1;
    failas10000000 << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Metodas" << setw(25) << "Pazymiai\n";

    for (i = 0; i < 10000000; i++)
    {
        int rand_sk = dist(gen);

        if (rand_sk == 0)
        {
            failas10000000 << setw(25) << "Vardas" + ss.str() << setw(25) << "Pavarde" + ss.str() << setw(25) << "v";
        }
        else
        {
            failas10000000 << setw(25) << "Vardas" + ss.str() << setw(25) << " Pavarde" + ss.str() << setw(25) << "m";
        }

        for (int y = 0; y < pazsk; y++)
        {
            rand_sk = dist(gen);
            failas10000000 << rand_sk << " ";
        }

        rand_sk = dist(gen);
        failas10000000 << " " << rand_sk << endl;
    }
    failas10000000.close();
    auto stop10000000 = std::chrono::high_resolution_clock::now();
    auto duration100000000 = std::chrono::duration_cast<std::chrono::milliseconds>(stop10000000- start10000000);
    cout << "failo 'failas10000000.txt'generavimas uztruko " << duration100000000.count() / 1000.0 << "s" << endl;
    cout << "------------------------------------------------------------------------\n";*/
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "bendrai failu generavimas uztruko " << duration.count() / 1000.0 << "s" << endl;
}
void perrasymas(int pazsk)
{
    int paz = 0;
    studentas a;
    string failas, line = "", taip;
    while (true)
    {


        while (true)
        {
            cout << "iveskite kazkuri is sugeneruotu failu: failas1000.txt, failas10000.txt, failas100000.txt, failas1000000.txt, failas10000000.txt: ";
            cin >> failas;
            if (failas == "failas1000.txt" || failas == "failas10000.txt" || failas == "failas100000.txt" || failas == "failas1000000.txt" || failas == "failas10000000.txt")
                break;
            else cout << "netinkamas failo pavadinimas, bandykite vėl\n";
        }
        auto startSkaitymas = std::chrono::high_resolution_clock::now();
        ifstream skaitymas(failas);
        ofstream kietiakai("kietiakai.txt");
        ofstream vargseliai("vargseliai.txt");
        getline(skaitymas, line);
        while (skaitymas >> a.vardas)
        {
            skaitymas >> a.pavarde >> a.metodas;
            for (int i = 0; i < pazsk; i++)
            {
                skaitymas >> paz;
                a.paz.push_back(paz);
            }
            skaitymas >> a.egz;
            if (a.metodas == "v")
                galutinisVid(a);
            else
                galutinisMed(a);
            if (a.vidurkis >= 5)
            {
                kietiakai << setw(25) << a.vardas << setw(25) << a.pavarde << setw(25) << a.metodas;
                for (int i = 0; i < pazsk; i++)
                    kietiakai << a.paz[i] << " ";
                kietiakai << a.egz << endl;
            }
            else
            {
                vargseliai << setw(25) << a.vardas << setw(25) << a.pavarde << setw(25) << a.metodas;
                for (int i = 0; i < pazsk; i++)
                    vargseliai << a.paz[i];
                vargseliai << a.egz << endl;
            }
        }
        auto stopSkaitymas = std::chrono::high_resolution_clock::now();
        auto durationSkaitymas = std::chrono::duration_cast<std::chrono::milliseconds>(stopSkaitymas - startSkaitymas);
        cout << "failas nuskaitytas per " << durationSkaitymas.count() / 1000.0 << "s" << endl;
        cout << "jei norite vel skaityti generuota faila, iveskite y, kitu atveju iveskite bet koki kita simboli: ";
        cin >> taip;
        if (taip != "y")
            break;
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
