#pragma once
#include "User.h"
#include <string>
using namespace std;


class Reader : public User
{
private:
	string reserve[5];
	int borrowPeriod[8];
	string books[8];//supposed to be 10. but we used 8
	int penalty;
public:
	string getReserve(int i);
	string getBooks(int i);
	bool checkBooks(int accType);
	int getBorrowPeriod(int i);
	void setBorrowPeriod(int x, int i);
	void setBooks(string s, int i);
	void addReserve(string title, int acctype);
	bool checkReserve(string title);
	void deleteReserve(string title);
	void printReserve();
	bool checkOverdue();
	void setReserve(string title);
	bool isReserveFull();
};

