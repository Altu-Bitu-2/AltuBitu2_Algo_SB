//
// Created by Subeen on 3/23/2022.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;    // 답을 저장할 vector ans

// 연산을 수행할 함수 calc
void calc(string a, string b) {
    int up = 0, goans;  // 다음 자리로 올릴 수: up(0으로 초기화), 해당 자릿수 답이 될 수: goans
    int num1, num2; // 자릿수를 정수로 바꾸어서 저장

    // 연산 수행
    for (int i = 0; i < a.size(); i++) {
        num1 = a[a.size() - 1 - i] - '0';   // 정수로 바꿈
        num2 = b[b.size() - 1 - i] - '0';   // 정수로 바꿈
        goans = num1 + num2 + up;       // 각 숫자의 자릿수 합과 올림된 수의 합
        up = goans / 10;    // goans 값이 10 이상이면 up = 1, 미만이면 up = 0
        goans = goans % 10;     // 답이 될 수
        ans.push_back(goans);   // 답을 저장할 vector ans 에 저장
    }
    if (up == 1) {  // 만약 마지막 계산 결과 up = 1이면 vector ans에 저장
        ans.push_back(up);
    }
}

int main() {
    string a, b;    // 입력 받을 수, 자릿수가 너무 많아서 문자열로 받음
    cin >> a;   // 입력을 받음
    cin >> b;   // 입력을 받음
    int size1 = a.size();   // 정수1의 자릿수: size1
    int size2 = b.size();   // 정수2의 자릿수: size2

    // 입력된 수의 길이에 같으면 바로 연산 수행, 다르면 숫자 앞에 "0"을 추가하여 자릿수를 맞추어 연산 진행
    if (size1 == size2) {   // 자릿수가 같은 경우
        calc(a, b); // 연산, calc() 함수 호출

    } else if (size1 > size2) { // 정수1의 자릿수가 큰 경우
        // "0" 추가
        for (int i = 0; i < size1 - size2; i++) {
            b = "0" + b;
        }
        calc(a, b); //연산, calc() 함수 호출
    } else {    // 정수2의 자릿수가 큰 경우
        // "0" 추가
        for (int i = 0; i < size2 - size1; i++) {
            a = "0" + a;
        }
        calc(a, b); // 연산, calc() 함수 호출
    }
    // 출력
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[ans.size() - 1 - i];
    }
    return 0;
}
