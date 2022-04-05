#include <iostream>
#include <vector>

using namespace std;
const int MOD = 10007;  // 상수 MOD = 10007, 10007로 나눈 나머지를 출력하기 위함

// fillTile(n) 함수
int fillTile(int n) {   // n: 정수, 2*n
    vector<int> dp(n + 1, 0);   // vector dp, 크기는 n+1, 0으로 초기화

    if (n == 1) {   // 인덱스 에러 안나도록 n이 1일 경우 바로 리턴
        return 1;   // n=1이면 리턴 1
    }

    // 너비 1, 2인 타일 채우는 경우의 수 미리 초기화
    dp[1] = 1;  // n=1 -> 1
    dp[2] = 3;  // n=2 -> 3

    // n>= 3인 경우
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];  // 연산
        dp[i] %= MOD; // 구하는 과정에서 int 범위 초과할 수 있으므로 마지막에 한 번이 아니라 중간 중간 모듈러 연산을 해줘야 함
    }
    return dp[n];   // 리턴 dp[n]
}

/**
 * 너비를 인덱스로 써서 n까지의 너비를 채우는 방법의 수를 저장하자!
 *
 * 우선, 너비 1은 2(높이)x1(너비) 타일로 채우는 경우밖에 없음
 * 너비 2는 1x2 2개와 2x2 1개 총 2 경우 + 너비 1에 2x1 타일을 더한 1 경우 -> 3 경우
 *
 * 그 후, 너비 3부터는 각각 너비 1, 2만큼을 뺀 타일에서 1, 2 너비 타일을 각각 더하는 경우를 생각해주자
 * 이때, 중복 경우의 수가 생기지 않도록 너비 2의 경우에서 1에서 더한 경우는 빼줌
 * -> dp[n] = (너비 1인 타일 채우는 경우의 수 = 1) * dp[n - 1]
 *          + (너비 2인 타일 채우는 경우의 수 = 2) * dp[n - 2]
 *
 * -> dp[n] = 1 * dp[n - 1] + 2 * dp[n - 2] (n >= 3)
 *
 * !주의! 모듈러 연산 해야함
 */

int main() {
    int n;  // 정수 n, 2*n의 n

    // 입력
    cin >> n;   // 입력 받은 정수를 n에 저장

    // 연산 & 출력
    cout << fillTile(n);    // fillTile(n) 함수 호출
    return 0;
}