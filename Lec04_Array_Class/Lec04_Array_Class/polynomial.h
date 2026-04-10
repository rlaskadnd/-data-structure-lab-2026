#pragma once
#include <cstdio>
#define MAX_DEGREE 80

class Polynomial {
	int degree;
	float coef[MAX_DEGREE];

public:
	//  수정1: 모든 계수를 0으로 초기화하여 쓰레기값을 제거한다.
	Polynomial() {
		degree = 0;
		for (int i = 0; i < MAX_DEGREE; i++) coef[i] = 0.0f;
	}

	void read() {
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf_s("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf_s("%f", &coef[i]);
	}

	void display(const char* str = " Poly = ") {
		printf("\n%s", str);
		for (int i = 0; i < degree; i++)
			printf("%5.1f x^%d +", coef[i], degree - i);
		printf("%5.1f\n", coef[degree]);
	}

	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				//지수 위치를 맞추는 계산
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}

	bool isZero() { return degree == 0; }

	void negate() {
		for (int i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}
};