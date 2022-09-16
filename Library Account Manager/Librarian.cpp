#include "Librarian.h"
#include "Book.h"
#include "Student.h"
#include "Teacher.h"
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

Librarian::Librarian() {
	setUser("");
	setPass("");
}
istream& operator >> (istream& input, Librarian& l) // Overloaded operator for inputs
{
	string user, pass;
	input >> user >> pass;
	l.setUser(user);
	l.setPass(pass);
	return input;
}
ostream& operator << (ostream& output, Librarian& l) //Overloaded operator for outputs
{

	cout << "\n\nUsername: " << l.getUser() << endl; //Prints Name (No password for safety reasons :))
	cout << "Password: ";
	l.printPassStars(l.getPass());
	cout << endl;
	cout << "Account Type: Librarian\n";
	return output;
}
Librarian::Librarian(string user, string pass) {
	setUser(user);
	setPass(pass);
}






