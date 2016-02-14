# include <windows.h>
# include <string>
# include "Admin.h"
# include "Surfer.h"
# include "Credentials_Analyzer.h"
using namespace std;
Credentials_Analyzer::Credentials_Analyzer()
{
}
void Credentials_Analyzer::Check_Admin(string admin_pass, Admin &a,Surfer&s)
{
	string pass=a.getPassword();
	if (s.getVisitTag() == false)
	{
		if (admin_pass == pass)
		{
			cout << "\aAccess granted, Welcome Admin!" << endl;
			bool tag = true;
			a.setEminencetag(tag);
		}
		else
		{
			cout << "\aAccess denied!You are not recognized as Admin!" << endl;
			bool tag = false;
			a.setEminencetag(tag);
		}
	}
}
void Credentials_Analyzer::Check_Surfer(string surf_pass, Surfer &s,Admin&a)
{
	bool pass=validateSurferfromFile(surf_pass,s.getName());
	if (a.getEminenceTag() == false)
	{
		if (pass)
		{
			cout << "\aAccess granted, Welcome Surfer!" << endl;
			bool tag = true;
			s.setVisittag(tag);
		}
		else
		{
			cout << "\aAccess denied!You are not recognized as Surfer!" << endl;
			bool tag = false;
			s.setVisittag(tag);
		}
	}
}
void Credentials_Analyzer::InputPassword( Admin &a, Surfer &s)
{
	string str="", nstr="";
	cout << "\nEnter your name: ";
	fflush(stdin);
	getline(cin, nstr);
	s.setName(nstr);
	a.setName(nstr);
	cout << "\nEnter your unique 5 characters long password(you won't see it!): " << endl;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));//Hide what is entered
	fflush(stdin);
	getline(cin, str);
	SetConsoleMode(hStdin, mode);//Echo now what is entered 
	Check_Admin(str, a, s);
	Check_Surfer(str, s,a);
}
Credentials_Analyzer::~Credentials_Analyzer()
{
}
