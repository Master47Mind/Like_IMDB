#include "User.h"
# include <iostream>
using namespace std;
User::User(string n)
{
	setName(n);
}
User::~User()
{
}
void User::setName(string n)
{
	size_t destination_size = sizeof (Name);
	strncpy_s(Name, str_obj.String_to_Array(n, 100, Name), destination_size);
	Name[destination_size - 1] = '\0';
}//copying arrays 
string User::getName()
{
	return string(Name);
}
ostream& operator<< (ostream& cout, User& user)
{
	cout << "Name: " << user.getName() << endl;
	user.Display();
	return cout;
}
User::User()
{
	for (int i = 0; i < 100; i++)
	{
		Name[i] = '\0';
	}
}
