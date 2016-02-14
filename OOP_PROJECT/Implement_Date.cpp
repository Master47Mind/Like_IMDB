#include "Date.h"

Date::Date( int day, int month, int year)
{
	Day = day;
	Month = month;
	Year = year;
}
int Date::getDay() const 
{ 
	return Day; 
}
int Date::getMonth() const 
{ 
	return Month; 
}
int Date::getYear() const 
{ 
	return Year;
}
void Date::setDay( int day) 
{ 
	if ((day == 31 && (Month == 2 || Month == 4 || Month == 6 || Month == 9 || Month == 11)))
		Day = 30;
	else if (day > 31)
		Day = 30;
	else if (day < 1)
		Day = 1;
	else if (day == 30 && Month == 2)
		Day = 28;
	else if ((day == 29 && Month == 2) && !(Year % 4 == 0)) //but not leap
		Day = 28;
	else
		Day = day;
}
void Date::setMonth(int month)
{ 
	if (month > 12)
		Month = 12;
	else if (month < 1)
		Month = 1;
	else
		Month = month;
}
void Date::setYear(int year) 
{ 
	if (year < 1970) //could be negative etc. by mistake
	{
		do
		{
			cout << "Archives do not allow outdated multimedia items or invalid year, enter year again" << endl;
			cin >> year;
		} while (year < 1970);
	}
	else 
		Year = year;
}
Date::~Date()
{
}
void Date::Display_Date()
{
	cout << Day << "/" << Month << "/" << Year << endl;
}
Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}

