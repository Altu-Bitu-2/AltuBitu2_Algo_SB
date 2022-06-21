#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) {    // 만약 값이 음수면 루트 정점
        return x;   // 리턴
    }
    return parent[x] = findParent(parent[x]);   // 그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x); // 새 루트
    int py = findParent(y); // 새 루트

    if (px == py) { // 만약 두 루트가 같다면
        return false;   // 리턴
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py];   // 합치기
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];   // 합치기
        parent[px] = py;
    }
    return true;
}

int kruskal(int n, vector<tp> &edges) {
    int sum = 0, cnt = 0;   // 최소비용, 횟수
    for (int i = 0; i < edges.size(); i++) {    // 반복
        int w = get<0>(edges[i]);   // 튜플에서 값을 가져옴
        int u = get<1>(edges[i]);   // 튜플에서 값을 가져옴
        int v = get<2>(edges[i]);   // 튜플에서 값을 가져옴
        if (!unionNodes(u, v)) {    // 만약 사이클이 생기면
            continue;
        }
        sum += w;   // 최소비용 업데이트
        cnt++;
        if (cnt == n - 1) { // 필요한 간선을 모두 찾으면
            return sum; // 리턴
        }
    }
    return 0;
}

/**
 * [전기가 부족해]
 *
 * 모든 도시에 전기가 공급될 수 있도록 최소 비용으로 도시를 연결하는 문제
 * 이 문제는 k개의 최소신장트리를 만들어야 하지만, 발전기가 있는 도시를 모두 가상의 정점에 연결한다고 생각하면 하나의 큰 트리를 이룸
 *
 * -> 한번의 크루스칼 알고리즘으로 해결 가능
 */
int main() {
    int n, m, k, u, v, w;   // 도시 개수(n), 설치 가능한 케이블 수(m), 발전소 개수(k), 케이블 정보(u, v, w)

    //입력
    cin >> n >> m >> k; // 도시 개수, 설치 가능 케이블 수, 발전소 개수를 입력 받음
    vector<tp> edge;    //
    parent.assign(n + 1, -1);
    for (int i = 0; i < k; i++) {   // 반복
        cin >> u;   // 케이블 정보 입력 받음
        parent[u] = 0; //0번 정점과 연결됐다고 생각
    }
    while (m--) {   // 반복
        cin >> u >> v >> w; // 케이블 정보 입력 받음
        edge.push_back({w, u, v});  // 저장
    }

    //연산
    sort(edge.begin(), edge.end()); // 정렬

    //연산 & 출력
    cout << kruskal(n - k + 1, edge); //k개의 정점은 이미 연결된 상태이므로 n - k개의 간선만 선택해도 됨
    return 0;
}