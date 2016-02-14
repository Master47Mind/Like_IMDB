# include "String_Manipulator.h"
# include <iostream>
using namespace std;
#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(push) 
#pragma warning(disable:4996) 
#endif 
char* String_Manipulator::String_to_Array(string s,int limit,char arr[])
{
	int length = s.size();
	length = (length < limit ? length : (limit-1));
	s.copy(arr, length);
	arr[length] = '\0';
	return arr;
}
String_Manipulator::String_Manipulator()
{
}
String_Manipulator::~String_Manipulator()
{
}
#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(pop) 
#endif
