#pragma once
#include <cstdio>
#include <cstring>

class Car {
protected:
	int speed;        //속도 (private)
	char name[40];    // 이름((private)
public:
	int gear;
	Car() {}
	~Car() {}
	Car(int s, char* n, int g)
		: speed(s), gear(g) {
		strcpy(name, n);
	}
	void changeGear(int g = 4) {
		gear = g;
	}
	void speedUp() {
		speed += 5;
	}
	void display() {
		printf("[%s] : 기어=%d단 속도=%dkmph\n", name, gear, speed);
	}
	void whereAmI() { printf("객체 주소= %X\n", this); }
};
