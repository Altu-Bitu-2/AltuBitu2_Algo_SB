#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    priority_queue<int, vector<int>, greater<>> pq; //최소힙
    vector<int> result; // 결과

    for (int i = 1; i <= n; i++) {  // 반복
        if (!indegree[i]) { // 만약 진입 차수가 0이라면
            pq.push(i);
        }
    }
    while (!pq.empty()) {   // 반복
        int node = pq.top();    // 큐의 앞 값을 노드로
        pq.pop();

        result.push_back(node); // 현재 정점 순서 결과를 배열에 삽입
        for (int i = 0; i < graph[node].size(); i++) {  // 반복
            int next_node = graph[node][i]; // 다음 노드 값
            indegree[next_node]--;  // 연결된 정점의 진입 차수 1 감소
            if (!indegree[next_node]) { // 연결된 정점의 진입 차수가 0이면
                pq.push(next_node);
            }
        }
    }
    return result;  // 리턴
}

/**
 * [문제집]
 *
 * - 조건 1, 2까지는 평범한 위상정렬
 * - 조건 3 "가능하면 쉬운 문제부터 풀어야 한다." -> 위상정렬 시, 정점이 작은 순서부터
 * - 조건 3을 만족시키기 위해, 진입차수가 0인 정점을 담는 컨테이너로 우선순위 큐 사용
 */

int main() {
    int n, m, a, b; // 문제 수, 먼저 푸는 것이 좋은 문제에 대한 정보, 두 정수의 순서쌍(a 먼저가 더 좋음)

    //입력
    cin >> n >> m;  // 입력 받음
    vector<int> indegree(n + 1, 0); // 각 정점의 진입 차수
    vector<vector<int>> graph(n + 1, vector<int>(0));   // 인접 리스트 그래프
    while (m--) {   // 반복
        cin >> a >> b;  // 입력 받음
        graph[a].push_back(b); //a->b
        indegree[b]++;
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

    //출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}