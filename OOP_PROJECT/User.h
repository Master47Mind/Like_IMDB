# include <string>
# include <iostream>
# include "String_Manipulator.h"
using namespace std;
# ifndef USER_H_
# define USER_H_
class User
{
protected:
	char Name[100];
	String_Manipulator str_obj;
public:
	User();
	void setName(string);
	string getName();
	User(string);
	virtual void Display() = 0;
	friend ostream& operator<< (ostream&, User&);
	virtual ~User();
};
#endif