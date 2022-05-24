#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt;    // vector subtree_cnt: 서브트리 정점 수

// 탐색
int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) { // 이미 탐색했던 상태
        return subtree_cnt[cur];    // 리턴
    }

    // 서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0;   // 현재 값을 0으로 설정
    int node = 1;   // 서브트리 정점 수
    for (int i = 0; i < graph[cur].size(); i++) {   // 반복
        node += treeDp(graph[cur][i], graph);   // 서브 트리 정점 수 업데이트
    }
    return subtree_cnt[cur] = node; // 리턴
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * [트리와 쿼리]
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 메모리제이션하며 계산
 * - 서브트리에 속한 정점의 개수를 저장하는 dp 배열의 초기화를 -1로 해주고,
 *   dfs 탐색 시 현재 정점의 dp 값을 0으로 설정함으로써 자식 노드만 탐색할 수 있도록 함 (부모 노드에 0이 저장되어 있으므로 바로 리턴)
 *
 */

int main() {
    // 입출력 속도
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;   // n: 트리의 정점의 수, r: 루트의 번호, q: 쿼리의 수, u,v: 양끝 점, input:

    // 입력
    cin >> n >> r >> q; // 트리 정점의 수, 루트 번호, 쿼리 수 입력 받음
    vector<vector<int>> graph(n + 1, vector<int>(0));   // vector graph
    subtree_cnt.assign(n + 1, -1);  // subtree_cnt를 -1로 초기화

    while (--n) { // 무방향 그래프
        cin >> u >> v;  // 양 끝점 입력 받음
        graph[u].push_back(v);  // 그래프에 저장
        graph[v].push_back(u);  // 그래프에 저장
    }

    // 연산
    treeDp(r, graph);

    // 출력
    while (q--) {
        cin >> input;
        cout << subtree_cnt[input] << '\n';
    }
    return 0;
}