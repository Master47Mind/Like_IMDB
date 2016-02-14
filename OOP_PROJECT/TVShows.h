#pragma once
# include "Multimedia.h"
# include "Admin.h"
#ifndef TVSHOWS_H_
#define TVSHOWS_H_
class TVShows:public Multimedia
{
public:
	TVShows(string,string, string,string, string, string, string, double,string,double,int,int,int);
	~TVShows();
	TVShows();
	void setViewers(double);
	void setDistributors(string);//Warner Bros etc.
	void setCreator(string); //Idea protagonist or executive producer
	void setCentral_Cast(string);
	void setLocation(string);
	void setChannel(string);
	double getViewers();
	string getDistributors();
	string getCreator();
	string getAwards();
	void setAwards(string);
	string getCentral_Cast();
	string getChannel();
	string getLocation();
	void Display();
	
private:
	friend class Admin;
	double viewers_in_millions;
	char Distributors [100],Awards[100], Creator[100], Central_Cast[100], Location[100], Channel[100];
};
#endif