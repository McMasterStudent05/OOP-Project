#include <iostream>

#include <string>

#include <fstream>

#include "Climate.h"

#include "Location.h"

using namespace std;

string climate;

bool isOceania = false;

void PrintCountries(int x) {

	if (x == 1) {

		cout << "Enter Country (Canada, USA, Mexico, CentralAmerica, Arctic)" << endl;

	}

	else if (x == 2) {

		cout << "Enter Country (Brazil, Argentina, Chile, Equador)" << endl;

	}

	else if (x == 3) {

		cout << "Enter Region (NorthernEurope, Mediterranean, Siberia)" << endl;

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

string NorthAmericanCountry(int c, string* climate) {

	string country;

	int x = 0;

	do {

		PrintCountries(c);

		cin >> country;

		if (country == "Siberia" || country == "Arctic") {

			*climate = "Polar";

			x = 1;

		}

		else if (country == "Canada" || country == "USA" || country == "NorthernEurope" || country == "Chile" || country == "SouthernAfrica" || country == "NewZealand" || country == "NorthEastAsia") {

			*climate = "Temperate";

			x = 1;

		}

		else if (country == "Mexico" || country == "Argentina" || country == "NorthAfrica" || country == "Australia" || country == "MiddleEast" || country == "Mediterranean") {

			*climate = "SubTropical";

			x = 1;

		}

		else if (country == "CentralAmerica" || country == "Brazil" || country == "CentralAfrica" || country == "PacificIslands" || country == "SouthAsia") {

			*climate = "Tropical";

			x = 1;

		}

		else if (country == "Ecuador" || country == "EquatorialAfrica" || country == "Indonesia") {

			*climate = "Equatorial";

			x = 1;

		}

		if (x == 0)
		{
			cout << "---Enter a valid option!---" << endl;
		}

	} while (x == 0);

	return country;

}

string findSeason(int m) {

	if (m <= 2 || m > 11) {

		if (isOceania) {

			return "Summer";

		}

		else {

			return "Winter";

		}

	}

	else if (m > 2 && m <= 5) {

		if (isOceania) {

			return "Fall";

		}

		else {

			return "Spring";

		}

	}

	else if (m > 5 && m <= 8) {

		if (isOceania) {

			return "Winter";

		}

		else {

			return "Summer";

		}

	}

	else {

		if (isOceania) {

			return "Spring";

		}

		else {

			return "Fall";

		}

	}

}

Climate createObj(string SeasonType, string ClimateType) {

	fstream readfile;

	double Array[6][5];

	if (SeasonType == "Winter") {

		readfile.open("Winter.txt");

	}

	else if (SeasonType == "Fall") {

		readfile.open("Fall.txt");

	}

	else if (SeasonType == "Summer") {

		readfile.open("Summer.txt");

	}

	else if (SeasonType == "Spring") {

		readfile.open("Spring.txt");

	}

	if (!readfile.is_open()) {

		cout << "File can't be read" << endl;

		Climate empty;

		return empty;

	}

	// Read data from file into Array

	for (int y = 0; y < 5; ++y) {

		for (int x = 0; x < 6; ++x) {

			readfile >> Array[x][y];

		}

	}

	readfile.close();

	double Array2[6];

	for (int c = 0; c < 6; c++) {

		if (ClimateType == "Polar") {

			Array2[c] = Array[c][0];

		}

		else if (ClimateType == "Temperate") {

			Array2[c] = Array[c][1];

		}

		else if (ClimateType == "SubTropical") {

			Array2[c] = Array[c][2];

		}

		else if (ClimateType == "Tropical") {

			Array2[c] = Array[c][3];

		}

		else if (ClimateType == "Equatorial") {

			Array2[c] = Array[c][4];

		}

	}

	Climate Obj(Array2[0], Array2[1], Array2[2], Array2[3], Array2[4], Array2[5]);

	return Obj;

}

struct DailyWeather {

	double rain;

	double temperature;

	double clouds;

	double humidity;

	double snowfall;

};

void printForecast(DailyWeather) {

	DailyWeather forecast[7];

	cout << "7-Day Weather Forecast:" << endl;

	cout << "Day\tRain(mm)\tTemperature\tClouds\tHumidity\tSnowfall" << endl;

	for (int i = 0; i < 7; ++i) {

		cout << i + 1 << "\t" << forecast[i].rain << "\t" << forecast[i].temperature << "\t\t"

			<< forecast[i].clouds << "\t" << forecast[i].humidity << "\t\t" << forecast[i].snowfall << endl;

	}

}

void generateWeeklyForecast(Climate today) {

	cout << "7-Day Weather Forecast:" << endl;

	cout << "Day\tRain\tSnow\tWind\tTemperature\tClouds\tHumidity" << endl;

	for (int i = 0; i < 7; ++i) {

		// Adjustments for each parameter

		double rainAdjustment = rand() % 20 - 10; // Random adjustment between -10 to +10 for rain

		double snowAdjustment = rand() % 5 - 2; // Random adjustment between -2 to +2 for snow

		double windAdjustment = rand() % 30 - 15; // Random adjustment between -15 to +15 for wind

		double tempAdjustment = rand() % 5 - 2; // Random adjustment between -2 to +2 for temperature

		double cloudsAdjustment = rand() % 20 - 10; // Random adjustment between -10 to +10 for clouds

		double humidityAdjustment = rand() % 20 - 10; // Random adjustment between -10 to +10 for humidity

		cout << i + 1 << "\t" << today.getRainFall() + rainAdjustment << "\t" << today.getSnowFall() + snowAdjustment << "\t"

			<< today.getWind() + windAdjustment << "\t" << today.getTemp() + tempAdjustment << "\t\t"

			<< today.getClouds() + cloudsAdjustment << "\t" << today.getHumidity() + humidityAdjustment << endl;

	}

}

void generateHourlyForecast(Climate today) {

	cout << "Hourly Weather Forecast:" << endl;

	cout << "Hour\tRain\tSnow\tWind\tTemperature\tClouds\tHumidity" << endl;

	for (int i = 0; i < 8; ++i) {

		// Adjustments for each parameter

		double rainAdjustment = rand() % (10 - 5);

		double snowAdjustment = rand() % (5 - 0);

		double windAdjustment = rand() % (10 - 3);

		double tempAdjustment = rand() % (5 - 2);

		double cloudsAdjustment = rand() % (15 - 10);

		double humidityAdjustment = rand() % (7 - 10);

		cout << i + 1 << "\t" << today.getRainFall() - rainAdjustment << "\t" << today.getSnowFall() - snowAdjustment << "\t"

			<< today.getWind() - windAdjustment << "\t" << today.getTemp() - tempAdjustment << "\t\t"

			<< today.getClouds() - cloudsAdjustment << "\t" << today.getHumidity() - humidityAdjustment << endl;

	}

	for (int i = 8; i < 20; ++i) {

		double rainAdjustment = rand() % (10 - 5);

		double snowAdjustment = rand() % (5 - 0);

		double windAdjustment = rand() % (10 - 3);

		double tempAdjustment = rand() % (5 - 2);

		double cloudsAdjustment = rand() % (15 - 10);

		double humidityAdjustment = rand() % (7 - 10);

		cout << i + 1 << "\t" << today.getRainFall() + rainAdjustment << "\t" << today.getSnowFall() + snowAdjustment << "\t"

			<< today.getWind() + windAdjustment << "\t" << today.getTemp() + tempAdjustment << "\t\t"

			<< today.getClouds() + cloudsAdjustment << "\t" << today.getHumidity() + humidityAdjustment << endl;

	}

	for (int i = 20; i < 24; ++i) {

		double rainAdjustment = rand() % (10 - 5);

		double snowAdjustment = rand() % (5 - 0);

		double windAdjustment = rand() % (10 - 3);

		double tempAdjustment = rand() % (5 - 2);

		double cloudsAdjustment = rand() % (15 - 10);

		double humidityAdjustment = rand() % (7 - 10);

		cout << i + 1 << "\t" << today.getRainFall() - rainAdjustment << "\t" << today.getSnowFall() - snowAdjustment << "\t"

			<< today.getWind() - windAdjustment << "\t" << today.getTemp() - tempAdjustment << "\t\t"

			<< today.getClouds() - cloudsAdjustment << "\t" << today.getHumidity() - humidityAdjustment << endl;

	}

}

string getMonth(int a) {

	switch (a) {

	case 1: return "January";

	case 2: return "February";

	case 3: return "March";

	case 4: return "April";

	case 5: return "May";

	case 6: return "June";

	case 7: return "July";

	case 8: return "August";

	case 9: return "September";

	case 10: return "October";

	case 11: return "November";

	case 12: return "December";

	}

}

int main() {

	bool a = true;

	int contChoice = 0;

	int month;

	int day;

	int choice;

	Location obj;

	Climate temp;

	string climates;

	int g = 0;

	do {

		cout << "Enter Month (1-12)" << endl;

		cin >> month;

		cout << "Enter Day (1-31)" << endl;

		cin >> day;

		if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {

			g = 1;

		}

		else {

			cout << "Invalid Month or Day Option" << endl;

		}

	} while (g == 0);

	string season = findSeason(month);

	do {

		cout << "Enter Location" << endl << " 1-North America, 2-South America, 3-Europe, 4-Asia, 5-Africa, 6-Oceania" << endl;

		cin >> contChoice;

		if (contChoice <= 0 || contChoice >= 7) {

			cout << "Enter a valid option (1-6)" << endl;

		}

	} while (contChoice <= 0 || contChoice >= 7);

	obj.setContinent(contChoice);

	int y = obj.getContinent();

	string country = NorthAmericanCountry(y, &climates);

	obj.setCountry(country);

	Climate obj1 = createObj(season, climates);

	cout << endl;

	int h = 0;

	cout << "Displaying Weather Forecast for: " << obj.getCountry() << " - " << getMonth(month) << " " << day << endl;

	do {

		cout << endl << "Enter option:" << endl << "1: 7 Day Forecast" << endl << "2: Hourly Forecast" << endl << "3: End Program" << endl;

		cin >> choice;

		if (choice == 1) {

			generateWeeklyForecast(obj1);

		}

		else if (choice == 2) {

			generateHourlyForecast(obj1);

		}

		else if (choice == 3) {

			h = 1;

		}

	} while (h == 0);

}