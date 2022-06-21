#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
vector<int> topologicalSort(int n, vector<int> &t, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;   // 진입차수가 0인 정점 관리
    vector<int> dp(n + 1, 0);   // 건물을 짓기까지 걸리는 최소 시간

    for (int i = 1; i <= n; i++) {  // 반복
        dp[i] = t[i];   // 배열 초기화
        if (!indegree[i]) { // 진입차수가 0이라면
            q.push(i);
        }
    }
    while (!q.empty()) {    // 반복, 비지 않을 동안
        int node = q.front();   // 큐의 가장 앞 값을 노드로
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {  // 반복
            int next_node = graph[node][i];
            // 다음 정점의 최소 시간 계산
            dp[next_node] = max(dp[next_node], dp[node] + t[next_node]);

            indegree[next_node]--;  // 연결된 정점의 진입 차수 1 감소
            if (!indegree[next_node]) { // 진입 차수가 0이면
                q.push(next_node);  // 큐에 추가
            }
        }
    }
    return dp;  // 리턴
}

/**
 * [게임 개발]
 *
 * - ACM Craft (1005) 와 동일한 문제
 * - 최소 시간 = 건물을 동시에 지을 수 있는 건 최대한 동시에 지어야 최소 시간이 걸리므로 그 전 정점 중 가장 오래 걸리는 시간을 선택
 */

int main() {
    int n, input;

    //입력
    cin >> n;
    vector<int> t(n + 1, 0); //건물을 짓는데 걸리는 시간
    vector<int> indegree(n + 1, 0); // 진입 차수
    vector<vector<int>> graph(n + 1, vector<int>(0));   // 인접 리스트 그래프
    for (int i = 1; i <= n; i++) {  // 반복
        cin >> t[i];    // 입력 받음
        while (cin >> input) {  // 반복
            if (input == -1) {  // 줄의 끝이면
                break;
            }
            graph[input].push_back(i);  // 저장
            indegree[i]++;
        }
    }

    //연산
    vector<int> ans = topologicalSort(n, t, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}