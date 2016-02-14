#include "Admin.h"
#include "Movies.h"
#include "Games.h"
#include "TVShows.h"
#include "Surfer.h"
# include <string>
# include <windows.h>
using namespace std;
void Admin::setPassword(string pass)
{
	size_t destination_size = sizeof (Password);
	strncpy_s(Password, str_obj.String_to_Array(pass, 6, Password), destination_size);
	Password[destination_size - 1] = '\0';
}
string Admin::getPassword()
{
	return Password;
}
Admin::Admin(string name,string pass,bool tag,int size) :User(name)
{
	setEminencetag(tag);
	setFileSize(size);
	setPassword(pass);
}
Admin::~Admin()
{
}
void Admin::setEminencetag(bool tag)
{
	Eminence_tag = tag;
}
bool Admin::getEminenceTag()
{
	return Eminence_tag;
}
void Admin::AddMovie(Movies& m, int id)
{
	Movies empty;
	string Void;
	fstream to_handle("Movies.dat", ios_base::in | ios_base::out | ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(Movies));
	to_handle.read(reinterpret_cast<char*>(&empty), sizeof(Movies));
	Void = empty.getName();
	if (Void == "")
	{
		to_handle.seekp((id - 1)*sizeof(Movies));
		to_handle.write(reinterpret_cast<const char*>(&m), sizeof(Movies));
		cout << "Data has been written!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is not empty" << endl;
	}
	to_handle.close();
}
void Admin::AddTVShow(TVShows& tv, int id)
{
	TVShows empty;
	fstream to_handle("TVShows.dat", ios_base::in | ios_base::out | ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(TVShows));
	to_handle.read(reinterpret_cast<char*>(&empty), sizeof(TVShows));
	string Void = empty.getName();
	if (Void == "")
	{
		to_handle.seekp((id - 1)*sizeof(TVShows));
		to_handle.write(reinterpret_cast<const char*>(&tv), sizeof(TVShows));
		cout << "Data has been written!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is not empty" << endl;
	}
	to_handle.close();
}
void Admin::AddGame(Games& g, int id)
{
	Games empty;
	fstream to_handle("Games.dat", ios_base::in | ios_base::out | ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(Games));
	to_handle.read(reinterpret_cast<char*>(&empty), sizeof(Games));
	string Void = empty.getName();
	if (Void == "")
	{
		to_handle.seekp((id - 1)*sizeof(Games));
		to_handle.write(reinterpret_cast<const char*>(&g), sizeof(Games));
		cout << "Data has been written!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is not empty" << endl;
	}
	to_handle.close();
}
void Admin::UpdateMovie(Movies& m, int id)
{
	Movies empty;
	fstream to_handle("Movies.dat", ios_base::in | ios_base::out | ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(Movies));
	to_handle.read(reinterpret_cast<char*>(&empty), sizeof(Movies));
	string Void = empty.getName();
	if (Void != "")
	{
		to_handle.seekp((id - 1)*sizeof(Movies));
		to_handle.write(reinterpret_cast<const char*>(&m), sizeof(Movies));
		cout << "Update successfull!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is empty" << endl;
	}
	to_handle.seekp((id - 1)*sizeof(Movies));
	to_handle.write(reinterpret_cast<const char*>(&m), sizeof(Movies));
	to_handle.close();
}
void Admin::UpdateTVShow(TVShows& tv, int id)
{
	TVShows empty;
	fstream to_handle("TVShows.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(TVShows));
	to_handle.read(reinterpret_cast<char*>(&empty), sizeof(TVShows));
	string Void = empty.getName();
	if (Void != "")
	{
		to_handle.seekp((id - 1)*sizeof(TVShows));
		to_handle.write(reinterpret_cast<const char*>(&tv), sizeof(TVShows));
		cout << "Update successfull!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is empty" << endl;
	}
	to_handle.close();
}
void Admin::UpdateGame(Games&g, int id)
{
	Games empty;
	fstream to_handle("Games.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(Games));
	to_handle.read(reinterpret_cast<char*>(&empty), sizeof(Games));
	string Void = empty.getName();
	if (Void!= "")
	{
		to_handle.seekp((id - 1)*sizeof(Games));
		to_handle.write(reinterpret_cast<const char*>(&g), sizeof(Games));
		cout << "Update successfull!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is empty" << endl;
	}
	to_handle.close();
}
void Admin::DeleteSurfer(int id)
{
	bool check=false;
	string name="", pass="";
	Surfer empty,filled;
	fstream to_handle("Surfers.dat", ios_base::in | ios_base::out | ios::binary);
	fstream to_delete("Passwords.txt", ios_base::in | ios_base::out);
	fstream to_write("newPasswords.txt", ios_base::in |ios_base::out|ios::trunc);
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
	to_handle.seekg((id - 1)*sizeof(Surfer));
	to_handle.read(reinterpret_cast<char*>(&filled), sizeof(Surfer));
	string Void = filled.getName();
	if (Void!="")
	{
		to_handle.seekp((id - 1)*sizeof(Surfer));
		to_handle.write(reinterpret_cast<const char*>(&empty), sizeof(Surfer));
		cout << "Memory of Surfer " << filled.getName()<<" at block no.#" << id << " has been erased" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is already empty" << endl;
	}
	to_handle.close();

while (getline(to_delete, name, ':'))
{
		getline(to_delete, pass);

		if (filled.getName() == name)
		{
			cout << "Deleting " << filled.getName() << " 's credentials" << endl;
			check = true;
			continue;
		}
		else
		{
			to_write << name;
			to_write << ":";
			to_write << pass;
			to_write << "\n";
		}
}
	to_delete.close();
	to_write.close();

	if (check==false)
	{
		cout << "Credentials were not detected for this surfer" << endl;
	}
}
void Admin::DeleteComment(string name, string on_which_item)
{
	string line="",surfer_name="",item_name="",str="";
	size_t ilen = on_which_item.size();
	size_t nlen=name.size();
	size_t item_index = 0, name_index = 0;
	bool checkfound=false,checkstring=false;
	fstream to_handle("Comments.txt", ios_base::in | ios_base::out);
	fstream renew("newComments.txt", ios_base::in | ios_base::out|ios_base::trunc);
	if (!to_handle || !renew)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	while (getline(to_handle,line))
	{ 
		size_t found1 = line.find(on_which_item);
		size_t found2 = line.find(name);
		if (found1 != string::npos || found2 != string::npos)
			checkstring = true;
		
		if (checkstring)
		{
			item_index = line.find(on_which_item);
			item_name = line.substr(item_index, ilen);
			name_index = line.find(name);
			surfer_name = line.substr(name_index, nlen);
			if (item_name == on_which_item && surfer_name == name)
			{
				cout << "Target found! Executing your directive!" << endl;
				line.replace(line.find(line), line.length(), "");
				checkfound = true;
				continue;
			}
			else
			{
				renew << line;
				renew << "\n";
			}
		}
	}
	to_handle.close();
	renew.close();

	if (checkfound == false)
	{
		cout << "Requested person's comment was not found on given item " << endl;
	}
}
void Admin::DeleteMovie(int id)
{
	Movies empty, filled;
	fstream to_handle("Movies.dat",ios::in|ios::out|ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(Movies));
	to_handle.read(reinterpret_cast<char*>(&filled), sizeof(Movies));
	string Void = filled.getName();
	if (Void!= "")
	{
		to_handle.seekp((id - 1)*sizeof(Movies));
		to_handle.write(reinterpret_cast<const char*>(&empty), sizeof(Movies));
		cout << "Targeted item "<<filled.getName()<<" at place " << id << " has been deleted!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is already empty" << endl;
	}
	to_handle.close();
}
void Admin::DeleteTVShow(int id)
{
	TVShows empty,filled;
	fstream to_handle("TVShows.dat", ios_base::in|ios_base::out|ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(TVShows));
	to_handle.read(reinterpret_cast<char*>(&filled), sizeof(TVShows));
	string Void = filled.getName();
	if (Void != "")
	{
		to_handle.seekp((id - 1)*sizeof(TVShows));
		to_handle.write(reinterpret_cast<const char*>(&empty), sizeof(TVShows));
		cout << "Targeted item "<<filled.getName()<<" at place " << id << " has been deleted!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is already empty" << endl;
	}
	to_handle.close();
}
void Admin::DeleteGame(int id)
{
	Games empty,filled;
	fstream to_handle("Games.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_handle.is_open())
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg((id - 1)*sizeof(Games));
	to_handle.read(reinterpret_cast<char*>(&filled), sizeof(Games));
	string Void = filled.getName();
	if (Void!="")
	{
		to_handle.seekp((id - 1)*sizeof(Games));
		to_handle.write(reinterpret_cast<const char*>(&empty), sizeof(Games));
		cout << "Targeted item "<<filled.getName()<<" at place " << id << " has been deleted!" << endl;
	}
	else
	{
		cout << "Block no.#" << id << " is already empty" << endl;
	}
	to_handle.close();
}
void Admin::ShowComments(string m)
{
	bool checkfound = false, checkstring = false;
	string line="";
	fstream to_handle("Comments.txt", ios_base::in | ios_base::out);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	size_t found = 0;
	while (getline(to_handle,line))
	{
		found = line.find(m);
		if (found != string::npos)
			checkstring = true;

		if (checkstring)
		{
			checkfound = true;
			cout <<line << endl;
		}
	}
	to_handle.close();
	if (checkfound == false)
	{
		cout << "Comments on this item were not found!" << endl;
	}
}
void Admin::Display()
{}
void Admin::SeeAllMovies()
{
	Movies blank; int c = 1;
	string Void;
	fstream to_handle("Movies.dat",ios::in|ios::out|ios::binary);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg(0, ios::beg);
	while (to_handle.read(reinterpret_cast<char*>(&blank), sizeof(Movies)))
	{
		Void = blank.getName();
		if (Void != "")
		{
			cout << blank;
			blank.Display();
			cout << "at ID: " << c << endl;
		}
		c++;
	}
	to_handle.close();
}
void Admin::SeeAllTVShows()
{
	TVShows blank; int c = 1;
	string Void;
	fstream to_handle("TVShows.dat", ios_base::in | ios_base::out|ios::binary);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg(0, ios::beg);
	while (to_handle.read(reinterpret_cast<char*>(&blank), sizeof(TVShows)))
	{
		Void = blank.getName();
		if (Void!= "")
		{
			cout << blank;
			blank.Display();
			cout << "at ID: " << c << endl;
		}
		c++;
	}
	to_handle.close();
}
void Admin::SeeAllGames()
{
	Games blank; int c = 1;
	string Void;
	fstream to_handle("Games.dat", ios_base::in|ios_base::out|ios::binary);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	to_handle.seekg(0, ios::beg);
	while (to_handle.read(reinterpret_cast<char*>(&blank), sizeof(Games)))
	{
		Void = blank.getName();
		if (Void!= "")
		{
			cout << blank;
			blank.Display();
			cout << "at ID: " << c << endl;
		}
		c++;
	}
	to_handle.close();
}
void Admin::setFileSize(int size)
{
	filesize = size;
}
int Admin::getFileSize() const
{
	return filesize;
}
void Admin::PostNews()
{
	string news="";
	fstream to_handle("News.txt", ios_base::out|ios_base::in);
	if (!to_handle)
	{
		cout << "Could not open file, press any key to exit:" << endl;
		fflush(stdin);
		getchar();
		exit(1);
	}
	cout << "Enter news to post for surfers: " << endl;
	fflush(stdin);
	getline(cin,news);
	to_handle<<news; // write out the line
	to_handle << "\n";
	to_handle.close();
}
void Admin::SeeAllSurfers()
{
	Surfer blank; int count = 1; bool check = false;
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
		if (blank.getName() != "")
		{
			cout << blank.getName() << " at block no.# " << count << endl;
			check = true;
		}
		count++;
	}

	if (check == false)
	{
		cout << "None exist yet!" << endl;
	}
	to_handle.close();
}