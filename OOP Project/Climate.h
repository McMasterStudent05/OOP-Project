#pragma once

class Climate {

protected:

	double rainfall;

	double snowfall;

	double wind;

	double temperature;

	double clouds;

	double humidity;

public:

	Climate();

	Climate(double, double, double, double, double, double);

	double getRainFall() { return rainfall; }

	double getSnowFall() { return snowfall; }

	double getWind() { return wind; }

	double getTemp() { return temperature; }

	double getClouds() { return clouds; }

	double getHumidity() { return humidity; }

};