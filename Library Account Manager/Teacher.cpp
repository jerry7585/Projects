#include "Teacher.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

Teacher::Teacher() {
	setUser(""); setPass("");
}//Default constructors
Teacher::Teacher(string user, string pass) { setUser(user); setPass(pass); } //parameterized constructor

istream& operator >> (istream& input, Teacher& t) // Overloaded operator for inputs
{
	string user, pass;
	input >> user >> pass;
	t.setUser(user);
	t.setPass(pass);
	return input;
}
ostream& operator << (ostream& output, Teacher& t) //Overloaded operator for outputs
{
	cout << "\n\nUsername: " << t.getUser() << endl; //Prints Name (No password for safety reasons :))
	cout << "Password: ";
	t.printPassStars(t.getPass());
	cout << endl;
	cout << "You are currently borrowing the following books: " << endl;
	for (int i = 0; i < 8; i++) //Prints borrowed Books
	{
		if (t.getBooks(i) != "" && t.getBooks(i) != "NULL")
		{
			cout << t.getBooks(i) << " Expires in : " << t.getBorrowPeriod(i) - (clock() / CLOCKS_PER_SEC / 10) << "days" << endl;
		}
	}
	cout << "Books currently reserved: " << endl;
	for (int i = 0; i < 5; i++) //Prints reserved books
	{
		if (t.getReserve(i) != "NULL" && t.getReserve(i) != "")
			cout << t.getReserve(i) << endl;
	}
	return output;
}
