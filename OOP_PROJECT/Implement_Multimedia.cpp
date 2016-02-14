# include "Multimedia.h"
# include <iostream>
# include <string>
using namespace std;

Multimedia::Multimedia()
{
	Rating = 0.0;
	for (int i = 0; i < 100; i++)
	{
		Genre[i] = '\0';
		Name[i] = '\0';
	}
	
}
Multimedia::Multimedia(string genre, string name, double rating, int day, int month, int year) :release_date(day,month,year)
{
	setGenre(genre);
	setName(name);
	setRating (rating);
}
ostream& operator<< (ostream& cout, Multimedia& media)
{
	cout << "Name: " << media.getName() << endl;
	cout << "Genre :" << media.getGenre() << endl;
	cout << "Rating :" << media.getRating() << endl;
	//media.Display();
	return cout;
}
Multimedia::~Multimedia()
{
}
void Multimedia::setGenre(string genre)
{
	size_t destination_size = sizeof (Genre);
	strncpy_s(Genre, str_obj.String_to_Array(genre, 100, Genre), destination_size);
	Genre[destination_size - 1] = '\0';
}
void Multimedia::setRating(double rating)
{
	Rating = rating;
}
string Multimedia::getGenre()
{
	return string(Genre);
}
double Multimedia::getRating()
{
	return Rating;
}
void Multimedia::setName(string name)
{
	size_t destination_size = sizeof (Name);
	strncpy_s(Name, str_obj.String_to_Array(name, 100,Name), destination_size);
	Name[destination_size - 1] = '\0';
}
string Multimedia::getName()
{
	return string(Name);
}
void Multimedia::setDate(int dy, int mo, int yr)
{
	release_date.setDay(dy);
	release_date.setMonth(mo);
	release_date.setYear(yr);
}
