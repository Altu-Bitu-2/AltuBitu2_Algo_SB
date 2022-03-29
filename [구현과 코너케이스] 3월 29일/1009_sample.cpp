#include <iostream>
#include <vector>
using namespace std;

// 패턴을 찾는 함수 findPattern
vector<int> findPattern(int num) {
    vector<int> pattern = {num};    // vector pattern 에 num으로 초기화

    int temp = num; // 변수 temp에 num 저장
    while (num != (temp * num) % 10) {  // 패턴을 찾는 과정, 최초의 num 이 되기 전까지
        temp *= num;    // temp에 num을 곱함(제곱)
        temp %= 10;     // 일의 자리 수만 고려
        pattern.push_back(temp);    // vector pattern 에 temp 저장
    }
    return pattern; // vector pattern 리턴
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;    // 정수형 변수 t, a, b 선언

    // 0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0)); // 2차원 vector last_digit
    vector<int> pattern_size(10, 1);    // vector pattern_size, 크기가 10, 1로 초기화
    // 0 ~ 9 까지 일의 자리 패턴 구함
    for (int i = 0; i < 10; i++) {
        last_digit[i] = findPattern(i); // findPattern 함수 호출
        pattern_size[i] = last_digit[i].size(); // pattern_size에 일의 자릿수 크기 저장
    }

    // 입력
    cin >> t;   // 테스트 개수 t를 입력 받음
    while (t--) {   // t개 동안
        cin >> a >> b;  // 테스트 정수 a, b를 입력 받음
        a %= 10;    // a의 일의 자리 수를 구하기 위해 10으로 나눔

        if (a == 0) {   // 예외처리, 0일 때
            cout << "10\n"; // 10번 컴퓨터가 처리
            continue;
        }
        // 인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';
    }
    return 0;
}