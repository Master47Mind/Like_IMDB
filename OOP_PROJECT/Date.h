#pragma once//use with precaution, it might not allow inclusion of header where gravely required
//it is to suppress file depth warning or error
#ifndef DATE_H_
#define DATE_H_
#include <iostream>
using namespace std;
class Date {
private:
	int Year;
	int Month;
	int Day;
public:
	Date();
	Date( int , int ,  int );
	bool valid(void) const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay( int);
	void setMonth(int);
	void setYear( int);
	void Display_Date();
	~Date();
};

#endif