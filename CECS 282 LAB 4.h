// Osman Khan
// CECS 282-07
// Proj 4 -Operator Overloading 
// 11/4/2019
using namespace std;
#ifndef UPDATE_H
#define UPDATE_H
#include <string>
class upDate
{
private:
	int* dptr;
	static int count;
public:
	upDate();
	upDate(int, int, int);
	upDate(int);
	upDate(const upDate &D);
	~upDate();
	void setDate(int, int, int);
	int getMonth();
	int getDay();
	int getYear();
	upDate& operator = (const upDate& D);
	upDate operator +=(int);
	upDate operator -=(int);
	upDate operator +(int);
	friend upDate operator+(int val, const upDate &D);
	upDate operator -(int);
	int operator -(const upDate& D);
	static int GetDateCount();
	friend ostream& operator << (ostream& o, const upDate& D);
	upDate operator ++(int);
	upDate operator ++();
	upDate operator --(int);
	upDate operator --();
	string getMonthName();
	int julian();
	bool operator ==(const upDate& D);
	bool operator <(const upDate& D);
	bool operator >(const upDate& D);
};
#endif
