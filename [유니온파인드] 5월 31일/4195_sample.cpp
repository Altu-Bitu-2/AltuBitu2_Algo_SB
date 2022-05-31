#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; // 친구 관계가 모두 다른 사용자로 들어왔을 때의 정점 최댓값

vector<int> parent(MAX + 1, -1);
map<string, int> people;    // 친구 관계, string을 int로 매핑

// Find 연산
int findParent(int node) {
    if (parent[node] < 0) { // 값이 음수면 루트 정점
        return node;    // 리턴
    }
    return parent[node] = findParent(parent[node]); // 그래프 압축, 루트 정점 찾기
}

// Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); // 루트 정점 찾기
    int yp = findParent(y); // 루트 정점 찾기

    if (xp == yp) { // 이미 있다면
        return; // 리턴
    }
    if (parent[xp] < parent[yp]) {  // 새로운 루트 xp에 대해
        parent[xp] += parent[yp];   // 업데이트
        parent[yp] = xp;    // 업데이트
    } else {    // 새로운 루트 yp에 대해
        parent[yp] += parent[xp];   // 업데이트
        parent[xp] = yp;    // 업데이트
    }
}

/**
 * [친구 네트워크]
 *
 * 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 * 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근
 *
 * !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f;   // 테스트 케이스 개수, 친구 관계의 수
    string a, b;    // 사용자 ID

    // 입력
    cin >> t;   // 테스트 케이스 개수
    while (t--) {   // 반복
        int idx = 1; // 정점과 매핑할 수
        parent.assign(MAX + 1, -1); // -1로 초기화

        cin >> f;   // 친구 관계의 수
        while (f--) {   // 반복
            cin >> a >> b;  // 사용자 ID 입력 받음
            if (!people[a]) {   // 새로운 친구 이면
                people[a] = idx++;  // 정점과 매핑할 수 증가
            }
            if (!people[b]) {   // 새로운 친구이면
                people[b] = idx++;  // 정점과 매핑할 수
            }

            // 연산
            int x = people[a], y = people[b];   // 친구 관계 저장
            unionInput(x, y);   // 유니온 연산

            // 출력
            cout << -parent[findParent(x)] << '\n';
        }
    }
    return 0;
}