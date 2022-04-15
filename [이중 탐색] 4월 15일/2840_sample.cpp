#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci; // pair<char, char>를 ci로 정의

// 특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {   // 입력값: 특정 화살표의 인덱스, 바퀴 칸의 수, 바퀴의 상태
    string ans = "";    // 답을 출력할 ans 변수를 초기화
    int start = arrow_point;    // start: 특정 화살표를 의미하는 인덱스
    do {
        ans += wheel[arrow_point];  // ans를 ans + wheel 값으로 업데이트
        arrow_point = (arrow_point + 1) % n;    // arrow_point(화살표의 인덱스) 값을 바꿔줌
    } while (arrow_point != start); // 화살표의 인덱스가 stat와 동일하면 stop
    return ans; // ans 리턴
}

// 행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {   // 입력값: 바퀴의 칸의 수, 바퀴 회전 기록
    vector<char> wheel(n, '?'); // 바퀴의 상태, 처음에는 어떤 상태인지 모르기에 '?'로 초기화
    vector<bool> is_available(26, false);   // 알파벳 중복 체크

    int idx = 0;    // 화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) {   // 바퀴의 회전 기록 횟수 동안 반복
        int rot = record[i].first;  // rot: 바퀴를 회전시켰을 때, 글자가 바뀐 횟수
        char alpha = record[i].second;  // alpha: 회전을 멈추었을 때, 가리키는 글자
        idx = (idx - rot % n + n) % n;  // 화살표가 가리키는 인덱스 계산
        if (wheel[idx] == alpha) {  // 만약 바퀴의 상태와 회전을 멈추었을 때 글자가 동일하다면
            continue;   // continue
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) {   // 만약 바퀴의 상태가 '?'가 아니거나, is_available 값이 true면
            return "!"; // '!' 리턴
        }
        wheel[idx] = alpha; // 인덱스에 해당하는 wheel의 값을 alpha로 저장 (칸이 결정되지 않았을 때)
        is_available[alpha - 'A'] = true;   // is_available을 true로 업데이트
    }
    return arrowStartWheel(idx, n, wheel);  // arrowStartWheel() 리턴
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가리키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k;   // n: 바퀴의 칸의 수, k: 바퀴를 돌리는 횟수

    // 입력
    cin >> n >> k;  // 바퀴의 칸의 수 n, 바퀴를 돌리는 횟수 k를 입력 받음
    vector<ci> record(k, {0, 0});   // vector record에 바퀴 회전 기록, {글자가 바뀐 횟수(S), 회전을 멈추었을 때 가리킨 글자}
    for (int i = 0; i < k; i++) {   // 바퀴를 k번 회전
        cin >> record[i].first >> record[i].second; // first에 글자가 바뀐 횟수, second에 회전을 멈추었을 때의 글자 저장
    }

    // 연산 & 출력
    cout << makeWheel(n, record);   // makeWheel() 함수 호출, 행운의 바퀴를 구함
    return 0;
}