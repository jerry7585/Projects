#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
#include "Librarian.h"
#include "Book.h"
#include <vector>
#include <ctime>
#include "Teacher.h"

using namespace std;



template <typename reader>
void loginStudent(vector<reader>& s, istream& in, bool& login, int& userNumber) {//prompts login screen
	cout << "--------------------------------------\n";
	cout << "----------------LOGIN-----------------\n";
	cout << "--------------------------------------\n";
	cout << "Username: ";//asks for user name
	string user, pass;
	in >> user;
	cout << "Password: ";//asks for password
	in >> pass;

	login = false; // so whenever they login , login is refreshed to false, and only when it is true, will the login continue
	for (int i = 0; i < size(s); i++) {//if there is an account with same username and password in student vector, then login 
		if (s[i].getUser() == user && s[i].getPass() == pass) {
			userNumber = i; // records the position of the logged in account in the student vector so we can change its content when needed
			login = true;
		}
	}
}
void loadBooks(vector<Book>& books) {
	int ISBN, ID, startDate, category;
	string title, author, reader;
	ifstream fin;
	fin.open("Books.txt");//opens book text and sees if it opens correctly
	if (fin.fail()) {
		cerr << "Can not open file...";
		return;
	}
	/*while (!fin.eof()) {
		fin >> ISBN >> ID >> startDate >> category >> title >> author >> reader;
		Book b(ISBN, ID, startDate, category, title, author, reader);// creates book constructor with parameters read from file
		books.push_back(b);// adds the book to the book vector
	}*/

	//Above is the alternate code if overloading is not used

	while (!fin.eof())//Pushes in the books from a txt file into a vector array using an overloaded operator
	{
		Book book;
		fin >> book;
		books.push_back(book);

	}
	for (int i = 0; i < size(books); i++) {
		for (int j = 0; j < books[i].getNumCopy(); j++) {
			books[i].addCopy(books[i].getISBN(), books);
		}
	}
	fin.close();//closes file
	cout << "\nBooks loaded from text file\n\n";
}
void checkLogin(bool login) {
	if (login) {// checks if the boolean login is true or not 
		cout << "Login Successful\n";
	}
	else {
		cout << "Username and/or Password incorrect\n";
	}
}
void createStudentAccount(vector<Student>& s, istream& in) {
	cout << "--------------------------------------\n";
	cout << "---------Account Creation-------------\n";
	cout << "--------------------------------------\n";
	fstream myFile;
	myFile.open("Student.txt"); // opens the student text so we can alter it later
	if (myFile.fail()) {// checks if file opens correctly.
		cerr << "Cannot open Student text file." << endl;
		return;
	}
	string user, pass;
	cout << "New Username: ";// asks for new username 
	in >> user;

	cout << "New Password: ";// asks for new password
	in >> pass;
	for (int i = 0; i < size(s); i++) {//if there is an account with same username and password in student vector, then login 
		if ((s[i].getUser() == user && s[i].getPass() == pass) || (s[i].getUser() == user)) {
			cout << "Duplicate account detected . . . Account can not be created\n"; // to check if there's already an account with same user and pass
			return;
		}
	}
	Student st(user, pass);//creates a student with the new username and password
	s.push_back(st);//adds the newly created student account to student vector
	cout << "Account with user: " << user << " created\n";
	myFile.seekg(0, ios::end);
	myFile << endl << user << "\t" << pass << endl;// adds the new student account into student.txt 
	myFile.seekg(0, ios::beg);

}
void createTeacherAccount(vector<Teacher>& s, istream& in) {
	cout << "--------------------------------------\n";
	cout << "---------Account Creation-------------\n";
	cout << "--------------------------------------\n";
	fstream myFile;
	myFile.open("Teacher.txt"); // opens the student text so we can alter it later
	if (myFile.fail()) {// checks if file opens correctly.
		cerr << "Cannot open Student text file." << endl;
		return;
	}
	string user, pass;
	cout << "New Username: ";// asks for new username 
	in >> user;

	cout << "New Password: ";// asks for new password
	in >> pass;
	for (int i = 0; i < size(s); i++) {//if there is an account with same username and password in student vector, then login 
		if ((s[i].getUser() == user && s[i].getPass() == pass) || (s[i].getUser() == user)) {
			cout << "Duplicate account detected . . . Account can not be created\n"; // to check if there's already an account with same user and pass
			return;
		}
	}
	Teacher st(user, pass);//creates a student with the new username and password
	s.push_back(st);//adds the newly created student account to student vector
	cout << "Account with user: " << user << " created\n";
	myFile.seekg(0, ios::end);
	myFile << endl << user << "\t" << pass << endl;// adds the new student account into student.txt 
	myFile.seekg(0, ios::beg);

}
void createLibrarianAccount(vector<Librarian>& s, istream& in) {
	cout << "--------------------------------------\n";
	cout << "---------Account Creation-------------\n";
	cout << "--------------------------------------\n";
	fstream myFile;
	myFile.open("Librarian.txt"); // opens the student text so we can alter it later
	if (myFile.fail()) {// checks if file opens correctly.
		cerr << "Cannot open Student text file." << endl;
		return;
	}
	string user, pass;
	cout << "New Username: ";// asks for new username 
	in >> user;

	cout << "New Password: ";// asks for new password
	in >> pass;
	for (int i = 0; i < size(s); i++) {//if there is an account with same username and password in student vector, then login 
		if ((s[i].getUser() == user && s[i].getPass() == pass) || (s[i].getUser() == user)) {
			cout << "Duplicate account detected . . . Account can not be created\n"; // to check if there's already an account with same user and pass
			return;
		}
	}
	Librarian st(user, pass);//creates a student with the new username and password
	s.push_back(st);//adds the newly created student account to student vector
	cout << "Account with user: " << user << " created\n";
	myFile.seekg(0, ios::end);
	myFile << endl << user << "\t" << pass << endl;// adds the new student account into student.txt 
	myFile.seekg(0, ios::beg);

}
template <typename reader>
void fileAccountStudent(vector<reader>& r) {
	cout << "--------------------------------------\n";
	cout << "---------File Account Import----------\n";
	cout << "--------------------------------------\n";
	ifstream fin;
	fin.open("Student.txt");//opens the student text
	if (fin.fail()) {// checks if the text opens correctly;
		cerr << "Error opening Student Text" << endl;
		return;
	}
	while (!fin.eof()) {
		reader user;
		fin >> user;
		r.push_back(user);
	}
	cout << "Accounts loaded from student file\n";
}// good
template <typename reader>
void fileAccountTeacher(vector<reader>& r) {
	cout << "--------------------------------------\n";
	cout << "---------File Account Import----------\n";
	cout << "--------------------------------------\n";
	ifstream fin;
	fin.open("Teacher.txt");//opens the student text
	if (fin.fail()) {// checks if the text opens correctly;
		cerr << "Error opening Teacher Text" << endl;
		return;
	}
	while (!fin.eof()) {
		reader user;
		fin >> user;
		r.push_back(user);
	}
	cout << "Accounts loaded from teacher file\n";
}// good
template <typename reader>
void fileAccountLibrarian(vector<reader>& r) {
	cout << "--------------------------------------\n";
	cout << "---------File Account Import----------\n";
	cout << "--------------------------------------\n";
	ifstream fin;
	fin.open("Librarian.txt");//opens the student text
	if (fin.fail()) {// checks if the text opens correctly;
		cerr << "Error opening Librarian Text" << endl;
		return;
	}
	while (!fin.eof()) {
		reader user;
		fin >> user;
		r.push_back(user);
	}
	cout << "Accounts loaded from Librarian file\n";
}// good
template <typename user>
void searchUsers(vector<user> u, string name, int accType) {//needs work
	bool search = false;
	if (accType == 1) {
		for (int i = 0; i < size(u); i++) {
			if (u[i].getUser() == name) {
				cout << "\nUser found!\n";
				cout << "Username: " << u[i].getUser() << endl;
				cout << "Password: ";
				u[i].printPassStars(u[i].getPass());
				cout << endl;
				cout << "Reader Type:  Librarian\n";
				search = true;
				return;

			}
		}
	}
	else {
		for (int i = 0; i < size(u); i++) {
			if (u[i].getUser() == name) {
				cout << "\nUser found!\n";
				cout << "Username: " << u[i].getUser() << endl;
				cout << "Password: ";
				u[i].printPassStars(u[i].getPass());
				cout << endl;
				cout << "Reader Type: ";
				search = true;
				if (accType == 2) {
					cout << "Student\n" << endl;
				}
				else if (accType == 3) {
					cout << "Teacher\n" << endl;
				}

				//still need printing function for books
				return;
			}
		}
	}
	if (search == false) {
		cout << "Account is not found." << endl;
	}
}
template <typename reader>
int readReserveCheck(vector<Book>& b, int ISBN, int& userNumber, vector<reader>& s) //Finds if there is an available book and returns the location of the book
{
	for (int i = 0; i < size(b); i++)
	{
		if (b[i].getISBN() == ISBN)
		{
			for (int j = 0; j < b[i].getNumCopy(); j++)
			{
				if (b[i].getCopy(j).getReader() == "NULL" || b[i].getCopy(j).getReader() == "")
				{
					cout << "location:" << j << endl;
					if (b[i].getCopy(j).getReserver() == "NULL" || b[i].getCopy(j).getReserver() == "" || b[i].getCopy(j).getReserver() == s[userNumber].getUser())
						return j;
				}
			}
		}
	}
	return -1;
}
template<typename reader>
void borrowBook(vector<Book>& b, vector<reader>& s, int& userNumber, int accType) //Function for borrowing a book
{
	int ISBN, t, x;
	bool flag = false;
	cout << "Please type in the ISBN of the Book" << endl; //User identifies the book with its ID
	cin >> ISBN;
	for (int i = 0; i < size(b); i++) {
		if (ISBN == b[i].getISBN()) { //Checks if the IDs from the input and the book vector are the same
			x = readReserveCheck(b, ISBN, userNumber, s);
			cout << "Location: " << x << endl;
			if (x == -1) //Checks if the book is borrowed
			{
				cout << "All copies of this book have been borrowed or reserved" << endl;
				return;
			}
			if (s[userNumber].checkOverdue()) {
				cout << "You cannot borrow this book, because you have an overdue book" << endl; //if a book is overdue, it stops them from borrowing
				return;
			}
			if (accType == 2) {
				for (int j = 0; j < 5; j++) //Inserts the name of the book into the student array of books (What they have borrowed)
				{
					if (s[userNumber].getBooks(j) == "" || s[userNumber].getBooks(j) == "NULL")
					{
						flag = true;
						s[userNumber].setBooks(b[i].getTitle(), j);
						t = j;
						b[i].getCopy(x).setReader(s[userNumber].getUser()); //Sets the user to the reader of the book and starts the countdown (starting date and expiration date
						b[i].getCopy(x).setStartDate();
						b[i].getCopy(x).setExpireDate();
						s[userNumber].setBorrowPeriod(b[i].getCopy(x).getExpireDate(), t);
						break;
					}

					else if (j == 4) //A check to see if the student has the max number of books borrowed
					{
						cout << "You've already borrowed 5 books\n" << endl;
						return;
					}
				}

			}
			else {
				for (int j = 0; j < 8; j++) //Inserts the name of the book into the teacher array of books (What they have borrowed)
				{
					if (s[userNumber].getBooks(j) == "" || s[userNumber].getBooks(j) == "NULL")
					{
						flag = true;
						s[userNumber].setBooks(b[i].getTitle(), j);
						t = j;
						b[i].getCopy(x).setReader(s[userNumber].getUser()); //Sets the user to the reader of the book and starts the countdown (starting date and expiration date
						b[i].getCopy(x).setStartDate();
						b[i].getCopy(x).setExpireDate();
						s[userNumber].setBorrowPeriod(b[i].getCopy(x).getExpireDate(), t);
					}

					else if (j == 7) //A check to see if the teacher has the max number of books borrowed
					{
						cout << "You've already borrowed 8 books\n" << endl;
						return;
					}
				}
			}


			if (flag) {
				cout << "You've successfully borrowed this book" << endl << endl;
				s[userNumber].deleteReserve(b[i].getTitle());
			}
		}
	}
}
template<typename reader>
void returnBook(vector<Book>& b, vector<reader>& s, int& userNumber, int accType)
{
	string title;
	cout << "Please type in the name of the book you want to return" << endl;
	cin >> title;
	for (int i = 0; i < size(b); i++) {
		if (title == b[i].getTitle())
		{
			for (int j = 0; j < size(b); j++)
			{
				if (b[i].getCopy(j).getReader() == s[userNumber].getUser())
					b[i].getCopy(j).setReader("");
			}
			if (accType == 2)
			{ 
				for (int k = 0; k < 5; k++)
				{
					if (s[userNumber].getBooks(k) == title)
					{
						s[userNumber].setBooks("", k);
					}
				}
			}
			if (accType == 3)
			{
				for (int k = 0; k < 8; k++)
				{
					if (s[userNumber].getBooks(k) == title)
					{
						s[userNumber].setBooks("", k);
					}
				}
			}
		}
	}

}
void deleteUsers(vector<Librarian>& u, vector<Student>& s, vector<Teacher>& t, string name, int accType, int& userNumber, vector<Book> books) {
	string del;
	bool acc = false;
	if (accType == 1) {
		cout << "Username of account you want to delete: ";
		cin >> del;
		for (int i = 0; i < size(u); i++) {
			if (u[i].getUser() == del) {
				u.erase(u.begin() + i);
				if (userNumber > i) {
					userNumber -= 1;
				}
				else if (userNumber == i) {
					cout << "You just deleted current account." << endl;
					userNumber = -1;
					return;
				}
				cout << "Entered username is now deleted :)!\n" << endl;
				return;
			}

		}
	}
	else if (accType == 2) {
		cout << "Username of account you want to delete: ";
		cin >> del;
		for (int i = 0; i < size(s); i++) {
			if (s[i].getUser() == del) {
				if (s[i].checkBooks(accType)) {
					for (int j = 0; j < 5; j++) {
						if (s[i].getReserve(j) != "") {
							for (int k = 0; k < size(books); k++) {
								if (s[i].getReserve(j) == books[k].getTitle()) {
									books[k].cancelReserve(s[userNumber].getUser());
								}
							}
						}
					}
					s.erase(s.begin() + i);
					//(function to remove user off reservee list of books.)
					//reserve array
					// for loop to see if they even reserving any in the first place?
					// when deleting, u just do reserve[i] = ""
					// reservee.erase(reservee.begin()+position);


					cout << "Deleted Successfully" << endl;
					return;
				}
				else {
					cout << "User has borrowed copies. Can not be deleted" << endl;
					return;
				}


			}

		}
	}
	else if (accType == 3) {
		cout << "Username of account you want to delete: ";
		cin >> del;
		for (int i = 0; i < size(t); i++) {
			if (t[i].getUser() == del) {
				if (t[i].checkBooks(accType)) {
					for (int j = 0; j < 5; j++) {
						if (s[i].getReserve(j) != "") {
							for (int k = 0; k < size(books); k++) {
								if (s[i].getReserve(j) == books[k].getTitle()) {
									books[k].cancelReserve(s[userNumber].getUser());
								}
							}
						}
					}
					t.erase(t.begin() + i);
					//(function to remove user off reservee list of books.)


					cout << "Deleted Successfully" << endl;
					return;
				}
				else {
					cout << "User has borrowed copies. Can not be deleted" << endl;
					return;
				}


			}

		}
	}
	if (acc == false) {
		cout << "User with entered username can not be found." << endl;
	}

}
template <typename reader>
void reserveBook(istream& in, vector<reader>& s, vector<Book>& b, int& userNumber, int accType) {
	ifstream fin;
	string bookFile;
	bool flag = false;
	cout << "Enter book name: ";
	string book;
	int avail = 0;
	in >> book;// asks user to enter title of book they want to reserve
	for (int i = 0; i < size(b); i++) {
		if (book == b[i].getTitle()) {// if the book is the same as title of book in the book vector
			int temp;
			for (int k = 0; k < b[i].copyVectorSize(); k++)
			{
				if (s[userNumber].getUser() == b[i].getCopy(k).getReserver()|| s[userNumber].getUser() == b[i].getCopy(k).getReader())
				{
					cout << "You already reserved or borrowed this book" << endl;
					return;
				}
			}
			if (b[i].checkAvailableCopies()) {
				b[i].setCopyReserve(s[userNumber].getUser());
				s[userNumber].setReserve(b[i].getTitle());
				return;
			}
			else {
				cout << "Cannot reserve the book. It is fully reserved " << endl;// if there are too many reservations
				return;
			}


		}
	}
	cout << "There is no book by that name" << endl;
}
template <typename reader>
void cancelBookReserve(istream& in, vector<reader>& s, vector<Book>& b, int& userNumber, int accType) {
	string name;
	cout << "Title of book you want to cancel reservation for: ";
	cin >> name;
	s[userNumber].deleteReserve(name);
	for (int i = 0; i < size(b); i++) {
		if (name == b[i].getTitle()) {
			b[i].cancelReserve(s[userNumber].getUser());
		}
	}
}
void deleCopy(int ID, vector <Book>& books, int bookPosition, vector<Student>& s, vector<Teacher>& t, int userNumber) {
	for (int i = 0; i < books[bookPosition].copyVectorSize(); i++) {
		if (books[bookPosition].getCopy(i).getID() == ID) {
			if (books[bookPosition].getCopy(i).getReader() != "") {
				cout << "Can not delete copy. Copy is being borrowed by a reader.\n";
				return;
			}
			if (books[bookPosition].getNumCopy() == 1) {
				for (int j = 0; j < size(s); j++) {
					for (int k = 0; k < 5; k++) {
						if (s[j].getReserve(k) == books[bookPosition].getTitle()) {
							s[j].deleteReserve(books[bookPosition].getTitle());
						}

					}
				}
				for (int j = 0; j < size(t); j++) {
					for (int k = 0; k < 5; k++) {
						if (t[j].getReserve(k) == books[bookPosition].getTitle()) {
							t[j].deleteReserve(books[bookPosition].getTitle());
						}

					}
				}
				cout << "You deleted last copy of " << books[bookPosition].getTitle() << endl;
				books.erase(books.begin() + bookPosition);

			}
			else {
				for (int j = 0; j < size(s); j++) {
					for (int k = 0; k < 5; k++) {
						if (s[j].getReserve(k) == books[bookPosition].getTitle()) {
							s[j].deleteReserve(books[bookPosition].getTitle());
						}

					}
				}
				for (int j = 0; j < size(t); j++) {
					for (int k = 0; k < 5; k++) {
						if (t[j].getReserve(k) == books[bookPosition].getTitle()) {
							t[j].deleteReserve(books[bookPosition].getTitle());
						}

					}
				}
				books.erase(books.begin() + bookPosition);
				books[bookPosition].setNumCopy(books[bookPosition].getNumCopy() - 1);
				cout << "There are now " << books[bookPosition].getNumCopy() << " copies of " << books[bookPosition].getTitle() << endl;
			}
		}

	}
}
void userSearchSelection(istream& in, vector<Book>& b) {
	int oper = -1, isbn, hold;
	vector<int> popularity;
	vector<int> pop;
	string name;
	cout << "What do you want to search by?\n";
	cout << "1. ISBN\n";
	cout << "2. Author's Name\n";
	cout << "3. Title\n";
	cout << "4. Category\n";
	in >> oper;
	switch (oper) {
	case 1:
		cout << "ISBN of Book you're adding: ";
		cin >> isbn;
		for (int i = 0; i < size(b); i++) {
			if (b[i].getISBN() == isbn) {
				hold = i;

			}
		}
		b[hold].print(); break;
	case 2:
		cout << "Author's name: ";
		cin >> name;
		for (int i = 0; i < size(b); i++) {
			if (b[i].getAuthor() == name) {
				popularity.push_back(i);
			}
		}
		for (int i = 0; i < size(popularity); i++) {
			for (int j = i; j < size(popularity); j++) {
				if (b[popularity[i]].getFavor() < b[popularity[j]].getFavor()) {
					int temp = popularity[i];
					popularity[i] = popularity[j];
					popularity[j] = temp;
				}
			}
		}
		for (int i = 0; i < size(popularity); i++) {
			b[popularity[i]].print();
		}
		break;
	case 3:
		cout << "Title: ";
		cin >> name;
		for (int i = 0; i < size(b); i++) {
			if (b[i].getTitle() == name) {
				b[i].print();
				cout << endl;
			}
		}break;
	case 4:
		cout << "Current Category list\n";
		cout << "1. Math\n";
		cout << "2. Chemistry\n";
		cout << "3. Engineering\n";
		cout << "4. Language\n";
		cin >> hold;
		for (int i = 0; i < size(b); i++) {
			if (b[i].getCategory() == hold) {
				pop.push_back(i);
			}
		}
		for (int i = 0; i < size(pop); i++) {
			for (int j = i; j < size(pop); j++) {
				if (b[pop[i]].getFavor() < b[pop[j]].getFavor()) {
					int temp = pop[i];
					pop[i] = pop[j];
					pop[j] = temp;
				}
			}
		}
		for (int i = 0; i < size(pop); i++) {
			b[pop[i]].print();
		}
		break;
	default:
		cout << "Invalid choice" << endl;
		break;
	}

}
template <typename reader>
void selectionPanel(istream& in, vector<reader>& s, vector<Book>& b, int& userNumber, int accType) {// selection for the user
	int oper = -1;
	cout << "----------------------------------------\n";
	cout << "\tWelcome " << s[userNumber].getUser() << "\n";
	cout << "----------------------------------------\n";
	string pass;
	while (!(oper == 0)) {
		cout << "Please choose:\n"; //Case switch depending on user input
		cout << "\t1. Search Books\n";
		cout << "\t2. Borrow Books\n";
		cout << "\t3. Return Books\n";
		cout << "\t4. Reserve Books\n";
		cout << "\t5. Cancel Reservations\n";
		cout << "\t6. My Information\n";
		cout << "\t7. Change Password\n";
		cout << "\t8. Recommend Books\n";
		cout << "\t0. Logout\n";
		cin >> oper;// asks for selection
		switch (oper) {// prompts the selected selection
		case 1:
			userSearchSelection(cin, b);
			break;
		case 2:
			borrowBook(b, s, userNumber,accType);
			break;
		case 3:
			//returnBook(b, s, userNumber);
			break;
		case 4:
			reserveBook(cin, s, b, userNumber, accType);
			break;
		case 5:
			cancelBookReserve(cin, s, b, userNumber, accType);
			break;
		case 6:
			cout << s[userNumber];
			break;
		case 7:
			/*cout << "Enter new password: " << endl;
			cin >> pass;// enters new password
			s[userNumber].setPass(pass); // changes previous password to this new password
			cout << "Sucessflly changed password." << endl;// prints a confirmation
			*/
			break;
		case 8:
			//s[userNumber].recommendBooks(b);
		case 0:
			break;
		default: cout << "Invalid choice."; break; //If input is not recognized, the switch case is run again
		}
	}
}

