#include <cstdio>

#define HEIGHT 8
#define WIDTH 8

//예제 코드1 1차원 배열 최댓값 구하기
//매개 변수로 배열의 길이 전달
int findMaxValue(int a[], int len) {
	int max_val = a[0];
	for (int i = 1; i < len; i++) {
		if (a[i] > max_val) {
			max_val = a[i];
		}
	}
	return max_val;
}

// 예제 코드2 2차원 이미지 최대 화소 밝기 구하기
int findMaxPixel(int a[][WIDTH], int h, int w) {
	int max_val = a[0][0];

	//글로벌 상수가 아닌 매개변수로 받아온 h,w를 사용하여 반복문 실행
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] >  max_val ) {
				max_val = a[i][j];
			}
		}
	}
	return max_val;
}

int main() {
	//1. 1차원 배열 테스트 (슬라이드 예제처럼 arr 이름 사용)
	int arr[10] = { 3, 15, 32, 7, 49, 21, 5, 44, 12, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int maxVal = findMaxValue(arr, len);
	printf("1. 1차원 배열 최댓값: %d\n", maxVal);

	//2. 2차원 이미지 테스트
	int image[HEIGHT][WIDTH] = {
		{ 10, 30, 55, 80, 120, 160, 200, 230 },
		{ 20, 45, 70, 100, 140, 180, 220, 210 },
		{ 35, 60, 90, 130, 170, 210, 240, 190 },
		{ 50, 80, 115, 150, 190, 230, 255, 170 },
		{ 40, 65, 100, 140, 175, 215, 235, 150 },
		{ 25, 50, 80, 115, 155, 195, 210, 130 },
		{ 15, 35, 60, 90, 130, 165, 185, 110 },
		{ 5, 20, 40, 70, 105, 140, 160, 90 }
	};

	//함수 호출 시 배열과 함께 높이와 너비를 전달
	int maxPixel = findMaxPixel(image, HEIGHT, WIDTH);
	printf("2. 2차원 이미지 최대 밝기 : %d\n", maxPixel);

	return 0; 
}