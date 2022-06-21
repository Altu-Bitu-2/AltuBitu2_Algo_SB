#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) {    // 값이 음수면 루트 정점
        return x;   // 리턴
    }
    return parent[x] = findParent(parent[x]);   // 그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x); // 새 루트
    int py = findParent(y); // 새 루트

    if (px == py) { // 만약 값이 같다면
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

double kruskal(int v, vector<tp> &edge) {
    double sum = 0; // 통로들의 길이 합
    int cnt = 0;    // 횟수

    for (int i = 0; i < edge.size(); i++) { // 반복
        double cost = get<0>(edge[i]);  // 비용 정보
        int x = get<1>(edge[i]);    // 좌표 받음
        int y = get<2>(edge[i]);    // 좌표 받음

        if (!unionNodes(x, y)) {    // 사이클이 생기는 경우
            continue;
        }
        sum += cost;    // 길이 업데이트
        cnt++;  // 횟수
        if (cnt == v - 1) { // 만약 간선을 다 찾으면
            return sum; // 리턴
        }
    }
    return 0;
}

/**
 * [우주신과의 교감]
 *
 * 4386번 : 별자리 만들기의 응용 문제
 * 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일
 *
 * 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 * 2. 이미 존재하는 통로들 표시
 *    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
 *          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 * 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
 */
int main() {
    int n, m, a, b, v = 0;  // 우주신들의 개수(n), 이미 연결된 신들과의 통로 개수(m)
    double x, y;    // 우주신들의 좌표

    //입력
    cin >> n >> m;  // 우주신 개수, 이미 연결된 신들과의 통로 개수를 입력 받음
    parent.assign(n + 1, -1);
    vector<tp> edge;    // 간선 배열
    vector<ci> star(n + 1); // 별의 위치

    for (int i = 1; i <= n; i++) {  // 반복
        cin >> x >> y;  // 우주신들의 좌표를 입력 받음
        for (int j = 1; j < i; j++) {   // 반복
            //임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx * dx + dy * dy), i, j});    // 거리 추가
        }
        star[i] = {x, y};   // 별의 위치
    }

    //연산
    while (m--) {   // 반복
        cin >> a >> b;  // 이미 연결된 통로 입력 받음
        if (unionNodes(a, b)) { //이미 연결된 통로
            v++;
        }
    }
    sort(edge.begin(), edge.end()); // 정렬

    //연산 & 출력
    cout << fixed;  // 고정된 소수점 자리로 출력할 것을 선언
    cout.precision(2);  // 소수점 2번째 자리로 정확도를 설정
    cout << kruskal(n - v, edge);   // 출력
    return 0;
}