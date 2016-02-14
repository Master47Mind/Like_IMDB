#pragma once
# include <string>
using namespace std;
#ifndef STRING_MANIP
#define STRING_MANIP
class String_Manipulator
{
private:
public:
	char* String_to_Array(string,int,char[]);
	String_Manipulator();
	~String_Manipulator();
};
#endif