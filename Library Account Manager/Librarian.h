#pragma once
#include "User.h"
#include "Book.h"
#include "Student.h"
#include "Teacher.h"
#include <string>

using namespace std;
class Librarian :public User
{
public:
	Librarian();
	Librarian(string user, string pass);
	friend istream& operator >> (istream& input, Librarian& student);
	friend ostream& operator << (ostream& output, Librarian& student);
	void searchBooks();
	void addBooks(vector<Book>& b);
	void deleteBooks(vector<Book>& b);

};

