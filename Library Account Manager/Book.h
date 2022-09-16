#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Copy.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Book
{
private:
	int ISBN, index, category, favor, numCopy;
	//startDate and expireDate are ints for now, but could be changed for a different implimentation
	//The reason for putting category in int is so that each number can represent a topic
	//We can decide on which number is which topic in the implementation
	string title, author;
	vector<Copy> copies;
public:
	Book();
	Book(int ISBN, int index, int category, int favor, int numCopy, string title, string author);
	friend istream& operator >>(istream& input, Book& book);
	friend ostream& operator <<(ostream& output, Book& book);
	int getISBN();
	int getCategory();
	int getIndex();
	int getNumCopy();
	int copyVectorSize();
	int getFavor();
	Copy getCopy(int i);
	string getTitle();
	string getAuthor();
	bool checkAvailableCopies();
	void setISBN(int ISBN);
	void setCategory(int Category);
	void setTitle(string title);
	void setAuthor(string author);
	void setIndex(int index);
	void setNumCopy(int numCopy);
	void setFavor(int favor);
	void print();
	string categoryCheck(int category);
	void addCopy(int ISBN, vector<Book>& books);
	//void deleCopy(int ID, vector <Book>& books, int bookPosition, vector<Student>& s, vector<Teacher>& t);
	void setCopyReserve(string name);
	void cancelReserve(string name);
};
