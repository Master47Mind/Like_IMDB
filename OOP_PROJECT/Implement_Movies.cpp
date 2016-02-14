# include <string>
# include "Movies.h"
using namespace std;
Movies::Movies(string director, string cast, string name, string distributors, string country, string awards, double budget, string genre, double rating, int day, int month, int year) :Multimedia(genre,name, rating, day, month, year)
{
	setDirector(director);
	setCentral_Cast(cast);
	setDistributors(distributors);
	setCountry(country);
	setAwards(awards);
	setBudget(budget);
}
Movies::~Movies()
{
}
string Movies::getDirector()
{
	return string(Director);
}
string Movies::getCentral_Cast()
{
	return string(Central_Cast);
}
string Movies::getDistributors()
{
	return string(Distributors);
}
string Movies::getCountry()
{
	return string(Country);
}
string Movies::getAwards()
{
	return string(Awards);
}
double Movies:: getBudget()
{
	return Budget;
}
void Movies::setDirector(string director)
{
	size_t destination_size = sizeof (Director);
	strncpy_s(Director, str_obj.String_to_Array(director, 100, Director), destination_size);
	Director[destination_size - 1] = '\0';
}
void Movies::setCentral_Cast(string cast)
{
	size_t destination_size = sizeof (Central_Cast);
	strncpy_s(Central_Cast, str_obj.String_to_Array(cast, 100, Central_Cast), destination_size);
	Central_Cast[destination_size - 1] = '\0';
}
void Movies::setDistributors(string distributors)
{
	size_t destination_size = sizeof (Distributors);
	strncpy_s(Distributors, str_obj.String_to_Array(distributors, 100, Distributors), destination_size);
	Distributors[destination_size - 1] = '\0';
}
void Movies::setCountry(string country)
{
	size_t destination_size = sizeof (Country);
	strncpy_s(Country, str_obj.String_to_Array(country, 100, Country), destination_size);
	Country[destination_size - 1] = '\0';
}
void Movies::setAwards(string award)
{
	size_t destination_size = sizeof (Awards);
	strncpy_s(Awards, str_obj.String_to_Array(award, 100, Awards), destination_size);
	Awards[destination_size - 1] = '\0';
}
void Movies::setBudget(double budget)
{
	Budget = budget;
}
void Movies::Display()
{
	cout << "Director: " << getDirector() << endl;
	cout << "Starring: " << getCentral_Cast() << endl;
	cout << "Distributors: " << getDistributors() << endl;
	cout << "Country: " << getCountry() << endl;
	cout << "Awards won: " << getAwards() << endl;
	cout << "Budget in millions (US dollars): " << getBudget() << endl;
	release_date.Display_Date();
}
Movies::Movies()
{
	Budget = 0.0;
	for (int i = 0; i < 100; i++)
	{
		Director[i] = '\0';
		Country[i] = '\0';
		Central_Cast[i] = '\0'; 
		Distributors[i] = '\0'; 
		Awards[i] = '\0';
	}
}