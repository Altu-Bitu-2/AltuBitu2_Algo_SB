#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // parent 벡터

// Find 연산
int findParent(int node) {
    if (parent[node] < 0) { // 값이 음수면 루트 정점
        return node;    // 리턴
    }
    return parent[node] = findParent(parent[node]); // 그래프를 압축하며 루트 정점 찾음
}

// Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); // 루트 정점 찾기
    int yp = findParent(y); // 루트 정점 찾기

    if (xp == yp) { // 이미 같은 집합에 있는 경우
        return false;   // 리턴
    }
    if (parent[xp] < parent[yp]) {  // 새로운 루트 xp
        parent[xp] += parent[yp];   // 값 업데이트
        parent[yp] = xp;    // 값 업데이트
    } else {
        parent[yp] += parent[xp];   // 새로운 루트 yp
        parent[xp] = yp;    // 값 업데이트
    }
    return true;    // 리턴
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    int n, m, x, y; // 점의 개수 n, 진행된 차례 m, 플레이어가 선택한 점 x, y
    // 입력
    cin >> n >> m;  // 점의 개수와 진행 차례를 입력 받음
    parent.assign(n, -1);   // parent 벡터를 -1로 초기화
    for (int i = 0; i < m; i++) {   // 반복
        cin >> x >> y;  // 플레이어가 선택한 점 입력

        // 연산 & 출력
        if (!unionInput(x, y)) { // 사이클이 생성됨
            cout << i + 1;  // 출력, 처음 사이클이 완성된 차례
            return 0;   // 리턴
        }
    }
    cout << 0;  // m 번의 차례 모두 처리한 이후에도 종료 되지 않았다면 0 출력
    return 0;
}