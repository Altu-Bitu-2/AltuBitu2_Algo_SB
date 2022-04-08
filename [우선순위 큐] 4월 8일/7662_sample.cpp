#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;  // pair<int, int> -> ci

vector<bool> is_valid;  // vector is_valid 선언

// deleteMax() 함수, 최대 힙에서 최댓값을 삭제. 최대 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMax(priority_queue<ci> &heap) {  // 입력값: 최대 힙
    while (!heap.empty() && !is_valid[heap.top().second]) { // 최대 힙이 비거나, top 데이터가 is_valid 할 때까지
        heap.pop(); // 최대 힙에서 최댓값 삭제
    }
}

// deleteMin() 함수, 최소 힙에서 최솟값 삭제. 최소 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>> &heap) {   // 입력값: 최소 힙
    while (!heap.empty() && !is_valid[heap.top().second]) { // 최소 힙이 비거나, top 데이터가 is_valid 할 때까지
        heap.pop(); // 최소 힙에서 최솟값 삭제
    }
}

/**
 * 우선순위 큐 풀이
 * 최대 힙과 최소 힙을 동시에 관리하면서 각각의 힙에서 삭제된 데이터를 다른 힙에 반영하는 방법
 * -> 각 데이터의 유효성을 체크하는 배열을 만들기
 */

/*
 * 1. 삽입
 * 2. 삭제
 *      - 우선 순위 가장 높은 것(n=1)
 *      - 우선 순위 가장 낮은 것(n=-1)
 */
int main() {
    int t, k, n;    // t: 테스트 데이터(입력 데이터의 수), k: Q에 적용할 연산의 개수, n: 정수
    char cmd;   // cmd: 수행할 연산을 나타내는 문자 ('D' or 'I')

    cin >> t;   // 입력 받은 테스트 케이스의 수를 t에 저장
    while (t--) {   // 테스트 케이스 수 만큼 반복
        priority_queue<ci> max_heap;    // 최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; // 최소 힙
        cin >> k;   // 입력 받은 연산의 개수 k에 저장
        int idx = 0;    // I 연산으로 입력된 숫자의 인덱스
        while (k--) {   // 연산의 개수 만큼 반복
            // 입력
            cin >> cmd >> n;    // 수행할 연산과 정수 저장

            // 연산
            switch (cmd) {  // 입력 받은 수행할 연산이
                case 'I':   // 'I'이면, 두가지 힙 모두에 값을 넣은 뒤, is_valid 벡터에도 추가
                    max_heap.push(ci(n, idx));  // 최대 힙에 <n, 인덱스> 쌍 추가
                    min_heap.push(ci(n, idx));  // 최소 힙에 <n, 인덱스> 쌍 추가
                    is_valid.push_back(true);   // vector is_valid에 true 추가
                    idx++;  // 인덱스 값 1 증가
                    break;  // break
                case 'D':   // 'D'이면, n에 따라 최대 힙 또는 최소 힙에서 데이터 삭제
                    if (n == 1) {   // 최댓값을 삭제하는 연산
                        deleteMax(max_heap);    // D연산 전처리, deleteMax() 함수 호출
                        if (!max_heap.empty()) {    // D연산, 최대 힙이 empty가 아니라면
                            is_valid[max_heap.top().second] = false;    // is_valid[최대 힙의 인덱스]에 false 추가
                            max_heap.pop(); // 최대 힙에서 최댓값 삭제
                        }
                    }
                    if (n == -1) {  // 최솟값을 삭제하는 연산
                        deleteMin(min_heap);    // D연산 전처리, deleteMin() 함수 호출
                        if (!min_heap.empty()) {    // D연산, 최소 힙이 empty가 아니라면
                            is_valid[min_heap.top().second] = false;    // is_valid[최소 힙의 인덱스]에 false 추가
                            min_heap.pop(); // 최소 힙에서 최솟값 삭제
                        }
                    }
                    break;  // break
            }
        }
        // 마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);    //deleteMax() 함수 호출
        deleteMin(min_heap);    //deleteMin() 함수 호출

        // 출력
        if (max_heap.empty()) { // 만약 최대 힙이 비었다면
            cout << "EMPTY\n";  // "EMPTY" 출력
        }
        else {  // 비지 않았다면
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';    // 최대 힙의 맨 처음 값, 최소 힙의 맨 처음 값 출력
        }
        is_valid.clear();   // 새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}