#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Reader.h"
using namespace std;

class Teacher:public Reader
{
public:
	Teacher();
	Teacher(string user, string pass);
	friend istream& operator >> (istream& input, Teacher& t);
	friend ostream& operator << (ostream& output, Teacher& t);

};
