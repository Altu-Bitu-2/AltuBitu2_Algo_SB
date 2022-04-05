#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10; // 상수 10, 정수 n의 max 값

// bottom-up 방식 dp 배열 채우기
// n=1 -> 1가지, n=2 -> 2가지 따로 작성
vector<int> numberOfAllCases() {    // 함수 numberOfAllCases(), 벡터 반환
    vector<int> dp(MAX + 1, 0); // vector dp, 크기는 11(MAX+1), 0으로 초기화

    dp[0] = dp[1] = 1;  // 인덱스가 0(더미 인덱스), 1인 dp(n=1인 경우)는 1
    dp[2] = 2;  // 인덱스가 2인 dp(n=2인 경우)는 2로
    // n>= 3인 경우
    for (int i = 3; i <= MAX; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];  // 찾은 규칙 연산, 0으로 초기화 되어 있던 dp 값 업데이트
    }
    return dp;  // dp 리턴
}

/**
 * [bottom-up 접근]
 * 각 수를 인덱스로 써서 정수 n까지 1, 2, 3의 합으로 나타내는 방법의 수를 저장하자!
 *
 * 우선 3까지 1, 2, 3의 합으로 나타내는 방법의 수 초기화 함
 * 해당 인덱스에서 -1, -2, -3 한 인덱스에 +1, +2, +3을 해줬다고 생각하면 됨
 *
 * -> dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] (n >= 3)
 *
 * 해당 풀이는 인덱스 관리를 편하게 하기 위해 0을 더미 인덱스로 줘서 인덱스 3부터 연산
 * 테스트케이스로 입력이 들어오고, 입력 범위가 11로 작기 때문에 미리 dp 배열 채우고 시작하는 것이 더 효율적
 */

int main() {
    int t, n;   // t: 테스트 케이스의 개수, n: 정수

    // 미리 dp 채우기
    vector<int> dp = numberOfAllCases();    // 함수 numberOfAllCases() 호출, 리턴 값 vector dp에 저장

    // 입력
    cin >> t;   // 입력 받은 테스트케이스 수 저장
    while (t--) {   // t개 동안
        cin >> n;   // 입력 받은 정수 값 n에 저장

        // 출력
        cout << dp[n] << '\n';  // 인덱스 n에 해당하는 dp 값 출력
    }
    return 0;
}