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
    return parent[x] = findParent(parent[x]);   // 그래프를 압축하며 루트 정점 찾기
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x); // 새 루트
    int py = findParent(y); // 새 루트

    if (px == py) { // 만약 두 루트가 같으면
        return false;   // 리턴
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py];   // 합치기
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];   // 합치기
        parent[px] = py;
    }
    return true;    // 리턴
}

int kruskal(int n, vector<tp> &edge) {
    int sum = 0, cnt = 0;   // 최소 유지비, 횟수
    for (int i = 0; i < edge.size(); i++) { // 반복
        int w = get<0>(edge[i]);    // 정보를 가져옴
        int u = get<1>(edge[i]);    // 정보를 가져옴
        int v = get<2>(edge[i]);    // 정보를 가져옴
        if (!unionNodes(u, v)) {    // 만약 사이클이 생기면
            continue;   // 넘어감
        }
        sum += w;   // 유지비 업데이트
        cnt++;  // 횟수 증가
        if (cnt == n - 1) { // 필요한 간선을 모두 찾으면
            return sum; // 리턴
        }
    }
    return 0;
}

/**
 * [도시 분할 계획]
 *
 * 마을을 두개로 분리하고, 각 집끼리 이동할 수 있는 최소한의 도로만 남기는 문제
 * 즉, 2개의 최소신장트리를 만들어야 하는 문제
 * -> 하나의 최소신장트리를 만들고, 그 중 가장 유지비가 큰 도로를 삭제
 * -> 크루스칼 알고리즘에서 가장 마지막에 삭제되는 도로가 유지비가 가장 큼
 * -> 크루스칼 알고리즘에서 간선을 n-2개만 선택하여 그 합을 구하여 해결
 */
int main() {
    int n, m, a, b, c;  // 집의 개수(n), 길의 개수(m), 길의 정보(a, b, c)

    //입력
    cin >> n >> m;  // 집의 개수, 길의 개수 입력 받음
    vector<tp> edge;
    parent.assign(n + 1, -1);
    while (m--) {   // 반복
        cin >> a >> b >> c; // 길의 정보를 입력 받음
        edge.push_back({c, a, b});  // 길의 정보 저장
    }

    //연산
    sort(edge.begin(), edge.end()); // 정렬

    //연산&출력
    cout << kruskal(n - 1, edge);   // 최소 유지비 출력
    return 0;
}