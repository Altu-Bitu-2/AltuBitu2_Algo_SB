#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;  // pair<int, int>를 ci로 대체

// 구조체 baseball
struct baseball {
    string num;     // 서로 다른 세 자리 수
    int strike, ball;   // 스트라이크 개수, 볼 개수
};

// 스트라이크, 볼 개수 count 하는 함수
ci cntStrikeBall(string &s1, string &s2) {
    int strike_cnt = 0; // s1과 s2 사이의 strike 개수, 0으로 초기화
    int ball_cnt = 0;   // s1과 s2 사이의 ball 개수, 0으로 초기화

    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) {  // 위치 + 수 정확히 일치 -> 스트라이크
            strike_cnt++;   // 스트라이크 개수 1 증가
        } else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재 -> 볼
            ball_cnt++; // 볼 개수 1 증가
        }
    }
    return ci(strike_cnt, ball_cnt);    // 스트라이크 수, 볼 수 리턴
}
// game() 함수, 게임이 진행
int game(int n, vector<baseball> &question) {
    int ans = 0;    // 정답 개수 변수 ans, 0으로 초기화

    for (int i = 123; i <= 987; i++) {  // 서로 다른 숫자로 구성된 가장 작은 수부터 가장 큰 수까지
        bool check = true;  // check 변수 true로 초기화
        string s1 = to_string(i);   // 정답인지 확인할 수

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') {  // 0이 하나라도 있다면 넘어감
            continue;
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { // 서로 같은 수 하나라도 있다면 넘어감
            continue;
        }

        for (int j = 0; j < n; j++) {
            string s2 = question[j].num; // 질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); // s1과 s2사이의 스트라이크와 볼 개수, cntStrikeBall() 함수 호출
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { // 하나라도 다르면
                check = false;  // 틀림
                break;  // break
            }
        }

        if (check) {    // 정답이면
            ans++;  // ans 1 증가
        }
    }
    return ans; // ans 리턴
}

/**
* [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면, 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123-987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서, 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865*100*3(자릴수)으로 접근 충분히 가능
*/

int main() {
    int n;  // 질문 횟수 저장 변수 n 선언

    // 입력
    cin >> n;   // 질문 횟수를 입력 받음, 1 <= n <= 100

    vector<baseball> question(n);   // vector question 생성
    for (int i = 0; i < n; i++) {
        cin >> question[i].num >> question[i].strike >> question[i].ball;   // 입력, 민혁이가 질문한 세 자리 수, 영수가 답한 스트라이크 개수, 볼의 개수
    }

    // 연산 + 출력
    cout << game(n, question);  // game() 함수 호출

    return 0;
}