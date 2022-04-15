#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// childNum() 함수, 해당 과자 길이일 때 몇 명의 조카에게 나누어 줄 수 있는지 계산
int childNum(int len, vector<int> &snacks) {    // 입력값: 나누어 주려는 과자의 길이, 과자 길이 목록
    int cnt = 0;    // 나눠줄 수 있는 조카의 수 cnt, 0으로 초기화
    for (int i = snacks.size() - 1; i >= 0; i--) {  // 가장 긴 과자부터 검사
        if (snacks[i] < len) {  // 나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break;  // break
        }
        cnt += (snacks[i] / len);   // 나눠줄 수 있는 조카의 수 증가
    }

    return cnt; // 아이 수 리턴
}
// upperSearch() 함수, 1명에게 줄 수 있는 막대 과자의 최대 길이 계산
int upperSearch(int left, int right, int target, vector<int> &snacks) {
    // 입력값: 과자 길이의 최솟값, 과자 길이의 최댓값, 조카의 수, 과자 길이 목록
    while (left <= right) { // 과자 길이의 최솟값이 최댓값보다 작거나 같은 동안 반복
        int mid = (left + right) / 2;   // 과자의 길이
        int cnt = childNum(mid, snacks);    // childNum() 함수 호출, 과자 길이가 mid일 때 몇 명에게 나눠주는지 계산

        if (cnt >= target) {    // target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1; // 과자 길이의 최솟값을 mid+1로 증가
        } else {    // target 보다 적다면
            right = mid - 1;    // 과자 길이의 최댓값을 mid-1로 감소
        }
    }
    return left - 1;    // left-1 을 리턴
}

/**
 * [과자 나눠주기]
 *
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0;  // m: 조카의 수, n: 과자의 수, left: 과자 길이의 최솟값, right: 과자 길이의 최댓값

    // 입력
    cin >> m >> n;  // 조카의 수 m과 과자의 수 n을 입력 받음
    vector<int> snacks(n, 0);   // 과자의 길이 목록
    for (int i = 0; i < n; i++) {   // 과자 n개의 길이를 저장
        cin >> snacks[i];   // 과자의 길이를 저장
    }

    // 연산
    sort(snacks.begin(), snacks.end()); // 과자의 길이를 정렬
    right = snacks[n - 1];  // 과자 길이의 최댓값을 업데이트

    // 연산 & 출력
    cout << upperSearch(left, right, m, snacks);    // upperSearch() 함수 호출, 조카 1명에게 줄 수 있는 최대 길이 출력
    return 0;
}