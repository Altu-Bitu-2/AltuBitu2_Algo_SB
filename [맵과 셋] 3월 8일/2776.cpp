//
// Created by Subeen on 3/14/2022.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, input;
    vector<int> v1, v2;

    cin >> t;
    cin >> n;
    // vector v1에 수첩1 정수 저장
    for (int i = 0; i < n; i++) {
        cin >> input;
        v1.push_back(input);
    }

    cin >> m;
    // vector v2에 수첩2 정수 저장
    for (int i = 0; i < m; i++) {
        cin >> input;
        v2.push_back(input);
    }
    // 수첩2의 정수가 수첩1에 있는지 확인 (수첩2 정수의 순서대로, 수첩1에 있으면 1, 없으면 0)
    for (int i = 0; i < m; i++) {
        // 수첩1에 수첩2의 정수가 없을 때 -> 0
        if (find(v1.begin(), v1.end(), v2[i]) == v1.end()) {
            cout << 0 << '\n';
        } else {    // 수첩1에 수첩2의 정수가 있을 때 -> 1
            cout << 1 << '\n';
        }
    }
    return 0;
}
