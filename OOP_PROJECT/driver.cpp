# include "Admin.h"
# include "Date.h"
# include "Games.h"
# include "Movies.h"
# include "Surfer.h"
# include "TVShows.h"
# include <string>
# include <iostream>
#include <stdio.h>
# include <fstream>
#include <windows.h>
# include "Credentials_Analyzer.h"
using namespace std;

//Prototype declarations
int AdminChoices();
int SurferChoices();


int main()
{
	cout << "\n\n\n***///___WELCOME TO YOUR GUIDE TO THE WORLD OF ENTERTAINMENT___///***\n\n\n" << endl;
	
	//Objects
	Admin Finch("HEAT", "Blaze", false, 100);
	Surfer Reese("Sci-fi", "Gaming", "John", "Are you a Gamer?", false);
	Games aGame("Crytek", "Windows/XBOX", "Crysis 3", "FPS", "Electronic Arts", "Optical disc/download", "Sci_Fi/Action", 8.8, 14, 4, 2012);
	Movies aMovie("Michael Bay", "Mark Wahlberg, Nicola Peltz", "Transformers", "DreamWorks Pictures", "USA", " Best Special Effects in the 2007 Kuala Lumpur International Film Festival", 150, "Sci-Fi/Action", 8.0, 27, 6, 2007);
	TVShows aTVShow("Warner Bros", "People's Choice Award", "John Nolan", "Jim Caviezel, Michael Emerson", "Person of Interst", "USA", "CBS", 17.87, "Action, Crime, Drama", 8.8, 22, 9, 2011);
	Credentials_Analyzer cred;
	Surfer blank; Movies empty; Games none; TVShows Void;

	//Files  //open them
	fstream movies,tvshows,games,comments,passwords,surfers,news;
	movies.open("Movies.dat",ios_base::in | ios_base::out);
	tvshows.open("TVShows.dat", ios_base::in | ios_base::out);
	games.open("Games.dat", ios_base::in | ios_base::out);
	surfers.open("Surfers.dat", ios_base::in | ios_base::out);
	comments.open("Comments.txt", ios_base::in | ios_base::out);
	news.open("News.txt", ios_base::in | ios_base::out);
	passwords.open("Passwords.txt", ios_base::in | ios_base::out);
	if (!movies) //if not present, create them with empty records specified in Admin's constructor when server is created
	{
		fstream movies("Movies.dat", ios::in | ios::out |ios::binary|ios::trunc);
		for (int i = 1; i <= Finch.getFileSize(); i++)
		{
			movies.seekp((i - 1)*sizeof(Movies));
			movies.write(reinterpret_cast<const char*>(&empty), sizeof(Movies));
		}
		movies.close();
	}
	if (!tvshows)
	{
		fstream tvshows("TVShows.dat", ios::in | ios::out | ios::binary | ios::trunc);
		for (int i = 1; i <= Finch.getFileSize(); i++)
		{
			tvshows.seekp((i - 1)*sizeof(TVShows));
			tvshows.write(reinterpret_cast<const char*>(&Void), sizeof(TVShows));
		}
		tvshows.close();
	}
	if (!games)
	{
		fstream games("Games.dat", ios::in|ios::out|ios::binary|ios::trunc);
		for (int i = 1; i <= Finch.getFileSize(); i++)
		{
			games.seekp((i - 1)*sizeof(Games));
			games.write(reinterpret_cast<const char*>(&none), sizeof(Games));
		}
		games.close();
	}
	if (!news)
		fstream news("News.txt", ios::in | ios::out |ios::trunc);
	if (!comments)
		fstream comments("Comments.txt", ios::in|ios::out|ios::trunc);
	if ( !passwords)
		fstream passwords("Passwords.txt", ios::in|ios::out|ios::trunc);
	if (!surfers)
	{
		fstream surfers("Surfers.dat", ios::in|ios::out|ios::binary|ios::trunc);
		for (int i = 1; i <= Finch.getFileSize(); i++)
		{
			surfers.seekp((i - 1)*sizeof(Surfer));
			surfers.write(reinterpret_cast<const char*>(&blank), sizeof(Surfer));
		}
		surfers.close();
	}

	//Local variables
	bool to_update=false;
	int choice_ad,choice_surf,id=1,dy=0,m=0,yr=0,count=1;
	string str,surfer,quest;
	char choice;
	double doubles;

	//Core Functionality
	do
	{ 
		cout << "\nPress 'a' if you are member already,\nPress 's' to signup if you are a new surfer,\nPress 'q' if you forgot your password,\nPress 'e' to exit: " << endl;
		fflush(stdin);
		cin >> choice;
		if (choice == 'a')
		{
			cred.InputPassword(Finch, Reese);
		}

		if (choice == 'q')
		{
			cout << "Enter your name: " << endl;
			fflush(stdin);
			getline(cin, str);
			cout << "Enter your security question" << endl;
			fflush(stdin);
			getline(cin, quest);
			Reese.ForgotPassword(str,quest);
		}
		if (choice == 's')
		{
			cout << "Enter name: ";
			fflush(stdin);
			getline(cin,str);
			Reese.setName(str);
			cout << "\nEnter favourite genre: ";
			fflush(stdin);
			getline(cin,str);
			Reese.setFav_genre(str);
			cout << "\nEnter your hobby: ";
			fflush(stdin);
			getline(cin,str);
			Reese.setHobby(str);
			cout << "\nEnter security question: ";
			fflush(stdin);
			getline(cin,str);
			Reese.setQuestion(str);
			cout << "\nEnter unique ID form 0 to " << Finch.getFileSize() << endl;
			cin >> id;
			while (id<0 || id>Finch.getFileSize())
			{
				cout << "\nEnter unique ID form 0 to " << Finch.getFileSize() << endl;
				cin >> id;
			}
			Reese.SetProfile(Reese, id,to_update);
		}

		if (Finch.getEminenceTag())
		{
			do
			{
				choice_ad = AdminChoices();
				switch (choice_ad)
				{
				case 1:
					cout << "\nEnter movie's name: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setName(str);
					cout << "\nEnter its genre: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setGenre(str);
					cout << "\nEnter its BOX OFFICE rating(decimals allowed): ";
					cin >> doubles;
					aMovie.setRating(doubles);
					cout << "\nEnter its Central_Cast characters:  ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setCentral_Cast(str);
					cout << "\nEnter its Director name: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setDirector(str);
					cout << "\nEnter its Distributors: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setDistributors(str);
					cout << "\nEnter budget (enter hard figure only, it'll be assumed in US million dollars): ";
					cin >> doubles;
					aMovie.setBudget(doubles);
					cout << "\nEnter Awards: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setAwards(str);
					cout << "\nEnter country: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setCountry(str);
					cout << "\nEnter channel: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setChannel(str);
					cout << "\nEnter release day(int): ";
					cin >> dy;
					cout << "\nEnter release month(int): ";
					cin >> m;
					cout << "\nEnter release year(int): ";
					cin >> yr;
					aMovie.setDate(dy, m, yr);
					do
					{
						cout << "\nEnter block no. where you want to put data object in file:  ";
						cin >> id;
					} while (id < 0 || id>Finch.getFileSize());
					Finch.AddMovie(aMovie, id);
					break;
				case 2:
					cout << "\nEnter shows's name: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setName(str);
					cout << "\nEnter its genre: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setGenre(str);
					cout << "\nEnter viewers (enter hard figure in decimals, they will be assumed in millions): ";
					cin >> doubles;
					aTVShow.setViewers(doubles);
					cout << "\nEnter its BOX OFFICE rating(decimals allowed): ";
					cin >> doubles;
					aTVShow.setRating(doubles);
					cout << "\nEnter its central_cast characters:  ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setCentral_Cast(str);
					cout << "\nEnter its creator name: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setCreator(str);
					cout << "\nEnter its distributors: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setDistributors(str);
					cout << "\nEnter awards: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setAwards(str);
					cout << "\nEnter location: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setLocation(str);
					cout << "\nEnter release day(int): ";
					cin >> dy;
					cout << "\nEnter release month(int): ";
					cin >> m;
					cout << "\nEnter release year(int): ";
					cin >> yr;
					aTVShow.setDate(dy, m, yr);
					do
					{
						cout << "\nEnter block no. where you want to put data object in file:  ";
						cin >> id;
					} while (id < 0 || id>Finch.getFileSize());
					Finch.AddTVShow(aTVShow, id);
					break;
				case 3:
					cout << "\nEnter game's name: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setName(str);
					cout << "\nEnter its genre: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setGenre(str);
					cout << "\nEnter its Game Spot rating(decimals allowed): ";
					cin >> doubles;
					aGame.setRating(doubles);
					cout << "\nEnter its developers:  ";
					fflush(stdin);
					getline(cin,str);
					aGame.setDevelopers(str);
					cout << "\nEnter its in_game mechanics: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setGame_Mechanics(str);
					cout << "\nEnter its way of dissemination and distribution in market: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setDistribution(str);
					cout << "\nEnter Publishers: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setPublisher(str);
					cout << "\nEnter platform to play: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setPlatform(str);
					cout << "\nEnter release day(int): ";
					cin >> dy;
					cout << "\nEnter release month(int): ";
					cin >> m;
					cout << "\nEnter release year(int): ";
					cin >> yr;
					aGame.setDate(dy, m, yr);
					do
					{
						cout << "\nEnter block no. where you want to put data object in file:  ";
						cin >> id;
					} while (id < 0 || id>Finch.getFileSize());
					Finch.AddGame(aGame, id);
					break;
				case 6:
					Finch.SeeAllMovies();
					break;
				case 4:
					Finch.SeeAllTVShows();
					break;
				case 5:
					Finch.SeeAllGames();
					break;
				case 7:
					cout << "\nEnter Surfer's block no.: ";
					cin >> id;
					Finch.DeleteSurfer(id);
					Reese.setName("");
					passwords.close();

					if (remove("Passwords.txt") != 0)
						perror("Error deleting file");
					else
						puts("Insider operation, passwords file deleted successfully!");

					rename("newPasswords.txt", "Passwords.txt");
					break;
				case 8:
					cout << "\nEnter movie's name: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setName(str);
					cout << "\nEnter its genre: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setGenre(str);
					cout << "\nEnter its BOX OFFICE rating(decimals allowed): ";
					cin >> doubles;
					aMovie.setRating(doubles);
					cout << "\nEnter its Central_Cast characters:  ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setCentral_Cast(str);
					cout << "\nEnter its Director name: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setDirector(str);
					cout << "\nEnter its Distributors: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setDistributors(str);
					cout << "\nEnter budget (enter hard figure only, it'll be assumed in US million dollars): ";
					cin >> doubles;
					aMovie.setBudget(doubles);
					cout << "\nEnter Awards: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setAwards(str);
					cout << "\nEnter country: ";
					fflush(stdin);
					getline(cin,str);
					aMovie.setCountry(str);
					cout << "\nEnter channel: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setChannel(str);
					cout << "\nEnter release day(int): ";
					cin >> dy;
					cout << "\nEnter release month(int): ";
					cin >> m;
					cout << "\nEnter release year(int): ";
					cin >> yr;
					aMovie.setDate(dy, m, yr);
					do
					{
						cout << "\nEnter block no. where you want to put data object in file:  ";
						cin >> id;
					} while (id < 0 || id>Finch.getFileSize());
					Finch.UpdateMovie(aMovie, id);
					break;
				case 9:
					cout << "\nEnter shows's name: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setName(str);
					cout << "\nEnter its genre: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setGenre(str);
					cout << "\nEnter its BOX OFFICE rating(decimals allowed): ";
					cin >> doubles;
					aTVShow.setRating(doubles);
					cout << "\nEnter its central_cast characters:  ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setCentral_Cast(str);
					cout << "\nEnter its creator name: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setCreator(str);
					cout << "\nEnter its distributors: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setDistributors(str);
					cout << "\nEnter awards: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setAwards(str);
					cout << "\nEnter location: ";
					fflush(stdin);
					getline(cin,str);
					aTVShow.setLocation(str);
					cout << "\nEnter release day(int): ";
					cin >> dy;
					cout << "\nEnter release month(int): ";
					cin >> m;
					cout << "\nEnter release year(int): ";
					cin >> yr;
					aTVShow.setDate(dy, m, yr);
					do
					{
						cout << "\nEnter block no. where you want to put data object in file:  ";
						cin >> id;
					} while (id < 0 || id>Finch.getFileSize());
					Finch.UpdateTVShow(aTVShow, id);
					break;
				case 10:
					cout << "\nEnter game's name: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setName(str);
					cout << "\nEnter its genre: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setGenre(str);
					cout << "\nEnter its Game Spot rating(decimals allowed): ";
					fflush(stdin);
					getline(cin,str);
					aGame.setRating(doubles);
					cout << "\nEnter its developers:  ";
					fflush(stdin);
					getline(cin,str);
					aGame.setDevelopers(str);
					cout << "\nEnter its in_game mechanics: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setGame_Mechanics(str);
					cout << "\nEnter its way of dissemination and distribution in market: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setDistribution(str);
					cout << "\nEnter Publishers: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setPublisher(str);
					cout << "\nEnter platform to play: ";
					fflush(stdin);
					getline(cin,str);
					aGame.setPlatform(str);
					cout << "\nEnter release day(int): ";
					cin >> dy;
					cout << "\nEnter release month(int): ";
					cin >> m;
					cout << "\nEnter release year(int): ";
					cin >> yr;
					aGame.setDate(dy, m, yr);
					do
					{
						cout << "\nEnter block no. where you want to put data object in file:  ";
						cin >> id;
					} while (id < 0 || id>Finch.getFileSize());
					Finch.UpdateGame(aGame, id);
					break;
				case 11:
					do
					{
						cout << "\nEnter location of movie to delete it: ";
						cin >> id;
					} while (id < 0 || id>Finch.getFileSize());
					Finch.DeleteMovie(id);
					break;
				case 12:
					cout << "\nEnter location of show to delete it: ";
					cin >> id;
					Finch.DeleteTVShow(id);
					break;
				case 13:
					cout << "\nEnter location of game to delete it: ";
					cin >> id;
					Finch.DeleteGame(id);
					break;
				case 14:
					cout << "\nEnter item to display surfers' responses on it: ";
					fflush(stdin);
					getline(cin,str);
					Finch.ShowComments(str);
					break;
				case 15:
					cout << "\nEnter item's name on which you want to delete someone's comment: ";
					fflush(stdin);
					getline(cin,str);
					cout << "\nEnter surfer's name: ";
					fflush(stdin);
					getline(cin, surfer);
					Finch.DeleteComment(surfer, str);

					comments.close();

					if (remove("Comments.txt") != 0)
						perror("Error deleting file");
					else
						puts("Insider operation, comments file deleted successfully");

					rename("newComments.txt", "Comments.txt");
					break;
				case 16:
					Finch.PostNews();
					break;
				case 17:
					cout << "Are you sure you want to wipe server clean? y/n" << endl;
					fflush(stdin);
					cin >> choice;
					if (choice == 'y')
					{
						cout << "Server wipes in " << endl;
						for (int sec = 5; sec >= 0; sec--)
						{
							Sleep(1000);
							cout << sec << " seconds" << endl;
						}
						Sleep(1000);
						comments.close();
						surfers.close();
						movies.close();
						tvshows.close();
						games.close();
						passwords.close();
						news.close();

						if (remove("Comments.txt") != 0)
							perror("Error deleting file");
						else
							puts("Comments file deleted successfully");

						if (remove("Surfers.dat") != 0)
							perror("Error deleting file");
						else
							puts("Surfers file deleted successfully");

						if (remove("Movies.dat") != 0)
							perror("Error deleting file");
						else
							puts("Movies file deleted successfully");

						if (remove("Games.dat") != 0)
							perror("Error deleting file");
						else
							puts("Games file deleted successfully");

						if (remove("TVShows.dat") != 0)
							perror("Error deleting file");
						else
							puts("TVShows file deleted successfully");
						
						if (remove("Passwords.txt") != 0)
							perror("Error deleting file");
						else
							puts("Passwords file deleted successfully");
						
						if (remove("News.txt") != 0)
							perror("Error deleting file");
						else
							puts("News file deleted successfully");

						system("shutdown");
					}
					
					break;
				case 18:
					Finch.SeeAllSurfers();
					break;
				case 0:
					Finch.setEminencetag(false);
					break;
				default:
					cout << "\nNo such directive exists!" << endl;
				}
				games.clear();
				tvshows.clear();
				movies.clear();
				surfers.clear();
			}while (choice_ad != 0);
		} 

		if (Reese.getVisitTag())
		{
			cout << "\nNews by Admin: " << endl;
			Reese.ReadNews();
			cout << "\nYour last activity: " << endl;
			Reese.ShowLastActivity(Reese.getName());
			cout << endl;

			do
			{
				choice_surf = SurferChoices();
				switch (choice_surf)
				{
				case 1:
					to_update = true;
					cout << "Enter name: ";
					fflush(stdin);
					getline(cin,str);
					fflush(stdin);
					Reese.setName(str);
					cout << "\nEnter favourite genre: ";
					fflush(stdin);
					getline(cin,str);
					Reese.setFav_genre(str);
					cout << "\nEnter your hobby: ";
					fflush(stdin);
					getline(cin,str);
					Reese.setHobby(str);
					cout << "\nEnter security question: ";
					fflush(stdin);
					getline(cin,str);
					Reese.setQuestion(str);
					while (surfers.read(reinterpret_cast<char*>(&blank),(sizeof(Surfer))))
					{
						if (blank.getName() == Reese.getName())
						{
							id = count;
							break;
						}
						count++;
					}
					Reese.SetProfile(Reese, id,to_update);
					break;
				case 2:
					cout << "\nEnter name of movie: ";
					fflush(stdin);
					getline(cin,str);
					Reese.SearchMoviebyName(str);
					break;
				case 3:
					cout << "\nEnter genre to display relevant movies: ";
					fflush(stdin);
					getline(cin,str);
					Reese.SearchMoviesbyGenre(str);
					break;
				case 4:
					cout << "\nEnter an item to add review on it: " << endl;
					fflush(stdin);
					getline(cin,str);
					Reese.AddReview(str);
					break;
				case 5:
					cout << "\nEnter name of show: ";
					fflush(stdin);
					getline(cin,str);
					Reese.SearchTVShowbyName(str);
					break;
				case 6:
					cout << "\nEnter genre to display relevant shows: ";
					fflush(stdin);
					getline(cin,str);
					Reese.SearchTVShowsbyGenre(str);
					break;
				case 7:
					cout << "\nEnter name of game: ";
					fflush(stdin);
					getline(cin,str);
					Reese.SearchGamebyName(str);
					break;
				case 8:
					cout << "\nEnter game mechanics to display relevant games(FPS etc.): ";
					fflush(stdin);
					getline(cin,str);
					Reese.SearchGamesbyGame_Mech(str);
					break;
				case 9:
					Reese.DeactivateAccount(Reese.getName());
					Reese.setName("");
					goto end;
					break;
				case 10:
					cout << "Your current profile: " << endl;
					Reese.ViewProfile(Reese.getName());
					break;
				case 0:
					Reese.setName("");
					Reese.setVisittag(false);
					break;
				default:
					cout << "No such directive exists" << endl;
				}
				games.clear();
				tvshows.clear();
				movies.clear();
				surfers.clear();
			} while (choice_surf != 0);
		}
	end:{}
	 } while (choice!='e');

	 comments.close();
	 surfers.close();
	 movies.close();
	 tvshows.close();
	 games.close();
	 passwords.close();
	 news.close();
	 return 0;
}


