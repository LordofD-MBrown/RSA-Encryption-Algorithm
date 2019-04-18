// CIS -167-01 - RSA Encryption Algorithim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include "iostream";
#include "random";
#include "time.h";

using namespace std;
//Matt=========================
int getRandomPrimeNumber(int);
void encryption(int, int);
//=============================

//Anton========================
int leastCommonMultiple(int, int);
//=============================

int main()
{
	srand(time(NULL));
	int p = 7;
	int q = 53;
	encryption(p, q);
	system("Pause");
    return 0;
}

//Matt================================
int getRandomPrimeNumber(int upperbound)
{
	int testnumber;
	bool primeFound = false;
	while (!primeFound)
	{
		primeFound = true;
		testnumber = rand() % upperbound + 2;
		cout << testnumber << endl;
		for (int i = 2; i <= (testnumber / 2); i++)
		{
			if (testnumber % i == 0)
			{
				primeFound = false;
			}
		}
	}
	return testnumber;
}
//====================================

//Matt================================
void encryption(int p, int q)
{
	int n = p * q;
	int upperbound = leastCommonMultiple((p-1),(q - 1));
	int e = getRandomPrimeNumber(upperbound);
	int mod = 1 % upperbound;
	cout << mod;

}
//====================================

//Anton===============================
int leastCommonMultiple(int p, int q)
{
	int max;

	if (p > q)
	{
		max = p;
	}
	else
	{
		max = q;
	}

	while (true)
	{
		if (max % p == 0 && max % q == 0)
		{
			return max; 
			break;
		}
		else
		{
			max++;
		}
	}	
}
//==================================
