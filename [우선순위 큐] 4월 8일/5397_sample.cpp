#include <iostream>
#include <deque>

using namespace std;

// dqToString() 함수: deque를 string으로 변환
string dqToString(deque<char> &dq) {    // 리턴값: 강산이의 비밀번호 일부(커서 왼/오) 문자열로 변환한 값, 입력값: 강산의 비밀번호 일부(커서 왼/오)
    string ans = "";    // 문자열 ans 공백으로 초기화
    while (!dq.empty()) {   // 입력값이 빌 때까지 반복
        ans += dq.front();  // deque의 첫 원소를 ans에 저장
        dq.pop_front(); // deque의 첫 원소를 삭제
    }
    return ans; // ans를 리턴
}

// findPass() 함수: 비밀번호를 알아냄
string findPass(string s) { // 리턴값: 강산이의 비밀번호, 입력값(s): 강산이가 입력한 문자열
    deque<char> dq_left;    // 커서 이전 내용을 저장
    deque<char> dq_right;   // 커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {  // 강산이가 입력한 문자열의 길이 동안 반복
        switch (s[i]) { // 문자열 s의 해당 인덱스(i)의 값이
            case '-':   // '-'일 경우, 현재 커서 앞에 있는 글자를 지운다.
                if (!dq_left.empty()) { // 만약 dq_left 가 비어있지 않다면
                    dq_left.pop_back(); // dq_left 맨 뒤 원소 제거(backspace)
                }
                break;  // break
            case '<':   // '<'일 경우, 커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
                if (!dq_left.empty()) { // 만약 dq_left 가 비어있지 않다면
                    dq_right.push_front(dq_left.back());    // dq_right 의 맨 앞에 dq_left 의 맨 마지막 원소를 삽입
                    dq_left.pop_back(); // dq_left 의 맨 뒤 원소 제거(커서 앞으로 이동)
                }
                break;  // break
            case '>':   // '>'일 경우, 커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
                if (!dq_right.empty()) {    // 만약 dq_right 가 비어있지 않다면
                    dq_left.push_back(dq_right.front());    // dq_left 의 맨 뒤에 dq_right 의 맨 처음 원소를 삽입
                    dq_right.pop_front();   // dq_right 의 맨 앞 원소 제거(커서 뒤로 이동)
                }
                break;  // break
            default:    // 문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
                dq_left.push_back(s[i]);    // 입력된 문자를 dq_left 의 맨 뒤에 삽입
                break;  // break
        }
    }

    string pass = dqToString(dq_left);  // pass: 강산이의 비밀번호, dqToString() 함수 호출
    pass += dqToString(dq_right);   // 문자열로 변환한 커서 이전 내용 + 커서 이후 내용
    return pass;    // 문자열로 변환한 강산의 전체 비밀번호 리턴
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int t;  // 테스트 케이스 개수 t
    string s;   // 강산이가 입력한 문자열

    // 입력
    cin >> t;   // 입력 받은 테스트 케이스 수를 t에 저장

    // 각 테스트 케이스에 대해서, 강산이의 비밀번호를 출력
    while (t--) {   // 테스트 케이스의 개수만큼 반복
        cin >> s;   // 입력 받은 문자열을 s에 저장

        // 연산 & 출력
        cout << findPass(s) << '\n';    // 출력, findPass() 함수 호출, 각 테스트 케이스 마다 한 줄씩 출력
    }
    return 0;
}