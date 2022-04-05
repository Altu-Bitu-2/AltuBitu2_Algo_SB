#include <iostream>
#include <vector>

using namespace std;

// kanpsack() 함수
int knapsack(int n, int m, vector<int> &coin) { // n: 동전의 가지 수, m: 만들 금액, coin: 동전 각 금액
    vector<int> dp(m + 1, 0);   // vector dp(주어진 동전을 이용하여 조건 금액을 만드는 경우의 수), 크기는 m+1, 0으로 초기화

    dp[0] = 1;  // 0원을 만드는 경우의 수 1

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= m; j++) {    // j: 동전 종류를 나타내기 위함, 만들어야 하는 금액인 m까지 반복
            dp[j] += dp[j - coin[i]];   // 해당 동전을 사용하기 전 경우의 수와 현재 경우의 수를 더함
        }
    }
    return dp[m];   // m원을 만드는 경우의 수 리턴
}

/**
 * dp[i] = 주어진 동전 종류를 사용해서 i원을 만드는 경우의 수
 *
 * dp[0] = 1 을 넣고 시작 (0원을 만드는 경우의 수 1로 생각)
 * 각 동전마다 해당 동전부터 만들어야 하는 금액(m)까지 돌리면서 해당 동전을 사용하기 전 금액의 경우의 수와 현재 경우의 수를 더함
 * 해당 동전 사용하기 전 금액의 경우의 수가 0이면 금액을 만들 수 없는 경우이지만, 어차피 더해도 값 변화는 없으므로 따로 고려하지 않음
 */

int main() {
    int t, n, m;    // t: 테스트케이스 개수, n: 동전의 가지 수, m: n가지 동전으로 만들어야 할 금액

    // 입력
    cin >> t;   // 테스트케이스 저장
    while (t--) {   // 테스트케이스 개수 동안
        cin >> n;   // 동전의 가지 수 n 저장
        vector<int> coin(n, 0); // vector coin(n가지 동전의 각 금액을 저장), 크기는 n, 0으로 초기화
        // n가지 동전의 각 금액 저장 (오름차순 배열)
        for (int i = 0; i < n; i++) {
            cin >> coin[i]; // 금액 저장
        }
        cin >> m;   // 만들어야 할 금액 m 저장

        // 연산 & 출력
        cout << knapsack(n, m, coin) << '\n';   // knapsack() 함수 호출
    }
    return 0;
}