#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<int> bfs(int n, vector<vector<ci>> &graph) {
    queue<int> q;
    vector<int> cnt(n + 1, 0); //큐에 있는 부품 번호에 따른 개수 저장 + 방문체크
    vector<int> ans(n + 1, 0); //기본 부품 개수 저장

    //시작 정점 초기화
    q.push(n);
    cnt[n] = 1;

    while (!q.empty()) {    // 반복
        int x = q.front();  // 큐의 앞 값
        q.pop();    // 큐에서 꺼냄

        //리프노드(기본부품)인 경우
        if (graph[x].empty()) {
            ans[x] += cnt[x];   // 답에 추가
        }
        //중간부품인 경우
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i].first;
            int k = graph[x][i].second;
            if (!cnt[y]) {  // 연결된 정점의 진입 차수가 0이면
                q.push(y);  // 저장
            }
            cnt[y] += k * cnt[x];   // 중간부품을 만들기 위한 기본부품 정보 업데이트
        }
        cnt[x] = 0; //처리가 끝나면 0으로 리셋
    }
    return ans; // 리턴
}

/**
 * [장난감 조립]
 *
 * - 완제품을 만들기 위해 필요한 기본 부품의 개수를 구하는 문제
 * - y(필요한 부품) -> x(만들어지는 부품)의 관계를 역으로 만들면 x -> y가 되면서 루트노드가 완제품이 되고 리프노드가 기본 부품이 됨
 * - 따라서, BFS/DFS 탐색을 통해 필요한 리프노드의 총 개수를 구함
 */
int main() {
    int n, m, x, y, k;  // 부품 번호, 자연수, 부품들 간의 관계

    //입력
    cin >> n >> m;  // 입력 받음
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    while (m--) {   // 반복
        cin >> x >> y >> k; // 부품들 간의 관계를 입력 받음
        graph[x].push_back({y, k}); // 값 추가
    }

    //연산
    vector<int> result = bfs(n, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        if (result[i]) {
            cout << i << ' ' << result[i] << '\n';
        }
    }
    return 0;
}