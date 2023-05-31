Versija 0.4

Pridėta galimybė generuoti į failus su duomenimis

Pridėtos programos veikimo laiko funkcijos

Kodo pavyzdys:

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
   
 Pavyzdinis konsolės rezultatas
    
![image](https://github.com/DanVens/projektas1.0/assets/60598434/04a497f3-3ef3-456d-a3c8-80801642840e)