void loginPanelpt1(int& accType) {// to login into which type of account
	cout << "Which type of account are you looking for?" << endl;
	cout << "1. Librarian\n";
	cout << "2. Student\n";
	cout << "3. Teacher\n";
	int choice;
	cin >> choice;
	accType = choice;
}

void selectionPanelLibrarian(istream& in, vector<Librarian>& l, vector<Student>& s, vector<Teacher>& t, vector<Book>& b, int& userNumber) {
	int accType;
	int isbn;
	int hold;
	string pass;
	cout << "----------------------------------------\n";
	cout << "Welcome Librarian " << l[userNumber].getUser() << endl;
	cout << "----------------------------------------\n";
	int oper(-1);
	while (!(oper == 0)) {
		cout << "Please choose:\n"; //Case switch depending on librarian input
		cout << "\t1. Search Books\n";
		cout << "\t2. Add Books\n";
		cout << "\t3. Delete Books\n";
		cout << "\t4. Search Users\n";
		cout << "\t5. Add Users\n";
		cout << "\t6. Delete Users\n";
		cout << "\t7. My information\n";
		cout << "\t8. Change Password\n";
		cout << "\t0. Logout\n";
		cin >> oper;// asks for selection
		string nameSearch;
		switch (oper) {
		case 1:
			userSearchSelection(cin, b);
			break;
		case 2:
			cout << "ISBN of Book you're adding: ";
			cin >> isbn;
			for (int i = 0; i < size(b); i++) {
				if (b[i].getISBN() == isbn) {
					hold = i;

				}
			}
			b[hold].addCopy(isbn, b);
			cout << "Copy successfully added." << endl;
			break;
		case 3:
			cout << "Title of book you want to delete: ";
			cin >> nameSearch;
			for (int i = 0; i < size(b); i++) {
				if (b[i].getTitle() == nameSearch) {
					cout << "ID of copy u wish to delete: ";
					cin >> hold;
					deleCopy(hold, b, i, s, t, userNumber);
				}
			}
			break;
		case 4:
			loginPanelpt1(accType);
			cout << "Who are you trying to find?\n";
			cout << "Username: ";
			cin >> nameSearch;
			if (accType == 1) {
				searchUsers(l, nameSearch, accType);
			}
			else if (accType == 2) {
				searchUsers(s, nameSearch, accType);
			}
			else if (accType == 3) {
				searchUsers(t, nameSearch, accType);
			}
			break;
		case 5:
			loginPanelpt1(accType);
			if (accType == 1) {
				createLibrarianAccount(l, cin);
			}
			else if (accType == 2) {
				createStudentAccount(s, cin);
			}
			else if (accType == 3) {
				createTeacherAccount(t, cin);
			}
			break;
		case 6:
			loginPanelpt1(accType);
			cout << "Who are you trying to delete?\n";
			cout << "Username: ";
			cin >> nameSearch;
			if (accType == 1) {
				deleteUsers(l, s, t, nameSearch, accType, userNumber, b);
				if (userNumber == -1) {
					oper = 0;
				}
			}
			else if (accType == 2) {
				deleteUsers(l, s, t, nameSearch, accType, userNumber, b);
			}
			else if (accType == 3) {
				deleteUsers(l, s, t, nameSearch, accType, userNumber, b);
			}

			break;
		case 7:
			cout << l[userNumber];
			break;
		case 8:
			cout << "What's your current password?" << endl;
			cin >> pass;
			if (pass == l[userNumber].getPass()) {
				cout << "Correct Password!\n";
				cout << "Enter New Password: ";
				cin >> pass;
				l[userNumber].setPass(pass);
			}
			else {
				cout << "You did not enter the correct current password.\n";
			}
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice.";
			break;
		}
	}
}

