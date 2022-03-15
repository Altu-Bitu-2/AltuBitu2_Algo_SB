#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 이분탐색을 이용한 풀이
 * O(n)의 시간복잡도를 갖는 선형탐색과 달리, 이분탐색은 O(logN)의 시간복잡도를 가짐
 */

int main() {
    // 입출력 처리 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int t;  // 정수형 변수 t 선언
    cin >> t;   // t에 입력값 저장
    // 반복
    while (t--) {
        int n, m, input;    // 정수형 변수 n, m, input 선언 (n: 수첩1 정수 개수, m: 수첩2 정수 개수, input: 수첩의 정수)

        // 수첩1에 해당되는 원소들을 vector에 저장
        cin >> n;   // n에 입력값 저장
        vector<int> note1(n, 0);    // vector note1 생성
        // 반복문을 이용해서 수첩1에 정수 저장
        for (int i = 0; i < n; i++) {
            cin >> note1[i];
        }
        // 이분탐색을 하기 위해 정렬
        sort(note1.begin(), note1.end());

        cin >> m;   // m에 입력값 저장
        while (m--) {
            cin >> input;   // input에 입력값 저장
            // 이분탐색 라이브러리 함수를 활용해, 원소가 수첩1에 엤는지 확인
            // binary_search() -> 이분탐색으로 원소가 있는지를 확인하고 결과를 리틴하는 함수
            // 수첩1에 없이면 0, 있으면 1 출력
            if (binary_search(note1.begin(), note1.end(), input)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
    return 0;
}
