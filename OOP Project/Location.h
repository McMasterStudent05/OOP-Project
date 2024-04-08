#pragma once
#include <iostream>

#include <string>

using namespace std;

class Location {

private:

	int continent;

	string country;

public:

	Location();

	void setContinent(int a) { continent = a; }

	void setCountry(string c) { country = c; }

	int getContinent() { return continent; }

	string getCountry() { return country; }

};