/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

TemperatureData::TemperatureData() {
	this->id = "0";
	this->year = 0;
	this->month = 0;
	this->temperature = -99.99;
} 

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) {
	this->id = id;
	this->year = year;
	this->month = month;
	this->temperature = temperature;
}

TemperatureData::~TemperatureData() {

}

bool TemperatureData::operator<(const TemperatureData& b) {
	if (id.compare(b.id) < 0) {return true;} 
	else if (id > b.id) {return false;}
	
	if (year < b.year) {return true;} 
	else if (year > b.year) {return false;}
	
	if (month < b.month) {return true;}
	else if (month > b.month) {return false;}

	return false;
}

