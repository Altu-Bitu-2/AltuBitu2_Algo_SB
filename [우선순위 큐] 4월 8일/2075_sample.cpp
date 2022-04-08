#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;   // n: 정수, input: 각 칸의 수
    priority_queue<int, vector<int>, greater<>> pq; // 최소 힙, 정렬이랑 반대, 상위 n개만 저장하는 힙

    cin >> n;   // 입력 받은 정수 값 n에 저장
    int size = n * n;   // size: n*n 표의 칸 수
    while (size--) {    // size 개수 동안 반복
        // 입력
        cin >> input;    // 입력 받은 각 칸의 수를 input 에 저장

        // 연산
        pq.push(input); // 칸에 채워진 수 저장
        if (pq.size() > n) {    // 최소 힙의 크기가 n 이상이라면 가장 작은 값 삭제
            pq.pop();   // 맨 처음 수(가장 작은 값) 삭제
        }
    }

    // 출력
    cout << pq.top();   // 힙의 맨 처음 수 출력, 가장 작은 수 순서로 n개 저장 되어 있기 때문에, 가장 큰 순서로 n번째 수와 동일
    return 0;
}