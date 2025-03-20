int add(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}
float add(float a, float b) {
	return a + b;
}
double add(double a, double b) {
	return a + b;
}
void main() {
	int r1 = add(1, 2);
	float r2 = add(1.0f, 2.0f);
	double r3 = add(1.0, 2.0);
}