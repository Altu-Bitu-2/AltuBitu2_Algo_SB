#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;  // ci = pair<int, int>

// 노드 찾는 함수
ci dfs(int node, int parent, vector<vector<ci>> &graph) {
    int pos = node, len = 0; // 지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) {  // 반복
        int next_node = graph[node][i].first;   // 다음 노드 저장
        if (next_node == parent) {  // 만약 부모 노드와 다음 노드가 동일하면
            continue;
        }

        ci dfs_search = dfs(next_node, node, graph); // 자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.second > len) { // 기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.second;    // 더 긴 거리로 업데이트
            pos = dfs_search.first; // 지름을 구성하는 노드 중 하나 업데이트
        }
    }
    return {pos, len};  // 리턴
}

/**
 * [트리의 지름]
 *
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */

int main() {
    int n, p, c, w; // n: 노드의 개수, p: 부모 노드, c: 자식 노드, w: 간선의 가중치

    // 입력
    cin >> n;   // 노드의 개수 저장
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); // vector graph
    for (int i = 1; i < n; i++) { // 무방향 그래프로 만들기
        cin >> p >> c >> w; // 부모 노드, 자식 노드, 간선의 가중치 입력
        graph[p].push_back({c, w}); // vector graph에 요소 추가
        graph[c].push_back({p, w}); // vector graph에 요소 추가
    }

    // 연산
    ci first_node = dfs(1, -1, graph); // 지름을 구성하는 노드 하나 찾기, dfs() 함수
    ci second_node = dfs(first_node.first, -1, graph); // 지름을 구성하는 다른 노드 찾기, dfs() 함수

    // 출력
    cout << second_node.second;
    return 0;
}