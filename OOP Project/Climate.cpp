#include <iostream>

#include "Climate.h"

using namespace std;

Climate::Climate() {

	rainfall = 0.0;

	snowfall = 0.0;

	wind = 0.0;

	temperature = 0.0;

	clouds = 0.0;

	humidity = 0.0;

}

Climate::Climate(double a, double b, double c, double d, double e, double f) {

	rainfall = a;

	snowfall = b;

	wind = c;

	temperature = d;

	clouds = e;

	humidity = f;

}