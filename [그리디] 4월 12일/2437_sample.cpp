#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// findUnmeasurable() 함수, 주어진 저울추들로 측정할 수 없는 무게의 최솟값을 계산하는 함수
int findUnmeasurable(vector<int> &weight) { // 리턴 값: 측정할 수 없는 가장 작은 무게, 입력 값: 추들의 정보
    int sum = 0;    // 현재 측정가능한 무게 범위 sum, 1씩 증가시키면서 비어있는 값을 확인하기 위해 0으로 초기화
    // 측정하고자 하는 무게를 무게가 1인 경우부터 +1 하면서 측정가능한지 확인
    for (int i = 0; i < weight.size(); i++) {   // 저울추의 개수 동안 반복, 모든 정수 무게를 확인
        if (sum + 1 < weight[i]) {  // 현재 측정가능한 무게 범위 sum + 1 이 저울추의 무게 보다 작은 경우, 측정 불가한 최솟값이 되므로
            return sum + 1; // sum+1 리턴
        }
        sum += weight[i];   // 측정가능한 범위를 증가
    }
    return sum + 1; // 저울추 합 이내의 모든 경우가 측정 가능한 경우, 측정가능한 값 sum+1 를 리턴
}

/**
 * [저울]
 *
 * 작은 값부터 측정 가능한지 파악해야 하므로, 오름차순으로 정렬한다.
 * 현재 0부터 scope까지 모든 무게를 빠짐없이 측정가능하다고 했을 때, 새로운 무게는 scope + 1보다 작거나 같아야 한다.
 * ex) 현재 1~5까지 측정 가능한데, 다음 값이 7인 경우 -> 6은 측정 불가
 *
 * 만약 이 조건을 만족할 경우, 측정 가능한 범위는 [1, scope + 새로운 무게]로 갱신된다.
 * 모든 저울을 살펴봤는데도 비어있는 값이 없으면, scope + 1 리턴
 */

int main() {
    int n;  // n: 저울추의 개수

    // 입력
    cin >> n;   // 저울추의 개수를 입력 받음
    vector<int> weight(n, 0);   // 각 저울추의 무게를 정보를 나타내는 vector weight
    for (int i = 0; i < n; i++) {   // 저울추의 개수 동안
        cin >> weight[i];   // 저울추의 무게 저장
    }

    // 정렬
    sort(weight.begin(), weight.end()); // 오름차순 정렬

    // 연산 & 출력
    cout << findUnmeasurable(weight);   // findUnmeasurable() 함수 호출
    return 0;
}