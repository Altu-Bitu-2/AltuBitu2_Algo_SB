#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * set을 이용한 풀이
 * 정렬을 할 필요가 없이, 삽입과 검색만 일어나는 문제
 * 입력의 수가 최대 1,000,000으로 삽입과 탐색이 많이 일어남
 * 따라서, O(log N)의 set이 아니라 O(1)인 unordered_set을 사용해서 풀이
 */

int main() {
    // 입출력 처리 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int t;  // 정수형 변수 t 선언
    cin >> t;   // t에 입력값 저장
    while(t--) {
        int n, m, input;    // 정수형 변수 n, m, input 선언 (n: 수첩1 정수 개수, m: 수첩2 정수 개수, input: 수첩의 정수)
        unordered_set<int> note1;   // 정렬되지 않은 set note1 선언

        // 수첩1에 해당되는 원소들을 unordered_set에 삽입
        cin >> n;   // n에 입력값을 받음
        while (n--) {   // 반복해서 수첩에 추가
            cin >> input;   // input에 입력값을 받음
            note1.insert(input);    // note1에 input 값 추가
        }
        cin >> m;   // m에 입력값을 받음
        while (m--) {   // 반복해서 수첩에 추가
            cin >> input;   // input에 입력값을 받음
            // 반복자를 이용해서 원소가 셋에 포함되어 있는지 확인
            auto iter = note1.find(input);
            // 수첩1에 없이면 0, 있으면 1 출력
            if (iter == note1.end()) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        }
    }
    return 0;
}
