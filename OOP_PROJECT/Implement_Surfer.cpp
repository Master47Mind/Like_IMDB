# include "Surfer.h"
# include <iostream>
# include <string>
# include <fstream>
using namespace std;
Surfer::Surfer()
{
	for (int i = 0; i < 100; i++)
	{
		Hobby[i] = '\0';
		Fav_genre[i] = '\0';
		Security_Quest[i] = '\0';
	}
}
Surfer::Surfer(string fav_genre, string hobby, string name,string quest,bool tag) :User(name)
{
	setFav_genre(fav_genre);
	setHobby(hobby);
	setVisittag(tag);
	setQuestion(quest);
}
Surfer::~Surfer()
{
}
void Surfer::Display()
{
	cout << "Favourite Genre: " << getFav_genre() << endl;
	cout << "Hobby: " << getHobby() << endl;
}
void Surfer::setVisittag(bool tag)
{
	Visit_tag = tag;
}
bool Surfer::getVisitTag()
{
	return Visit_tag;
}
void Surfer::setFav_genre(string fav_genre)
{
	size_t destination_size = sizeof (Fav_genre);
	strncpy_s(Fav_genre, str_obj.String_to_Array(fav_genre, 100, Fav_genre), destination_size);
	Fav_genre[destination_size - 1] = '\0';
}
void Surfer::setHobby(string hobby)
{
	size_t destination_size = sizeof (Hobby);
	strncpy_s(Hobby, str_obj.String_to_Array(hobby, 100, Hobby), destination_size);
	Hobby[destination_size - 1] = '\0';
}
string Surfer::getFav_genre()
{
	return string(Fav_genre);
}
string Surfer::getHobby()
{
	return string(Hobby);
}
void Surfer::SearchMoviebyName(string name)
{
	bool check = false;
	Movies empty;
	string Void;
	fstream to_read("Movies.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_read.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_read.seekg(0);
	while (to_read.read(reinterpret_cast<char*>(&empty), sizeof(Movies)))
	{
	 Void = empty.getName();
		if (Void == name)
		{
			cout <<"Results found: \n";
			cout << empty;
			empty.Display();
			check = true;
		}
	}
	if (check == false)
	{
		cout << "This item has no information yet" << endl;
	}
	to_read.close();
}
void Surfer::SearchMoviesbyGenre(string genre)
{
	bool check = false; string Void;
	Movies empty;
	fstream to_read("Movies.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_read.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_read.seekg(0);
	while (to_read.read(reinterpret_cast<char*>(&empty), sizeof(Movies)))
	{
		Void = empty.getGenre();
		if (Void == genre)
		{
			cout << "Results found: \n";
			cout << empty;
			empty.Display();
			check = true;
		}
	}
	if (check == false)
	{
		cout << "Item of this genre does not exist yet!" << endl;
	}
	to_read.close();

}
void Surfer::SearchTVShowbyName(string name)
{
	bool check = false; string Void;
	TVShows empty;
	fstream to_read("TVShows.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_read.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_read.seekg(0);
	while (to_read.read(reinterpret_cast<char*>(&empty), sizeof(TVShows)))
	{
		Void = empty.getName();
		if (Void == name)
		{
			cout << "Results found: \n";
			cout << empty;
			empty.Display();
			check = true;
		}
	}
     if (check == false)
	{
		cout << "This item has no information yet" << endl;
	}
	to_read.close();
}
void Surfer::SearchTVShowsbyGenre(string genre)
{
	bool check = false;
	string Void;
	TVShows empty;
	fstream to_read("TVShows.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_read.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_read.seekg(0);
	while (to_read.read(reinterpret_cast<char*>(&empty), sizeof(TVShows)))
	{
		Void = empty.getGenre();
		if (Void == genre)
		{
			cout << "Results found: \n";
			cout << empty;
			empty.Display();
			check = true;
		}
	}
	if (check == false)
	{
		cout << "Item of this genre does not exist yet!" << endl;
	}
	to_read.close();
}
void Surfer::SearchGamebyName(string name)
{
	bool check = false;
	Games empty;
	string Void;
	fstream to_read("Games.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_read.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_read.seekg(0);
	while (to_read.read(reinterpret_cast<char*>(&empty), sizeof(Games)))
	{
		Void = empty.getName();
		if (Void== name)
		{
			cout << "Results found: \n";
			cout << empty;
			empty.Display();
			check = true;
		}
	}
	if (check == false)
	{
		cout << "This item has no information yet" << endl;
	}
	to_read.close();
}
void Surfer::SearchGamesbyGame_Mech(string mech)
{
	bool check = false;
	Games empty;
	string Void;
	fstream to_read("Games.dat", ios_base::in | ios_base::out|ios_base::binary);
	if (!to_read.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_read.seekg(0);
	while (to_read.read(reinterpret_cast<char*>(&empty), sizeof(Games)))
	{
		Void = empty.getGame_Mechanics();
		if (Void == mech)
		{
			cout << "Results found: \n";
			cout << empty;
			empty.Display();
			check = true;
		}
	}
	if (check == false)
	{
		cout << "Game of this mechanism does not exist yet!" << endl;
	}
	to_read.close();
}
void Surfer::AddReview(string item)
{
	string comment; 
	double rating;
	fstream to_read("Comments.txt", ios_base::in | ios_base::out);
	if (!to_read.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	cout << "Enter comment: " << endl;
	fflush(stdin);
	getline(cin, comment);
	cout << "Enter your rating(decimals allowed): " << endl;
	cin >> rating;

	to_read << item << ";";
	to_read << this->Name;
	to_read << ":";
	to_read << comment;
	to_read << "/";
	to_read << rating;
	to_read << "\n";
}
void Surfer::SetProfile(Surfer &s, int id,bool to_update)
{
	Surfer empty; int count = 1;
	string Void,pass;
	fstream to_read("Surfers.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_read)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_read.seekg((id-1)*sizeof(Surfer));
	to_read.read(reinterpret_cast<char*>(&empty),sizeof(Surfer));
	Void = empty.getName();
	if (Void == "" || to_update==true)
	{
		to_read.seekp((id - 1) * sizeof(Surfer));
		to_read.write(reinterpret_cast<const char*>(&s), sizeof(Surfer));
		cout << "\nSet your 5 characters long password: ";
		fflush(stdin);
		getline(cin, pass);
		s.setPassword(s.getName(), pass);
	}
	else 
	{
		to_read.seekg(0, ios::beg);
		while (to_read.read(reinterpret_cast<char*>(&empty), sizeof(Surfer)))
		{
			Void = empty.getName();
			 if (Void == "")
			 {
				 cout << "It's occupied. Available ID is: " << count << endl;
				 break;
			 }
			 count++;
		}
    }
}
bool validateSurferfromFile( string s,string n)
{
	bool var = false;
	string password = "";
    string name = "";
	fstream to_handle("Passwords.txt", ios_base::in | ios_base::out);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	while (getline(to_handle,name,':'))
	{
		getline(to_handle, password);
		{
			if (password == s && name == n)
			{
				var = true;
				break;
			}
		}
	}
	return var;
}
void Surfer::ReadNews()
{
	string reading;
	fstream to_handle("News.txt", ios::app | ios::in);
	while (getline(to_handle, reading))
	{
		cout << reading << endl;
	}
	to_handle.close();
}
void Surfer::setPassword(string name,string pass)
{
	fstream to_handle("Passwords.txt", ios_base::out | ios_base::in);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle << name;
	to_handle << ':';
	to_handle << pass;
	to_handle << '\n';
	to_handle.close();
}
void Surfer::ShowLastActivity(string m)
{
	bool checkstring = false;
	size_t found = 0, len = m.size();
	bool check = false;
	string  name="",line="";
	fstream to_handle("Comments.txt", ios_base::in | ios_base::out);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	while (getline(to_handle, line))
	{
		found = line.find(m);

		if (found != string::npos)
			checkstring = true;

		if (checkstring)
		{
			name= line.substr(found,len);
			if (name == m)
			{
				cout << line << endl;
				check = true;
			}
		}
	}
	if (check == false)
		cout << "No previous activity" << endl;
	to_handle.close();
}
void Surfer::setQuestion(string quest)
{
	size_t destination_size = sizeof (Security_Quest);
	strncpy_s(Security_Quest, str_obj.String_to_Array(quest, 100, Security_Quest), destination_size);
	Security_Quest[destination_size - 1] = '\0';
}
string Surfer::getQuestion()
{
	return string(Security_Quest);
}
void Surfer::ForgotPassword(string name, string q)
{
	Surfer blank; bool check = false;
	string Void, pass, surfer_name;
	fstream to_handle("Surfers.dat", ios_base::in | ios_base::out | ios::binary);
	fstream read("Passwords.txt", ios_base::in | ios_base::out);
	if (!read)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg(0, ios::beg);
	while (to_handle.read(reinterpret_cast<char*>(&blank), sizeof(Surfer)))
	{
		Void = blank.getName();
		if (Void == name && blank.getQuestion() == q)
		{
			check = true;
			while (getline(read, surfer_name, ':'))
			{
				getline(read, pass);
				if (surfer_name == name)
				{
					cout << "\nYour password is: ";
					cout << pass[0] << "***" << pass[4];
					cout << "Guess the middle characters" << endl;
				}
			}
		}
		if (check == false)
			cout << "Either you entered wrong question or you don't exist in Surfer's database;sorry for inconvenience" << endl;
		to_handle.close();
		read.close();
	}
}
void Surfer::DeactivateAccount(string name)
{
	bool check = false,checkstring=false;
	size_t len = name.size(),found=0;
	string line="", Void=""; 
	int counter = 1;
	Surfer empty, filled;
	fstream to_handle("Surfers.dat", ios_base::in | ios_base::out | ios::binary);
	fstream to_delete("Passwords.txt", ios_base::in | ios_base::out);
	fstream to_write("newPasswords.txt", ios_base::in | ios_base::out | ios::trunc);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	if (!to_delete)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	if (!to_write)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg(0,ios::beg);
	while (to_handle.read(reinterpret_cast<char*>(&filled), sizeof(Surfer)))
	{
		Void = filled.getName();
		if (Void == name)
		{
			to_handle.seekp((counter - 1)*sizeof(Surfer));
			to_handle.write(reinterpret_cast<const char*>(&empty), sizeof(Surfer));
			cout << "Memory of Surfer " << filled.getName() << " at block no.#" << counter << " has been erased" << endl;
		}
		counter++;
	}
	to_handle.close();

	while (getline(to_delete,line))
	{
		found = line.find(name);

		if (found != string::npos)
			checkstring = true;

		if (checkstring)
		{
			if (name==filled.getName())
			{
				cout << "Deleting " << filled.getName() << " 's credentials" << endl;
				line.replace(line.find(line), line.length(), "");
				check = true;
				continue;
			}
		}
		else
		{
			to_write << line;
			to_write << "\n";
		}
	}
	to_delete.close();
	to_write.close();
}
void Surfer::ViewProfile(string n)
{
        Surfer blank;
		fstream to_handle("Surfers.dat", ios_base::out | ios_base::in);
		if (!to_handle)
		{
			cout << "Could not open file, press any key to exit:" << endl;
			fflush(stdin);
			getchar();
			exit(1);
		}
		to_handle.seekg(0, ios::beg);
		while (to_handle.read(reinterpret_cast<char*>(&blank), sizeof(Surfer)))
		{
			if (blank.getName() == n)
			{
				cout << blank << endl;
			}
		}
		to_handle.close();
}