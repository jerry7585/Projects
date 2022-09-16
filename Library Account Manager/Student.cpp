#include "Student.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

Student::Student() { setUser(""); setPass(""); }; //Default constructors
Student::Student(string user, string pass) { setUser(user); setPass(pass); } //parameterized constructor

istream& operator >> (istream& input, Student& student) // Overloaded operator for inputs
{
	string user, pass;
	input >> user >> pass;
	student.setUser(user);
	student.setPass(pass);
	return input;
}
ostream& operator << (ostream& output, Student& student) //Overloaded operator for outputs
{
	cout << "\n\nUsername: " << student.getUser() << endl; //Prints Name (No password for safety reasons :))
	cout << "Password: ";
	student.printPassStars(student.getPass());
	cout << endl;
	cout << "You are currently borrowing the following books: " << endl;
	for (int i = 0; i < 5; i++) //Prints borrowed Books
	{
		if (student.getBooks(i) != "" && student.getBooks(i) != "NULL")
		{
			cout << student.getBooks(i) << " Expires in : " << student.getBorrowPeriod(i) - (clock() / CLOCKS_PER_SEC / 10) << "days" << endl;
		}
	}
	cout << "Books currently reserved: " << endl;
	for (int i = 0; i < 5; i++) //Prints reserved books
	{
		if (student.getReserve(i) != "NULL" && student.getReserve(i) != "")
			cout << student.getReserve(i) << endl;
	}
	return output;
}
