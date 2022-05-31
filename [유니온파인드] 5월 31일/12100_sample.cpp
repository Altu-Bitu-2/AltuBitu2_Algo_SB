#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix; // matrix 를 vector<vector<int>> 로 정의

int n, ans = 0; // 보드의 크기 n, 정답 ans=0

// 가장 큰 블록을 찾음
int getMaxBlock(matrix &board) {    // 입력: 보드판
    int max_block = 0;  // 가장 큰 블록 값 0으로 초기화
    for (int i = 0; i < n; i++) {   // 반복
        for (int j = 0; j < n; j++) {   // 반복
            max_block = max(max_block, board[i][j]);    // 가장 큰 블록 업데이트
        }
    }
    return max_block;   // 리턴
}

// 매트릭스의 모양(배열) 바꿈, 보드를 돌림
matrix transposeMatrix(matrix &board) { // 입력: 보드판
    matrix board_t(n, vector<int>(n, 0));   // 바뀐 보드를 저장할 board_t 초기화
    for (int i = 0; i < n; i++) {   // 반복
        for (int j = 0; j < n; j++) {   // 반복
            board_t[i][j] = board[j][i];    // 바뀐 보드 업데이트
        }
    }
    return board_t; // 리턴
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */
matrix upMove(matrix board) {   // 입력: 보드판
    matrix temp(n, vector<int>(n, 0)); // 새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) {   // 반복
        int idx = 0;    // 인덱스
        int prev = 0;   // 이전 값
        for (int i = 0; i < n; i++) {   // 반복
            if (!board[i][j]) { // 블록 없는 부분
                continue;   // 넘어감
            }
            if (board[i][j] == prev) {  // 만약 이전 값과 같다면
                temp[idx - 1][j] *= 2;  // 합침
                prev = 0;   // 이전 값 0으로
            } else {    // 다르다면
                temp[idx++][j] = board[i][j];   // 블록이 존재했던 값 저장
                prev = board[i][j]; // 업데이트
            }
        }
    }
    return temp;    // 리턴
}

// 백트래킹 탐색
void backtracking(int cnt, matrix board) {
    if (cnt == 5) { // 최대 5번 이동
        ans = max(ans, getMaxBlock(board)); // 가장 큰 블록을 찾음
        return; // 리턴
    }
    // Transpose matrix 구하기 (상->좌)
    matrix board_t = transposeMatrix(board);
    // 상
    backtracking(cnt + 1, upMove(board));   // 백트래킹 탐색
    // 하
    reverse(board.begin(), board.end());    // 보드를 돌림
    backtracking(cnt + 1, upMove(board));   // 백트래킹 탐색
    // 좌
    backtracking(cnt + 1, upMove(board_t)); // 백트래킹 탐색
    // 우
    reverse(board_t.begin(), board_t.end());    // 보드를 돌림
    backtracking(cnt + 1, upMove(board_t)); // 백트래킹 탐색
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    // 입력
    cin >> n;   // 보드의 크기 입력 받음
    matrix board(n, vector<int>(n, 0)); // matrix 타입의 board 생성, 보드판
    for (int i = 0; i < n; i++) {   // 반복
        for (int j = 0; j < n; j++) {   // 반복
            cin >> board[i][j]; // 보드판을 그림
        }
    }

    // 연산
    backtracking(0, board); // 백트래킹 탐색

    // 출력
    cout << ans;
    return 0;
}