void loginPanel(istream& in, vector<Student>& s, vector<Book>& b, vector<Teacher> t, vector<Librarian> l, bool& login, int& userNumber) {
	while (1) {
		int accType;
		loginPanelpt1(accType);
		cout << "1. Login\n";
		cout << "2. Exit Program\n";
		int oper;
		in >> oper;
		switch (oper) {
		case 1:
			if (accType == 1) {
				loginStudent(l, cin, login, userNumber);// asks for username and password of account and changes login boolean accordingly
				checkLogin(login);// checks the status of log in and prints message out 
				if (login) {// if login successful, then continue to selection screen
					cout << "LOGGED IN\n\n\n Weclome Librarian\n";// for logout, u can just leave blank statement. and because it's blank, it will pop out of this if statement
					selectionPanelLibrarian(cin, l, s, t, b, userNumber);
				}

			}
			else if (accType == 2) {
				loginStudent(s, cin, login, userNumber);// asks for username and password of account and changes login boolean accordingly
				checkLogin(login);// checks the status of log in and prints message out 
				if (login) {// if login successful, then continue to selection screen
					cout << "LOGGED IN\n\n\n Weclome Student\n";// for logout, u can just leave blank statement. and because it's blank, it will pop out of this if statement
					selectionPanel(cin, s, b, userNumber, accType);
				}
			}
			else if (accType == 3) {
				loginStudent(t, cin, login, userNumber);// asks for username and password of account and changes login boolean accordingly
				checkLogin(login);// checks the status of log in and prints message out 
				if (login) {// if login successful, then continue to selection screen
					cout << "LOGGED IN\n\n\n Weclome Teacher\n";// for logout, u can just leave blank statement. and because it's blank, it will pop out of this if statement
					selectionPanel(cin, t, b, userNumber, accType);
				}

			}


			break;
		case 2:
			cout << "Exiting Program. . .\n";
			exit(1);
		default:
			cout << "Not a valid choice. Please Try again.\n"; break;
		}
	}

}

int main() {
	vector<Student> s; //Initializes the arrays, fills them up with the corresponding files and starts the console
	vector<Book> b;
	vector<Teacher> t;
	vector<Librarian> l;
	bool login;
	int userNumber = -1;
	fileAccountStudent(s);
	fileAccountTeacher(t);
	fileAccountLibrarian(l);
	loadBooks(b);

	loginPanel(cin, s, b, t, l, login, userNumber);
}
