#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ci; // ci를 pair<int, int>의 별칭으로 생각한다..?
bool cmp(const ci &a, const ci &b) {
    if (a.second != b.second) { // 1. y좌표가 증가하는 순서
        return a.second < b.second;
    }
    return a.first < b.first;   // 2. (y좌표가 같으면) x좌표가 증가하는 순서
}

int main() {
    int n, a, b;    // 변수 n, a, b 선언, n: 점의 개수, a: x좌표, b: y좌표

    // 입력
    cin >> n;
    vector<ci> arr(n, {0,0});
    for (int i = 0; i<n;i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    // 연산
    sort(arr.begin(), arr.end(), cmp);
    // 출력
    for(int i=0;i<n;i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return 0;
}