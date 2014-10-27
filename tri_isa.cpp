/**
 * @file tri_isa.cpp
 * @author GIRARD Laurent et LE FALHUN Mattis
 * @date 
 * @brief 
**/
#include <iostream>  // cout, cin
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time(), clock_t, clock(), CLOCKS_PER_SEC
#include <cassert>   // assert()
#include <climits>   // UINT_MAX
#include <cfloat>    // DBL_MAX
using namespace std;


const unsigned int N = 10;
typedef int TabEntier[N];

// Procédure permettant de remplir un tableau avec les entiers de 0 à N-1 (croissant)
void remplir_croissant(TabEntier & T)
{
	unsigned int i;
	for(i=0; i<N; ++i)
	{
		T[i] = i;
	}	
}

// Procédure permettant de remplir un tableau avec les entiers de N-1 à 0 (décroissant)
void remplir_decroissant(TabEntier & T)
{
	unsigned int i;
	for(i=0; i<N; ++i)
	{
		T[i] = N - i - 1;
	}
}

// Procédure permettant de permuter deux éléments d'un tableau T aux indices i et j.
void permuter(TabEntier &T, unsigned int i, unsigned int j)
{
	int tmp;

	tmp = T[i];
	T[i] = T[j];
	T[j] = tmp;
}

// Procédure permettant d'effectuer k permutation avec des indices aléatoires.
void permuter_rand(TabEntier &T, unsigned int k)
{
	int a,b;
	unsigned int i;
	for (i = 0; i < k; ++i)
	{
		a = rand()%(N);       // valeur recherchée : aléatoire entre 0 et N
		b = rand()%(N);       // valeur recherchée : aléatoire entre 0 et N
		permuter(T, a, b);
	}
}

// Fonction permettant de savoir si un tableau est trié dans l'ordre croissant.
bool is_croissant(TabEntier T)
{
	bool test = true;
	unsigned int i;

	for (i = 0; i < N-1; ++i)
	{
		if (T[i] > T[i+1])
		{
			test = false;
		}
	}

	return test;
}

// Procédure permettant d'afficher un tableau sur la sortie standard
void afficher_tab(TabEntier T)
{
	unsigned int i;
	for (i = 0; i < N; ++i)
	{
		cout << T[i] << "|";
	}
	cout << endl;
}

// Procédure de tri par selection
void TriSelection (TabEntier & T)
{
	unsigned i, j, min;

	for (i = 0; i < N; ++i)
	{
		min = i;

		for (j = i+1; j < N; ++j)
		{
			if(T[j] < T[min])
			{
				min = j;
			}
		}

		if(min != i)
		{
			permuter(T, min, i);
		}
	}
}

// Procédure de tri par insertion
void TriInsertion(TabEntier & T)
{
	unsigned int i, j;
	for (i = 1; i < N; ++i)
	{
		j = i;
		while((j > 0) && (T[j] < T[j-1]))
		{
			permuter(T, j, j-1);
			j--;
		}
	}
}

void TriAleatoire(TabEntier & T)
{
	bool estTrie;
	estTrie = is_croissant(T);
	while(estTrie == false)
	{
		permuter_rand(T, 1);
		estTrie = is_croissant(T);
	}
}

//--------------------------------------------------------------------
/**
 * @brief fonction principale
 * 
 * @b Role : -
 * 
 * @b Cadre : -
 * 
 * @pre -
 * @post -
**/

int main()
{
	srand((int)time(0));   // initialisation du tirage aléatoire
	TabEntier T;
	
	remplir_croissant(T);
	//remplir_decroissant(T);
	permuter_rand(T, 100);
	afficher_tab(T);
	//TriSelection(T);
	//TriInsertion(T);
	TriAleatoire(T);
	afficher_tab(T);
	//cout << is_croissant(T) << endl;


	return 0;
}
