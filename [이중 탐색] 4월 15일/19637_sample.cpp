#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; // 칭호와 그 칭호의 전투력 상한값

    int n, m, power;    // n: 칭호의 개수, m: 캐릭터의 개수, power: 전투력 상한값
    string name;    // name: 칭호의 이름

    // 입력
    cin >> n >> m;  // 칭호의 개수 n, 캐릭터의 수 m를 입력 받음
    while (n--) {   // 칭호의 개수 n 동안 반복
        cin >> name >> power;   // 칭호의 이름 name과 전투력 상한값 power를 입력 받음
        if (title[power].empty()) { // 만약 전투력 상한값에 해당하는 칭호가 없다면
            title[power] = name;    // 그 칭호를 title에 저장
        }
    }

    // 출력
    while (m--) {   // 캐릭터의 수 m 동안 반복
        cin >> power;   // 전투력의 상한값 power를 입력 받음
        cout << title.lower_bound(power)->second << '\n';   // 캐릭터의 전투력 상한값에 따라 칭호를 출력
    }
}