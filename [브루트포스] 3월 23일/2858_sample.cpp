#include <iostream>
using namespace std;

// 기숙사 바닥의 l(높이), w(넓이) 구해서 리턴하는 함수
pair<int, int> length(int r, int b) {
    int area = r + b;   // 기숙사 바닥의 넓이 area: 빨간 타일의 개수 r과 갈색 타일의 개수 b의 합
    for (int i = area; i > 0; i--) {    // i = l(높이) 의 값
        if (area % i != 0) {    // w 가 정수가 아니라면 넘어감
            continue;
        }
        int w = area / i;   // w는 기숙사 바닥 넓이를 l(높이)로 나눈 값
        if (r == ((i + w) * 2 - 4)) {   // 만약 빨간 타일의 개수 r과 테두리 개수가 같으면
            return make_pair(i, w); // 상근이네 방의 크기 l과 w 리턴
        }
    }
}

/**
 * [기숙사 바닥 문제]
 * 빨간 타일: 테두리를 채움, 갈색 타일: 나머지
 * 문제 입력에 만족하는 방의 크기 l, w (l > w)를 출력하는 문제
 *
 * [풀이]
 * 기숙사 바닥의 넓이는 타일의 개수의 총합인 r + b
 * l(높이)이 r + b인 사각형부터 검사 (w = (r + b) / l) -> 테두리 타일 개수가 r개와 같다면 정답
 * 테두리 개수 = (l + w) * 2 - 4(겹치는 부분)
 * 입력 범위는 최대 r + b = 2,005,000 이므로 접근 가능!
 */

int main() {
    int r, b;   // r: 빨간 타일 개수, b: 갈색 타일 개수

    // 입력
    cin >> r >> b;  // 입력값을 r과 b에 저장

    // 연산
    pair<int, int> result = length(r, b);   // int 타입의 pair 클래스 result, length() 함수 호출

    // 출력
    cout << result.first << ' ' << result.second << '\n';   // l 과 w 출력
    return 0;
}