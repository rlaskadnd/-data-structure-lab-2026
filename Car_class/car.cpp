#define _CRT_SECURE_NO_WARNINGS
#include "SportsCar.h"
#include <cstdio>

int main() {
	// 1. 일반 자동차 테스트
	printf("--- Car Test ---\n");
	Car myCar(0, (char*)"Avante", 1); //이름과 속도 초기화
	myCar.display();

	myCar.speedUp();
	myCar.changeGear(2);
	myCar.display();
	myCar.whereAmI();
	printf("\n");

	//2. 스포츠카 테스트
	printf("--- SportsCar Test ---Wn");
	SportsCar myScar; // 위에서 만든 생성자가 호출되어 쓰레기 값이 사라진다

	myScar.setTurbo(false);
	printf("[Turbo OFF]\n");
	myScar.speedUp();
	myScar.display();

	myScar.setTurbo(true);
	printf("[Turbo ON]\n");
	myScar.speedUp();
	myScar.display();
	myScar.whereAmI();

	return 0;
}