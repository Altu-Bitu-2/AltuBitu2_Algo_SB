#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; // 배열 크기, 8

int n, m;   // 자연수의 개수 변수 n, 수열의 길이 변수 m
vector<int> num(SIZE);  // 정수형 vector num (n개의 수), 크기: SIZE(8)
vector<int> ans(SIZE);  // 정수형 vector ans (정답 수열), 크기: SIZE(8)
vector<bool> check(SIZE);   // vector check (중복 제거 위한 vector), 크기: SIZE(8)

// backtracking() 함수
void backtracking(int cnt) {    // cnt: 인덱스 역할, 수열에서 위치
    if (cnt == m) { // 길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) {   // vector ans 출력
            cout << ans[i] << ' ';  // vector ans, 수열 한 줄에 하나씩 출력(공백 구분)
        }
        cout << '\n';   // 마지막 줄
        return; // 리턴
    }
    int prev = 0;   // 이전에 선택한 값
    for (int i = 0; i < n; i++) {
        if (!check[i] && prev != num[i]) {  // 수 위치 중복 체크 && 이전에 탐색한 값이 아니라면
            prev = num[i];  // 이전에 선택한 값(prev) num[i]로 업데이트
            ans[cnt] = num[i];  // ans[cnt]를 num[i]로 업데이트
            check[i] = true;    // ckeck[i]를 true로 업데이트
            backtracking(cnt + 1);  // backtracking() 함수 호출 (재귀)
            check[i] = false;   // ckeck[i] 값 다시 false로
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
 */

int main() {
    // 입력
    cin >> n >> m;  // 입력 받은 정수 n, m에 저장
    for (int i = 0; i < n; i++) {   // 입력 받은 n개의 자연수 저장
        cin >> num[i];  // 입력 받은 수 저장
    }

    // 연산
    sort(num.begin(), num.begin() + n); // vector num 오름차순 정렬

    // 백트래킹 & 출력
    backtracking(0);    // backtracking() 함수 호출
    return 0;
}