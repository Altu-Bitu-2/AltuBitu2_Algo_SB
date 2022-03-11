#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 함수 s의 계산
int calcS(int n, vector<int> a, vector<int> b) {    // 배열의 길이 n, vector a, b 를 입력값으로 받음
    int s = 0;  // 변수 s를 0으로 초기화
    // vector a와 vector b 값을 곱해줌
    for (int i = 0; i < n; i++) {
        s += (a[i] * b[i]);
    }
    return s;
}

/**
 * 문제에서 B를 재배열하지 말라고 했지만, 해야하는 문제
 * 각배열에서 가장 큰 값과 가장 작은 값을 곱해야 최솟값이 나옴!
 */

int main() {
    int n;  // 변수 n 선언
    vector<int> a, b;   // vector a, b 선언

    // 입력
    cin >> n;   // 배열의 길이 N 입력 받음
    a.assign(n, 0); // 0을 n번 vector a에 넣음
    b.assign(n, 0); // 0을 n번 vector b에 넣음
    // vector a에 값 저장
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // vector b에 값 저장
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // 연산
    sort(a.begin(), a.end());    // 오름차순 정렬
    sort(b.begin(), b.end(), greater<>());  // 내림차순 정렬
    int result = calcS(n, a, b);    // calcS 함수 호출

    // 출력
    cout << result;
    return 0;
}