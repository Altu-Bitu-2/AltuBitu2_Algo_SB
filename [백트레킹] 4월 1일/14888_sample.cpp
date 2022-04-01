#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;    // 상수 INF_MAX = 10^9
const int SIZE = 11;    // 상수 SIZE = 11

int n;  // 수의 개수 변수 n 선언
vector<int> num(SIZE + 1);  // 정수형 vector num 선언, 크기: SIZE+1
vector<int> expression(4); // 정수형 vector expression 선언, 0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;  // 정수 변수 max_value(만들 수 있는 식의 최댓값) = -10^9로 초기화, min_value(만들 수 있는 식의 최솟값) = 10^9로 초기화

// backtracking() 함수
void backtracking(int cnt, int sum) {   // cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { // 연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);    // max_value는 max_value 값과 sum 중 최댓값
        min_value = min(min_value, sum);    // min_value는 min_value 값과 sum 중 최솟값
        return; // 리턴
    }
    for (int i = 0; i < 4; i++) {   // 연산자 검사
        if (expression[i]) {
            expression[i]--;    // 연산자의 개수 1 줄임
            int new_sum = 0;    // 새로운 연산 값을 저장할 변수 new_sum, 0으로 초기화
            switch (i) {    // 연산자 종류에 따라
                case 0: // i = 0일 때
                    new_sum = sum + num[cnt + 1];   // 덧셈 수행
                    break;
                case 1: // i = 1일 때
                    new_sum = sum - num[cnt + 1];   // 뺄셈 수행
                    break;
                case 2: // i = 2일 때
                    new_sum = sum * num[cnt + 1];   // 곱셈 수행
                    break;
                case 3: // i = 3일 때
                    new_sum = sum / num[cnt + 1];   // 나눗셈 수행
                    break;
            }
            backtracking(cnt + 1, new_sum); // backtracking() 함수 호출 (재귀)
            expression[i]++;    // 연산자의 개수 다시 1 증가
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    // 입력
    cin >> n;   // 입력 받은 값 n에 저장, 수의 개수
    for (int i = 0; i < n; i++) {   // vector num에 입력 받은 수열 저장
        cin >> num[i];  // 수열 저장
    }
    for (int i = 0; i < 4; i++) {   // vector expression에 입력 받은 각 연산자 개수 저장
        cin >> expression[i];   // 연산자 개수 저장
    }

    // 연산
    backtracking(0, num[0]);    // backtracking() 함수 호출

    // 출력
    cout << max_value << '\n' << min_value;
    return 0;
}