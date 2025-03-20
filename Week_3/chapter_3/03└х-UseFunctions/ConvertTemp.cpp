double Celcius2Fahrenheit(double cels) {
	double fahr = 32 + 180.0 / 100.0 * cels;
	return fahr;
}
double Fahrenheit2Celcius(double fahr) {
	double	cels = 100.0 / 180.0 * (fahr - 32);
	return	cels;
}