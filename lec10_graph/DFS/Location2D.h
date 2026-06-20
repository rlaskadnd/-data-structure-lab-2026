#pragma once
#include <cstdio>

const int MAZE_SIZE = 6;

struct Location2D {
    int row;
    int col;

    // 생성자
    Location2D(int r = 0, int c = 0) {
        row = r;
        col = c;
    }

    // 두 위치가 같은지 확인하는 연산자 오버로딩
    bool operator==(Location2D& p) {
        return row == p.row && col == p.col;
    }
};

// 교재 미로 데이터 (0: 갈 수 있는 길, 1: 벽, e: 입구, x: 출구)
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

// 갈 수 있는 위치인지 확인하는 함수 (교재 로직)
bool isValidLoc(int r, int c) {
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
    return map[r][c] == '0' || map[r][c] == 'x';
}

