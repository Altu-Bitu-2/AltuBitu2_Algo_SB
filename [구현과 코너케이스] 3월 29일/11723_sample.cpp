#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int SIZE = 21;    // 상수 SIZE 21

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸림
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num; // 수행해야하는 연산의 수: m, x: num
    string cmd; // 수행해야하는 연산
    vector<bool> s(SIZE, false);    // vector s

    cin >> m;   // 수행해야하는 연산의 수를 입력 받음
    while (m--) {   // m 개수 동안
        cin >> cmd; // 수행해야하는 연산을 입력 받음
        if (cmd == "all") { // cmd가 all 이면
            s.assign(SIZE, true);   // vector s를 {1, 2, ..., 20}으로 바꿈
            continue;
        }
        if (cmd == "empty") {   // cmd가 empty 이면
            s.assign(SIZE, false);  // vector s를 비움(공집합으로 만든다)
            continue;
        }

        cin >> num; // num을 입력 받음
        if (cmd == "add") { // cmd가 add 이면
            s[num] = true;  // vector s에 num 추가
            continue;
        }
        if (cmd == "remove") {  // cmd가 remove 이면
            s[num] = false; // vector s에서 num 삭제
            continue;
        }
        if (cmd == "check") {   // cmd가 check 이면
            cout << s[num] << '\n'; // bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (cmd == "toggle") {  // cmd가 toggle 이면
            s[num] = !s[num];   // num이 있으면 삭제, 없으면 추가
            continue;
        }
    }
    return 0;
}