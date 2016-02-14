# pragma once
# include "User.h"
# include "Multimedia.h"
# include <fstream>
# ifndef ADMIN_H_
# define ADMIN_H_
class Movies;
class TVShows;
class Games;
class Surfer;
class Credentials_Analyzer;
class Admin:public User
{
private:
	friend class Credentials_Analyzer;
	bool Eminence_tag;
	int filesize;
	char Password[6];
public:
	Admin(string,string,bool,int);
	~Admin();
	void setEminencetag(bool);
	bool getEminenceTag();
	void AddMovie(Movies&, int);
	void AddTVShow(TVShows&, int);
	void AddGame(Games&, int);
	void UpdateMovie(Movies&, int);
	void UpdateTVShow(TVShows&, int );
	void UpdateGame(Games&, int );
	void DeleteSurfer(int );
	void DeleteComment(string, string);
	void DeleteGame(int);
	void DeleteMovie(int);
	void DeleteTVShow(int);
	void ShowComments(string);
	void Display();
	void SeeAllMovies();
	void SeeAllTVShows();
	void SeeAllGames();
	void setFileSize(int);
	void setPassword(string);
	string getPassword();
	int getFileSize() const;
	void PostNews();
	void SeeAllSurfers();
};
# endif