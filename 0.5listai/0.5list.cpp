#include "bibliotekos.h"
#include "struktura.h"
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    list<studentas> S;
    int dydis = 1;
    int n = 1;
    string taip, mv;
    int pazsk = 0;
    ifstream failas1000("failas1000.txt");
    ifstream failas10000("failas10000.txt");
    ifstream failas100000("failas100000.txt");
    ifstream failas1000000("failas1000000.txt");
    //ifstream failas10000000("failas10000000.txt");
    for (int i = 0; i < n; i++)
    {
        cout << "iveskite y, jei noretumete ivesti duomenis is 5 failu, iveskite bet koki kita simboli, jei noretumete testi: ";
        cin >> taip;
        if (taip == "y")
        {
            cout << "ar noretumete is naujo generuoti failus, ar noretumete naudoti jau esamus? Jei norite generuoti is naujo, spauskite y, jei ne, spauskite bet koki mygtuka: ";
            cin >> taip;
            if ((taip != "y" && !failas1000) || (taip != "y" && !failas10000) || (taip != "y" && !failas100000) || (taip != "y" && !failas1000000))
            {
                cout << "nera bent vieno failo, reikia failus sugeneruoti\n";
                FailuGeneravimas(pazsk);
            }
            else if (taip == "y")
                FailuGeneravimas(pazsk);
            perrasymas(pazsk);
            cout << "jei norite testi su kitais ivedimo budais, iveskite y, kitu atveju iveskite bet koki kita simboli ";
            cin >> taip;
            if (taip != "y")
            {
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
                cout << "programa veike " << duration.count() / 1000.0 << "s";
                break;
            }

        }
        pildymas(S);

        for (list<studentas>::iterator it = S.begin(); it != S.end(); ++it) 
        {
            if (it->paz.size() > 1) {
                rusiavimas(it->paz, it->paz.begin(), std::prev(it->paz.end()));
            }
        }

        rusiavimasStudentu(S, 0, S.size() - 1);

        Spausdinimas(S);

        cout << "Jeigu norite ivesti dar viena studenta ar faila, iveskite 'y' ir spauskite enter. Jei ne, iveskite bet koki kita simboli ir spauskite enter: ";
        cin >> taip;

        if (taip == "y")
        {
            if (!S.empty()) {
                n = S.size();
                i = S.size() - 2;
            }
        }
        else
        {
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout << "programa veike " << duration.count() / 1000.0 << "s";
            break;
        }
    }
}
