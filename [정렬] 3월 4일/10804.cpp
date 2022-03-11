//
// Created by Subeen on 3/9/2022.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr; //vector arr 생성


int main() {
    // 1-20을 vector arr에 할당
    for (int i = 1; i <= 20; i++) {
        arr.push_back(i);
    }

    int a, b;
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;     // 구간 [a,b]
        // 구간 [a,b]에 해당하는 arr의 index값을 비교하여 a>=b 이면 swap 중지
        while (a < b) {
            swap(arr[a - 1], arr[b - 1]);   // 원소 swap
            a++;    // 다음 index로 넘어가야하므로 +1
            b--;    // 이전 index로 내려가야하므로 -1
        }
    }
    // arr 출력
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