int SurferChoices()
{
	cout << "\nEnter your choice: " << endl
		<< "1- Reset profile"<<endl
		<< "2- Search a Movie in database by name" << endl
		<< "3- See all existing Movies in database by genre " << endl
		<< "4- Add a comment and rate a particular item" << endl
		<< "5- Search a TVShow in database by name " << endl
		<< "6- See all existing TVShows in database by genre " << endl
		<< "7- Search a Game in database by name " << endl
		<< "8- See all existing Games in database by game_mechanics" << endl
		<< "9- Deactivate account"<<endl
		<< "10-View Profile"<<endl
		<< "0- Sign out\n???_";
	int menuChoice;
	cin >> menuChoice; // input menu selection
	return menuChoice;
}
int AdminChoices()
{
	cout << "\nEnter your choice: " << endl
		<< "1- Add a Movie in database by name" << endl
		<< "2- Add a TVShow in database by name " << endl
		<< "3- Add a Game in database by name " << endl
		<< "4- See all existing TVShows in database " << endl
		<< "5- See all existing Games in database " << endl
		<< "6- See all existing Movies in database " << endl
		<< "7- Delete a Surfer " << endl
		<< "8- Update a Movie in database " << endl
		<< "9- Update a TVShow in database " << endl
		<< "10- Update a Game in database " << endl
		<< "11- Delete a Movie in database " << endl
		<< "12- Delete a TVShow in database " << endl
		<< "13- Delete a Game in database " << endl
		<< "14- Show all comments/ratings on an item: " << endl
		<< "15- Delete someone's response " << endl
		<< "16- Post news on site "<<endl
		<< "17- Wipe server and Shut it down"<<endl
		<< "18- See all current surfers with memory location"<<endl
		<< "0- Sign out\n???_";
	int menuChoice;
	cin >> menuChoice; // input menu selection 
	return menuChoice;
}
