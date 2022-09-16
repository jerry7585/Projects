#include "Reader.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

//get and set functions
string Reader::getBooks(int i)
{
	return books[i];
}
string Reader::getReserve(int i)
{
	return reserve[i];
}
int Reader::getBorrowPeriod(int i)
{
	return borrowPeriod[i];
}
void Reader::setBorrowPeriod(int x, int i)
{
	borrowPeriod[i] = x;
}
void Reader::setBooks(string s, int i)
{
	books[i] = s;
}

bool Reader::checkBooks(int accType) { //if acctype is 2, checks the array of books to see if there is an empty, return false if there is
	if (accType == 2) {
		for (int i = 0; i < 5; i++) { 
			if (books[i] != "") {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < 8; i++) {//if acctype is anything elsee, checks the array of books to see if there is an empty, return false if there is
			if (books[i] != "") {
				return false;
			}
		}
		return true;
	}

}
void Reader::addReserve(string title, int accType) { //Sets Reserve
	bool flag = false;
	if (accType == 2) {
		for (int i = 0; i < 5; i++) { //Goes through the array looking for an empty element to insert the book
			if (reserve[i] == "") {
				reserve[i] = title;
				flag = true;
				i = 5; // if found it breaks the loop
				cout << "Book has been reserved." << endl;
			}
		}
		if (flag == false) { //Means no empty arrays elements
			cout << "Reader has already resevered 5 books. Can not reserve anymore\n";
		}
	}
	else if (accType == 3) {
		for (int i = 0; i < 8; i++) { //Goes through the array looking for an empty element to insert the book
			if (reserve[i] == "") {
				reserve[i] = title;
				flag = true;
				i = 8; // if found it breaks the loop
				cout << "Book has been reserved." << endl;
			}
		}
		if (flag == false) { //Means no empty arrays elements
			cout << "Reader has already resevered 5 books. Can not reserve anymore\n";
		}
	}
}
bool Reader::checkReserve(string title) { //Checks the reserve array elements with a title
	for (int i = 0; i < 5; i++) {
		if (reserve[i] == title) {
			return true;
		}
	}
	return false;
}
void Reader::deleteReserve(string title) { //Cancels a reserve
	bool flag = false;
	for (int i = 0; i < 5; i++) {
		if (reserve[i] == title) {
			this->reserve[i] = "";
			flag = true;
		}
	}
	if (flag) {
		cout << "Reservation successfully canceled\n";
	}
}

void Reader::printReserve() {  //Prints the reserve
	int len = sizeof(reserve) / sizeof(reserve[0]);
	for (int i = 0; i < len; i++) {
		cout << reserve[i] << endl;
	}
}



bool Reader::checkOverdue() {
	for (int k = 0; k < 5; k++)//Checks if the user has an overdue book
	{
		if (getBooks(k) != "" && getBooks(k) != "NULL")
		{
			if (getBorrowPeriod(k) - (clock() / CLOCKS_PER_SEC / 10) < 0)
				//Any / 10 thats commented out is for the sake of being able to test the clock function faster. Normally the program should run it so that 1 day is 10 seconds
			{
				return true;
			}
		}
	}
	return false;
}
void Reader::setReserve(string title) { //Sets Reserve
	bool flag = false;
	for (int i = 0; i < 5; i++) { //Goes through the array looking for an empty element to insert the book
		if (reserve[i] == "") {
			reserve[i] = title;
			flag = true;
			i = 5; // if found it breaks the loop
			cout << "Book has been reserved." << endl;
		}
	}
	if (flag == false) { //Means no empty arrays elements
		cout << "User has already resevered 5 books. Can not reserve anymore. Students and Teacher accounts reserve the same amount of books.\n";
	}
}
bool Reader::isReserveFull() {
	for (int i = 0; i < 5; i++) { //checks the reserve array, if any is empty return false
		if (reserve[i] == "") {
			return false;
		}
	}
	return true;

}