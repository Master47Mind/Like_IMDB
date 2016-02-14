#pragma once
# include "Multimedia.h"
# include "Admin.h"
#ifndef MOVIES_H_
#define MOVIES_H_
class Movies : public Multimedia
{
private:
	char Director [100], Central_Cast [100], Distributors [100], Country[100],Awards[100];
	double Budget;
	friend class Admin;
public:
	Movies(string, string, string, string, string,string, double, string, double,int,int,int);
	~Movies();
	Movies();
	string getDirector();
	string getCentral_Cast();
	string getDistributors(); //20th century Fox,LionsGate etc.
	string getCountry();
	string getAwards();
	double getBudget();
	void setDirector(string);
	void setCentral_Cast(string);
	void setDistributors(string);
	void setCountry(string);
	void setAwards(string);
	void setBudget(double);
	void Display();
	
};
# endif