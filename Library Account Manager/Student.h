#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Reader.h"
using namespace std;

class Student :public Reader
{
public:
	Student();
	Student(string user, string pass);
	friend istream& operator >> (istream& input, Student& student);
	friend ostream& operator << (ostream& output, Student& student);

};