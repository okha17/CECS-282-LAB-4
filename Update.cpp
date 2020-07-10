#include "upDate.h"
#include <iostream>
using namespace std;
int upDate::count = 0;
// Gregorian to Julian function that returns an int value for a Julian date
int Greg2Julian(int month, int day, int year)
{
	int JD = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367
		* (month - 2 - (month - 14) / 12 * 12) / 12 - 3
		* ((year + 4900 + (month - 14) / 12) / 100) / 4;
	return JD;
}
// Julian to Gregorian function that works through pass by reference 
void Julian2Greg(int JD, int& month, int& day, int& year)
{
	int I, J, K;
	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}

//Default constructor
upDate::upDate()
{
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
	count++;
}

upDate::upDate(int m, int d, int y)
{
	dptr = new int[3];
	int val = Greg2Julian(m, d, y);
	Julian2Greg(val, m, d, y);

	if (m > 12)
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
	else
	{
		dptr[0] = m;
		dptr[1] = d;
		dptr[2] = y;
	}
	count++;
}

upDate::upDate(int j)
{
	dptr = new int[3];
	Julian2Greg(j, dptr[0], dptr[1], dptr[2]);
	count++;
}

upDate::upDate(const upDate &D)
{
	dptr = new int[3];
	for (int i = 0; i < 3; i++)
	{
		dptr[i] = D.dptr[i];
	}
	count++;
}

upDate::~upDate()
{
	--count;
	delete[] dptr;
}

void upDate::setDate(int m, int d, int y)
{
	int val = Greg2Julian(m, d, y);
	Julian2Greg(val, m, d, y);

	if (m > 12)
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
	else
	{
		dptr[0] = m;
		dptr[1] = d;
		dptr[2] = y;
	}
}

int upDate::getMonth()
{
	return dptr[0];
}

int upDate::getDay()
{
	return dptr[1];
}

int upDate::getYear()
{
	return dptr[2];
}

string upDate::getMonthName()
{ 
	string months[] = {"January", "February", "March", "April",
					"May", "June", "July", "August", "September",
					"October", "November", "December" };
	return months[dptr[0] - 1];
}

upDate& upDate::operator=(const upDate& D)
{
	if (this == &D)
	{
		return *this;
	}
	for (int i = 0; i < 3; i++)
	{
		dptr[i] = D.dptr[i];
	}
	return *this;
}

upDate upDate:: operator+=(int value)
{
	int date = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	date += value;
	Julian2Greg(date, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate:: operator-=(int value)
{
	int date = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	date -= value;
	Julian2Greg(date, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator+(int value)
{
	upDate temp;
	for (int i = 0; i < 3; i++)
	{
		temp.dptr[i] = dptr[i];
	}
	int date = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	date += value;
	Julian2Greg(date, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate operator +(int val, const upDate& D)
{
	upDate temp;
	for (int i = 0; i < 3; i++)
	{
		temp.dptr[i] = D.dptr[i];
	} 
	int date = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	date += val;
	Julian2Greg(date, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate upDate::operator-(int value)
{
	upDate temp;
	for (int i = 0; i < 3; i++)
	{
		temp.dptr[i] = dptr[i];
	}
	int date = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	date -= value;
	Julian2Greg(date, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

int upDate::operator-(const upDate& D)
{
	int date = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int date_D = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	int diff = date - date_D;
	return diff;
}

upDate upDate::operator ++(int)
{
	upDate temp(*this);
	*this += 1;
	return temp;
}

upDate upDate::operator ++()
{
	*this += 1;
	return *this;
}

upDate upDate::operator --(int)
{
	upDate temp(*this);
	*this -= 1;
	return temp;
}

upDate upDate::operator --()
{
	*this -= 1;
	return *this;
}

ostream& operator << (ostream& os, const upDate& D)
{
	os << D.dptr[0] << "/" << D.dptr[1] << "/" << D.dptr[2];
	return os;
}

 int upDate::GetDateCount()
{
	 return count;
}

 int upDate::julian()
 {
	 int date = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	 return date;
 }

 bool upDate::operator==(const upDate& D)
{
	 int date = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	 int date_D = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	 return date == date_D;
}

 bool upDate::operator<(const upDate& D)
 {
	 int date = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	 int date_D = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	 return date < date_D;
 }

 bool upDate::operator>(const upDate& D)
 {
	 int date = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	 int date_D = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	 return date > date_D;
 }
