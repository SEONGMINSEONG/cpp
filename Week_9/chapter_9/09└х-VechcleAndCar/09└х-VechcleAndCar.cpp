#include <cstdio>

class Vehicle {
	int	serial;
protected:
	int	speed;
public:
	int	price;
	Vehicle(int s = 0) : serial(s), speed(0), price(0) { }
	void speedUp() { speed++; }
	void speedDown() { speed--; }
	void print() {
		printf("[Vehicle] serial=%d, speed=%d, price=%d\n",
			serial, speed, price);
	}
};

class Car : public Vehicle {
	int	gear;
public:
	Car(int g = 0) : gear(g) {}
	void pushAccel() { speed += 5; }
	void pushBrake() { speedDown(); }
	void setGear(int g) { gear = g; }
	void printCarInfo(char* msg = "car") {
		printf("%s", msg);
		//printf(" serial=%d", serial);
		printf(" speed=%d,", speed);
		printf(" gear=%d,", gear);
		printf(" price=%d\n", price);
	}
};

void main() {
	Car myCar(2), yourCar(3);

	// myCar.serial = 20170118;
	// yourCar.speed = 20;
	myCar.pushAccel();
	myCar.price = 3000;
	yourCar.price = 2500;

	myCar.print();
	yourCar.print();

	myCar.printCarInfo("[My  Car]");
	yourCar.printCarInfo("[YourCar]");
}