# include "TVShows.h"
# include <string>
using namespace std;
TVShows::TVShows(string distributors,string awards, string creator, string cast, string name, string location, string channel, double viewers, string genre, double rating, int day, int month, int year) :Multimedia(genre,name, rating, day, month, year)
{
	setViewers(viewers);
	setDistributors(distributors);
	setCreator(creator); 
	setCentral_Cast(cast);
	setLocation(location);
	setChannel(channel);
	setAwards(awards);
}
TVShows::TVShows()
{
	viewers_in_millions = 0.0;
	for (int i = 0; i < 100; i++)
	{
		Distributors[i] = '\0';
		Awards[i] = '\0';
		Creator[i] = '\0';
		Central_Cast[i] = '\0';
		Location[i] = '\0';
		Channel[i] = '\0';
	}
}
TVShows::~TVShows()
{
}
void TVShows:: setViewers(double viewers)
{
	viewers_in_millions= viewers;
}
void TVShows:: setDistributors(string distributors)
{
	size_t destination_size = sizeof (Distributors);
	strncpy_s(Distributors, str_obj.String_to_Array(distributors, 100, Distributors), destination_size);
	Distributors[destination_size - 1] = '\0';
}
void TVShows::setCreator(string creator)
{
	size_t destination_size = sizeof (Creator);
	strncpy_s(Creator, str_obj.String_to_Array(creator, 100, Creator), destination_size);
	Creator[destination_size - 1] = '\0';
}
void TVShows::setCentral_Cast(string cast)
{
	size_t destination_size = sizeof (Central_Cast);
	strncpy_s(Central_Cast, str_obj.String_to_Array(cast, 100, Central_Cast), destination_size);
	Central_Cast[destination_size - 1] = '\0';
}
void TVShows::setLocation(string location)
{
	size_t destination_size = sizeof (Location);
	strncpy_s(Location, str_obj.String_to_Array(location, 100, Location), destination_size);
	Location[destination_size - 1] = '\0';
}
void TVShows::setChannel(string channel)
{
	size_t destination_size = sizeof (Channel);
	strncpy_s(Channel, str_obj.String_to_Array(channel, 100, Channel), destination_size);
	Channel[destination_size - 1] = '\0';
}
double TVShows:: getViewers()
{
	return viewers_in_millions;
}
string TVShows::getDistributors()
{
	return string(Distributors);
}
string TVShows::getCreator()
{
	return string(Creator);
}
string TVShows::getCentral_Cast()
{
	return string(Central_Cast);
}
string TVShows::getChannel()
{
	return string(Channel);
}
string TVShows::getLocation()
{
	return string(Location);
}
void TVShows:: Display()
{
	cout << "Distributors: " << Distributors << endl;
	cout << "Creator or Executive Producer: " << Creator << endl;
	cout << "Central_Cast: " << Central_Cast << endl;
	cout<< "Location: "<< Location<<endl;
	cout << "Channel: " << Channel << endl;
	cout << "Viewers in millions: " << viewers_in_millions << endl;
	cout << "Original on_air date: ";
	release_date.Display_Date();
}
void TVShows::setAwards(string award)
{
	size_t destination_size = sizeof (Awards);
	strncpy_s(Awards, str_obj.String_to_Array(award, 100, Awards), destination_size);
	Awards[destination_size - 1] = '\0';
}
string TVShows::getAwards()
{
	return string(Awards);
}