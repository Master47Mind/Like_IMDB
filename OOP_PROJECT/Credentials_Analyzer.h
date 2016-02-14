#ifndef CREDENTIALS_ANALYZER
#define CREDENTIALS_ANALYZER
#include "String_Manipulator.h"
class Admin;
class Surfer;
using namespace std;
class Credentials_Analyzer
{
private:
	String_Manipulator str;
public:
	void Check_Admin(string,Admin&,Surfer&);
	void Check_Surfer(string, Surfer&,Admin&);
	void InputPassword(Admin&,Surfer&);
	Credentials_Analyzer();
	~Credentials_Analyzer();
};
#endif