#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;   // vector tree

// 주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {   // 입력: 루트, 지울 노드
    if (node == erase_node) {   // 만약 루트와 지울 노드가 동일하면
        return 0;   // 리턴 0
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {    // 만약 트리가 비었거나 트리가 1, 지울 노드와 같으면
        return 1;   // 리턴 1
    }
    int cnt = 0;    // 리프 노드 개수
    for (int i = 0; i < tree[node].size(); i++) {   // 반복
        cnt += eraseLeafCnt(tree[node][i], erase_node); // 리프 노드 수 업데이트
    }
    return cnt; // 리턴
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node;   // n: 트리의 노드 개수, par: 각 노드의 부모, root: 루트, erase_node: 지울 노드

    // 입력
    cin >> n;   // 트리의 노드 개수 입력 받음
    tree.assign(n, vector<int>(0)); // tree에 노드 저장
    for (int i = 0; i < n; i++) {   // 반복
        cin >> par; // 각 노드의 부모 입력 받음
        if (par == -1) {    // 만약 부모 노드가 없다면 (par = -1로 주어진 경우)
            root = i;   // 루트 i로 업데이트
            continue;
        }
        tree[par].push_back(i); // tree에 부모 노드 저장
    }
    cin >> erase_node;  // 지울 노드를 입력 받음

    // 연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}