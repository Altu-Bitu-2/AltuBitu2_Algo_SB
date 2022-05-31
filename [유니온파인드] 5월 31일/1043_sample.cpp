#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // parent 벡터

// Find 연산
int findParent(int node) {
    if (parent[node] < 0) { // 값이 음수면 루트 정점
        return node;    // 리턴
    }
    return parent[node] = findParent(parent[node]); // 그래프 압축, 루트 정점 찾기
}

// Union 연산
void unionInput(int x, int y) { // y 사람의 번호
    int xp = findParent(x); // 루트 정점 찾기
    int yp = findParent(y); // 루트 정점 찾기

    if (xp == yp) { // 이미 같은 집합에 있다면
        return; // 리턴
    }
    if (parent[xp] < parent[yp]) {  // 새로운 루트 xp에 대해
        parent[xp] += parent[yp];   // 값 업데이트
        parent[yp] = xp;    // 값 업데이트
    } else {    // 새로운 루트 yp에 대해
        parent[yp] += parent[xp];   // 값 업데이트
        parent[xp] = yp;    // 값 업데이트
    }
}

// 거짓말 가능한 파티 찾기
int liarParty(vector<int> &parties) {
    int cnt = 0;    // 거짓말 가능한 파티 수, 0 초기화
    for (int i = 0; i < parties.size(); i++) {  // 반복
        if (findParent(parties[i]) != findParent(0)) {  // 만약 진실을 아는 사람과 같은 집합이 아니라면
            cnt++;  // 거짓말 가능 파티 수 증가
        }
    }
    return cnt; // 리턴
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m;   // 사람 수 n, 파티 수 m

    // 입력
    cin >> n >> m;  // 사람 수와 파티 수 입력 받음
    parent.assign(n + 1, -1);   // parent 배열 -1 초기화

    int init, p;    // 진실을 아는 사람 init, 사람의 번호 p
    cin >> init;    // 진실을 아는 사람 입력 받음
    while (init--) { //  진실을 아는 사람들
        cin >> p;   // 사람의 번호 입력 받음
        unionInput(0, p);   // Union 연산
    }

    int cnt, first_person, person;  // 파티 사람 수, 파티에 참석하는 첫 번째 사람, 파티에 참석하는 사람
    vector<int> parties;    // 파티 집합
    while (m--) {   // 파티 수만큼 반복
        cin >> cnt >> first_person; // 입력 받음

        // 연산
        parties.push_back(first_person); // 파티 정보, 각 파티의 첫번째 사람만 저장
        while (--cnt) { // 파티 사람 수 동안 반복
            cin >> person;  // 사람 정보
            unionInput(first_person, person);   // Union 연산
        }
    }

    // 연산 & 출력
    cout << liarParty(parties); // 거짓말 할 수 있는 파티 수
    return 0;
}