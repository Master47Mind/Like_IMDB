#pragma once
# include "Multimedia.h"
# include "Admin.h"
# ifndef GAMES_H_
# define GAMES_H_
class Games: public Multimedia
{
private:
	char Publisher[100], Platform[100], Game_mechanics[100], Developers[100], Distribution[100];
	friend class Admin;
public:
	Games(string, string,string, string, string, string,string,double,int,int,int);
	~Games();
	Games();
	void setPublisher(string);
	void setPlatform(string);//Windows,MAC etc.
	void setGame_Mechanics(string);//FirstPersonShooter,RolePlayingGame etc.
	void setDevelopers(string);
	void setDistribution(string);//optical disc,cloud computing,download etc.
	string getPublisher();
	string getPlatform();
	string getGame_Mechanics();
	string getDevelopers();
	string getDistribution();
	void Display();
	
};
#endif