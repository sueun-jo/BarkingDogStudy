#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. n을 입력받는다
    long long n; 
    cin >> n;

    // 2. n의 자릿수 cnt를 구한다
    int cnt=0;
    int q = n;
    while (q!=0){
        q /= 10;
        cnt++; //자릿수 늘리기
    }

    // 3. cnt를 기준으로 i*9*10^i를 구하여 answer에 누적하여 더한다
    // 자릿수가 4개면, 1 * 9*10^0개 + 2자릿수 90개 + 3자릿수 900개를 더해야함
    long long answer = 0;
    
    for (int i=1; i<=cnt-1; i++){

        answer += i*9*pow(10,i-1);
    }

    //4. 남은 remain을 계산한다. remain = n - (10^(cnt-1)-1)
    // cnt * remian 값을 계산한다 

    long long remain = n-(pow(10, cnt-1)-1);
    answer += cnt*remain;
    
    cout << answer;
    
    return 0;
}