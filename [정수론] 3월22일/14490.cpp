#include <iostream>
using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {    // 최대공약수를 구하는 함수
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {   // b = 0 이면 a 리턴
        return a;
    }
    return gcdRecursion(b, a % b);  // 재귀함수 호출, b와 a를 b로 나눈 나머지 를 다시 변수로
}

int main() {
    string s;   // 입력 값을 받을 변수 s

    //입력
    cin >> s;   // 입력값을 변수 s에 저장

    //연산(입력으로부터 n, m 추출하기)
    int index = s.find(':'); // ':' 위치 찾기
    int n = stoi(s.substr(0, index)); // : 이전의 문자를 숫자로 변경
    int m = stoi(s.substr(index + 1, s.length())); // : 이후 문자를 숫자로 변경

    //최대공약수 구하기
    int g = gcdRecursion(max(n, m), min(n, m));     // 최대공약수를 구하는 함수 호출, 정수형 변수 g에 저장

    //출력
    cout << n / g << ':' << m / g << '\n';

    return 0;
}