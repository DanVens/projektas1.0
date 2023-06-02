#include "bibliotekos.h"
#include "struktura.h"
void pildymas(std::deque<studentas>& a) //pildo studentų deko
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
                std::getline(failas, line);
                int k = 1;
                while (std::getline(failas, line))
                {
                    std::istringstream iss(line);
                    int num;
                    iss >> b.vardas >> b.pavarde;

                    while (iss >> num) {
                        b.paz.push_back(num);
                    }
                    b.egz = b.paz.back();
                    b.paz.pop_back();
                    a.push_back(b);
                    b.paz.clear();
                }
                break;

            }
            break;
        }
        cout << "netinkami duomenys, bandykite vel\n";
    }
}
void FailuGeneravimas(int& pazsk)
{
    int rand_sk, i = 0;
    studentas a;
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
    ofstream failas1000("failas1000.txt");
    failas1000.clear();
    failas1000 << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Pazymiai\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    for (i = 0; i < 1000; i++)
    {
        failas1000 << "Vardas" << i + 1 << setw(25) << "Pavarde" << i + 1;
        failas1000 << setw(15);
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
    ofstream failas10000("failas10000.txt");
    failas10000.clear();
    failas10000 << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Pazymiai\n";
    for (i = 0; i < 10000; i++)
    {
        failas10000 << "Vardas" << i + 1 << setw(25) << "Pavarde" << i + 1;
        failas10000 << setw(15);
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
    ofstream failas100000("failas100000.txt");
    failas100000.clear();
    failas100000 << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Pazymiai\n";

    for (i = 0; i < 100000; i++)
    {
        failas100000 << "Vardas" << i + 1 << setw(25) << "Pavarde" << i + 1;
        failas100000 << setw(15);
        for (int y = 0; y < pazsk; y++)
        {
            rand_sk = dist(gen);
            failas100000 << rand_sk << " ";
        }

        rand_sk = dist(gen);
        failas100000 << " " << rand_sk << endl;
    }
    failas100000.close();
    auto stop100000 = std::chrono::high_resolution_clock::now();
    auto duration100000 = std::chrono::duration_cast<std::chrono::milliseconds>(stop100000 - start100000);
    cout << "failo 'failas100000.txt'generavimas uztruko " << duration100000.count() / 1000.0 << "s" << endl;
    cout << "------------------------------------------------------------------------\n";
    auto start1000000 = std::chrono::high_resolution_clock::now();
    ofstream failas1000000("failas1000000.txt");
    failas1000000.clear();
    failas1000000 << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Pazymiai\n";

    for (i = 0; i < 1000000; i++)
    {
        failas1000000 << "Vardas" << i + 1 << setw(25) << "Pavarde" << i + 1;
        failas1000000 << setw(15);
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
    auto duration1000000 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1000000 - start1000000);
    cout << "failo 'failas1000000.txt'generavimas uztruko " << duration1000000.count() / 1000.0 << "s" << endl;
    cout << "------------------------------------------------------------------------\n";
    /*auto start10000000 = std::chrono::high_resolution_clock::now();
    ofstream failas10000000("failas1000000.txt");
    failas10000000.clear();
    failas10000000 << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Pazymiai\n";

    for (i = 0; i < 10000000; i++)
    {
        failas10000000 << "Vardas" << i + 1 << setw(25) << "Pavarde" << i + 1;
        failas10000000 << setw(15);
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
    int pazym = 0;
    studentas a;
    string failas, line = "", taip, nereikalinga;
    ofstream kietiakai("kietiakai.txt");
    ofstream vargseliai("vargseliai.txt");
    kietiakai << setw(25) << "vardas" << setw(25) << "pavarde" << setw(15) << "vidurkis" << setw(15) << "mediana" << setw(25) << "pazymiai" << endl;
    vargseliai << setw(25) << "vardas" << setw(25) << "pavarde" << setw(15) << "vidurkis" << setw(15) << "mediana" << setw(25) << "pazymiai" << endl;
    kietiakai.clear();
    vargseliai.clear();
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
        // << a.pavarde << a.metodas;
        skaitymas >> nereikalinga >> nereikalinga >> nereikalinga;
        while (skaitymas >> a.vardas)
        {
            skaitymas >> a.pavarde;
            for (int i = 0; i < pazsk; i++)
            {
                skaitymas >> pazym;
                a.paz.push_back(pazym);
            }
            skaitymas >> a.egz;
            galutinisVid(a);
            galutinisMed(a);
            if (a.vidurkis >= 5 || a.mediana >= 5)
            {
                kietiakai << setw(25) << a.vardas << setw(25) << a.pavarde << setw(15) << a.vidurkis << setw(15) << a.mediana << setw(15);
                for (int i = 0; i < pazsk; i++)
                    kietiakai << a.paz[i] << " ";
                kietiakai << a.egz << endl;
            }
            else
            {
                vargseliai << setw(25) << a.vardas << setw(25) << a.pavarde << setw(15) << a.vidurkis << setw(15) << a.mediana << setw(15);
                for (int i = 0; i < pazsk; i++)
                    vargseliai << a.paz[i] << " ";
                vargseliai << a.egz << endl;
            }
            a.paz.clear();
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
void rusiavimas(deque<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = low;
        int i = low + 1;
        int j = high;

        while (i <= j) {
            if (arr[i] > arr[pivot] && arr[j] <= arr[pivot]) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
            if (arr[i] <= arr[pivot]) {
                i++;
            }
            if (arr[j] > arr[pivot]) {
                j--;
            }
        }

        std::swap(arr[pivot], arr[j]);

        rusiavimas(arr, low, j - 1);
        rusiavimas(arr, j + 1, high);
    }
}
bool palyginimas(const studentas& a, const studentas& b) {
    if (a.vardas.length() != b.vardas.length()) {
        return a.vardas.length() > b.vardas.length();
    }
    if (a.pavarde.length() != b.pavarde.length()) {
        return a.pavarde.length() > b.pavarde.length();
    }
    if (a.vardas == b.vardas) {
        return a.pavarde > b.pavarde;
    }
    return a.vardas > b.vardas;
}
void merge(deque<studentas>& A, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::deque<studentas> left(n1);
    std::deque<studentas> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = A[low + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = A[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (!palyginimas(left[i], right[j])) {
            A[k] = left[i];
            i++;
        }
        else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = right[j];
        j++;
        k++;
    }
}
void rusiavimasStudentu(deque<studentas>& A, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        rusiavimasStudentu(A, low, mid);
        rusiavimasStudentu(A, mid + 1, high);
        merge(A, low, mid, high);
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
    A.mediana = galutinis;
}
void Spausdinimas(deque<studentas> & A)
{
    cout << setw(10) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Vidurkis" << setw(15) << "Mediana" << endl;
    cout << "---------------------------------------------------------------\n";
    for (int y = 0; y < A.size(); y++)
    {
        galutinisVid(A[y]);
        galutinisMed(A[y]);
        cout << setw(10) << A[y].vardas << setw(15) << A[y].pavarde << setw(15) << fixed << setprecision(2) << A[y].vidurkis << setw(15) << fixed << setprecision(2) << A[y].mediana << endl;
    }

}
