#include <iostream>

using namespace std;

// 화살표 연산자
string solution(int x, int n) { // 입력: x의 초기값, 화살표 길이
    if (n > 1 && n % 2 == 1) {  // 만약 n이 1보다 크고 홀수면
        return "ERROR"; // ERROR 리턴
    }
    if (n == 1 && x < 0) {  // 만약 n이 1, x가 음수이면
        return "INFINITE";  // INFINITE 리턴
    }
    if (n == 1 || x <= 0) { // 만약 n이 1 또는 x가 0이하 이면
        return "0"; // 0 리턴
    }
    if (n == 0) {   // 만약 n 이 0이면
        return "INFINITE";  // INFINITE 리턴
    }
    return to_string((x - 1) / (n / 2));    // (x - 1)을 (n / 2)로 나눈 몫 리턴
}

/**
 * [화살표 연산자]
 *
 * 1. n이 1보다 큰 홀수인 경우 -> ERROR
 * 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 * 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 5. 나머지 경우엔 (x - 1)을 (n / 2)로 나눈 몫을 출력
 *    - 연산했을 때 1 이상이 남을 때까지만 출력을 할 수 있으므로 1을 뺀 값에서 몫을 구함
 */

int main() {
    int x, n;   // 변수 x의 초기값 x, 화살표 길이 n

    // 입력
    cin >> x >> n;  // 입력 받음

    // 연산 & 출력
    cout << solution(x, n); // solution() 함수, 연산
    return 0;
}