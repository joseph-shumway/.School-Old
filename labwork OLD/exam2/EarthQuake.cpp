/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc 
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>       /* fabs */
#include <limits>

#include "EarthQuake.h"

using namespace std;

// QuakeDataSegment constructors
/* TODO */
QuakeDataSegment::QuakeDataSegment() 
{
	this -> waveAmplitude = 0;
	this -> latitude = 0;
	this -> longitude = 0;
	this -> depth = 0;
}

/* TODO */
QuakeDataSegment::QuakeDataSegment(double wa, double lat, double longi, double dep) 
{
	this -> waveAmplitude = wa;
	this -> latitude = lat;
	this -> longitude = longi;
	this -> depth = dep;
}

// overloaded output operator for QuakeDataSegment
ostream &operator<< (ostream &os, const QuakeDataSegment &x) //remember x is an alias
{
	os << "waveAmplitude: " <<  x.getWaveAmplitude() << endl;
	os << "latitude: " <<  x.getLatitude() << endl;
	os << "longitude: " <<  x.getLongitude() << endl;
	os << "depth: " <<  x.getDepth() << endl;
	return os;
}

static unsigned int arraySize = 0;

// EarthQuake constructor
EarthQuake::EarthQuake() :
	lengthOfQuake(0), 
	// this is used so you don't have to pass the size
	maxAmplitude(numeric_limits<double>::max()),
	minAmplitude(numeric_limits<double>::min()),

	sWaveIndex(0),

	localGpsLatitude(30.6), localGpsLongitude(-96.3),
	// College Station TX coordinates

	earthquakeGpsLatitude(0.0),  // - if South 
	earthquakeGpsLongitude(0.0), // - if West
	  
	distanceFromQuake(0),
		
	movedLatLong(false),
	movedDepth(false)
{}

// getters
int EarthQuake::getLengthOfQuake() const { return lengthOfQuake;	}
double EarthQuake::getMaxAmplitude() const { return maxAmplitude; }
double EarthQuake::getMinAmplitude() const { return minAmplitude; }
unsigned int EarthQuake::getSWaveIndex() const { return sWaveIndex; }
string EarthQuake::getEarthquakeLocation() const
{ return to_string(earthquakeGpsLongitude) + " " + to_string(earthquakeGpsLatitude); }
bool EarthQuake::getChangeInLatLong() const { return movedLatLong; }
bool EarthQuake::getChangeInDepth() const { return movedDepth; }
unsigned int EarthQuake::getDistanceFromQuake() const { return distanceFromQuake; }

void EarthQuake::setDistanceFromQuake()
{
	int R = 6371; // radius = 6371 kilometers
	double x = earthquakeGpsLatitude * M_PI/180; // in radians
	double y = localGpsLatitude * M_PI/180;
	double deltaX = (localGpsLongitude -earthquakeGpsLongitude) * M_PI/180;
	double deltaY = (localGpsLatitude -earthquakeGpsLatitude) * M_PI/180;

	double a = sin(deltaY/2) * sin(deltaY/2) +
			  cos(x) * cos(y) *
			  sin(deltaX/2) * sin(deltaX/2);
	distanceFromQuake = (2 * R * atan2(sqrt(a), sqrt(1-a))); // in meters
}

void EarthQuake::displayDataSegment(QuakeDataSegment * dS) const
{
	for (unsigned int i = 0; i < lengthOfQuake; i++)
	{
		// using overloaded QuakeDataSegment
		cout << "******************" << endl;
		cout << "at second " << (i + 1) << endl;
		cout << dS[i] << endl;
	}
}

