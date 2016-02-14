#pragma once
# include <iostream>
# include "Date.h"
# include "String_Manipulator.h"
using namespace std;
# ifndef MULTIMEDIA_H_
# define MULTIMEDIA_H_
class Multimedia
{
public:
	Multimedia(string,string,double,int,int,int);
	virtual ~Multimedia();
	Multimedia();
	string getGenre();
	void setName(string);
	string getName();
	void setGenre(string);
	double getRating();
	void setRating(double);
	void setDate(int, int, int);
	virtual void Display()=0;
	friend ostream& operator<< (ostream&, Multimedia&);
protected:
	char Genre[100],Name[100];
	double Rating;
	Date release_date;
	String_Manipulator str_obj;
};
#endif