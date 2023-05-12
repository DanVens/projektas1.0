#include "Header.h"
struct studentas //struktūra, nusakanti studento duomenis
{
	string vardas, pavarde;
	int* paz;
	int egz;
	int y;
	double vidurkis;
	string metodas;
};
void pildymas(studentas& a) //pildo studentų masyvą
{
	int* A = new int[1];
	int dydis = 1;
	int n = 0;     
	int y = 0; 
	string arrandom;
	string s;
	cout << "iveskite varda ir pavarde: ";
	cin >> a.vardas >> a.pavarde;
	cout << endl;
	while (true)
	{
		cout << "jei norite ranka pildyti studento duomenis, spauskite x, jei norite atsitiktinai generuoti studento duomenis, spauskite y: ";
		cin >> arrandom;
		if (arrandom == "x") //jei ivedamas simbolis x, pildomi duomenys ranka
		{
			cout << "iveskite pazymius po viena nuo 1 iki 10 ir po kiekvieno spauskite enter (iveskite x, kai busite ivede visus pazymius): " << endl;
			while (true) {
				if (y == dydis)
				{
					int* B = new int[dydis * 2];
					for (int i = 0; i < dydis; i++)
					{
						B[i] = A[i];
					}
					delete[] A;
					A = B;
					a.paz = A;
					dydis = dydis * 2;
				} //jei masyvas pilnas, kuriamas naujas, kurio dydis dvigubai didesnis, tada ištrinamas senas masyvas ir rodyklė nurodoma į naują
				cout << "\npazymys " << y + 1 << ": ";
				try
				{
					cin >> s;
					int i = stoi(s);
					if (i > 0 && i < 11)
					{
						A[y] = i;
						y++;
						a.y = y;
					}
					else cout << "pazymys nera tarp 1 ir 10, bandykite dar karta\n";
				}
				catch (...)
				{
					if (s == "x" && y != 0)
						break;
					else if (s == "x" && y == 0)
						cout << "turi buti ivestas bent vienas pazymys, bandykite vel\n";
					else cout << "netinkami duomenys, bandykite vel\n";
				} //vedami pažymiai, jei netinkami duomenys, vėl prašoma pažymio

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
						a.egz = i;
						y++;
						break;
					}
					else cout << "pazymys nera tarp 1 ir 10, bandykite dar karta\n";
				}
				catch (...)
				{
					cout << "netinkami duomenys, bandykite vel\n";
				}
			} //vedamas egzamino rezultatas, jei netinkami duomenys, vėl prašoma pažymio
			break;
		}
		else if (arrandom == "y") //jei ivedamas y, duomenys generuojammi
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
			int* B = new int[dydis];
			delete[] A;
			A = B;
			a.paz = A;
			a.y = dydis;
			srand(time(NULL));
			int rand_sk;
			for (int i = 0; i < dydis; i++) //generuojami ir pildomi skaičiai
			{
				rand_sk = rand();
				while (rand_sk > (RAND_MAX - (RAND_MAX % 10)) && rand_sk != 0); //generuojamas skaičius, kol gaunamas toks, kuris neišeina iš nustatytų ribų
				if (rand_sk % 10 == 0)
					rand_sk = 10;
				else rand_sk = rand_sk % 10;
				A[i] = rand_sk;
			}
			while (rand_sk > (RAND_MAX - (RAND_MAX % 10)));
			if (rand_sk % 10 == 0)
				rand_sk = 10;
			else rand_sk = rand_sk % 10;
			a.egz = rand_sk;
			break;
		}
		cout << "netinkami duomenys, bandykite vel\n";
	}
}
void rusiavimas(studentas& A) //surūšiuoja studento pažymius
{
	int i, j;
	for (i = 0; i < A.y - 1; i++)
		for (j = 0; j < A.y - i - 1; j++)
			if (A.paz[j] > A.paz[j + 1])
				swap(A.paz[j], A.paz[j + 1]);
}
void galutinisVid(studentas& A) //suskaičiuoja galutinį pažymį pagal vidurkį
{
	double galutinis, vid, sum = 0;
	for (int i = 0; i < A.y; i++)
	{
		sum = sum + A.paz[i];
	}
	vid = sum / A.y;
	galutinis = 0.4 * vid + 0.6 * A.egz;
	A.vidurkis = galutinis;
}
void galutinisMed(studentas& A) //suskaičiuoja galutinį pažymį pagal medianą
{
	double galutinis, med = 0;
	int vidurinis = A.y / 2;
	if (A.y % 2 == 0)
		med = (A.paz[vidurinis - 1] + A.paz[vidurinis]) / 2;
	else med = A.paz[vidurinis];
	galutinis = 0.4 * med + 0.6 * A.egz;
	A.vidurkis = galutinis;

}
void Spausdinimas(studentas* A, int i) //atspausdina studentų duomenis
{
	cout << setw(10) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis" << endl;
	cout << "---------------------------------------------------\n";
	for (int y = 0; y < i+1; y++)
	{
		if(A[y].metodas == "v")
		cout << setw(10) << A[y].vardas << setw(15) << A[y].pavarde << setw(15) << fixed << setprecision(2) << A[y].vidurkis << " (vidurkis)" << endl;
		else if (A[y].metodas == "m")
		cout << setw(10) << A[y].vardas << setw(15) << A[y].pavarde << setw(15) << fixed << setprecision(2) << A[y].vidurkis << " (mediana)" << endl;
	}
}
int main()
{
	studentas* A = new studentas[1];
	int dydis = 1;
	int n = 1;
	string taip, mv, arrandom;
	for (int i = 0; i < n; i++)
	{
		if (dydis == i)
		{
			studentas* B = new studentas[dydis * 2];
			for (int i = 0; i < dydis; i++)
			{
				B[i] = A[i];
			}
			delete[] A;
			A = B;
			dydis = dydis * 2;
		}
		pildymas(A[i]);
		rusiavimas(A[i]);
		while (true)
		{
			cout << "jei norite galutinio rezultato, suskaiciuoto pagal vidurki, iveskite v ir enter, jei norite pagal mediana, iveskite m ir enter: ";
			cin >> mv;
			A[i].metodas = mv;
			if (mv == "v")
			{
				galutinisVid(A[i]);
				Spausdinimas(A, i);
				break;
			}
			else if (mv == "m")
			{
				galutinisMed(A[i]);
				Spausdinimas(A, i);
				break;
			}
			cout << "netinkami duomenys, bandykite vel\n";
		}
		cout << "jeigu norite ivesti dar viena studenta, iveskite y ir spauskite enter, jei ne, iveskite bet koki kita simboli ir spauskite enter";
		cin >> taip;
		if (taip == "y")
			n++;
	}
}
