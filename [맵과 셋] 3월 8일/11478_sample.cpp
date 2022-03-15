#include <iostream>
#include <set>

using namespace std;

// 서로 다른 부분 문자열 구하는 함수
int cntDiff(string s) {
    set<string> sub;    // 중복 없이 부분 문자열 저장
    // 문자열의 길이만큼 반복
    for (int i = 0; i < s.length(); i++) {  // 문자열 시작 부분
        string temp = "";   // 빈 문자열 temp 선언
        for (int j = i; j < s.length(); j++) { // 문자열 끝 부분
            temp += s[j];   // i-j 부분 문자열
            sub.insert(temp);   // 삽입
        }
    }
    return sub.size();  // 부분 문자열 개수 return
}

/**
 * 중복을 제거해서 저장해주는 컨테이너인 set을 활용해서 풀이 가능
 * 삽입만 하므로 트리 구조 셋(set)이나 해시 구조 셋(unordered_set) 중 무엇을 쓰든 크게 상관 X
 */

int main() {
    string s;   // 문자열 s 선언

    // 입력
    cin >> s;   // 입력 받은 문자열 저장
    // 연산 & 출력
    cout << cntDiff(s);     // cntDiff(s)함수 호출
    return 0;
}