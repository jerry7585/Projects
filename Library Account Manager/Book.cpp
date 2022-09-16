#include "Book.h"
#include "Copy.h"
#include <string>
#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include <ctime>
using namespace std;
//Just implementations so far
Book::Book()
{
	ISBN = 0;
	index = 0;
	category = 0;
	favor = 0;
	numCopy = 0;
	title = "";
	author = "";
}
Book::Book(int ISBN, int index, int category, int favor, int numCopy, string title, string author)
{
	this->ISBN = ISBN;
	this->category = category;
	this->title = title;
	this->author = author;
	this->index = index;
	this->numCopy = numCopy;
	this->favor = favor;
}
istream& operator >> (istream& input, Book& book) //Overloaded operator for inputting in a book
{
	int ISBN, index, category, numCopy, favor;
	string title, author;
	input >> ISBN >> index >> category >> numCopy >> favor >> title >> author;
	book.setISBN(ISBN);
	book.setIndex(index);
	book.setCategory(category);
	book.setNumCopy(numCopy);
	book.setFavor(favor);
	book.setTitle(title);
	book.setAuthor(author);

	return input;
}
ostream& operator << (ostream& output, Book& book) //Overloaded operator for outputting a book
{
	output << "ISBN: " << book.getISBN() <<
		"\nCategory: " << book.categoryCheck(book.getCategory()) <<
		"\nTitle: " << book.getTitle() <<
		"\nAuthor: " << book.getAuthor() << //Some info on the book is left out due to being irrelevant or safety concers :) 
		"\nIndex: " << book.getIndex() <<
		"\nCopies: " << book.getNumCopy() <<
		"\nFavor: " << book.getFavor() << endl;
	return output;
}
int Book::getISBN() //Gets and Sets functions
{
	return ISBN;
}
int Book::getIndex() {
	return index;
}
int Book::getCategory()
{
	return category;
}
int Book::getFavor() {
	return favor;
}
int Book::getNumCopy() {
	return numCopy;
}
Copy Book::getCopy(int i)
{
	return copies[i];
}
string Book::getTitle()
{
	return title;
}
string Book::getAuthor()
{
	return author;
}
void Book::setISBN(int ISBN)
{
	this->ISBN = ISBN;
}
void Book::setCategory(int category)
{
	this->category = category;
}
void Book::setTitle(string title)
{
	this->title = title;
}
void Book::setAuthor(string author)
{
	this->author = author;
}
void Book::setFavor(int favor) {
	this->favor = favor;
}
void Book::setNumCopy(int numCopy) {
	this->numCopy = numCopy;
}
void Book::setIndex(int index) {
	this->index = index;
}

void Book::print() //Prints all contents (used everywhere in the code)
{
	cout << "\nISBN: " << getISBN() << endl;
	cout << "Category: " << categoryCheck(getCategory()) << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Number of Copies: " << getNumCopy() << endl << endl;

}

int Book::copyVectorSize() {
	return size(copies);
}
string Book::categoryCheck(int category) //Turns the ints of categories into strings
{
	switch (category)
	{
	case 1:
		return "Math";
	case 2:
		return "Chemistry";
	case 3:
		return "Engineering";
	case 4:
		return "Language";
	default:
		return "Unknown/Must be added recently"; //More categories can be added
	}
}

void Book::addCopy(int ISBN, vector<Book>& books) { //goes through the books vector and checks to see if ISBN will match the input
	for (int i = 0; i < size(books); i++) {
		if (books.at(i).getISBN() == ISBN) { //if it matches, create a copy into book and push it into the copies vector
			Copy boook;
			boook.setID(size(copies) + 1);
			boook.setAvail(true);
			boook.setStartDate();
			boook.setExpireDate();
			boook.setReserveDate(0);
			boook.setReader("");
			copies.push_back(boook);
			return;
		}
	}
	//if it doesnt match we can add the book in with every information 1 by 1
	Book book;
	cout << "There is no book with that ISBN. Enter book information to add new book." << endl;
	cout << "category :" << endl;
	cin >> category;
	cout << "title: " << endl;
	cin >> title;
	cout << "author: " << endl;
	cin >> author;
	cout << "index: " << endl;
	cin >> index;
	book.setISBN(ISBN);
	book.setCategory(category);
	book.setTitle(title);
	book.setIndex(index);
	book.setNumCopy(0);
	book.setFavor(0);
	books.push_back(book);
	addCopy(book.getISBN(), books);
}
/*void Book::deleCopy(int ID, vector <Book>& books, int bookPosition, vector<Student>& s, vector<Teacher>& t) {
	for (int i = 0; i < size(copies); i++) {
		if (copies[i].getID() == ID) {
			if (copies[i].getReader() != "") {
				cout << "Can not delete copy. Copy is being borrowed by a reader.\n";
				return;
			}
			if (getNumCopy() == 1) {
				cout << "You deleted last copy of " << getTitle() << endl;
				books.erase(books.begin() + bookPosition);
				for (int j = 0; j < size(s); j++) {
					if (s[j].checkReserve(getTitle())) {
						s[j].deleteReserve(getTitle());
					}

				}
			}
			else {
				books.erase(books.begin() + bookPosition);
				books[bookPosition].setNumCopy(getNumCopy() - 1);
				cout << "There are now " << getNumCopy() << " copies of " << getTitle() << endl;
			}
		}
		//still need function to delete off of reservee lists
	}
}*/
bool Book::checkAvailableCopies() { //goes through the copies vector and checks to see if the reserver is empty return true if it is empty
	for (int i = 0; i < size(copies); i++) {
		if (copies[i].getReserver() == "") {
			return true;
		}
	}
	return false;
}
void Book::cancelReserve(string name) {
	for (int i = 0; i < size(copies); i++) { //goes through the copies vector and checks to see if the reserver is equal to the name, make it empty when it matches
		if (copies[i].getReserver() == name) {
			copies[i].setReserver("");
			return;
		}
	}
}
void Book::setCopyReserve(string name) {
	for (int i = 0; i < size(copies); i++) { //goes through the copies vector and checks to see if the reserver is empty 
		if (copies[i].getReserver() == "") {
			copies[i].setReserver(name); //set the reserver to the input name and start the timer for clock
			copies[i].setReserveDate((clock() / CLOCKS_PER_SEC) / 10 + 5);
			return;
		}
	}

}