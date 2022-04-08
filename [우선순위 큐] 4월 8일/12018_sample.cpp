#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// maxClass() 함수, 최대 과목 수 리턴, 가장 마일리지가 적게드는 과목부터 수강
int maxClass(int m, priority_queue<int, vector<int>, greater<>> &pq) {  // 리턴값: 최대로 들을 수 있는 강의 개수, 입력값: 성준이의 마일리지, 과목 수강에 필요한 마일리지
    int result = 0; // 들을 수 있는 과목 수 result, 0으로 초기화
    while (!pq.empty() && pq.top() <= m) {  // 더이상 들을 과목이 없거나, 마일리지가 모자르면 반복문 탈출
        m -= pq.top();  // 성준이의 마일리지 = 성준이의 마일리지 - 최소 마일리지 과목의 마일리지
        pq.pop();   // 수강 신청한 과목은 각 과목의 마일리지에서 제거
        result++;   // 들을 수 있는 과목 수 1 증가
    }
    return result;  // 들을 수 있는 과목 수 리턴
}

/**
 * [Yonsei TOTO]
 *
 * 수강 인원이 미달일 때 필요한 마일리지는 0이 아니라 1
 * 1. 각 과목을 듣기 위해 필요한 최소 마일리지를 계산 (정렬)
 * 2. 가장 마일리지가 적게 드는 과목부터 수강 신청 (우선순위 큐 or 정렬)
 */
int main() {
    int n, m, p, l; // n: 과목 수, m: 마일리지, p: 과목을 신청한 사람 수, l: 과목의 수강인원
    priority_queue<int, vector<int>, greater<>> pq; // 최소 힙, 각 과목 수강에 필요한 마일리지 저장

    cin >> n >> m;  // 입력 값 n, m에 저장
    while (n--) {   // 과목 수 동안 반복
        // 입력
        cin >> p >> l;  // 입력 값 p, l에 저장,
        vector<int> arr(p); // vector arr 선언, 크기는 p, 각 사람의 마일리지를 저장
        for (int i = 0; i < p; i++) {   // 과목을 신청한 사람 수만큼 반복
            cin >> arr[i];  // arr 에 각 사람의 마일리지 저장
        }

        // 연산
        if (p < l) {    // 수강인원이 미달이라면 마일리지를 1만 넣어도 됨 (과목을 신청한 사람 수 < 과목의 수강 정원)
            pq.push(1); // 과목 수강에 필요한 마일리지에 1을 삽입
            continue;   // continue
        }
        sort(arr.begin(), arr.end(), greater<>());  // 내림차순 정렬, 각 사람의 마일리지를 가장 큰 값부터 정렬
        pq.push(arr[l - 1]);    // l번째로 마일리지를 많이 넣은 사람과 같은 양의 마일리지를 넣어야 수강 가능
    }

    // 출력
    cout << maxClass(m, pq);    // 최대 과목 수를 출력, maxClass() 함수 호출
}