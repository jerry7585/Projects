#include "Copy.h"
#include <iostream>
using namespace std;

//constructors
Copy::Copy()
{
	ID = 0;
	avail = 0;
	startDate = 10;
	expireDate = 0;
	reserveDate = 0;
	title = "";
	reader = "";
	reserver = "";
}
Copy::Copy(int ID, int avail, int startDate, int expireDate, int reserveDate, string title, string reader, string reserver)
{
	this->ID = ID;
	this->avail = avail;
	this->startDate = startDate;
	this->expireDate = expireDate;
	this->reserveDate = reserveDate;
	this->title = title;
	this->reader = reader;
	this->reserver = reserver;
}
//getter and setter
void Copy::setReserver(string name) {
	reserver = name;
}
string Copy::getReserver() {
	return reserver;
}
int Copy::getID()
{
	return ID;
}
int Copy::getAvail()
{
	return avail;
}
int Copy::getStartDate()
{
	return startDate;
}
int Copy::getExpireDate()
{
	return expireDate;
}
int Copy::getReserveDate()
{
	return reserveDate;
}
string Copy::getTitle()
{
	return title;
}
string Copy::getReader()
{
	return reader;
}
void Copy::setID(int ID)
{
	this->ID = ID;
}
void Copy::setAvail(int avail)
{
	this->avail = avail;
}
void Copy::setStartDate()
{
	startDate = (clock() / CLOCKS_PER_SEC / 10);
}
void Copy::setExpireDate()
{
	expireDate = getStartDate() + 30;
}
void Copy::setReserveDate(int reserveDate)
{
	this->reserveDate = reserveDate;
}
void Copy::setReader(string reader)
{
	this->reader = reader;
}