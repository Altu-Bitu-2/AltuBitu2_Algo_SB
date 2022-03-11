//
// Created by Subeen on 3/9/2022.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;    // vector arr 생성

// 시계바늘이 가리키는 시각을 보여주는 함수
void showHour(int n) {      // n: 초 단위
    int h, m, s;
    arr.clear();    // 배열 초기화
    // 초를 h,m,s로 환산
    h = n / 3600;
    m = (n % 3600) / 60;
    s = (n % 3600) % 60;
    // arr에 저장
    arr.push_back(h);
    arr.push_back(m);
    arr.push_back(s);
    // arr 출력
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int h, m, s, hour;
    int q, T, c;

    cin >> h >> m >> s; // 입력 받은 값을 h,m,s 저장
    hour = 3600 * h + 60 * m + s;   // 초 단위로 환산
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> T;
        // T가 1일 때, 시계를 앞으로 c초 돌림(=시계가 가리키는 시각이 증가)
        if (T == 1) {
            cin >> c;
            hour = hour + c;
        }
        // T가 2일 때, 시계를 뒤로 c초 돌림(=시계가 가리키는 시각이 감소)
        else if (T == 2) {
            cin >> c;
            hour = hour - c;
        }
        else {
            showHour(hour);
        }
    }
    return 0;
}