// functions for setting and loading data
void EarthQuake::loadEarthquakeData(QuakeDataSegment*& dataSegment, string file)
{
	ifstream ifs(file);
	string line = "";
	double value = 0;


	if (file.substr(file.size() - 4, 4) != ".txt") {
		throw std::invalid_argument("Error: File is not a text file");
	}

	if (!ifs.is_open()) {
        throw std::invalid_argument("Error: Unable to open file");
    }

	std::stringstream ss;

	// init the first element of the array
	lengthOfQuake++;
	getline(ifs, line);
	ss.str(line);
	ss >> value;
	dataSegment[0].setWaveAmplitude(value);
	ss >> value;
	dataSegment[0].setLatitude(value);
	ss >> value;
	dataSegment[0].setLongitude(value);
	ss >> value;
	dataSegment[0].setDepth(value);
	ss.clear();





	int counter = 1;
	// get each line
	while (getline(ifs, line))
	{
		if (line.size() == 1) {
			continue;
		}
		// resize array to +1 each time to fit new data
		resizeArray(dataSegment);

		// create string stream to break up each line
		ss.str(line);

		// set each value from line
		ss >> value;
		dataSegment[counter].setWaveAmplitude(value);
		ss >> value;
		dataSegment[counter].setLatitude(value);
		ss >> value;
		dataSegment[counter].setLongitude(value);
		ss >> value;
		dataSegment[counter].setDepth(value);

		ss.clear();
		counter++;
	}

	ifs.close();

}
	


void EarthQuake::resizeArray(QuakeDataSegment*& segarr)
{	
	QuakeDataSegment* temp = new QuakeDataSegment[lengthOfQuake + 1];	
	
	for (int i = 0; i < lengthOfQuake; i++)
	{
		temp[i] = segarr[i];
	}

	delete[] segarr;
	segarr = temp;

	lengthOfQuake++;
}


void EarthQuake::setMaxAmplitude(QuakeDataSegment* segarr)
{	
	double maxAmp = 0;
	for (int i = 0; i < lengthOfQuake; i++)
	{
		if (segarr[i].getWaveAmplitude() > maxAmp) {
			maxAmp = segarr[i].getWaveAmplitude();
		}
	}

	this -> maxAmplitude = maxAmp;
	

}

void EarthQuake::setMinAmplitude(QuakeDataSegment* segarr)
{
	double minAmp = 200;
	for (int i = 0; i < lengthOfQuake; i++)
	{
		if (segarr[i].getWaveAmplitude() < minAmp) {
			minAmp = segarr[i].getWaveAmplitude();
		}
	}

	this -> minAmplitude = minAmp;
}

void EarthQuake::setSWaveIndex(QuakeDataSegment* segarr)
{
	unsigned int maxTime = 1;
	double maxAmp = 0;
	for (int i = 1; i < lengthOfQuake; i++)
	{
		if (segarr[i].getWaveAmplitude() > maxAmp) {
			if (segarr[i].getWaveAmplitude() >= 4 * segarr[i - 1].getWaveAmplitude()) {
				maxAmp = segarr[i].getWaveAmplitude();
				maxTime = i;
			}
			
		}
	}
	
	this -> sWaveIndex = maxTime + 1;
}

void EarthQuake::setEarthquakeLocation(QuakeDataSegment* segarr) 
{
	this -> earthquakeGpsLatitude = segarr[0].getLatitude();
	this -> earthquakeGpsLongitude = segarr[0].getLongitude();
}

void EarthQuake::setChangeInLatLong(QuakeDataSegment* segarr)
{
	double longitude = segarr[0].getLongitude();
	double latitude = segarr[0].getLatitude();

	for (int i = 0; i < lengthOfQuake; i++)
	{
		if (segarr[i].getLongitude() != longitude) {
			this -> movedLatLong = true;
		}

		if (segarr[i].getLatitude() != latitude) {
			this -> movedLatLong = true;
		}
	}
}

void EarthQuake::setChangeInDepth(QuakeDataSegment* segarr)
{
	double depth = segarr[0].getDepth();
	for (int i = 0; i < lengthOfQuake; i++)
	{
		if (segarr[i].getDepth() != depth) {
			this -> movedDepth = true;
		}
	}

}

ostream &operator << (ostream &os, const EarthQuake &x)
{
	os << "Max amp: " << x.getMaxAmplitude() << endl;
	os << "Min amp: " << x.getMinAmplitude() << endl;
	os << "Length of Quake: " << x.getLengthOfQuake() << endl;
	os << "S wave arrival (in seconds): " << x.getSWaveIndex() << endl;
	os << "Location of Quake: " << x.getEarthquakeLocation() << endl;
	os << "Distance from Quake: " << x.getDistanceFromQuake() << "km " << endl;
	os << "Did quake lat/long move? (0/1): " << x.getChangeInLatLong() << endl;
	os << "Did quake depth move? (0/1): " << x.getChangeInDepth() << endl;
	return os;
}
