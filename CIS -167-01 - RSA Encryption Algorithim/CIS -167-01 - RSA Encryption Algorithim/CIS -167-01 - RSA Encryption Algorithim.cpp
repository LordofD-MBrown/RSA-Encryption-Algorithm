// CIS -167-01 - RSA Encryption Algorithim.cpp : Defines the entry point for the console application.
//Names:	Matthew Brown,  Jessica Marimpietri, Anton Durham
//Desc:		this program is our version on RSA encryption. 
//			It functions as we stated, though there are severe vulnerabilities in the code, and would be very easy to crack. 
//			It only works with numbers and letters, and the prime numbers 3,7,5.
//Date:		4/30/2019

#include "stdafx.h";
#include "iostream";
#include "random";
#include "time.h";
#include "string";
#include "vector";
#include "Character.h";


using namespace std;
//Matt=========================
int getPrimeNumber(int);
void decryption(vector<Character>, int, int);
void encryption(int, int);
int dvalue(int, int);
vector<Character> getInput(int);
//=============================

//Anton========================
int leastCommonMultiple(int, int);
//=============================

int main()
{
	srand(time(NULL));
	int p = 3; //7,5
	int q = 5; //5,3
	encryption(p, q);
	system("Pause");
	return 0;
}

//Matt================================
int getPrimeNumber(int primeN)
{
	int testnumber =0;
	bool primeFound = false;
	for (int i = 1; i < primeN && !primeFound; i++)
	{
		if (i == 1)
		{
			primeFound = false;
		}
		else if (primeN % i > 0)
		{
			testnumber = i;
			primeFound = true;
		}
		else if (primeN % i == 0)
		{
			primeFound = false;
		}		
		i++;
	}
	return testnumber;
}
//====================================

//Matt================================
void encryption(int p, int q)
{
	char conversionChartChar[63] = { '1','2','3','4','5','6','7','8','9','A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z',' ','0' };
	int conversionChartInt[63] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,63 };
	//n is our max prime
	int n = p * q;
	int primeN = leastCommonMultiple((p - 1), (q - 1)); 
	int e = getPrimeNumber(primeN);
	float d = dvalue(e,primeN);
	cout << "n: " << n << endl;
	cout << "primeN: " << primeN << endl;
	cout << "e: " << e << endl;
	cout << "d: " << d << endl;

	vector<Character> message = getInput(n);
	vector<Character> encryptedMessage{};
	for (int i = 0; i < message.size(); i++)
	{
		long long int tNum = pow(message[i].getNumber(), e);
		tNum = tNum % n;
		Character character;
		character.setNumber(tNum);
		character.setCycleValue(message[i].getCycle());
		encryptedMessage.push_back(character);
	}
	cout << endl << "Your Encrypted Message is: ";
	for (int i = 0; i < encryptedMessage.size(); i++)
	{
		bool found = false;
		
		for (int j = 0; j < 63; j++)
		{
			if (encryptedMessage[i].getNumber() == conversionChartInt[j])
			{
				found = true;
				cout << conversionChartChar[j];
			}		
		}
		if (found == false)
		{
			cout << (char)encryptedMessage[i].getNumber();
		}
	}
	cout << endl;

	decryption(encryptedMessage, d, n);
}
//====================================

// start of Jessica & Anton ==================================================
void decryption(vector<Character> encryptedMessage, int d, int n)
{
	char conversionChartChar[63] = { '1','2','3','4','5','6','7','8','9','A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z',' ','0' };
	int conversionChartInt[63] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,63 };
	long int tNum;
	long int m;

	for (int i = 0; i < encryptedMessage.size(); i++)
	{
		tNum = pow(encryptedMessage[i].getNumber(), d);
		m = tNum % n;
		encryptedMessage[i].setNumber(m);
	}

	cout << endl << "Your decrypted Message is: ";
	for (int i = 0; i < encryptedMessage.size(); i++)
	{
		int cNum = encryptedMessage[i].getNumber();
		int cycleCount = encryptedMessage[i].getCycle();
		for (int x = 0; x < cycleCount; x++)
		{
			cNum += (n - 1);
		}
		for (int j = 0; j < 63; j++)
		{
			if (cNum == conversionChartInt[j])
			{						
				cout << conversionChartChar[j];
			}
		}
	}
	cout << endl;

}
// end of Jessica & Anton ==================================================

//Matt================================
vector<Character> getInput(int n)
{
	char conversionChartChar[63] = {'1','2','3','4','5','6','7','8','9','A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z',' ','0'};
	int conversionChartInt[63] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,63 };
	vector<Character> message{};
	string input;
	cout << "Please Enter A Message To Encypt" << endl << ">";
	getline(cin ,input);
	for (int i = 0; i < input.length(); i++)
	{
		for (int j = 0; j < 63; j++)
		{
			if (input.at(i) == conversionChartChar[j])
			{
				Character character;
				character.setCycle(conversionChartInt[j], n);
				message.push_back(character);
			}
		}
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
} //https:://www.includehelp.com/cpp-programs/find-lcm-of-2-numbers
//====================================

int dvalue(int e, int prime)
{
	double primeN = prime;
	for (int i = 2; i < primeN; i++)
	{
		float doubleD = ((i * primeN) + 1.0) / e;
		int intD = ((i * primeN) + 1) / e;
		if (intD - doubleD == 0)
		{
			return intD;
		}
	}
	return 0;
}

	