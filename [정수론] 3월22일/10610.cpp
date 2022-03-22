#include <iostream>
#include <algorithm>
using namespace std;

// findNumber() 함수 정의, 입력 및 출력으로 문자열 s
string findNumber(string s) {
    bool isTen = false; // 0이 존재하는지 확인
    int sum = 0;    // 3의 배수인지 확인하기 위한 수 sum = 0으로 초기화

    // for문 돌면서 3의 배수와 10의 배수인지 확인
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0');    // 각 자리 수의 합
        if (s[i] == '0') {  // 만약 입력된 수에 0이 있으면
            isTen = true;   // 10의 배수
        }
    }

    if (sum % 3 != 0 || !isTen) {   // 3의 배수가 아니거나, 10의 배수가 아니라면
        return "-1";    // "-1" 출력
    }

    // 가장 큰 수 만들기 위해 내림차순 정렬
    sort(s.begin(), s.end(), greater<>());
    return s;   // 30의 배수가 되는 가장 큰 수 출력
}

/**
*  [30]
 *  30의 배수 = 10의 배수 && 3의 배수
 *  1. 10의 배수 -> 입력된 수에 0이 포함되어 있는지 확인
 *  2. 3의 배수 -> 모든 자리수의 합이 3의 배수인지 확인
 *
 *  30의 배수임이 확인 되었으면,
 *  가장 큰 수를 만들기 위해 9부터 0까지 역순으로 나열한다.
*/

int main() {
    string s;   // 정수 N 문자열로 s 선언

    // 입력
    cin >> s;   // 입력값 s에 저장

    // 연산 & 출력
    cout << findNumber(s);  // findNumber() 함수 호출, 출력
    return 0;
}