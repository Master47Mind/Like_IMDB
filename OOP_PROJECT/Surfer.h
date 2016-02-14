# include "User.h"
#include "Games.h"
# include "Movies.h"
#include "TVShows.h"
# include <string>
# include <iostream>
# include <fstream>
using namespace std;
#ifndef SURFER_H_
#define SURFER_H_
class Credentials_Analyzer;
class Admin;
class Surfer :public User
{
private:
	friend class Admin;
	friend class Credentials_Analyzer;
	char Hobby[100],Fav_genre[100];char Security_Quest[100];
	bool Visit_tag;
public:
	friend bool validateSurferfromFile( string,string );
	Surfer(string,string,string,string,bool);
	~Surfer();
	Surfer();
	void setQuestion(string);
	string getQuestion();
	void setHobby(string);
	void setVisittag(bool);
	bool getVisitTag();
	void setFav_genre(string);
	string getFav_genre();
	string getHobby();
	void Display();
	void SearchMoviebyName(string);
	void SearchMoviesbyGenre(string);
	void SearchTVShowbyName(string);
	void SearchTVShowsbyGenre(string);
	void SearchGamebyName(string);
	void SearchGamesbyGame_Mech(string);
	void AddReview(string);
	void ShowComments();
	void ReadNews();
	void SetProfile(Surfer&, int,bool);
	void setPassword(string,string);
	void ShowLastActivity(string);
	void ForgotPassword(string,string);
	void DeactivateAccount(string);
	void ViewProfile(string);
};
#endif