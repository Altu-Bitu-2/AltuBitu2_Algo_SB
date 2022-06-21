#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) { // 입력: 스위치 개수, 학생이 받은 수, 스위치 상태
    for (int i = number; i <= n; i += number) { //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i]; // 스위치 상태 바꿈
    }
    return switches;    // 리턴
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) { // 입력: 스위치 개수, 학생이 받은 수, 스위치 상태
    switches[number] = !switches[number];   // 받은 번호의 스위치 상태 바꿈
    for (int i = 1; i < number; i++) {  // 반복
        if ((number + i > n) || (switches[number - i] != switches[number + i])) { //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break;
        }
        switches[number - i] = !switches[number - i];   // 구간에 해당하는 스위치 상태 바꾸기
        switches[number + i] = !switches[number + i];   // 구간에 해당하는 스위치 상태 바꾸기
    }
    return switches;    // 리턴
}

/**
 * [스위치 켜고 끄기]
 *
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m;   // n: 스위치 개수, m: 학생 수
    int student, number;    // student: 학생 성별, number: 학생이 받은 수

    //입력
    cin >> n;   // 스위치 개수 n을 입력 받음
    vector<int> switches(n + 1, 0); // 스위치 상태 배열
    for (int i = 1; i <= n; i++) {  // 반복
        cin >> switches[i]; // 스위치의 상태를 입력 받음
    }

    //입력 & 연산
    cin >> m;   // 학생 수 m을 입력 받음
    while (m--) {   // 반복
        cin >> student >> number;   // 학생 성별, 학생이 받은 수를 입력 받음
        if (student == 1) { // 만약 남학생이면 (student 값이 1인 경우)
            switches = changeSwitchBoy(n, number, switches);    // 스위치 상태를 바꿈
        } else {    // 여학생이면 (student 값이 2인 경우)
            switches = changeSwitchGirl(n, number, switches);   // 스위치 상태를 바꿈
        }
    }

    //출력
    for (int i = 1; i <= n; i++) {  // 반복
        cout << switches[i] << ' '; // 출력
        if (i % 20 == 0) {  // 한줄에 20개씩 출력
            cout << '\n';
        }
    }
    return 0;
}