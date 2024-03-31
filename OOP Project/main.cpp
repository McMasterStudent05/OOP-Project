#include <iostream> //main.cpp and print functions: eb
using namespace std;

int main()
{
#include <iostream>
	using namespace std;

	string* climate;
	bool isOceania = false;

	void PrintCountries(int x) { //used for printing out the u.i telling the user to select the listed countries.

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

	string NorthAmericanCountry(int c, string & climate, string s) { //categorizing northamerican countries and returning country values depending on groups of countries
		string country;
		PrintCountries(c);
		cin >> country;

		if (country == "Siberia" || country == "Artic") {
			return country;
			climate = "Polar";
			Polar obj1;
		}
		else if (country == "Canada" || country == "USA" || country == "NorthernEurope" || country == "Chile" || country == "SouthernAfrica" || country == "NewZealand") {
			return country;
			climate = "Temperate";
		}
		else if (country == "Mexico" || country == "Argentina" || country == "NorthernAfrica" || country == "Australia") {
			return country;
			climate = "SubTropical";
		}
		else if (country == "CentralAmerica" || country == "Brazil" || country == "CentralAfrica" || country == "PacificIslands") {
			return country;
			climate = "Tropical";
			Tropical obj1(s);
		}
		else if (country == "Ecuador" || country == "EquatorialAfrica" || country == "Indonesia") {
			return country;
			climate = "Equatorial";
		}
	}

	string findSeason(int m) { //Finding and returning the current season
		if (m <= 2 || m > 11) {
			return "Winter";
		}
		else if (m > 2 || m <= 5) {
			return "Spring";
		}
		else if (m > 5 || m <= 8) {
			return "Summer";
		}
		else if (m > 8 || m <= 11) {
			return "Fall";
		}
		//need a statement for invalid month option
	}


	class Climate { //used for determining the climate
	protected:
		double rainfall;
		double wind;
		double temperature;
		double clouds;
		double humidity;
		string season;
		bool reverse;
	public:
		Climate(double rainfall, double wind, double temperature, double clouds, double humidity, bool reverse);

		void virtual Print() = 0;
	};

	Climate::Climate() {
		rainfall = 0.0;
		wind = 0.0;
		temperature = 0.0;
		clouds = 0.0;
		humidity = 0.0;
		reverse = false;
	}

	class Tropical : public Climate { //tropical: a type of climate
	public:
		Tropical(string y);
		void Print();
	};

	Tropical::Tropical(string y) {
		season = y;
		rainfall =
			wind =
			temperature =
			clouds =
			humidity =
			reverse = isOceania;
	}

	class Polar : public Climate { //another type of climate
	public:
		Tropical(string x);
		void Print();
	};

	Polar::Polar(string y) {
		season = y;
		rainfall =
			wind =
			temperature =
			clouds =
			humidity =
			reverse = isOceania;
	}


	class Location { //used for finding the location and relevant weather
		int continent;
		string country;
	public:
		Location() { continent = 0; }
		void setContinent(int a) { continent = a; }
		void setCountry(string c) { country = c; }
		int getContinent() { return continent; }

	};




	void WeekForecast() {
		cout << "Forecast";
	}

	int main() { //the actual main function

		bool a = true;
		int contChoice = 0;
		int month;
		int day;

		Location obj;

		string x = *climate;

		{
			cout << "Enter Month (1-12)" << endl; //more u.i stuff
			cin >> month;
			cout << "Enter Day (1-31)" << endl;
			cin >> day;

			string season = findSeason(month); //u.i find season

			cout << "Enter Location" << endl << " 1-North America" << endl;
			cin >> contChoice;
			obj.setContinent(contChoice);

			int y = obj.getContinent();
			string country = NorthAmericanCountry(y, *climate, season);
			obj.setCountry(country);



		} while (a)




		{
			cout << "Enter option:" << endl << "1: 7 Day Forecast" << endl << "2: Hourly Forecast" << endl; //u.i stuff for forecasts
			cin >> choice;

			if (choice == 1) {
				WeekForecast();
			}


		}while (a)


	}

}