#include "parallel_tracks.h"

using std::cin;
using std::cout;
using std::endl;

//-------------------------------------------------------
// Name: is_valid_number
// PreCondition:  a string that needs to be checked as a valid competition
// number (non-negative int)
// PostCondition: returns TRUE if string is only made up of numeric chars 0-9
//---------------------------------------------------------
bool is_valid_number(const std::string &str)
{
	if (str.size() == 0)
	{
		return false;
	}

	for (unsigned int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			continue;
		default:
			return false;
		}
	}

	return true;
}

//-------------------------------------------------------
// Name: is_valid_time
// PreCondition:  a string that needs to be checked as a valid maxTime
// (non-negative float)
// PostCondition: returns TRUE if string is only made up of numeric chars
// 0-9 or '.'
//---------------------------------------------------------
bool is_valid_time(const std::string &str)
{
	int period = 0;

	if (str.size() == 0)
	{
		return false;
	}

	if (str.size() == 1)
	{
		if (str[0] == '.')
		{
			return false;
		}
	}

	for (unsigned int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			continue;
		case '.':
			if (period < 1)
			{
				period++;
				//cout << "Period: " << period << endl;
				continue;
			}
			else
			{
				//cout << "Too many periods" << endl;
				return false;
			}
		default:
			return false;
		}
	}

	return true;
}

//-------------------------------------------------------
// Name: is_valid_country
// PreCondition:  a string that needs to be checked as a valid country (std::string)
// PostCondition: returns TRUE if string is made of exactly 3 capital chars A-Z
//---------------------------------------------------------
bool is_valid_country(const std::string &str)
{

	if (str.size() != 3)
	{
		return false;
	}

	for (unsigned int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			continue;
		default:
			return false;
		}
	}

	return true;
}

//-------------------------------------------------------
// Name: is_valid_name
// PreCondition:  a string that needs to be checked as a valid name (std::string)
// PostCondition: returns TRUE if string is made of letters A-Z, a-z, and ' '
//---------------------------------------------------------
bool is_valid_name(const std::string &str)
{

	if (str.size() == 0)
	{
		return false;
	}

	for (unsigned int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':

		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
		case ' ':
			continue;
		default:
			return false;
		}
	}

	return true;
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void get_runner_data(const std::string &file, float *timeArray, std::string *countryArray,
					 unsigned int *numberArray, std::string *lastnameArray)
{
	if (file.size() < 4 || file.substr(file.length() - 4, 4) != ".csv")
		throw std::invalid_argument("File not CSV file");
	// using syntax from iostreams notes (examples)

	std::ifstream infile;

	infile.open(file);

	if (!infile.is_open())
	{
		throw std::invalid_argument("Cannot open file");
	}

	// all data abot to be read in from the CSV file
	std::string line;	 // reading the line from the file
	float maxTime;		 // float version of maxTime
	std::string strTime; // string version of maxTime
	std::string country;
	std::string strNumber; // string version of number
	unsigned int number;
	std::string lname;

	int i = 0; // index that values are bout to be placed

	// get whole line to be broken up later
	while (getline(infile, line))
	{
		// convert line to istringstream in order to break it up
		std::istringstream sin(line);

		// get data, piece by piece using the , as the delimiter
		// if data missing, throw exception
		if (!getline(sin, strTime, ','))
			throw std::invalid_argument("File missing data");
		// if strTime is not a valid (non-negative) float, throw exception
		if (!is_valid_time(strTime))
			throw std::invalid_argument("File contains invalid data (time)"); //Customize to maxTime?
		// THEN convert to FLOAT (since not a string)
		maxTime = std::stof(strTime);

		// if data missing, throw exception
		if (!getline(sin, country, ','))
			throw std::invalid_argument("File missing data");
		// if country is not a valid country name (3 uppercase char), throw exception
		if (!is_valid_country(country))
			throw std::invalid_argument("File contains invalid data (country)");

		// if data missing, throw exception
		if (!getline(sin, strNumber, ','))
			throw std::invalid_argument("File missing data");
		// if strNumber is not a valid (non-negative) int, throw exception
		if (!is_valid_number(strNumber))
			throw std::invalid_argument("File contains invalid data (number)"); // Customize to number?
		// THEN convert to FLOAT (since not a string)
		number = std::stoi(strNumber); // this is NOT perfect!! there is a long int version, but...

		// last line does not have a ,
		// if data missing, throw exception
		if (!getline(sin, lname))
			throw std::invalid_argument("File missing data");
		// if lname is not a valid name (alphabet chars and ' '), throw exception
		if (!is_valid_name(lname))
			throw std::invalid_argument("File contains invalid data (name)");

		// assign values to arrays
		timeArray[i] = maxTime;
		countryArray[i] = country;
		numberArray[i] = number;
		lastnameArray[i] = lname;
		i++; // increment to fill next index in the parallel arrays
	}

	infile.close();
}

