#include "User.h"
#include <iostream>
#include <string>

using namespace std;

string User::getUser() { //Gets and Sets functions
	return username;
}
string User::getPass() {
	return password;
}

void User::setUser(string user)
{
	this->username = user;
}
void User::setPass(string pass) {
	this->password = pass;
}

//print a * for every character in the password
void User::printPassStars(string pass) {
	for (int i = 0; i < pass.length(); i++) {
		cout << "*";

	}

}