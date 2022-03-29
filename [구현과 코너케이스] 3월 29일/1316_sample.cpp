#include <iostream>
#include <vector>
using namespace std;

// 그룹 단어인지 확인하는 함수
bool isGroup(string str) {
    char cur = NULL;    // 현재의 문자
    vector<bool> alphabet(26, false);   // 각 알파벳의 등장 여부를 체크

    for (int i = 0; i < str.size(); i++) {  // 문자열(입력된 단어)의 크기 동안
        if (str[i] == cur) {    // 연속해서 나타난 문자
            continue;   // 넘어감
        }
        // 이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[str[i] - 'a']) {   // 이전에 등장했던 문자면 떨어져서 나타난 것
            return false;   // 그룹 단어가 아님
        }
        cur = str[i];   // 현재의 문자 업데이트
        alphabet[str[i] - 'a'] = true;  // 배열의 정보 업데이트
    }
    return true;    // 그룹 단어임
}

/**
 * [그룹 단어 체커] - 단순 구현 문제
 * - 이미 등장한 알파벳을 배열의 인덱스(알파벳)를 활용해서 정보 true/false로 저장
 * - set으로 체크할 수도 있겠지만 검색, 삽입 시마다 O(logN)의 시간복잡도가 걸리므로 인덱스 접근이 가능한 배열이 효율적
 * - 처음 등장하는 알파벳은 배열 정보 업데이트 하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.
 */

int main() {
    int n, result = 0;  // 입력 받을 단어의 개수 저장 변수: n, 그룹 단어의 개수를 저장할 변수: result (0으로 초기화)

    // 입력
    cin >> n;   // 단어의 개수를 입력 받아 변수 n에 저장
    while (n--) {   // n 개 동안
        string word;    // 문자열 변수: word
        cin >> word;    // word에 단어 저장

        // 연산
        if (isGroup(word)) {    // 그룹 단어인지 확인, isGroup() 함수 호출
            result++;   // 그룹 단어이면 result 수 증가
        }
    }

    // 출력
    cout << result; // result 값 출력
    return 0;
}