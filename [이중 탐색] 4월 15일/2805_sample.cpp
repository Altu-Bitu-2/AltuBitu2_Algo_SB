#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;   // long long 을 ll로 정의

// cntTree() 함수, 상근이가 집에 가져갈 수 있는 나무의 길이의 총합
ll cntTree(int height, vector<int> &tree) { // 입력값: 절단기에 설정한 높이(H), 나무 높이 정보
    ll sum = 0; // 상근이가 집에 가져갈 수 있는 총 나무의 길이, 0으로 초기화
    for (int i = 0; i < tree.size(); i++) { // 나무의 개수 동안 반복, 높은 나무부터
        if (height >= tree[i]) {    // 만약 절단기에 설정한 높이보다 낮다면
            return sum; // 상근이가 집에 가져갈 수 있는 총 나무 길이 sum 리턴
        }
        sum += (tree[i] - height);  // 절단기에 설정한 높이보다 놓은 나무라면, 절단기 설정 높이 위의 부분을 sum 에 저장
    }
    return sum; // 상근이가 집에 가져갈 수 있는 총 나무 길이 sum 리턴
}

// upperSearch() 함수, 절단기에 설정할 수 있는 높이의 최댓값 구함
int upperSearch(int left, int right, int target, vector<int> &tree) {
    // 입력값: 절단기의 최소 높이, 절단기의 최대 높이(가장 높은 나무), 상근이가 가져가려는 나무의 길이, 나무 높이 정보
    while (left <= right) { // 절단기의 최소 높이가 최대 높이보다 작거나 같은 동안 반복
        int mid = (left + right) / 2;   // 이분 탐색을 위해 중간값을 설정
        ll tree_cnt = cntTree(mid, tree);   // cntTree() 함수 호출, 상근이가 가져갈 수 있는 나무의 총 길이(tree_cnt)를 구함

        if (tree_cnt >= target) {   // 만약 상근이가 집에 가져갈 수 있는 나무의 길이가 상근이가 필요한 나무 길이보다 길거나 같으면
            left = mid + 1; // 절단기의 최소 높이를 mid+1로 업데이트
        } else {    // 작으면
            right = mid - 1;    // 절단기의 최대 높이를 mid+1로 업데이트
        }
    }
    return left - 1;    // left-1을 리턴
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m;   // n: 나무의 수, m: 상근이가 집으로 가져가려는 나무의 길이

    //입력
    cin >> n >> m;  // 나무의 수 n과 상근이가 집으로 가져가려는 나무의 길이 m을 입력 받음
    vector<int> tree(n, 0); // 한 줄에 있는 나무의 높이 정보 vector tree
    for (int i = 0; i < n; i++) {   // 한 줄에 있는 나무의 높이를 vector tree에 저장
        cin >> tree[i]; // 나무의 높이를 저장
    }

    sort(tree.begin(), tree.end(), greater<>());    // 나무의 높이 정보를 내림차순으로 정렬

    // 연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);   // upperSearch() 함수 호출, 절단기에 설정할 최대 높이 출력
    return 0;
}