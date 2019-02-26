// Alexander Peters
// LectureNotes 4.2
// 02/26/19

#include <iostream>
#include <cmath>

void ComputeTrig(const double degrees, double & cosOut,
				 double & sinOut. double & tanOut);

const double PI = acos(-1);

int main() {
	double cosValue, sinValue, tanValue;
	Computetrig(30, cosValue, sinValue, tanValue);
	cout << "cos(30) = " << cosValue
		 << ", sin(30) = " << sinValue
		 << ", tan(30) = " << tanValue
		 << '\n';

	return 0;
}

void ComputeTrig(const double degrees, double & cosOut
			     double & sinOut, double & tanOut) {
	const double radians = degrees * PI / 180;
	cosOut = cos(radians);
	sinOut = sin(radians);
	tanOut = tan(radians);
}
