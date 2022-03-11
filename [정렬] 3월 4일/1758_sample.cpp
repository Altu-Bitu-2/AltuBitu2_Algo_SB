#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 함수 calTip
long long calTip(int n, vector<int> &tips) {    // 사람 수 n과 vector 입력 받음
    long long ans = 0;  // 팁의 최댓값을 저장할 변수 ans 0으로 초기화
    // 실제로 강호가 받는 팁 계산
    for (int i = 0; i < n; i++) {
        int cur_tip = tips[i] - i;
        if (cur_tip < 0) // 음수면 팁에 더하지 않는데 처음에 내림차순 정렬했으므로 아예 break
            break;
        ans += cur_tip;
    }
    return ans;
}

/**
*  강호가 받을 수 있는 팁이 최댓값이 되려면 팁이 많은 사람의 순위가 높아야 함
 *  !주의! 주어지는 N의 최대 크기가 100,000 이고 팁의 최대 크기가 100,000이므로
 *  정답의 최댓값은 10^5 * ( 10^5 + 1 ) /2 로 int 범위를 넘기 때문에 long long 을 써야 함
*/

int main() {
    int n;  // 사람 수 변수 선언

    // 입력
    cin >> n;   // 사람 수 입력 받음
    vector<int> tips(n, 0); // vector tips, 0이 n개
    // vector tips에 입력 값 저장
    for (int i = 0; i < n; i++) {
        cin >> tips[i];
    }
    // 연산
    sort(tips.begin(), tips.end(), greater<>());    // 내림차순 정렬: 팁이 큰 사람이 앞에 서야하기 때문
    // 출력
    cout << calTip(n, tips) << '\n';
    return 0;
}