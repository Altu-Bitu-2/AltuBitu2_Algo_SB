#include <iostream>
#include <map>

using namespace std;

/**
 * 개강총회가 시작하기 전에 입장한 학회원을 먼저 map에 삽입
 * 개강총회를 끝내고 나서부터 스트리밍을 끝낼 때까지의 시간대의 채팅 기록을 보고 퇴장 여부 확인
 * -> 이때, 한 사람이 채팅 여러 개 남겼을 수 있으므로 이미 확인한 사람 체크하는 것이 중요 (map의 value 값 활용해서 체크)
 * 시간은 문자열로 받아서 처리 (대소관계 숫자와 동일)
 */

int main() {
    // 로컬에서 편하게 확인하기 위해 파일로 입력을 받아서 사용!
    // freopen("input.txt", "r", stdin);

    // 입출력 처리 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, e, q, t, name;    // 문자열 s, e, q, t, name 선언
    map<string, bool> m;    // 맵 m 선언
    int ans = 0;    // 출석 확인된 학회원 인원 수

    // 입력 & 연산
    cin >> s >> e >> q; // s, e, q 입력 받음
    while (cin >> t >> name) { // 입력이 있는 동안 반복
        if (t <= s) {    // 개강총회 시작하기 전 입장 시간대
            m[name] = true; // 우선 저장
        } else if (t >= e && t <= q) {  // 개강총회 끝 ~ 스트리밍 끝 시간대
            if (m[name]) {   // 출석 확인
                ans++;  // 출석 확인 학회원 수 증가
                m[name] = false;    // 같은 사람 여러 번 출석 되면 안되므로 체크
            }
        }
    }
    // 출력
    cout << ans << '\n';
    return 0;
}