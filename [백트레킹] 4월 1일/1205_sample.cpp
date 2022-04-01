#include <iostream>
#include <vector>

using namespace std;

// findRanking() 함수
int findRanking(int n, int new_score, int p, vector<int> &ranking) {
    // 리스트 점수 개수 n, 태수의 점수 new_score, 랭킹 리스트에 오를 수 있는 점수 개수 p, 랭킹 리스트 vector ranking
    int idx = 1;    // 인덱스 변수 idx를 1로 초기화
    int ans = 1;    // 태수의 새로운 점수의 등수를 저장할 변수 ans, 1로 초기화
    // 새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) {  // idx가 n이하 동안 반복
        if (new_score > ranking[idx]) { // 만약 new_score 가 해당 인덱스의 점수보다 크면
            break;  // break
        }
        if (new_score < ranking[idx]) { // 만약 new_score 가 해당 인덱스의 점수보다 작으면
            ans = idx + 1;  // ans를 인덱스 값 + 1 해줌
        }
        idx++;  // 인덱스 값 1 증가
    }
    if (idx == p + 1) { // 랭킹 리스트에 들어가지 못하는 경우 (너무 낮아서...)
        return -1;  // -1 리턴
    }
    return ans; // ans 리턴
}

/**
 * [등수 구하기]
 *
 * 1. n = 0일 때, 고려
 * 2. 등수는 p보다 작지만, 점수가 더 좋을 때만 랭킹이 갱신되므로 랭킹 리스트에 들어가지 못하는 경우 고려 (동점)
 *
 * 현재 랭킹에 올라간 n까지 등수와 새로운 점수를 비교하며 새로운 점수 몇 등인지 계산
 * 새로운 점수가 현재 탐색 등수의 점수보다 작다면 -> 현재 탐색 등수 + 1
 * 동점일 경우 -> 그 전 등수 그대로 사용 -> 아무 처리도 하지 않음!
 */

int main() {
    int n, new_score, p;    // 정수형 변수 선언. n: 리스트에 있는 점수 개수, new_score: 태수의 새로운 점수, p: 랭킹 리스트에 올라갈 수 있는 점수의 개수

    // 입력
    cin >> n >> new_score >> p; // 입력 받은 값을 n, new_score, p에 저장
    vector<int> ranking(p + 1, 0);  // vector ranking 선언, p+1 개, 0으로 초기화
    for (int i = 1; i <= n; i++) {  // vector ranking에 값(리스트에 있는 점수) 저장
        cin >> ranking[i];  // 입력값 저장
    }

    // 연산 & 출력
    cout << findRanking(n, new_score, p, ranking);  // findRanking() 함수 호출
    return 0;
}