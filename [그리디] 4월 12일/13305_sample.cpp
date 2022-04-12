#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;   // long long 자료형을 ll으로 선언

// greedyOil() 함수, 최소비용을 출력
ll greedyOil(vector<pair<ll, ll>> &city, int n) {   // 리턴 값: 최소 비용, 입력 값: 도시에 관한 정보, 도시의 개수
    ll cur_cost = city[0].second, tot_cost = 0; // cur_cost: 현재의 (가장 저렴한)비용, tot_cost: 총 비용

    for (int i = 0; i < n; i++) {   // n개의 도시 동안
        if (city[i].second < cur_cost) {    // 이 도시의 기름값이 더 저렴하면 교체
            cur_cost = city[i].second;  // 현재의 가격을 더 저렴한 비용으로 교체
        }
        tot_cost += (cur_cost * city[i].first); // 이동 비용
    }
    return tot_cost;    // 총 비용을 리턴
}

/**
 * [주유소]
 *
 * 최대한 가격이 싼 곳에서 많은 기름을 넣어야 한다.
 * 따라서 첫번째 도시부터 현재까지 가장 싼 가격을 저장하고, 이동에 필요한만큼만 기름을 채운다.
 * 이렇게 하면 지금까지 지나 온 도시 중 가장 싼 곳에서 최대한 많이 살 수 있다.
 *
 * !주의! 도시 사이의 간격이 최대 10^9이고, 리터당 가격이 최대 10^9이므로
 *       가능한 정답의 최댓값은 10^18으로 int 범위 넘어감! -> long long 써야 함
 */

int main() {
    int n;  // n: 도시의 개수

    // 입력
    cin >> n;   // 도시의 개수를 입력 받음
    vector<pair<ll, ll>> city(n, {0, 0});   // 도시의 관한 정보를 저장할 vector city, x: 도로 수, y: 리터당 가격
    for (int i = 0; i < n - 1; i++) {   // (도시의 개수-1) 개의 도로 수
        cin >> city[i].first;   // 도로의 수를 vector city의 첫째 위치에 저장
    }
    for (int i = 0; i < n; i++) {   // 도시의 개수 동안
        cin >> city[i].second;  // 주요소의 리터당 가격 수를 vector city의 둘째 위치에 저장
    }

    // 연산 & 출력
    cout << greedyOil(city, n); // greedyOil() 함수를 호출하여 연산
    return 0;
}