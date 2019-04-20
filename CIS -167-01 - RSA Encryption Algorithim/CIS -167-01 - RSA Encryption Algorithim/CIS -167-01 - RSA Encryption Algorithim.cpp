// CIS -167-01 - RSA Encryption Algorithim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include "iostream";
#include "random";
#include "time.h";
#include "string";
#include "vector";

using namespace std;
//Matt=========================
int getRandomPrimeNumber(int);
void encryption(int, int);
vector<int> getInput();
//=============================

//Anton========================
int leastCommonMultiple(int, int);
//=============================

int main()
{
	srand(time(NULL));
	int p = 11;
	int q = 7;
	encryption(p, q);
	system("Pause");
	return 0;
}

//Matt================================
int getRandomPrimeNumber(int primeN)
{
	int testnumber = 1;
	bool primeFound = false;
	for (int i = 2; i < primeN && !primeFound; i++)
	{
		if (primeN % i == 0)
		{
			primeFound = false;
		}
		else
		{
			testnumber = i;
			primeFound = true;
		}
	}
	return testnumber;
}
//====================================

//Matt================================
void encryption(int p, int q)
{
	int n = p * q;
	int primeN = leastCommonMultiple((p - 1), (q - 1));
	int e = getRandomPrimeNumber(primeN);
	int k = 2;
	int d = ((k * primeN + 1) / e);
	vector<int> message = getInput();
	vector<long int> encryptedMessage{};
	for (int i = 0; i < message.size(); i++)
	{
		long long int tNum = pow(message[i], e);
		cout << e << endl;
		cout << tNum << endl;
		tNum = fmod(tNum, n);
		encryptedMessage.push_back(tNum);
	}
	cout << endl << "Your Encrypted Message is: ";
	for (int i = 0; i < encryptedMessage.size(); i++)
	{
		cout << (char)encryptedMessage[i];
	}
	cout << endl;
}
//====================================

//Matt================================
vector<int> getInput()
{
	//char conversionChartChar[61] = { '1','2','3','4','5','6','7','8','9','A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z' };
	//int conversionChartInt[61] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60 };
	vector<int> message{};
	string input;
	cout << "Please Enter A Message To Encypt" << endl << ">";
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		//for (int j = 0; j < 61; j++)
		//{
		//if (input.at(i) == conversionChartChar[j])
		//{
		message.push_back(input.at(i));
		//}
		//}
	}
	return message;
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
//====================================
