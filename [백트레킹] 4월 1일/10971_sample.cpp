#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;    // 상수 INF =10^8

vector<bool> visited;   // 방문 검사 배열 vector visited
vector<vector<int>> matrix; // 비용 행렬 vector matrix
int n, ans = INF;   // 최소 비용 저장 위해 미리 최댓값으로 초기화, n: 도시의 수, ans: 최소 비용

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 * -> cnt: 방문한 도시 수, cur_city: 현재 방문 도시 이름(번호), cost: 지금까지의 비용
 */
 // backtracking() 함수
void backtracking(int cnt, int cur_city, int cost) {    // cnt: 방문한 도시 수, cur_city: 현재 방문 도시 이름(번호), cost: 지금까지의 비용
    if (cost >= ans) {  // 생각해보기 : 이 조건문이 없으면 어떻게 될까요? -> 모든 경우의 수를 탐색하게 되나요..?
        return; // 리턴
    }
    if (cnt == n) { // 종료 조건 : n개의 도시를 순회했음
        // 출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { // 출발 도시로 돌아올 수 없음
            ans = min(ans, cost + matrix[cur_city][0]); // ans는 ans와 cost + matrix[cur_city][0] 중 최솟값
        }
        return; // 리턴
    }
    for (int i = 0; i < n; i++) {   // cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) {   // 길이 있고, 아직 방문하지 않은 도시
            visited[i] = true;  // 방문했음, true로 업데이트
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);   // backtracking() 함수 호출, 방문 도시 수 1 증가, 현재 방문 도시 i, 비용 업데이트
            visited[i] = false; // false로 업데이트
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    // 입력
    cin >> n;   // 입력값 n에 저장(도시의 수)
    visited.assign(n, false);   // 방문 검사 vector visited, 크기: n, false로 초기화 (모두 가지 않았으므로)
    matrix.assign(n, vector<int>(n, 0));    // 비용 행렬 vector matrix, 크기: n, 0으로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];    // vector matrix에 값 저장
        }
    }

    // 연산
    visited[0] = true;  // 0번 도시 방문, true로 업데이트
    backtracking(1, 0, 0);  // backtracking() 함수 호출, 현재 0번 도시(방문 도시 1개, 비용 0) -> cnt: 1, cur_city: 0, cost: 0

    // 출력
    cout << ans;    // ans 출력
    return 0;
}