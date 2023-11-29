#include <fstream>
#include <cstring>
#define NR_MAXIM_ELEVI 22
#define NR_MAXIM_ELEVI_IN_ECHIPA 8
#define NR_MAXIM_DISCIPLINE 10
using namespace std;
ofstream scrie("pluricex.out");
int nrElevi,
    nrEleviInEchipa,
    nrDiscipline,
    echipa[NR_MAXIM_ELEVI_IN_ECHIPA];
bool elev[NR_MAXIM_ELEVI][NR_MAXIM_DISCIPLINE];
void citesteDateleDeIntrare();
void determinaToateEchipele(int, int);
int main()
{
	citesteDateleDeIntrare();
	determinaToateEchipele(0, 0);
	scrie.close();
	return 0;
}
void afiseazaEchipa()
{
	for (int i = 0; i < nrEleviInEchipa; i++)
	{
		scrie << echipa[i]+1 << ' ';
	}
	scrie << endl;
}
bool indeplinesteConditiaProblemei()
{
	// verifica daca pentru fiecare disciplina
	// exista in echipa cel putin un membru
	// care sa o studieze
	bool uz[nrDiscipline];
	memset(uz, 0, sizeof(uz));
	int i, j;
	for (i = 0; i < nrEleviInEchipa; i++)
	{
		for (j = 0; j < nrDiscipline; j++)
		{
			if (elev[echipa[i]][j])
			{
				uz[j] = 1;
			}
		}
	}
	for (i = 0; i < nrDiscipline; i++)
	{
		if (uz[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}
void determinaToateEchipele(
	int nrOrdineElev,
	int nrEleviAlesiPanaAcum)
{
	if (nrEleviAlesiPanaAcum == nrEleviInEchipa)
	{
		if (indeplinesteConditiaProblemei())
		{
			afiseazaEchipa();
		}
	}
	else
	{
		for (int i = nrOrdineElev; i < nrElevi; i++)
		{
			echipa[nrEleviAlesiPanaAcum] = i;
			determinaToateEchipele(
				i+1,
				nrEleviAlesiPanaAcum+1);
		}
	}
}
void citesteDateleDeIntrare()
{
	ifstream citeste("pluricex.in");
	citeste >> nrElevi
		>> nrEleviInEchipa
		>> nrDiscipline;
	for (int i = 0; i < nrElevi; i++)
	{
		int nrDisciplineStudiate;
		citeste >> nrDisciplineStudiate;
		for (int j = 0; j < nrDisciplineStudiate; j++)
		{
			int disciplina;
			citeste >> disciplina;
			disciplina--; // retin indicii de la 0
			elev[i][disciplina] = 1;
		}
	}
	citeste.close();
}
