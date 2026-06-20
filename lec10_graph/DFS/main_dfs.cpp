#include "Location2D.h"
#include <deque> // STL의 deque 포함
using namespace std;

int main() {
    deque<Location2D> locDeque; // 위치 덱 객체 생성
    Location2D entry(1, 0);     // 입구 객체 생성
    locDeque.push_back(entry);   // 데크의 뒤에 삽입

    while (locDeque.empty() == false) {
        Location2D here = locDeque.back(); // 데크의 뒤에서 꺼냄 (스택의 top 역할)
        locDeque.pop_back();

        int r = here.row;
        int c = here.col;
        printf("(%d,%d) ", r, c);

        // 현재 위치가 출구(x)이면 탐색 성공
        if (map[r][c] == 'x') {
            printf("\n미로 탐색 성공\n");
            return 0;
        }
        else {
            map[r][c] = '.'; // 방문 표시

            // 교재 순서대로 상, 하, 좌, 우 검사하여 push
            if (isValidLoc(r - 1, c)) locDeque.push_back(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) locDeque.push_back(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) locDeque.push_back(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) locDeque.push_back(Location2D(r, c + 1));
        }
    }

    printf("\n미로 탐색 실패\n");
    return 0;
}