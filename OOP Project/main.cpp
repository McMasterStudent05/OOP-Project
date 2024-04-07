#include <iostream>
#include <fstream>
using namespace std;

string* climate;
bool isOceania = false;

void PrintCountries(int x) {

	if (x == 1) {
		cout << "Enter Country (Canada, USA, Mexico, CentralAmerica, Artic)" << endl;
	}
	else if (x == 2) {
		cout << "Enter Country (Brazil, Argentina, Chile, Equador)" << endl;
	}
	else if (x == 3) {
		cout << "Enter Region (NorthernEurope, Mediterranian, Siberia)" << endl;
	}
	else if (x == 4) {
		cout << "Enter Region (NorthEastAsia, SouthAsia, MiddleEast)" << endl;
	}
	else if (x == 5) {
		cout << "Enter Region (NorthAfrica, CentralAfrica, EquatorialAfrica, SouthernAfrica)" << endl;
	}
	else if (x == 6) {
		cout << "Enter Region (Australia, NewZealand, PacificIslands, Indonesia)" << endl;
		isOceania = true;
	}
}

string NorthAmericanCountry(int c, string& climate, string s) {
	string country;
	PrintCountries(c);
	cin >> country;

	if (country == "Siberia" || country == "Artic") {
		return country;
		climate = "Polar";
	}
	else if (country == "Canada" || country == "USA" || country == "NorthernEurope" || country == "Chile" || country == "SouthernAfrica" || country == "NewZealand" || country == "NorthEastAsia") {
		return country;
		climate = "Temperate";
	}
	else if (country == "Mexico" || country == "Argentina" || country == "NorthAfrica" || country == "Australia" || country == "MiddleEast" || country == "Mediterranian") {
		return country;
		climate = "SubTropical";
	}
	else if (country == "CentralAmerica" || country == "Brazil" || country == "CentralAfrica" || country == "PacificIslands" || country == "SouthAsia") {
		return country;
		climate = "Tropical";
	}
	else if (country == "Ecuador" || country == "EquatorialAfrica" || country == "Indonesia") {
		return country;
		climate = "Equatorial";
	}
}

string findSeason(int m) {
	if (m <= 2 || m > 11) {
		return "Winter";
	}
	else if (m > 2 && m <= 5) {
		return "Spring";
	}
	else if (m > 5 && m <= 8) {
		return "Summer";
	}
	else if (m > 8 && m <= 11) {
		return "Fall";
	}
	//need a statement for invalid month option
}

class Climate {
protected:
	double rainfall;
	double snowfall;
	double wind;
	double temperature;
	double clouds;
	double humidity;
	bool reverse;
public:
	Climate();
	Climate(double, double, double, double, double, double);

	void Print();
};

Climate::Climate() {
	rainfall = 0.0;
	snowfall = 0.0;
	wind = 0.0;
	temperature = 0.0;
	clouds = 0.0;
	humidity = 0.0;
	reverse = false;
}

Climate::Climate(double a, double b, double c, double d, double e, double f) {
	rainfall = a;
	snowfall = b;
	wind = c;
	temperature = d;
	clouds = e;
	humidity = f;
	reverse = false;
}

class Location {
private:
	int continent;
	string country;
public:
	Location();
	void setContinent(int a) { continent = a; }
	void setCountry(string c) { country = c; }
	int getContinent() { return continent; }

};

Location::Location() {
	continent = 0;
}

void WeekForecast() {
	cout << "Forecast";
}

Climate createObj(string SeasonType, string ClimateType) {

	fstream readfile;
	double Array[6][5];

	if (!readfile.is_open()) {
		cout << "File cant be read" << endl;

		Climate empty;
		return empty;
	}

	else if (readfile.is_open()) {


		if (SeasonType == "Winter") {

			readfile.open("Winter.txt");
		}
		else if (SeasonType == "Fall") {

			readfile.open("Fall.txt");
		}

		int a = 0, b = 0;

		while (readfile >> Array[a][b]) {

			if (a == 5) {
				b++;
				a = 0;
			}

			a++;
		}

		double Array2[6];
		for (int c = 0; c < 5; c++) {
			if (ClimateType == "Polar") {
				Array2[c] = Array[0][c];
			}
			else if (ClimateType == "Temperate") {
				Array2[c] = Array[1][c];
			}



		}

		Climate Obj(Array2[0], Array2[1], Array2[2], Array2[3], Array2[4], Array2[5]);
		return Obj;
	}
}

int main() {

	bool a = true;
	int contChoice = 0;
	int month;
	int day;
	int choice;

	Location obj;

	string climate;


	cout << "Enter Month (1-12)" << endl;
	cin >> month;
	cout << "Enter Day (1-31)" << endl;
	cin >> day;

	string season = findSeason(month);

	cout << "Enter Location" << endl << " 1-North America" << endl;
	cin >> contChoice;
	obj.setContinent(contChoice);

	int y = obj.getContinent();
	string country = NorthAmericanCountry(y, climate, season);
	obj.setCountry(country);

	Climate obj1 = createObj(season, climate);



	cout << endl << endl;

	cout << "Enter option:" << endl << "1: 7 Day Forecast" << endl << "2: Hourly Forecast" << endl;
	cin >> choice;

	if (choice == 1) {
		WeekForecast();
	}





}