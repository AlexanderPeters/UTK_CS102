// Alexander Peters
// 02/27/19
// Lab 6

// Imports and namespace
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

string getMonth(int month);
int main() {
	// Define given variables
	double interstate_mult = 5.2252;
	double highway_mult = 9.4412;
	double residential_mult = 17.1525;
	double noneOfTheAbove_mult = 12.152;

	// User input vars
	string input_file = "";
	string output_file = "";

	int start_month, start_day, start_year, 
		end_month, end_day, end_year;

	start_month = start_day = start_year
	= end_month = end_day = end_year = 0;

	// Begin user input
	cout << "Enter a ticket file: ";
	cin >> input_file;

	cout << "Enter a report file: ";
	cin >> output_file;
	
	input_file += ".txt";
	output_file += ".txt";

	cout << "Enter report start date (mm dd yyyy): ";
	cin >> start_month >> start_day >> start_year;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if(cin.fail() || start_month < 1 || start_month > 12 || 
	   start_day < 1 || start_day > 31 || start_year < 0
	   ||start_year > 9999) {
		cerr << "Invalid input";
		return 1;
	}

	cout << "Enter report end date   (mm dd yyyy): ";
	cin >> end_month >> end_day >> end_year;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if(cin.fail() || end_month < 1 || end_month > 12 || end_day < 1 
	   || end_day > 31 || end_year < 0 || end_year > 9999) {
		cerr << "Invalid input";
		return 1;
	}

	// Define input and ouput streams
	ifstream ifs(input_file);
	ofstream ofs(output_file);

	// Attempt to open the wanter input file
	if (!ifs) {
		cerr << "Unable to open: " << input_file;
		return 1;
	}
	
	// Define the vectors that will contain the line date
	// from the input file
	vector<string> ticket_numbers;
	vector<vector<int>> dates;
	vector<vector<int>> speeds;
	vector<char> road_types;

	// Fill vectors with line values
	string line = "";
	for(unsigned int i = 0; getline(ifs, line); ++i) {
		stringstream lineData(line);
		
		string ticketNumber = "";
		int month, day, year, clockedSpeed, speedLimit;
		month = day = year = clockedSpeed = speedLimit = 0;
		char roadType = ' ';

		lineData >> ticketNumber >> month >> day >> year >> clockedSpeed
			>> speedLimit >> roadType;
		
		ticket_numbers.push_back(ticketNumber);
		
		if(year < 100) year += 2000;

		vector<int> date;
		date.push_back(month);
		date.push_back(day);
		date.push_back(year);

		dates.push_back(date);

		vector<int> lineSpeeds;
		lineSpeeds.push_back(clockedSpeed);
		lineSpeeds.push_back(speedLimit);

		speeds.push_back(lineSpeeds);

		road_types.push_back(roadType);
	}
    
	// Find the wanted lines within the file
	// and store their indices in the wantedLines
	// vector.
	vector<int> wantedLines;
	for(unsigned int i = 0; i < dates.size(); ++i) {
		int month = dates.at(i).at(0);
		int day = dates.at(i).at(1);
		int year = dates.at(i).at(2);
		
		int currentDate = year * 10000 + month * 100 + day;
		int startDate = start_year * 10000 + start_month * 100 + start_day;
		int endDate = end_year * 10000 + end_month * 100 + end_day;

		if(currentDate >= startDate && currentDate <= endDate)
			wantedLines.push_back(i);
	}

	// Compute file output
	for(unsigned int i = 0; i < wantedLines.size(); ++i) {
		ofs << setfill('0') << setw(2) << dates.at(wantedLines.at(i)).at(1) << '-';
		ofs << setfill(' ') << getMonth(dates.at(wantedLines.at(i)).at(0)) << '-';
		ofs << dates.at(wantedLines.at(i)).at(2) << ' ';
		ofs << left << setw(10) <<  ticket_numbers.at(wantedLines.at(i)) << " $";

		double fine_mult = 0.0;
		switch(road_types.at(wantedLines.at(i))) {
			case 'i':
			case 'I':
				fine_mult = interstate_mult;
				break;
			case 'r':
			case 'R':
				fine_mult = residential_mult;
				break;
			case 'h':
			case 'H':
				fine_mult = highway_mult;
				break;				
			default:
				fine_mult = noneOfTheAbove_mult;
				break;
		}

		double fine = 0.0;
		int clockedSpeed = speeds.at(wantedLines.at(i)).at(0);
		int speedLimit = speeds.at(wantedLines.at(i)).at(1);
		fine = (clockedSpeed - speedLimit) * fine_mult;

		if(fine < 0.0) fine = 0.0;
		ofs << right << setw(9) << fixed << setprecision(2) << fine << '\n';
	}

	// Close file streams
	ifs.close();
	ofs.close();
	// Terminate program if run succesfully
	return 0;
}

string getMonth(int month) {
	const string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
							   "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
	return months[month - 1];
}

