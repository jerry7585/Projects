#pragma once
#include <string>
using namespace std;

class User {
private:
	string username, password;
public:
	string getUser();
	string getPass();
	void setUser(string user);
	void setPass(string pass);
	void printPassStars(string pass);
};
