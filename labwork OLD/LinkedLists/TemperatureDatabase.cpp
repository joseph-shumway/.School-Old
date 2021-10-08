#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1

	ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Error: Unable to open " << filename << endl;
    }

	string currentline = "";
	stringstream ss;

	string tempId;
	int tempYear;
	double tempMonth;
	double tempTemperature;

	while (getline(ifs, currentline)) {
		//cout << endl << "INPUT: " << currentline << endl;
		ss.clear();
		ss.str(currentline);
		ss >> tempId;
		ss >> tempYear;
		ss >> tempMonth;
		ss >> tempTemperature;

		//cout << "ID: " << tempId << endl;
		//cout << "Year: " << tempYear << endl;
		//cout << "Month: " << tempMonth << endl;
		//cout << "Temperature: " << tempTemperature << endl;

		if (tempYear > 2021 || tempYear < 1800) {
			cout << "Error: Invalid year " << tempYear << endl;
		}

		int test = tempMonth;
		if (test != tempMonth || tempMonth == -3333 || tempYear == -3333 || tempId == "" || tempTemperature == -3333) {
			cout << "Error: Other invalid input" << endl;
		}

		if (tempMonth > 12 || tempMonth < 1) {
			cout << "Error: Invalid month " << tempMonth << endl;
		}

		if ((tempTemperature < -50 && tempTemperature != -99.99) || tempTemperature > 50.0) {
			cout << "Error: Invalid temperature " << tempTemperature << endl;
		}

		records.insert(tempId, tempYear, tempMonth, tempTemperature);

		tempId = "";
		tempYear = -3333;
		tempMonth = -3333;
		tempTemperature = -3333;
	}

	//cout << records.print();


}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1

	ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Error: Unable to open " << filename << endl;
    }

	string currentline = "";
	stringstream ss;

	string tempId;
	string function;
	int year1;
	int year2;
	double temperature;

	while (getline(ifs, currentline)) {
		tempId = "-3333";
		function = "-3333";
		year1 = -3333;
		year2 = -3333;
		temperature = -3333;
		
		ss.clear();
		ss.str(currentline);

		ss >> tempId;
		ss >> function;
		ss >> year1;
		ss >> year2;
		ss >> temperature;

		Node* current = records.getHead();

		while (current->data.id != tempId) {
			current = current->next;
		}

		// now we have the first occurence of ID in the list assigned to current

		// takes the average
		double total = 0;
		int counter = 0;
		if (function.at(0) == 'A') {
			while (current->data.id == tempId) {
				total += current->data.temperature;
				counter++;

				current = current->next;
			}
			double average = total / counter;
			ofstream dataout("result.dat");
	
			if (!dataout.is_open()) {
				cout << "Error: Unable to open " << filename << endl;
				exit(1);
			}
			dataout << records.print();
		}

	}

}
