#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;  // ci = pair<int, int>

// 가장 추천 수가 적은 학생 중 게시 시간이 오래된 학생 찾는 함수
bool cmp(const pair<int, ci> &c1, const pair<int, ci> &c2) {
    if (c1.second.first != c2.second.first) {   // 만약 후보1과 후보2의 추천 학생수, 게시 개수가 다르면
        return c1.second.first < c2.second.first; // 리턴
    }
    return c1.second.second < c2.second.second; // 아닌 경우 리턴
}

/**
 * [후보 추천하기]
 *
 * 1. 비어있는 사진틀이 없는 경우, 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생을 삭제
 * -> min_element() 함수를 활용해서 조건을 만족하는 학생 찾기
 * -> min_element(x.begin(), x.end(), cmp): x 컨테이너 내에서 최솟값을 찾아주는 함수로 정렬과 비슷하게 cmp함수 써서 조건 설정 가능!
 *
 * 2. 후보 학생을 바로 찾기 위해 본 풀이는 map 컨테이너를 사용해 구현
 *
 * !주의! 게시 시간 정보 저장 시, 후보로 올라간 가장 첫 시간을 저장. 이미 후보에 있는데 게시 시간이 갱신되지 않도록 주의.
 */

int main() {
    int n, m, input;    // n: 사진들의 개수, m: 전체 학생의 총 추천 수, input: 추천받은 학생 번호, 추천받은 순

    // 입력 & 연산
    cin >> n >> m;  // 사진 개수, 총 추천 수 입력 받음
    map<int, ci> candidate; // first: 후보 학생, second: {추천 횟수, 게시 시간}
    for (int i = 0; i < m; i++) {
        cin >> input;   // 추천받은 학생 번호 입력
        // 비어있는 사진틀이 없는 경우
        if (candidate.size() == n && candidate.find(input) == candidate.end()) {
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp));  // 추천 수가 가장 적은 학생 중 게시 기간이 가장 오래된 학생 삭제
        }
        // 첫 게시라면
        if (candidate.find(input) == candidate.end()) {
            candidate[input].second = i;    // 후보로 올라간 가장 첫 시간 저장
        }
        candidate[input].first++; // 추천 횟수 증가
    }

    //출력
    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {
        cout << iter->first << ' ';
    }
    return 0;
}