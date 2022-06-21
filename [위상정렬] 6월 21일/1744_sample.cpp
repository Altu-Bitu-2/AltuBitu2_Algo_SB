#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수열을 묶음
int tieNumber(vector<int> &arr) {
    int total = 0;  // 전체 합
    int size = arr.size();  // 배열의 크기
    for (int i = 0; i < size - 1; i += 2) { // 반복
        total += arr[i] * arr[i + 1];   // 수열의 합
    }
    //하나 남은 수 더해줌
    if (size % 2) { // 만약 2로 나누어지면
        total += arr[size - 1]; // 더해줌
    }
    return total;   // 리턴
}

/**
 * [수 묶기]
 *
 * 1. 양수는 양수끼리, 음수는 음수끼리 곱해야 큰 수를 만들 수 있다.
 * 2. 절댓값이 큰 것끼리 곱해야 더 큰 수를 만들 수 있다.
 *     ex) 1, 2, 3, 4 => 4 * 1 + 3 * 2 = 10
 *                    => 4 * 3 + 2 * 1 = 14
 * 3. 1은 곱하는 것보다 더해야 큰 수를 만들 수 있다. (x * 1 = x < x + 1)
 */
int main() {
    int n, x, cnt1 = 0; // 수열의 길이(n), 수열의 수(x), 1의 개수(cnt1)

    //입력
    cin >> n;   // 수열의 길이 입력 받음
    vector<int> arr_pos, arr_neg;
    while (n--) {   // 반복
        cin >> x;   // 수열의 수 입력 받음
        if (x > 1) {    // 만약 수열의 수가 1보다 크면
            arr_pos.push_back(x);   // 양수 배열에
        } else if (x < 1) { // 1보다 작으면
            arr_neg.push_back(x);   // 음수 배열에
        } else {    // 1인 경우
            cnt1++; // 1의 개수 증가
        }
    }

    //절댓값이 큰 순으로 정렬
    sort(arr_pos.begin(), arr_pos.end(), greater<>());
    sort(arr_neg.begin(), arr_neg.end());

    //연산 & 출력
    cout << cnt1 + tieNumber(arr_pos) + tieNumber(arr_neg);
    return 0;
}