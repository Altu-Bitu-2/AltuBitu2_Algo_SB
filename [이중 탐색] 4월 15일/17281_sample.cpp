#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings;    // 이닝
vector<int> order(10, 0); // 타순
vector<bool> check(10, false);  // 선수 순서가 정해졌는지 여부
int n, ans; // n: 이닝 수, ans: 득점

// hitScore() 함수, 각 루타마다 얻는 점수
int hitScore(int hit, vector<bool> &baseman) {  // 입력값: 공격 상태, 각 루수의 선수 여부
    int score = 0;  // 총 점수
    for (int i = 3; i >= 0; i--) {  // i: 루수
        if (!baseman[i]) {  // 만약 i루수에 선수가 없다면
            continue;   // continue
        }
        if (i + hit >= 4) { // 루수와 공격 상태가 4 이상이면
            score ++;   // 홈에 선수가 도착하여 점수 1 증가
        } else {    // 아니면
            baseman[i + hit] = true;    // 루수에 선수가 있음으로 change
        }
        baseman[i] = false; // i루수에는 선수가 없음
    }
    if (hit == 4) { // 만약 hit = 4(홈런)이면
        score++;    // 점수 1 증가
    } else {    // 아니면
        baseman[hit] = true;    // 새로운 선수들 홈에 도착
    }
    return score;   // 총 점수(score) 리턴
}

// calcScore() 함수, 현재 배치의 점수
int calcScore() {
    int score = 0;  // 총 점수
    int idx = 1;    // 타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) {   // i: 이닝
        vector<bool> baseman(4, 0); // 각 루수마다 선수가 있는지
        int out = 0;    // 아웃 선수 카운트
        while (out < 3) {   // 아웃 선수가 3명 미만일 때
            int state = innings[i][order[idx++]];   // 현재 선수의 공격 상태
            if (idx == 10) {    // 만약 10번이라면
                idx = 1;    // 인덱스 번호를 다시 1로
            }
            if (state == 0) {   // 만약 현재 선수의 공격 상태가 0이면
                out++;  // 아웃의 수 1 증가
            } else {    // 공격 상태가 0이 아니라면
                score += hitScore(state, baseman);  // 총 점수를 증가, hitScore() 함수 호출
            }
        }
    }
    return score;   // 총 점수(score) 리턴
}

// array() 함수, 가능한 배치 모두 구하기
void array(int cnt) {   // cnt: 타자순서
    if (cnt == 4) { // 4번 타자는 정해져 있으므로
        array(cnt + 1); // 4번 타자 다음 타자의 배치
        return; // 리턴
    }
    if (cnt == 10) {    // 9번 타자까지 정해짐 (기저조건)
        int score = calcScore();    // calcScore() 함수 호출, 점수 계산
        ans = max(ans, score);  // ans를 더 최댓값으로 업데이트
        return; // 리턴
    }
    for (int i = 2; i <= 9; i++) {  // 2번 선수부터 9번 선수까지
        if (!check[i]) {    // 선수의 순서가 정해지지 않았다면
            order[cnt] = i; // cnt번 타자: i번 선수
            check[i] = true;    // i번 선수 순서 정해짐
            array(cnt + 1); // 다음 타자
            check[i] = false;   // 선수 순서 상태를 change
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    // 입력
    cin >> n;   // 이닝 수 n을 입력 받음
    innings.assign(n, vector<int>(10, 0));  // 이닝을 초기화
    for (int i = 0; i < n; i++) {   // n번의 이닝 결과 저장
        for (int j = 1; j < 10; j++) {  // 각 선수가 한 이닝에서 얻는 결과 저장
            cin >> innings[i][j];   // 결과 저장
        }
    }

    // 연산
    order[4] = 1;   // 4번 타자는 1번 선수
    check[1] = true;    // 1번 선수는 순서 정해짐
    array(1);   // array() 함수 호출, 가능한 모든 배치를 구함

    // 출력
    cout << ans;    // 득점을 출력
    return 0;
}