//-------------------------------------------------------
// Name: prep_float_array
// PreCondition:  a float arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_float_array(float *ary)
// making sure all values within the array are set to 0.0;
{
	for (int i = 0; i < 9; i++)
	{
		ary[i] = 0.0;
	}
}

//-------------------------------------------------------
// Name: prep_float_array
// PreCondition:  a float arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int *ary)
// making sure all values within the array are set to 0;
{
	for (int i = 0; i < 9; i++)
	{
		ary[i] = 0;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string *ary)
// making sure all values within the array are set to "N/A";
{
	for (int i = 0; i < 9; i++)
	{
		ary[i] = "N/A";
	}
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the maxTime array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const float *timeArray, unsigned int *rankArray)
{
	float maxTime = 0.0;
	int maxIndex = 0;
	int done[] = {0,0,0,0,0,0,0,0,0};
	int rankCounter = 1;

	for (unsigned int j = 0; j < 9; j++)
	{

		for (unsigned int i = 0; i < 9; i++)
		{	
			
			if (timeArray[i] > maxTime)
			{
				if (done[i] == 0) {
					maxTime = timeArray[i];
					maxIndex = i;
				}
			}
			//cout << "TimeArray[" << i << "] = " << timeArray[i] << endl;
			//cout << "doneArray[" << i << "] = " << done[i] << endl;
			//cout << "maxTime: " << maxTime << endl << endl;

		}
		maxTime = 0;
		//cout << "J: " << j << endl;

		if (done[maxIndex] == 0) {
			
			//cout << "MAX_INDEX = " << maxIndex << endl;
			rankArray[maxIndex] = 10 - rankCounter;
			rankCounter++;
			//cout << "RANK: " << rankArray[maxIndex] << endl;
			done[maxIndex] = 1;
			//cout << "TIME: " << timeArray[maxIndex] << endl << endl;
			//cout << "--------------------------------" << endl << endl << endl << endl;
		}
		
	}

	//cout << "--------------------------------" << endl << endl << endl << endl;

	for (int i = 0; i < 9; i++)
	{
		//cout << rankArray[i] << endl;
	}
	

}

//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very ineffiect nested loop to determine the ranks
// it then displays then along with a delta in maxTime from the start
//---------------------------------------------------------
void print_results(const float *timeArray, const std::string *countryArray,
				   const std::string *lastnameArray, const unsigned int *rankArray)
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	float best_time = 0.0f;

	// print the results, based of rank, but measure the maxTime difference_type
	for (unsigned int j = 1; j <= SIZE; j++)
	{

		// go thru each array, find who places in "i" spot
		for (unsigned int i = 0; i < SIZE; i++)
		{
			if (rankArray[i] == 1) // has to be a better way, but need the starting maxTime
			{
				best_time = timeArray[i];
			}

			if (rankArray[i] == j) // then display this person's data
			{
				// this needs percision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t"
						  << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl;
			}
		}
	}
}
