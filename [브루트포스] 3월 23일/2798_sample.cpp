#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 재귀함수 사용시, 함수를 계속 호출하므로 전역변수로 관리하는 것이 더 효율적
int n, m;   // 카드의 개수를 저장할 변수 n, 딜러가 외치는 숫자 m 전역변수로 선언
vector<int> card;   // vector card 전역변수로 선언

// 백트래킹 풀이
// 카드를 중복으로 고르는 걸 방지하기 위해 t 매개변수를 활용해서 그 전에 고른 카드 번호 이후부터 고르도록
int selectCard(int cnt, int t, int sum) { // cnt: 카드 개수, t: 현재 카드 번호, sum: 카드 합
    int ans = 0;    // 답을 저장할 변수 ans 0으로 초기화
    if (sum > m) { // 합이 m을 넘는다면 (문제에서 m을 넘지 않는 카드 합)
        return 0;   // 0 리턴
    }
    if (cnt == 3) { // 3장의 카드를 골랐다면
        return sum; // sum 리턴
    }
    for (int i = t; i < n; i++) {   // 현재 카드 번호 t부터 n까지
        ans = max(ans, selectCard(cnt + 1, i + 1, sum + card[i]));  // selectCard()를 다시 호출하여 m을 넘지 않는 max 값 찾기
    }
    return ans; // ans 리턴
}

int main() {
    // 입력
    cin >> n >> m;  // 입력 받은 카드의 개수 n, 딜러가 외치는 숫자 m에 저장
    card.assign(n, 0);  // 0인 원소가 n개인 vector card
    for (int i = 0; i < n; i++) {   // vector card에 원소 저장
        cin >> card[i];
    }

    // 연산 & 출력
    sort(card.begin(), card.end()); // vector card 정렬
    cout << selectCard(0, 0, 0);    // 출력, selectCaed() 함수 호출
    return 0;
}