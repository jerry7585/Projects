#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Copy
{
private:
	int ID, avail, startDate, expireDate, reserveDate;
	string title, reader, reserver;
public:
	Copy();
	Copy(int ID, int avail, int startDate, int expireDate, int reserveDate, string title, string reader, string reserver);
	int getID();
	int getAvail();
	int getStartDate();
	int getExpireDate();
	int getReserveDate();
	string getReserver();
	void setReserver(string name);
	string getTitle();
	string getReader();
	void setID(int ID);
	void setAvail(int avail);
	void setStartDate();
	void setExpireDate();
	void setReserveDate(int reserveDate);
	void setReader(string reader);
};
