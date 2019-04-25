
#include "stdafx.h"
#include "iostream"
#include "Character.h"

using namespace std;


Character::Character()
{
}


Character::~Character()
{

}

void Character::setCycle(int n_t, int n)
{
	bool smallest = false;
	int num = n_t;
	int cyc = 0;
	while (!smallest)
	{
		if (num >= n)
		{
			num = num - (n - 1);
			cyc++;
		}
		if (num < n)
		{
			smallest = true;
		}
	}
	number = num;
	cycle = cyc;
}
void Character::setNumber(int n_t)
{
	number = n_t;
}
void Character::setCycleValue(int c_t)
{
	cycle = c_t;
}
int Character::getCycle()
{
	return cycle;
}
int Character::getNumber()
{
	return number;
}
