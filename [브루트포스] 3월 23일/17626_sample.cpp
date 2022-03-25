#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// findMinNumber() 함수, 제곱수 개수가 최소인 경우 찾음
int findMinNumber(int n, int num_size, vector<int> &square_num) {
    if (square_num[num_size - 1] == n) {    // 1개로 만들 수 있을 경우 바로 리턴
        return 1;   // 1 리턴
    }
    for (int i = num_size - 1; i >= 0; i--) {   // 2개로 만들 수 있는 경우 검사
        for (int j = num_size - 1; j >= 0; j--) {
            if (square_num[i] + square_num[j] == n) {   // 만약 두 개의 square_num 원소 합으로 자연수 n을 만들 수 있으면
                return 2;   // 2 리턴
            }
        }
    }
    for (int i = num_size - 1; i >= 0; i--) {   // 3개로 만들 수 있는 경우 검사
        for (int j = num_size - 1; j >= 0; j--) {
            for (int k = num_size - 1; k >= 0; k--) {
                if (square_num[i] + square_num[j] + square_num[k] == n) {   // 만약 세 개의 square_num 원소 합으로 자연수 n을 만들 수 있으면
                    return 3;   // 3 리턴
                }
            }
        }
    }
    return 4;   // 1-3개가 아닌 경우 무조건 4개의 제곱수의 합으로 구성
}

/**
 * [Four Squares] - 브루트 포스 풀이 (8ms)
 * 자연수 n에 대해 최소 몇 개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 완전탐색
 *
 * 1 ~ 3개 조합으로 불가능한 경우, 답은 무조건 4가 된다 -> 4개의 합은 시도해보지 않아도 된다.
 *
 * sqrt(50000) = 약 223
 * 전체 연산 수  < 223^2 + 223^3 = 11139296 <1억 -> 브루트포스 가능
 */

int main() {
    int n, num_size;    // 자연수 n, 제곱수 개수 n 변수 선언
    vector<int> square_num; // 제곱수를 저장할 vector square_num 선언

    // 입력
    cin >> n;   // 입력된 자연수를 변수 n에 저장

    // 연산
    for (int i = 1; i <= sqrt(n); i++) {    // 미리 루트n 까지의 제곱수 저장
        square_num.push_back(i * i);    // vector square_num 에 1*1, 2*2, ..., 루트n*루트n 저장
    }
    num_size = square_num.size();   // 제곱수 개수 num_size는 vector square_num의 크기

    // 출력
    cout << findMinNumber(n, num_size, square_num); // findMinNumber() 함수 호출
    return 0;
}