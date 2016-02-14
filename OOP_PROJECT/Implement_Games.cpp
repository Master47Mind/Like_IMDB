# include "Games.h"
# include "TVShows.h"
# include "Movies.h"
# include <string>
using namespace std;

Games::Games()
{
	for (int i = 0; i < 100; i++)
	{
		Publisher[i] = '\0';
		Platform[i] = '\0';
		Game_mechanics[i] = '\0';
		Developers[i] = '\0';
		Distribution[i] = '\0';
	}
}
Games::Games(string publisher, string platform,string name, string mech, string developers, string distribution,string genre , double rating,int day,int month,int year) :Multimedia(genre,name,rating,day,month,year)
{
	setPublisher(publisher);
	setPlatform(platform);
	setGame_Mechanics(mech);
	setDevelopers(developers);
	setDistribution(distribution);
}
Games::~Games()
{
}
void Games::setPublisher(string pub)
{
	 size_t destination_size = sizeof (Publisher);
	 strncpy_s(Publisher, str_obj.String_to_Array(pub, 100, Publisher) , destination_size);
	 Publisher[destination_size - 1] = '\0';
}

void Games::setPlatform(string plat)
{    
	size_t destination_size = sizeof (Platform);
	strncpy_s(Publisher, str_obj.String_to_Array(plat, 100, Platform), destination_size);
	Platform[destination_size - 1] = '\0';
}
void Games::setGame_Mechanics(string mech)
{
	size_t destination_size = sizeof (Game_mechanics);
	strncpy_s(Game_mechanics, str_obj.String_to_Array(mech, 100, Game_mechanics), destination_size);
	Game_mechanics[destination_size - 1] = '\0';
}
void Games::setDevelopers(string devel)
{
	size_t destination_size = sizeof (Developers);
	strncpy_s(Developers, str_obj.String_to_Array(devel, 100, Developers), destination_size);
	Developers[destination_size - 1] = '\0';
}
void Games::setDistribution(string distr)
{
	size_t destination_size = sizeof (Distribution);
	strncpy_s(Distribution, str_obj.String_to_Array(distr, 100, Distribution), destination_size);
	Distribution[destination_size - 1] = '\0';
}
string Games::getPublisher()
{
	return string(Publisher);
}
string Games::getPlatform()
{
	return string(Platform);
}
string Games::getGame_Mechanics()
{
	return string(Game_mechanics);
}
string Games::getDevelopers()
{
	return string(Developers);
}
string Games::getDistribution()
{
	return string(Distribution);
}
void Games::Display()
{
	cout << "Publishers: " << getPublisher() << endl;
	cout << "Developers: " << getDevelopers() << endl;
	cout << "Platform: " << getPlatform() << endl;
	cout << "Game Mechanics: " << getGame_Mechanics() << endl;
	cout << "Distribution: " << getDistribution() << endl;
	release_date.Display_Date();
}

